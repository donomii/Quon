{-# LANGUAGE DataKinds #-}
{-# LANGUAGE DuplicateRecordFields #-}
{-# LANGUAGE ExtendedDefaultRules #-}
{-# LANGUAGE TypeApplications #-}
import Control.Monad.Trans.Cont
import Control.Monad.IO.Class
import Data.Char (chr)
import Data.IORef
import Data.Maybe (isNothing)
import GHC.Records (getField)
import System.Directory (doesFileExist)
import System.Environment (getArgs, lookupEnv)
import System.Exit (ExitCode(..), exitWith)
import System.IO (Handle, stderr, hPutStr, hFlush)
import System.IO.Unsafe (unsafePerformIO)
import Text.Printf (printf, hPrintf)

default (Int, Double)

expect :: Maybe a -> a
expect (Just x) = x
expect Nothing = error "Quon nil dereference"

globalTrace :: IORef Bool
globalTrace = unsafePerformIO (newIORef False)
{-# NOINLINE globalTrace #-}

globalStepTrace :: IORef Bool
globalStepTrace = unsafePerformIO (newIORef False)
{-# NOINLINE globalStepTrace #-}

releaseMode :: IORef Bool
releaseMode = unsafePerformIO (newIORef False)
{-# NOINLINE releaseMode #-}

caller :: IORef String
caller = unsafePerformIO (newIORef "")
{-# NOINLINE caller #-}

globalArgs :: IORef [String]
globalArgs = unsafePerformIO (newIORef [])
{-# NOINLINE globalArgs #-}

globalArgsCount :: IORef Int
globalArgsCount = unsafePerformIO (newIORef 0)
{-# NOINLINE globalArgsCount #-}

globalStackTrace :: IORef (Maybe Box)
globalStackTrace = unsafePerformIO (newIORef Nothing)
{-# NOINLINE globalStackTrace #-}

hsIsNil :: Maybe a -> IO Bool
hsIsNil = pure . isNothing

hsGetEnv :: String -> IO String
hsGetEnv key = do
  value <- lookupEnv key
  pure (maybe "" (\x -> x) value)

hsPanic :: String -> IO ()
hsPanic = error

hsExit :: Int -> IO ()
hsExit 0 = exitWith ExitSuccess
hsExit n = exitWith (ExitFailure n)

hsStringLength :: String -> IO Int
hsStringLength = pure . length

hsSubString :: String -> Int -> Int -> IO String
hsSubString s start len = pure (take len (drop start s))

hsSetSubString :: String -> Int -> String -> IO String
hsSetSubString target start source = pure (take start target ++ source ++ drop (start + 1) target)

hsShowInt :: Int -> IO String
hsShowInt = pure . show

hsShowFloat :: Double -> IO String
hsShowFloat = pure . show

hsReadFile :: String -> IO (Maybe Box)
hsReadFile filename = do
  exists <- doesFileExist filename
  if exists then do
    contents <- readFile filename
    boxString contents
  else pure Nothing

hsWriteFile :: String -> String -> IO ()
hsWriteFile = writeFile

hsGetStringArray :: Int -> [String] -> IO String
hsGetStringArray index strs = pure (strs !! index)

hsProgramArgs :: IO [String]
hsProgramArgs = readIORef globalArgs

hsProgramArgsCount :: IO Int
hsProgramArgsCount = readIORef globalArgsCount

hsCharacter :: Int -> IO String
hsCharacter num = pure [chr num]

hsRemainder :: Int -> Int -> IO Int
hsRemainder a b = pure (a `mod` b)

hsMakeHash :: IO (IORef [(String, String)])
hsMakeHash = newIORef []

hsSetHash :: IORef [(String, String)] -> String -> String -> IO ()
hsSetHash hash key value = modifyIORef hash ((key, value) :)

hsGetHash :: IORef [(String, String)] -> String -> IO String
hsGetHash hash key = do
  pairs <- readIORef hash
  pure (maybe "" (\x -> x) (lookup key pairs))

hsInHash :: IORef [(String, String)] -> String -> IO Bool
hsInHash hash key = do
  pairs <- readIORef hash
  pure (not (isNothing (lookup key pairs)))

hsMakeArray :: Int -> IO [String]
hsMakeArray len = pure (replicate len "")

hsSetArray :: [String] -> Int -> String -> IO ()
hsSetArray _ _ _ = pure ()

hsGetArray :: [String] -> Int -> IO String
hsGetArray array index = pure (array !! index)


data Box = Box {   qf_lis :: IORef (Maybe Box)
,   qf_str :: IORef (String)
,   qf_i :: IORef (Int)
,   qf_f :: IORef (Double)
,   qf_typ :: IORef (String)
,   qf_voi :: IORef (Bool)
,   qf_boo :: IORef (Bool)
,   qf_lengt :: IORef (Int)
,   qf_car :: IORef (Maybe Box)
,   qf_cdr :: IORef (Maybe Box)
,   qf_tag :: IORef (Maybe Box)
}

newBox :: IO Box
newBox = do
  v_qf_lis <- newIORef Nothing
  v_qf_str <- newIORef ""
  v_qf_i <- newIORef 0
  v_qf_f <- newIORef 0.0
  v_qf_typ <- newIORef ""
  v_qf_voi <- newIORef False
  v_qf_boo <- newIORef False
  v_qf_lengt <- newIORef 0
  v_qf_car <- newIORef Nothing
  v_qf_cdr <- newIORef Nothing
  v_qf_tag <- newIORef Nothing
  pure Box { qf_lis = v_qf_lis, qf_str = v_qf_str, qf_i = v_qf_i, qf_f = v_qf_f, qf_typ = v_qf_typ, qf_voi = v_qf_voi, qf_boo = v_qf_boo, qf_lengt = v_qf_lengt, qf_car = v_qf_car, qf_cdr = v_qf_cdr, qf_tag = v_qf_tag }

notBool :: Bool -> IO (Bool)
notBool a_arg = evalContT $ callCC $ \qreturn -> do
  a <- liftIO (newIORef a_arg)
  hcond <- liftIO (readIORef a)
  if hcond
    then do
      hret <- pure False
      qreturn hret
      pure ()
    else do
      hret <- pure True
      qreturn hret
      pure ()
  pure False

andBool :: Bool -> Bool -> IO (Bool)
andBool a_arg b_arg = evalContT $ callCC $ \qreturn -> do
  a <- liftIO (newIORef a_arg)
  b <- liftIO (newIORef b_arg)
  hcond <- liftIO (readIORef a)
  if hcond
    then do
      hcond <- liftIO (readIORef b)
      if hcond
        then do
          hret <- pure True
          qreturn hret
          pure ()
        else do
          hret <- pure False
          qreturn hret
          pure ()
      pure ()
    else do
      hret <- pure False
      qreturn hret
      pure ()
  pure False

orBool :: Bool -> Bool -> IO (Bool)
orBool a_arg b_arg = evalContT $ callCC $ \qreturn -> do
  a <- liftIO (newIORef a_arg)
  b <- liftIO (newIORef b_arg)
  hcond <- liftIO (readIORef a)
  if hcond
    then do
      hret <- pure True
      qreturn hret
      pure ()
    else do
      hcond <- liftIO (readIORef b)
      if hcond
        then do
          hret <- pure True
          qreturn hret
          pure ()
        else do
          hret <- pure False
          qreturn hret
          pure ()
      pure ()
  pure False

nand :: Bool -> Bool -> IO (Bool)
nand a_arg b_arg = evalContT $ callCC $ \qreturn -> do
  a <- liftIO (newIORef a_arg)
  b <- liftIO (newIORef b_arg)
  hret <- do
    arg0 <- do
      arg0 <- liftIO (readIORef a)
      arg1 <- liftIO (readIORef b)
      liftIO (andBool arg0 arg1)
    liftIO (notBool arg0)
  qreturn hret
  pure False

xor :: Bool -> Bool -> IO (Bool)
xor a_arg b_arg = evalContT $ callCC $ \qreturn -> do
  a <- liftIO (newIORef a_arg)
  b <- liftIO (newIORef b_arg)
  hret <- do
    arg0 <- do
      arg0 <- liftIO (readIORef a)
      arg1 <- do
        arg0 <- liftIO (readIORef a)
        arg1 <- liftIO (readIORef b)
        liftIO (nand arg0 arg1)
      liftIO (nand arg0 arg1)
    arg1 <- do
      arg0 <- liftIO (readIORef b)
      arg1 <- do
        arg0 <- liftIO (readIORef a)
        arg1 <- liftIO (readIORef b)
        liftIO (nand arg0 arg1)
      liftIO (nand arg0 arg1)
    liftIO (nand arg0 arg1)
  qreturn hret
  pure False

lessThan :: Int -> Int -> IO (Bool)
lessThan a_arg b_arg = evalContT $ callCC $ \qreturn -> do
  a <- liftIO (newIORef a_arg)
  b <- liftIO (newIORef b_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef a)
        arg1 <- liftIO (readIORef b)
        liftIO (equal arg0 arg1)
      liftIO (notBool arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef a)
        arg1 <- liftIO (readIORef b)
        liftIO (greaterthan arg0 arg1)
      liftIO (notBool arg0)
    liftIO (andBool arg0 arg1)
  qreturn hret
  pure False

parserValidateBodyForm :: Maybe Box -> String -> IO (())
parserValidateBodyForm bodyForm_arg filename_arg = evalContT $ callCC $ \qreturn -> do
  bodyForm <- liftIO (newIORef bodyForm_arg)
  filename <- liftIO (newIORef filename_arg)
  hcond <- do
    arg0 <- liftIO (readIORef bodyForm)
    liftIO (isNil arg0)
  if hcond
    then do
      _ <- do
        arg0 <- liftIO (readIORef filename)
        arg1 <- pure Nothing
        arg2 <- pure "empty body fragment"
        liftIO (parserPanicAt arg0 arg1 arg2)
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef bodyForm)
    liftIO (isList arg0)
  if hcond
    then do
      pure ()
    else do
      _ <- do
        arg0 <- liftIO (readIORef filename)
        arg1 <- liftIO (readIORef bodyForm)
        arg2 <- pure "body fragment must be a list"
        liftIO (parserPanicAtNode arg0 arg1 arg2)
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef bodyForm)
    arg1 <- pure "body"
    liftIO (parserListStartsWith arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- do
          arg0 <- liftIO (readIORef bodyForm)
          liftIO (cdr arg0)
        arg1 <- liftIO (readIORef filename)
        liftIO (parserValidateBody arg0 arg1)
      pure ()
    else do
      _ <- do
        arg0 <- liftIO (readIORef filename)
        arg1 <- liftIO (readIORef bodyForm)
        arg2 <- pure "expected body fragment"
        liftIO (parserPanicAtNode arg0 arg1 arg2)
      pure ()
  pure ()

readBodySexpr :: String -> String -> IO (Maybe Box)
readBodySexpr aStr_arg filename_arg = evalContT $ callCC $ \qreturn -> do
  aStr <- liftIO (newIORef aStr_arg)
  filename <- liftIO (newIORef filename_arg)
  qinit <- pure Nothing
  tokens <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  as <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  bodyForm <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef aStr)
    arg1 <- liftIO (readIORef filename)
    liftIO (readSingleSexpr arg0 arg1)
  liftIO (writeIORef bodyForm qset)
  _ <- do
    arg0 <- liftIO (readIORef bodyForm)
    arg1 <- liftIO (readIORef filename)
    liftIO (parserValidateBodyForm arg0 arg1)
  hret <- liftIO (readIORef bodyForm)
  qreturn hret
  pure Nothing

readSingleSexpr :: String -> String -> IO (Maybe Box)
readSingleSexpr aStr_arg filename_arg = evalContT $ callCC $ \qreturn -> do
  aStr <- liftIO (newIORef aStr_arg)
  filename <- liftIO (newIORef filename_arg)
  qinit <- pure Nothing
  tokens <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  as <- liftIO (newIORef qinit)
  qset <- liftIO emptyList
  liftIO (writeIORef tokens qset)
  qset <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef aStr)
        arg1 <- pure 0
        arg2 <- pure 1
        arg3 <- pure 0
        arg4 <- pure 0
        arg5 <- liftIO (readIORef filename)
        liftIO (scan arg0 arg1 arg2 arg3 arg4 arg5)
      liftIO (filterVoid arg0)
    liftIO (filterTokens arg0)
  liftIO (writeIORef tokens qset)
  _ <- do
    arg0 <- liftIO (readIORef tokens)
    arg1 <- pure Nothing
    arg2 <- liftIO (readIORef filename)
    liftIO (parserValidateParens arg0 arg1 arg2)
  qset <- do
    arg0 <- liftIO (readIORef tokens)
    liftIO (sexprTree arg0)
  liftIO (writeIORef as qset)
  _ <- do
    arg0 <- liftIO (readIORef as)
    arg1 <- liftIO (readIORef filename)
    liftIO (parserValidateRoot arg0 arg1)
  hret <- do
    arg0 <- liftIO (readIORef as)
    liftIO (car arg0)
  qreturn hret
  pure Nothing

readBodyFragment :: String -> String -> IO (Maybe Box)
readBodyFragment source_arg filename_arg = evalContT $ callCC $ \qreturn -> do
  source <- liftIO (newIORef source_arg)
  filename <- liftIO (newIORef filename_arg)
  qinit <- pure ""
  wrapped <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- pure "(body\n"
    arg1 <- do
      arg0 <- liftIO (readIORef source)
      arg1 <- pure "\n)"
      liftIO (stringConcatenate arg0 arg1)
    liftIO (stringConcatenate arg0 arg1)
  liftIO (writeIORef wrapped qset)
  hret <- do
    arg0 <- liftIO (readIORef wrapped)
    arg1 <- liftIO (readIORef filename)
    liftIO (readBodySexpr arg0 arg1)
  qreturn hret
  pure Nothing

readFunctionsSexpr :: String -> String -> IO (Maybe Box)
readFunctionsSexpr aStr_arg filename_arg = evalContT $ callCC $ \qreturn -> do
  aStr <- liftIO (newIORef aStr_arg)
  filename <- liftIO (newIORef filename_arg)
  qinit <- pure Nothing
  section <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef aStr)
    arg1 <- liftIO (readIORef filename)
    liftIO (readSingleSexpr arg0 arg1)
  liftIO (writeIORef section qset)
  _ <- do
    arg0 <- liftIO (readIORef section)
    arg1 <- pure "functions"
    arg2 <- liftIO (readIORef filename)
    liftIO (parserValidateSection arg0 arg1 arg2)
  _ <- do
    arg0 <- do
      arg0 <- liftIO (readIORef section)
      liftIO (cdr arg0)
    arg1 <- liftIO (readIORef filename)
    liftIO (parserValidateFunctions arg0 arg1)
  hret <- liftIO (readIORef section)
  qreturn hret
  pure Nothing

readFunctionsFragment :: String -> String -> IO (Maybe Box)
readFunctionsFragment source_arg filename_arg = evalContT $ callCC $ \qreturn -> do
  source <- liftIO (newIORef source_arg)
  filename <- liftIO (newIORef filename_arg)
  qinit <- pure ""
  wrapped <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- pure "(functions\n"
    arg1 <- do
      arg0 <- liftIO (readIORef source)
      arg1 <- pure "\n)"
      liftIO (stringConcatenate arg0 arg1)
    liftIO (stringConcatenate arg0 arg1)
  liftIO (writeIORef wrapped qset)
  hret <- do
    arg0 <- liftIO (readIORef wrapped)
    arg1 <- liftIO (readIORef filename)
    liftIO (readFunctionsSexpr arg0 arg1)
  qreturn hret
  pure Nothing

readTypesSexpr :: String -> String -> IO (Maybe Box)
readTypesSexpr aStr_arg filename_arg = evalContT $ callCC $ \qreturn -> do
  aStr <- liftIO (newIORef aStr_arg)
  filename <- liftIO (newIORef filename_arg)
  qinit <- pure Nothing
  section <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef aStr)
    arg1 <- liftIO (readIORef filename)
    liftIO (readSingleSexpr arg0 arg1)
  liftIO (writeIORef section qset)
  _ <- do
    arg0 <- liftIO (readIORef section)
    arg1 <- pure "types"
    arg2 <- liftIO (readIORef filename)
    liftIO (parserValidateSection arg0 arg1 arg2)
  _ <- do
    arg0 <- do
      arg0 <- liftIO (readIORef section)
      liftIO (cdr arg0)
    arg1 <- liftIO (readIORef filename)
    liftIO (parserRejectFunctionDefinitions arg0 arg1)
  hret <- liftIO (readIORef section)
  qreturn hret
  pure Nothing

readTypesFragment :: String -> String -> IO (Maybe Box)
readTypesFragment source_arg filename_arg = evalContT $ callCC $ \qreturn -> do
  source <- liftIO (newIORef source_arg)
  filename <- liftIO (newIORef filename_arg)
  qinit <- pure ""
  wrapped <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- pure "(types\n"
    arg1 <- do
      arg0 <- liftIO (readIORef source)
      arg1 <- pure "\n)"
      liftIO (stringConcatenate arg0 arg1)
    liftIO (stringConcatenate arg0 arg1)
  liftIO (writeIORef wrapped qset)
  hret <- do
    arg0 <- liftIO (readIORef wrapped)
    arg1 <- liftIO (readIORef filename)
    liftIO (readTypesSexpr arg0 arg1)
  qreturn hret
  pure Nothing

bodyTreeToString :: Maybe Box -> IO (String)
bodyTreeToString tree_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  hret <- do
    arg0 <- do
      arg0 <- liftIO (readIORef tree)
      liftIO (flatten arg0)
    arg1 <- pure 0
    arg2 <- pure True
    arg3 <- pure False
    liftIO (listToString arg0 arg1 arg2 arg3)
  qreturn hret
  pure ""

compileBodySectionString :: String -> String -> String -> IO (String)
compileBodySectionString source_arg filename_arg target_arg = evalContT $ callCC $ \qreturn -> do
  source <- liftIO (newIORef source_arg)
  filename <- liftIO (newIORef filename_arg)
  target <- liftIO (newIORef target_arg)
  qinit <- pure Nothing
  bodyForm <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef source)
    arg1 <- liftIO (readIORef filename)
    liftIO (readBodySexpr arg0 arg1)
  liftIO (writeIORef bodyForm qset)
  hret <- do
    arg0 <- liftIO (readIORef bodyForm)
    arg1 <- liftIO (readIORef target)
    liftIO (compileBodyForm arg0 arg1)
  qreturn hret
  pure ""

compileBodyString :: String -> String -> String -> IO (String)
compileBodyString source_arg filename_arg target_arg = evalContT $ callCC $ \qreturn -> do
  source <- liftIO (newIORef source_arg)
  filename <- liftIO (newIORef filename_arg)
  target <- liftIO (newIORef target_arg)
  qinit <- pure Nothing
  bodyForm <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef source)
    arg1 <- liftIO (readIORef filename)
    liftIO (readBodyFragment arg0 arg1)
  liftIO (writeIORef bodyForm qset)
  hret <- do
    arg0 <- liftIO (readIORef bodyForm)
    arg1 <- liftIO (readIORef target)
    liftIO (compileBodyForm arg0 arg1)
  qreturn hret
  pure ""

compileBodyForm :: Maybe Box -> String -> IO (String)
compileBodyForm bodyForm_arg target_arg = evalContT $ callCC $ \qreturn -> do
  bodyForm <- liftIO (newIORef bodyForm_arg)
  target <- liftIO (newIORef target_arg)
  qinit <- pure Nothing
  variables <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef target)
    arg1 <- pure "node2"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef bodyForm)
            liftIO (cdr arg0)
          arg1 <- pure 0
          arg2 <- pure "snippet"
          liftIO (node2Body arg0 arg1 arg2)
        liftIO (bodyTreeToString arg0)
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef target)
    arg1 <- pure "perl"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      qset <- liftIO getGlobalVariables
      liftIO (writeIORef variables qset)
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef bodyForm)
            liftIO (cdr arg0)
          arg1 <- pure 0
          arg2 <- liftIO (readIORef variables)
          liftIO (perlBody arg0 arg1 arg2)
        liftIO (bodyTreeToString arg0)
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef target)
    arg1 <- pure "java"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef bodyForm)
            liftIO (cdr arg0)
          arg1 <- pure 0
          liftIO (javaBody arg0 arg1)
        liftIO (bodyTreeToString arg0)
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef target)
    arg1 <- pure "haskell"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      qset <- liftIO haskellGlobalVariables
      liftIO (writeIORef variables qset)
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef bodyForm)
            liftIO (cdr arg0)
          arg1 <- pure 0
          arg2 <- liftIO (readIORef variables)
          liftIO (haskellBody arg0 arg1 arg2)
        liftIO (bodyTreeToString arg0)
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef target)
      arg1 <- pure "ansi3"
      liftIO (equalString arg0 arg1)
    arg1 <- do
      arg0 <- liftIO (readIORef target)
      arg1 <- pure "ansi3-release"
      liftIO (equalString arg0 arg1)
    liftIO (orBool arg0 arg1)
  if hcond
    then do
      qset <- pure True
      liftIO (writeIORef releaseMode qset)
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef bodyForm)
            liftIO (cdr arg0)
          arg1 <- pure 0
          arg2 <- pure "snippet"
          liftIO (ansi3Body arg0 arg1 arg2)
        liftIO (bodyTreeToString arg0)
      qreturn hret
      pure ()
    else do
      pure ()
  _ <- do
    arg0 <- do
      arg0 <- pure "unknown body target: "
      arg1 <- liftIO (readIORef target)
      liftIO (stringConcatenate arg0 arg1)
    liftIO (panic arg0)
  hret <- pure ""
  qreturn hret
  pure ""

compileFunctionsSectionString :: String -> String -> String -> IO (String)
compileFunctionsSectionString source_arg filename_arg target_arg = evalContT $ callCC $ \qreturn -> do
  source <- liftIO (newIORef source_arg)
  filename <- liftIO (newIORef filename_arg)
  target <- liftIO (newIORef target_arg)
  qinit <- pure Nothing
  section <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef source)
    arg1 <- liftIO (readIORef filename)
    liftIO (readFunctionsSexpr arg0 arg1)
  liftIO (writeIORef section qset)
  hret <- do
    arg0 <- liftIO (readIORef section)
    arg1 <- liftIO (readIORef target)
    liftIO (compileFunctionsSection arg0 arg1)
  qreturn hret
  pure ""

compileFunctionsString :: String -> String -> String -> IO (String)
compileFunctionsString source_arg filename_arg target_arg = evalContT $ callCC $ \qreturn -> do
  source <- liftIO (newIORef source_arg)
  filename <- liftIO (newIORef filename_arg)
  target <- liftIO (newIORef target_arg)
  qinit <- pure Nothing
  section <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef source)
    arg1 <- liftIO (readIORef filename)
    liftIO (readFunctionsFragment arg0 arg1)
  liftIO (writeIORef section qset)
  hret <- do
    arg0 <- liftIO (readIORef section)
    arg1 <- liftIO (readIORef target)
    liftIO (compileFunctionsSection arg0 arg1)
  qreturn hret
  pure ""

compileFunctionsSection :: Maybe Box -> String -> IO (String)
compileFunctionsSection section_arg target_arg = evalContT $ callCC $ \qreturn -> do
  section <- liftIO (newIORef section_arg)
  target <- liftIO (newIORef target_arg)
  hcond <- do
    arg0 <- liftIO (readIORef target)
    arg1 <- pure "node2"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef section)
            liftIO (cdr arg0)
          liftIO (node2Functions arg0)
        liftIO (bodyTreeToString arg0)
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef target)
    arg1 <- pure "perl"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef section)
            liftIO (cdr arg0)
          liftIO (perlFunctions arg0)
        liftIO (bodyTreeToString arg0)
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef target)
    arg1 <- pure "java"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef section)
            liftIO (cdr arg0)
          liftIO (javaFunctions arg0)
        liftIO (bodyTreeToString arg0)
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef target)
    arg1 <- pure "haskell"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef section)
            liftIO (cdr arg0)
          liftIO (haskellFunctions arg0)
        liftIO (bodyTreeToString arg0)
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef target)
      arg1 <- pure "ansi3"
      liftIO (equalString arg0 arg1)
    arg1 <- do
      arg0 <- liftIO (readIORef target)
      arg1 <- pure "ansi3-release"
      liftIO (equalString arg0 arg1)
    liftIO (orBool arg0 arg1)
  if hcond
    then do
      qset <- pure True
      liftIO (writeIORef releaseMode qset)
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef section)
            liftIO (cdr arg0)
          liftIO (ansi3Functions arg0)
        liftIO (bodyTreeToString arg0)
      qreturn hret
      pure ()
    else do
      pure ()
  _ <- do
    arg0 <- do
      arg0 <- pure "unknown functions target: "
      arg1 <- liftIO (readIORef target)
      liftIO (stringConcatenate arg0 arg1)
    liftIO (panic arg0)
  hret <- pure ""
  qreturn hret
  pure ""

compileTypesSectionString :: String -> String -> String -> IO (String)
compileTypesSectionString source_arg filename_arg target_arg = evalContT $ callCC $ \qreturn -> do
  source <- liftIO (newIORef source_arg)
  filename <- liftIO (newIORef filename_arg)
  target <- liftIO (newIORef target_arg)
  qinit <- pure Nothing
  section <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef source)
    arg1 <- liftIO (readIORef filename)
    liftIO (readTypesSexpr arg0 arg1)
  liftIO (writeIORef section qset)
  hret <- do
    arg0 <- liftIO (readIORef section)
    arg1 <- liftIO (readIORef target)
    liftIO (compileTypesSection arg0 arg1)
  qreturn hret
  pure ""

compileTypesString :: String -> String -> String -> IO (String)
compileTypesString source_arg filename_arg target_arg = evalContT $ callCC $ \qreturn -> do
  source <- liftIO (newIORef source_arg)
  filename <- liftIO (newIORef filename_arg)
  target <- liftIO (newIORef target_arg)
  qinit <- pure Nothing
  section <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef source)
    arg1 <- liftIO (readIORef filename)
    liftIO (readTypesFragment arg0 arg1)
  liftIO (writeIORef section qset)
  hret <- do
    arg0 <- liftIO (readIORef section)
    arg1 <- liftIO (readIORef target)
    liftIO (compileTypesSection arg0 arg1)
  qreturn hret
  pure ""

compileTypesSection :: Maybe Box -> String -> IO (String)
compileTypesSection section_arg target_arg = evalContT $ callCC $ \qreturn -> do
  section <- liftIO (newIORef section_arg)
  target <- liftIO (newIORef target_arg)
  hcond <- do
    arg0 <- liftIO (readIORef target)
    arg1 <- pure "node2"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef section)
            liftIO (cdr arg0)
          liftIO (node2Types arg0)
        liftIO (bodyTreeToString arg0)
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef target)
    arg1 <- pure "perl"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef section)
            liftIO (cdr arg0)
          liftIO (perlTypes arg0)
        liftIO (bodyTreeToString arg0)
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef target)
    arg1 <- pure "java"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef section)
            liftIO (cdr arg0)
          liftIO (javaTypes arg0)
        liftIO (bodyTreeToString arg0)
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef target)
    arg1 <- pure "haskell"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef section)
            liftIO (cdr arg0)
          liftIO (haskellTypes arg0)
        liftIO (bodyTreeToString arg0)
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef target)
      arg1 <- pure "ansi3"
      liftIO (equalString arg0 arg1)
    arg1 <- do
      arg0 <- liftIO (readIORef target)
      arg1 <- pure "ansi3-release"
      liftIO (equalString arg0 arg1)
    liftIO (orBool arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef section)
            liftIO (cdr arg0)
          liftIO (ansi3Types arg0)
        liftIO (bodyTreeToString arg0)
      qreturn hret
      pure ()
    else do
      pure ()
  _ <- do
    arg0 <- do
      arg0 <- pure "unknown types target: "
      arg1 <- liftIO (readIORef target)
      liftIO (stringConcatenate arg0 arg1)
    liftIO (panic arg0)
  hret <- pure ""
  qreturn hret
  pure ""

compileProgramBareString :: String -> String -> String -> IO (String)
compileProgramBareString source_arg filename_arg target_arg = evalContT $ callCC $ \qreturn -> do
  source <- liftIO (newIORef source_arg)
  filename <- liftIO (newIORef filename_arg)
  target <- liftIO (newIORef target_arg)
  qinit <- pure Nothing
  tree <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef source)
    arg1 <- liftIO (readIORef filename)
    liftIO (readSexpr arg0 arg1)
  liftIO (writeIORef tree qset)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (macrowalk arg0)
  liftIO (writeIORef tree qset)
  hcond <- do
    arg0 <- liftIO (readIORef target)
    arg1 <- pure "java"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      qset <- do
        arg0 <- liftIO (readIORef tree)
        arg1 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef tree)
            liftIO (getTypes arg0)
          liftIO (cdr arg0)
        liftIO (javaApplyTypeAliases arg0 arg1)
      liftIO (writeIORef tree qset)
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef target)
    arg1 <- pure "haskell"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      qset <- do
        arg0 <- liftIO (readIORef tree)
        arg1 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef tree)
            liftIO (getTypes arg0)
          liftIO (cdr arg0)
        liftIO (haskellApplyTypeAliases arg0 arg1)
      liftIO (writeIORef tree qset)
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef target)
    arg1 <- pure "node2"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (getTypes arg0)
              liftIO (node2Types arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef tree)
                  liftIO (getFunctions arg0)
                liftIO (node2Functions arg0)
              liftIO (qid arg0)
            arg1 <- pure Nothing
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (bodyTreeToString arg0)
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef target)
    arg1 <- pure "perl"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (getTypes arg0)
              liftIO (perlTypes arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef tree)
                  liftIO (getFunctions arg0)
                liftIO (perlFunctions arg0)
              liftIO (qid arg0)
            arg1 <- pure Nothing
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (bodyTreeToString arg0)
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef target)
    arg1 <- pure "java"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (getTypes arg0)
              liftIO (javaTypes arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef tree)
                  liftIO (getFunctions arg0)
                liftIO (javaFunctions arg0)
              liftIO (qid arg0)
            arg1 <- pure Nothing
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (bodyTreeToString arg0)
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef target)
    arg1 <- pure "haskell"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (getTypes arg0)
              liftIO (haskellTypes arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef tree)
                  liftIO (getFunctions arg0)
                liftIO (haskellFunctions arg0)
              liftIO (qid arg0)
            arg1 <- pure Nothing
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (bodyTreeToString arg0)
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef target)
      arg1 <- pure "ansi3"
      liftIO (equalString arg0 arg1)
    arg1 <- do
      arg0 <- liftIO (readIORef target)
      arg1 <- pure "ansi3-release"
      liftIO (equalString arg0 arg1)
    liftIO (orBool arg0 arg1)
  if hcond
    then do
      qset <- pure True
      liftIO (writeIORef releaseMode qset)
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (getTypes arg0)
              liftIO (ansi3Types arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef tree)
                  liftIO (getFunctions arg0)
                liftIO (ansi3Functions arg0)
              liftIO (qid arg0)
            arg1 <- pure Nothing
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (bodyTreeToString arg0)
      qreturn hret
      pure ()
    else do
      pure ()
  _ <- do
    arg0 <- do
      arg0 <- pure "unknown program target: "
      arg1 <- liftIO (readIORef target)
      liftIO (stringConcatenate arg0 arg1)
    liftIO (panic arg0)
  hret <- pure ""
  qreturn hret
  pure ""

node2FunctionArgs :: Maybe Box -> IO (Maybe Box)
node2FunctionArgs tree_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  hcond <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef tree)
            liftIO (first arg0)
          liftIO (stringify arg0)
        arg1 <- pure "..."
        liftIO (equalString arg0 arg1)
      if hcond
        then do
          hcond <- do
            arg0 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (cddr arg0)
            liftIO (isNil arg0)
          if hcond
            then do
              hret <- do
                arg0 <- do
                  arg0 <- pure "..."
                  liftIO (boxString arg0)
                arg1 <- pure Nothing
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
            else do
              hret <- do
                arg0 <- do
                  arg0 <- pure "..."
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure ", "
                    liftIO (boxString arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef tree)
                          liftIO (cddr arg0)
                        liftIO (node2FunctionArgs arg0)
                      liftIO (qid arg0)
                    arg1 <- pure Nothing
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
          pure ()
        else do
          hcond <- do
            arg0 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (cddr arg0)
            liftIO (isNil arg0)
          if hcond
            then do
              hret <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef tree)
                      liftIO (second arg0)
                    liftIO (node2FuncMap arg0)
                  liftIO (qid arg0)
                arg1 <- pure Nothing
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
            else do
              hret <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef tree)
                      liftIO (second arg0)
                    liftIO (node2FuncMap arg0)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure ", "
                    liftIO (boxString arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef tree)
                          liftIO (cddr arg0)
                        liftIO (node2FunctionArgs arg0)
                      liftIO (qid arg0)
                    arg1 <- pure Nothing
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
          pure ()
      pure ()
  pure Nothing

node2Atom :: Maybe Box -> IO (Maybe Box)
node2Atom tree_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  hcond <- do
    arg0 <- pure "string"
    arg1 <- do
      arg0 <- liftIO (readIORef tree)
      liftIO (boxType arg0)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- pure "\""
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (stringify arg0)
              liftIO (boxString arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure "\""
              liftIO (boxString arg0)
            arg1 <- pure Nothing
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef tree)
            liftIO (node2FuncMap arg0)
          liftIO (qid arg0)
        arg1 <- pure Nothing
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

node2Expression :: Maybe Box -> Int -> IO (Maybe Box)
node2Expression tree_arg indent_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  indent <- liftIO (newIORef indent_arg)
  qinit <- pure Nothing
  thing <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef tree)
      liftIO (isList arg0)
    liftIO (notBool arg0)
  if hcond
    then do
      hret <- do
        arg0 <- liftIO (readIORef tree)
        liftIO (node2Atom arg0)
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- pure 1
        arg1 <- do
          arg0 <- liftIO (readIORef tree)
          liftIO (listLength arg0)
        liftIO (equal arg0 arg1)
      if hcond
        then do
          hcond <- do
            arg0 <- do
              arg0 <- pure "return"
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (car arg0)
            liftIO (equalBox arg0 arg1)
          if hcond
            then do
              hret <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef tree)
                      liftIO (car arg0)
                    liftIO (node2FuncMap arg0)
                  liftIO (qid arg0)
                arg1 <- pure Nothing
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
            else do
              hret <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef tree)
                      liftIO (car arg0)
                    liftIO (node2FuncMap arg0)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure "()"
                    liftIO (boxString arg0)
                  arg1 <- pure Nothing
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
          pure ()
        else do
          qset <- do
            arg0 <- liftIO (readIORef tree)
            liftIO (first arg0)
          liftIO (writeIORef thing qset)
          hcond <- do
            arg0 <- do
              arg0 <- pure "get-struct"
              liftIO (boxSymbol arg0)
            arg1 <- liftIO (readIORef thing)
            liftIO (equalBox arg0 arg1)
          if hcond
            then do
              hret <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef tree)
                      liftIO (second arg0)
                    arg1 <- liftIO (readIORef indent)
                    liftIO (node2Expression arg0 arg1)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure "."
                    liftIO (boxString arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef tree)
                        liftIO (third arg0)
                      liftIO (qid arg0)
                    arg1 <- pure Nothing
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
            else do
              hcond <- do
                arg0 <- do
                  arg0 <- pure "new"
                  liftIO (boxSymbol arg0)
                arg1 <- liftIO (readIORef thing)
                liftIO (equalBox arg0 arg1)
              if hcond
                then do
                  hret <- do
                    arg0 <- do
                      arg0 <- pure "{}"
                      liftIO (boxString arg0)
                    arg1 <- pure Nothing
                    liftIO (cons arg0 arg1)
                  qreturn hret
                  pure ()
                else do
                  hcond <- do
                    arg0 <- do
                      arg0 <- pure "passthrough"
                      liftIO (boxSymbol arg0)
                    arg1 <- liftIO (readIORef thing)
                    liftIO (equalBox arg0 arg1)
                  if hcond
                    then do
                      hret <- do
                        arg0 <- do
                          arg0 <- do
                            arg0 <- liftIO (readIORef tree)
                            liftIO (second arg0)
                          liftIO (qid arg0)
                        arg1 <- pure Nothing
                        liftIO (cons arg0 arg1)
                      qreturn hret
                      pure ()
                    else do
                      hcond <- do
                        arg0 <- do
                          arg0 <- pure "binop"
                          liftIO (boxSymbol arg0)
                        arg1 <- liftIO (readIORef thing)
                        liftIO (equalBox arg0 arg1)
                      if hcond
                        then do
                          hret <- do
                            arg0 <- do
                              arg0 <- pure "("
                              liftIO (boxString arg0)
                            arg1 <- do
                              arg0 <- do
                                arg0 <- do
                                  arg0 <- do
                                    arg0 <- liftIO (readIORef tree)
                                    liftIO (third arg0)
                                  arg1 <- liftIO (readIORef indent)
                                  liftIO (node2Expression arg0 arg1)
                                liftIO (qid arg0)
                              arg1 <- do
                                arg0 <- do
                                  arg0 <- pure " "
                                  liftIO (boxString arg0)
                                arg1 <- do
                                  arg0 <- do
                                    arg0 <- do
                                      arg0 <- liftIO (readIORef tree)
                                      liftIO (second arg0)
                                    liftIO (qid arg0)
                                  arg1 <- do
                                    arg0 <- do
                                      arg0 <- pure " "
                                      liftIO (boxString arg0)
                                    arg1 <- do
                                      arg0 <- do
                                        arg0 <- do
                                          arg0 <- do
                                            arg0 <- liftIO (readIORef tree)
                                            liftIO (fourth arg0)
                                          arg1 <- liftIO (readIORef indent)
                                          liftIO (node2Expression arg0 arg1)
                                        liftIO (qid arg0)
                                      arg1 <- do
                                        arg0 <- do
                                          arg0 <- pure ")"
                                          liftIO (boxString arg0)
                                        arg1 <- pure Nothing
                                        liftIO (cons arg0 arg1)
                                      liftIO (cons arg0 arg1)
                                    liftIO (cons arg0 arg1)
                                  liftIO (cons arg0 arg1)
                                liftIO (cons arg0 arg1)
                              liftIO (cons arg0 arg1)
                            liftIO (cons arg0 arg1)
                          qreturn hret
                          pure ()
                        else do
                          hret <- do
                            arg0 <- do
                              arg0 <- do
                                arg0 <- do
                                  arg0 <- liftIO (readIORef tree)
                                  liftIO (car arg0)
                                liftIO (node2FuncMap arg0)
                              liftIO (qid arg0)
                            arg1 <- do
                              arg0 <- do
                                arg0 <- pure "("
                                liftIO (boxString arg0)
                              arg1 <- do
                                arg0 <- do
                                  arg0 <- do
                                    arg0 <- do
                                      arg0 <- liftIO (readIORef tree)
                                      liftIO (cdr arg0)
                                    arg1 <- liftIO (readIORef indent)
                                    liftIO (node2RecurList arg0 arg1)
                                  liftIO (qid arg0)
                                arg1 <- do
                                  arg0 <- do
                                    arg0 <- pure ")"
                                    liftIO (boxString arg0)
                                  arg1 <- pure Nothing
                                  liftIO (cons arg0 arg1)
                                liftIO (cons arg0 arg1)
                              liftIO (cons arg0 arg1)
                            liftIO (cons arg0 arg1)
                          qreturn hret
                          pure ()
                      pure ()
                  pure ()
              pure ()
          pure ()
      pure ()
  pure Nothing

node2RecurList :: Maybe Box -> Int -> IO (Maybe Box)
node2RecurList expr_arg indent_arg = evalContT $ callCC $ \qreturn -> do
  expr <- liftIO (newIORef expr_arg)
  indent <- liftIO (newIORef indent_arg)
  hcond <- do
    arg0 <- liftIO (readIORef expr)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- do
          arg0 <- liftIO (readIORef expr)
          liftIO (cdr arg0)
        liftIO (isNil arg0)
      if hcond
        then do
          hret <- do
            arg0 <- do
              arg0 <- liftIO (readIORef expr)
              liftIO (car arg0)
            arg1 <- liftIO (readIORef indent)
            liftIO (node2Expression arg0 arg1)
          qreturn hret
          pure ()
        else do
          hret <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef expr)
                  liftIO (car arg0)
                arg1 <- liftIO (readIORef indent)
                liftIO (node2Expression arg0 arg1)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure ", "
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef expr)
                      liftIO (cdr arg0)
                    arg1 <- liftIO (readIORef indent)
                    liftIO (node2RecurList arg0 arg1)
                  liftIO (qid arg0)
                arg1 <- pure Nothing
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          qreturn hret
          pure ()
      pure ()
  pure Nothing

node2If :: Maybe Box -> Int -> String -> IO (Maybe Box)
node2If node_arg indent_arg functionName_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  indent <- liftIO (newIORef indent_arg)
  functionName <- liftIO (newIORef functionName_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef indent)
        liftIO (listNewLine arg0)
      liftIO (qid arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "if ("
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef node)
              liftIO (second arg0)
            arg1 <- pure 0
            liftIO (node2Expression arg0 arg1)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure ") {"
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef node)
                    liftIO (third arg0)
                  liftIO (cdr arg0)
                arg1 <- do
                  arg0 <- liftIO (readIORef indent)
                  liftIO (add1 arg0)
                arg2 <- liftIO (readIORef functionName)
                liftIO (node2Body arg0 arg1 arg2)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef indent)
                  liftIO (listNewLine arg0)
                liftIO (qid arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure "} else {"
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef node)
                          liftIO (fourth arg0)
                        liftIO (cdr arg0)
                      arg1 <- do
                        arg0 <- liftIO (readIORef indent)
                        liftIO (add1 arg0)
                      arg2 <- liftIO (readIORef functionName)
                      liftIO (node2Body arg0 arg1 arg2)
                    liftIO (qid arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef indent)
                        liftIO (listNewLine arg0)
                      liftIO (qid arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- pure "}"
                        liftIO (boxString arg0)
                      arg1 <- pure Nothing
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

node2SetStruct :: Maybe Box -> Int -> IO (Maybe Box)
node2SetStruct node_arg indent_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  indent <- liftIO (newIORef indent_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef indent)
        liftIO (listNewLine arg0)
      liftIO (qid arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef node)
            liftIO (second arg0)
          arg1 <- liftIO (readIORef indent)
          liftIO (node2Expression arg0 arg1)
        liftIO (qid arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure "."
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef node)
              liftIO (third arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure " = "
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef node)
                    liftIO (fourth arg0)
                  arg1 <- liftIO (readIORef indent)
                  liftIO (node2Expression arg0 arg1)
                liftIO (qid arg0)
              arg1 <- pure Nothing
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

node2Set :: Maybe Box -> Int -> IO (Maybe Box)
node2Set node_arg indent_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  indent <- liftIO (newIORef indent_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef indent)
        liftIO (listNewLine arg0)
      liftIO (qid arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef node)
            liftIO (second arg0)
          arg1 <- liftIO (readIORef indent)
          liftIO (node2Expression arg0 arg1)
        liftIO (qid arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure " = "
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef node)
                liftIO (third arg0)
              arg1 <- liftIO (readIORef indent)
              liftIO (node2Expression arg0 arg1)
            liftIO (qid arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

node2Return :: Maybe Box -> Int -> IO (Maybe Box)
node2Return node_arg indent_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  indent <- liftIO (newIORef indent_arg)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef node)
      liftIO (listLength arg0)
    arg1 <- pure 1
    liftIO (equal arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef indent)
            liftIO (listNewLine arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "return"
            liftIO (boxString arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef indent)
            liftIO (listNewLine arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "return "
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef node)
                  liftIO (cadr arg0)
                arg1 <- liftIO (readIORef indent)
                liftIO (node2Expression arg0 arg1)
              liftIO (qid arg0)
            arg1 <- pure Nothing
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

node2Statement :: Maybe Box -> Int -> String -> IO (Maybe Box)
node2Statement node_arg indent_arg functionName_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  indent <- liftIO (newIORef indent_arg)
  functionName <- liftIO (newIORef functionName_arg)
  hcond <- do
    arg0 <- do
      arg0 <- pure "set"
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- liftIO (readIORef node)
      liftIO (first arg0)
    liftIO (equalBox arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef node)
            arg1 <- liftIO (readIORef indent)
            liftIO (node2Set arg0 arg1)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure ";\n"
            liftIO (boxString arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- do
          arg0 <- pure "set-struct"
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- liftIO (readIORef node)
          liftIO (first arg0)
        liftIO (equalBox arg0 arg1)
      if hcond
        then do
          hret <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef node)
                arg1 <- liftIO (readIORef indent)
                liftIO (node2SetStruct arg0 arg1)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure ";\n"
                liftIO (boxString arg0)
              arg1 <- pure Nothing
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          qreturn hret
          pure ()
        else do
          hcond <- do
            arg0 <- do
              arg0 <- pure "if"
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- liftIO (readIORef node)
              liftIO (first arg0)
            liftIO (equalBox arg0 arg1)
          if hcond
            then do
              hret <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef node)
                    arg1 <- liftIO (readIORef indent)
                    arg2 <- liftIO (readIORef functionName)
                    liftIO (node2If arg0 arg1 arg2)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure ";\n"
                    liftIO (boxString arg0)
                  arg1 <- pure Nothing
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
            else do
              hcond <- do
                arg0 <- do
                  arg0 <- pure "return"
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- liftIO (readIORef node)
                  liftIO (first arg0)
                liftIO (equalBox arg0 arg1)
              if hcond
                then do
                  hret <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef node)
                        arg1 <- liftIO (readIORef indent)
                        liftIO (node2Return arg0 arg1)
                      liftIO (qid arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- pure ";\n"
                        liftIO (boxString arg0)
                      arg1 <- pure Nothing
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  qreturn hret
                  pure ()
                else do
                  hret <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef indent)
                        liftIO (listNewLine arg0)
                      liftIO (qid arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef node)
                          arg1 <- liftIO (readIORef indent)
                          liftIO (node2Expression arg0 arg1)
                        liftIO (qid arg0)
                      arg1 <- do
                        arg0 <- do
                          arg0 <- pure ";\n"
                          liftIO (boxString arg0)
                        arg1 <- pure Nothing
                        liftIO (cons arg0 arg1)
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  qreturn hret
                  pure ()
              pure ()
          pure ()
      pure ()
  pure Nothing

node2Body :: Maybe Box -> Int -> String -> IO (Maybe Box)
node2Body tree_arg indent_arg functionName_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  indent <- liftIO (newIORef indent_arg)
  functionName <- liftIO (newIORef functionName_arg)
  qinit <- pure Nothing
  code <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      qset <- do
        arg0 <- liftIO (readIORef tree)
        liftIO (car arg0)
      liftIO (writeIORef code qset)
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef code)
            arg1 <- liftIO (readIORef indent)
            arg2 <- liftIO (readIORef functionName)
            liftIO (node2Statement arg0 arg1 arg2)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (cdr arg0)
              arg1 <- liftIO (readIORef indent)
              arg2 <- liftIO (readIORef functionName)
              liftIO (node2Body arg0 arg1 arg2)
            liftIO (qid arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

node2Declarations :: Maybe Box -> Int -> IO (Maybe Box)
node2Declarations decls_arg indent_arg = evalContT $ callCC $ \qreturn -> do
  decls <- liftIO (newIORef decls_arg)
  indent <- liftIO (newIORef indent_arg)
  qinit <- pure Nothing
  decl <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef decls)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      qset <- do
        arg0 <- liftIO (readIORef decls)
        liftIO (car arg0)
      liftIO (writeIORef decl qset)
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef indent)
              liftIO (stringIndent arg0)
            liftIO (boxString arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "let "
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef decl)
                  liftIO (second arg0)
                liftIO (node2FuncMap arg0)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure " = "
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef decl)
                      liftIO (third arg0)
                    arg1 <- liftIO (readIORef indent)
                    liftIO (node2Expression arg0 arg1)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure ";\n"
                    liftIO (boxString arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef decls)
                          liftIO (cdr arg0)
                        arg1 <- liftIO (readIORef indent)
                        liftIO (node2Declarations arg0 arg1)
                      liftIO (qid arg0)
                    arg1 <- pure Nothing
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

node2Function :: Maybe Box -> IO (Maybe Box)
node2Function node_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  qinit <- pure Nothing
  name <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef node)
    liftIO (second arg0)
  liftIO (writeIORef name qset)
  hcond <- do
    arg0 <- liftIO (readIORef node)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- pure 0
            liftIO (listNewLine arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- pure 0
              liftIO (listNewLine arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure "function "
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef node)
                    liftIO (second arg0)
                  liftIO (node2FuncMap arg0)
                liftIO (qid arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure "("
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef node)
                        liftIO (third arg0)
                      liftIO (node2FunctionArgs arg0)
                    liftIO (qid arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- pure ") {"
                      liftIO (boxString arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- pure 1
                          liftIO (listNewLine arg0)
                        liftIO (qid arg0)
                      arg1 <- do
                        arg0 <- do
                          arg0 <- do
                            arg0 <- do
                              arg0 <- do
                                arg0 <- liftIO (readIORef node)
                                liftIO (fourth arg0)
                              liftIO (cdr arg0)
                            arg1 <- pure 1
                            liftIO (node2Declarations arg0 arg1)
                          liftIO (qid arg0)
                        arg1 <- do
                          arg0 <- do
                            arg0 <- do
                              arg0 <- do
                                arg0 <- do
                                  arg0 <- liftIO (readIORef node)
                                  liftIO (fifth arg0)
                                liftIO (cdr arg0)
                              arg1 <- pure 1
                              arg2 <- do
                                arg0 <- liftIO (readIORef name)
                                liftIO (stringify arg0)
                              liftIO (node2Body arg0 arg1 arg2)
                            liftIO (qid arg0)
                          arg1 <- do
                            arg0 <- do
                              arg0 <- pure "\n}\n"
                              liftIO (boxString arg0)
                            arg1 <- pure Nothing
                            liftIO (cons arg0 arg1)
                          liftIO (cons arg0 arg1)
                        liftIO (cons arg0 arg1)
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

node2Functions :: Maybe Box -> IO (Maybe Box)
node2Functions tree_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  hcond <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (car arg0)
            liftIO (node2Function arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (cdr arg0)
              liftIO (node2Functions arg0)
            liftIO (qid arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

node2Includes :: Maybe Box -> IO (Maybe Box)
node2Includes nodes_arg = evalContT $ callCC $ \qreturn -> do
  nodes <- liftIO (newIORef nodes_arg)
  hret <- do
    arg0 <- do
      arg0 <- pure "\"use strict\";\n"
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "const fs = (typeof require === \"function\") ? require(\"fs\") : null;\n"
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure "let globalArgsCount = 0;\n"
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "let globalArgs = [];\n"
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure "let releaseMode = false;\n"
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure "let globalTrace = false;\n"
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure "let globalStepTrace = false;\n"
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure "let globalStackTrace = null;\n"
                    liftIO (boxString arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- pure "let caller = \"\";\n"
                      liftIO (boxString arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- pure "let quonIO = makeDefaultQuonIO();\n"
                        liftIO (boxString arg0)
                      arg1 <- do
                        arg0 <- do
                          arg0 <- pure "let stderr = { write: function(s) { quonIO.error(String(s)); } };\n"
                          liftIO (boxString arg0)
                        arg1 <- do
                          arg0 <- do
                            arg0 <- pure "function makeDefaultQuonIO() {\n"
                            liftIO (boxString arg0)
                          arg1 <- do
                            arg0 <- do
                              arg0 <- pure "  return {\n"
                              liftIO (boxString arg0)
                            arg1 <- do
                              arg0 <- do
                                arg0 <- pure "    write: function(s) {\n"
                                liftIO (boxString arg0)
                              arg1 <- do
                                arg0 <- do
                                  arg0 <- pure "      if (typeof process !== \"undefined\" && process.stdout) process.stdout.write(String(s));\n"
                                  liftIO (boxString arg0)
                                arg1 <- do
                                  arg0 <- do
                                    arg0 <- pure "    },\n"
                                    liftIO (boxString arg0)
                                  arg1 <- do
                                    arg0 <- do
                                      arg0 <- pure "    error: function(s) {\n"
                                      liftIO (boxString arg0)
                                    arg1 <- do
                                      arg0 <- do
                                        arg0 <- pure "      if (typeof process !== \"undefined\" && process.stderr) process.stderr.write(String(s));\n"
                                        liftIO (boxString arg0)
                                      arg1 <- do
                                        arg0 <- do
                                          arg0 <- pure "      else if (typeof console !== \"undefined\" && console.error) console.error(String(s));\n"
                                          liftIO (boxString arg0)
                                        arg1 <- do
                                          arg0 <- do
                                            arg0 <- pure "    },\n"
                                            liftIO (boxString arg0)
                                          arg1 <- do
                                            arg0 <- do
                                              arg0 <- pure "    readFile: null,\n"
                                              liftIO (boxString arg0)
                                            arg1 <- do
                                              arg0 <- do
                                                arg0 <- pure "    writeFile: null,\n"
                                                liftIO (boxString arg0)
                                              arg1 <- do
                                                arg0 <- do
                                                  arg0 <- pure "    exit: null,\n"
                                                  liftIO (boxString arg0)
                                                arg1 <- do
                                                  arg0 <- do
                                                    arg0 <- pure "    env: (typeof process !== \"undefined\" && process.env) ? process.env : {}\n"
                                                    liftIO (boxString arg0)
                                                  arg1 <- do
                                                    arg0 <- do
                                                      arg0 <- pure "  };\n"
                                                      liftIO (boxString arg0)
                                                    arg1 <- do
                                                      arg0 <- do
                                                        arg0 <- pure "}\n"
                                                        liftIO (boxString arg0)
                                                      arg1 <- do
                                                        arg0 <- do
                                                          arg0 <- pure "function configureQuonIO(io) {\n"
                                                          liftIO (boxString arg0)
                                                        arg1 <- do
                                                          arg0 <- do
                                                            arg0 <- pure "  const defaults = makeDefaultQuonIO();\n"
                                                            liftIO (boxString arg0)
                                                          arg1 <- do
                                                            arg0 <- do
                                                              arg0 <- pure "  quonIO = Object.assign(defaults, io || {});\n"
                                                              liftIO (boxString arg0)
                                                            arg1 <- do
                                                              arg0 <- do
                                                                arg0 <- pure "  if (!quonIO.error) quonIO.error = defaults.error;\n"
                                                                liftIO (boxString arg0)
                                                              arg1 <- do
                                                                arg0 <- do
                                                                  arg0 <- pure "  if (!quonIO.write) quonIO.write = defaults.write;\n"
                                                                  liftIO (boxString arg0)
                                                                arg1 <- do
                                                                  arg0 <- do
                                                                    arg0 <- pure "  return quonIO;\n"
                                                                    liftIO (boxString arg0)
                                                                  arg1 <- do
                                                                    arg0 <- do
                                                                      arg0 <- pure "}\n"
                                                                      liftIO (boxString arg0)
                                                                    arg1 <- do
                                                                      arg0 <- do
                                                                        arg0 <- pure "function qreadFile(filename) {\n"
                                                                        liftIO (boxString arg0)
                                                                      arg1 <- do
                                                                        arg0 <- do
                                                                          arg0 <- pure "  if (quonIO.readFile) {\n"
                                                                          liftIO (boxString arg0)
                                                                        arg1 <- do
                                                                          arg0 <- do
                                                                            arg0 <- pure "    const data = quonIO.readFile(filename);\n"
                                                                            liftIO (boxString arg0)
                                                                          arg1 <- do
                                                                            arg0 <- do
                                                                              arg0 <- pure "    if (data === null || data === undefined) return null;\n"
                                                                              liftIO (boxString arg0)
                                                                            arg1 <- do
                                                                              arg0 <- do
                                                                                arg0 <- pure "    return boxString(String(data));\n"
                                                                                liftIO (boxString arg0)
                                                                              arg1 <- do
                                                                                arg0 <- do
                                                                                  arg0 <- pure "  }\n"
                                                                                  liftIO (boxString arg0)
                                                                                arg1 <- do
                                                                                  arg0 <- do
                                                                                    arg0 <- pure "  if (fs) {\n"
                                                                                    liftIO (boxString arg0)
                                                                                  arg1 <- do
                                                                                    arg0 <- do
                                                                                      arg0 <- pure "    try { return boxString(fs.readFileSync(filename, \"utf8\")); } catch (e) { return null; }\n"
                                                                                      liftIO (boxString arg0)
                                                                                    arg1 <- do
                                                                                      arg0 <- do
                                                                                        arg0 <- pure "  }\n"
                                                                                        liftIO (boxString arg0)
                                                                                      arg1 <- do
                                                                                        arg0 <- do
                                                                                          arg0 <- pure "  return null;\n"
                                                                                          liftIO (boxString arg0)
                                                                                        arg1 <- do
                                                                                          arg0 <- do
                                                                                            arg0 <- pure "}\n"
                                                                                            liftIO (boxString arg0)
                                                                                          arg1 <- do
                                                                                            arg0 <- do
                                                                                              arg0 <- pure "function qwriteFile(filename, data) {\n"
                                                                                              liftIO (boxString arg0)
                                                                                            arg1 <- do
                                                                                              arg0 <- do
                                                                                                arg0 <- pure "  if (quonIO.writeFile) return quonIO.writeFile(filename, data);\n"
                                                                                                liftIO (boxString arg0)
                                                                                              arg1 <- do
                                                                                                arg0 <- do
                                                                                                  arg0 <- pure "  if (fs) return fs.writeFileSync(filename, data);\n"
                                                                                                  liftIO (boxString arg0)
                                                                                                arg1 <- do
                                                                                                  arg0 <- do
                                                                                                    arg0 <- pure "  throw new Error(\"write-file is not available in this environment\");\n"
                                                                                                    liftIO (boxString arg0)
                                                                                                  arg1 <- do
                                                                                                    arg0 <- do
                                                                                                      arg0 <- pure "}\n"
                                                                                                      liftIO (boxString arg0)
                                                                                                    arg1 <- do
                                                                                                      arg0 <- do
                                                                                                        arg0 <- pure "function qexit(status) {\n"
                                                                                                        liftIO (boxString arg0)
                                                                                                      arg1 <- do
                                                                                                        arg0 <- do
                                                                                                          arg0 <- pure "  if (quonIO.exit) return quonIO.exit(status);\n"
                                                                                                          liftIO (boxString arg0)
                                                                                                        arg1 <- do
                                                                                                          arg0 <- do
                                                                                                            arg0 <- pure "  if (typeof process !== \"undefined\" && process.exit) return process.exit(status);\n"
                                                                                                            liftIO (boxString arg0)
                                                                                                          arg1 <- do
                                                                                                            arg0 <- do
                                                                                                              arg0 <- pure "  throw new Error(\"Quon exit \" + status);\n"
                                                                                                              liftIO (boxString arg0)
                                                                                                            arg1 <- do
                                                                                                              arg0 <- do
                                                                                                                arg0 <- pure "}\n"
                                                                                                                liftIO (boxString arg0)
                                                                                                              arg1 <- do
                                                                                                                arg0 <- do
                                                                                                                  arg0 <- pure "function cformat(fmt, ...args) {\n"
                                                                                                                  liftIO (boxString arg0)
                                                                                                                arg1 <- do
                                                                                                                  arg0 <- do
                                                                                                                    arg0 <- pure "  fmt = String(fmt);\n"
                                                                                                                    liftIO (boxString arg0)
                                                                                                                  arg1 <- do
                                                                                                                    arg0 <- do
                                                                                                                      arg0 <- pure "  let out = '';\n"
                                                                                                                      liftIO (boxString arg0)
                                                                                                                    arg1 <- do
                                                                                                                      arg0 <- do
                                                                                                                        arg0 <- pure "  let argi = 0;\n"
                                                                                                                        liftIO (boxString arg0)
                                                                                                                      arg1 <- do
                                                                                                                        arg0 <- do
                                                                                                                          arg0 <- pure "  for (let pos = 0; pos < fmt.length; pos++) {\n"
                                                                                                                          liftIO (boxString arg0)
                                                                                                                        arg1 <- do
                                                                                                                          arg0 <- do
                                                                                                                            arg0 <- pure "    let ch = fmt[pos];\n"
                                                                                                                            liftIO (boxString arg0)
                                                                                                                          arg1 <- do
                                                                                                                            arg0 <- do
                                                                                                                              arg0 <- pure "    if (ch !== '%') { out += ch; continue; }\n"
                                                                                                                              liftIO (boxString arg0)
                                                                                                                            arg1 <- do
                                                                                                                              arg0 <- do
                                                                                                                                arg0 <- pure "    if (fmt[pos + 1] === '%') { out += '%'; pos++; continue; }\n"
                                                                                                                                liftIO (boxString arg0)
                                                                                                                              arg1 <- do
                                                                                                                                arg0 <- do
                                                                                                                                  arg0 <- pure "    let precision = null;\n"
                                                                                                                                  liftIO (boxString arg0)
                                                                                                                                arg1 <- do
                                                                                                                                  arg0 <- do
                                                                                                                                    arg0 <- pure "    if (fmt[pos + 1] === '.') {\n"
                                                                                                                                    liftIO (boxString arg0)
                                                                                                                                  arg1 <- do
                                                                                                                                    arg0 <- do
                                                                                                                                      arg0 <- pure "      let end = pos + 2;\n"
                                                                                                                                      liftIO (boxString arg0)
                                                                                                                                    arg1 <- do
                                                                                                                                      arg0 <- do
                                                                                                                                        arg0 <- pure "      while (end < fmt.length && fmt[end] >= '0' && fmt[end] <= '9') end++;\n"
                                                                                                                                        liftIO (boxString arg0)
                                                                                                                                      arg1 <- do
                                                                                                                                        arg0 <- do
                                                                                                                                          arg0 <- pure "      precision = Number(fmt.slice(pos + 2, end));\n"
                                                                                                                                          liftIO (boxString arg0)
                                                                                                                                        arg1 <- do
                                                                                                                                          arg0 <- do
                                                                                                                                            arg0 <- pure "      pos = end - 1;\n"
                                                                                                                                            liftIO (boxString arg0)
                                                                                                                                          arg1 <- do
                                                                                                                                            arg0 <- do
                                                                                                                                              arg0 <- pure "    }\n"
                                                                                                                                              liftIO (boxString arg0)
                                                                                                                                            arg1 <- do
                                                                                                                                              arg0 <- do
                                                                                                                                                arg0 <- pure "    let spec = fmt[pos + 1];\n"
                                                                                                                                                liftIO (boxString arg0)
                                                                                                                                              arg1 <- do
                                                                                                                                                arg0 <- do
                                                                                                                                                  arg0 <- pure "    if (spec === 's' || spec === 'd') {\n"
                                                                                                                                                  liftIO (boxString arg0)
                                                                                                                                                arg1 <- do
                                                                                                                                                  arg0 <- do
                                                                                                                                                    arg0 <- pure "      let value = String(args[argi++]);\n"
                                                                                                                                                    liftIO (boxString arg0)
                                                                                                                                                  arg1 <- do
                                                                                                                                                    arg0 <- do
                                                                                                                                                      arg0 <- pure "      if (precision !== null) value = value.slice(0, precision);\n"
                                                                                                                                                      liftIO (boxString arg0)
                                                                                                                                                    arg1 <- do
                                                                                                                                                      arg0 <- do
                                                                                                                                                        arg0 <- pure "      out += value;\n"
                                                                                                                                                        liftIO (boxString arg0)
                                                                                                                                                      arg1 <- do
                                                                                                                                                        arg0 <- do
                                                                                                                                                          arg0 <- pure "      pos++;\n"
                                                                                                                                                          liftIO (boxString arg0)
                                                                                                                                                        arg1 <- do
                                                                                                                                                          arg0 <- do
                                                                                                                                                            arg0 <- pure "    } else {\n"
                                                                                                                                                            liftIO (boxString arg0)
                                                                                                                                                          arg1 <- do
                                                                                                                                                            arg0 <- do
                                                                                                                                                              arg0 <- pure "      out += ch;\n"
                                                                                                                                                              liftIO (boxString arg0)
                                                                                                                                                            arg1 <- do
                                                                                                                                                              arg0 <- do
                                                                                                                                                                arg0 <- pure "    }\n"
                                                                                                                                                                liftIO (boxString arg0)
                                                                                                                                                              arg1 <- do
                                                                                                                                                                arg0 <- do
                                                                                                                                                                  arg0 <- pure "  }\n"
                                                                                                                                                                  liftIO (boxString arg0)
                                                                                                                                                                arg1 <- do
                                                                                                                                                                  arg0 <- do
                                                                                                                                                                    arg0 <- pure "  return out;\n"
                                                                                                                                                                    liftIO (boxString arg0)
                                                                                                                                                                  arg1 <- do
                                                                                                                                                                    arg0 <- do
                                                                                                                                                                      arg0 <- pure "}\n"
                                                                                                                                                                      liftIO (boxString arg0)
                                                                                                                                                                    arg1 <- do
                                                                                                                                                                      arg0 <- do
                                                                                                                                                                        arg0 <- pure "function printf(fmt, ...args) { quonIO.write(cformat(fmt, ...args)); }\n"
                                                                                                                                                                        liftIO (boxString arg0)
                                                                                                                                                                      arg1 <- do
                                                                                                                                                                        arg0 <- do
                                                                                                                                                                          arg0 <- pure "function fprintf(stream, fmt, ...args) { stream.write(cformat(fmt, ...args)); }\n"
                                                                                                                                                                          liftIO (boxString arg0)
                                                                                                                                                                        arg1 <- pure Nothing
                                                                                                                                                                        liftIO (cons arg0 arg1)
                                                                                                                                                                      liftIO (cons arg0 arg1)
                                                                                                                                                                    liftIO (cons arg0 arg1)
                                                                                                                                                                  liftIO (cons arg0 arg1)
                                                                                                                                                                liftIO (cons arg0 arg1)
                                                                                                                                                              liftIO (cons arg0 arg1)
                                                                                                                                                            liftIO (cons arg0 arg1)
                                                                                                                                                          liftIO (cons arg0 arg1)
                                                                                                                                                        liftIO (cons arg0 arg1)
                                                                                                                                                      liftIO (cons arg0 arg1)
                                                                                                                                                    liftIO (cons arg0 arg1)
                                                                                                                                                  liftIO (cons arg0 arg1)
                                                                                                                                                liftIO (cons arg0 arg1)
                                                                                                                                              liftIO (cons arg0 arg1)
                                                                                                                                            liftIO (cons arg0 arg1)
                                                                                                                                          liftIO (cons arg0 arg1)
                                                                                                                                        liftIO (cons arg0 arg1)
                                                                                                                                      liftIO (cons arg0 arg1)
                                                                                                                                    liftIO (cons arg0 arg1)
                                                                                                                                  liftIO (cons arg0 arg1)
                                                                                                                                liftIO (cons arg0 arg1)
                                                                                                                              liftIO (cons arg0 arg1)
                                                                                                                            liftIO (cons arg0 arg1)
                                                                                                                          liftIO (cons arg0 arg1)
                                                                                                                        liftIO (cons arg0 arg1)
                                                                                                                      liftIO (cons arg0 arg1)
                                                                                                                    liftIO (cons arg0 arg1)
                                                                                                                  liftIO (cons arg0 arg1)
                                                                                                                liftIO (cons arg0 arg1)
                                                                                                              liftIO (cons arg0 arg1)
                                                                                                            liftIO (cons arg0 arg1)
                                                                                                          liftIO (cons arg0 arg1)
                                                                                                        liftIO (cons arg0 arg1)
                                                                                                      liftIO (cons arg0 arg1)
                                                                                                    liftIO (cons arg0 arg1)
                                                                                                  liftIO (cons arg0 arg1)
                                                                                                liftIO (cons arg0 arg1)
                                                                                              liftIO (cons arg0 arg1)
                                                                                            liftIO (cons arg0 arg1)
                                                                                          liftIO (cons arg0 arg1)
                                                                                        liftIO (cons arg0 arg1)
                                                                                      liftIO (cons arg0 arg1)
                                                                                    liftIO (cons arg0 arg1)
                                                                                  liftIO (cons arg0 arg1)
                                                                                liftIO (cons arg0 arg1)
                                                                              liftIO (cons arg0 arg1)
                                                                            liftIO (cons arg0 arg1)
                                                                          liftIO (cons arg0 arg1)
                                                                        liftIO (cons arg0 arg1)
                                                                      liftIO (cons arg0 arg1)
                                                                    liftIO (cons arg0 arg1)
                                                                  liftIO (cons arg0 arg1)
                                                                liftIO (cons arg0 arg1)
                                                              liftIO (cons arg0 arg1)
                                                            liftIO (cons arg0 arg1)
                                                          liftIO (cons arg0 arg1)
                                                        liftIO (cons arg0 arg1)
                                                      liftIO (cons arg0 arg1)
                                                    liftIO (cons arg0 arg1)
                                                  liftIO (cons arg0 arg1)
                                                liftIO (cons arg0 arg1)
                                              liftIO (cons arg0 arg1)
                                            liftIO (cons arg0 arg1)
                                          liftIO (cons arg0 arg1)
                                        liftIO (cons arg0 arg1)
                                      liftIO (cons arg0 arg1)
                                    liftIO (cons arg0 arg1)
                                  liftIO (cons arg0 arg1)
                                liftIO (cons arg0 arg1)
                              liftIO (cons arg0 arg1)
                            liftIO (cons arg0 arg1)
                          liftIO (cons arg0 arg1)
                        liftIO (cons arg0 arg1)
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

node2Types :: Maybe Box -> IO (Maybe Box)
node2Types nodes_arg = evalContT $ callCC $ \qreturn -> do
  nodes <- liftIO (newIORef nodes_arg)
  hret <- liftIO emptyList
  qreturn hret
  pure Nothing

node2FuncMap :: Maybe Box -> IO (Maybe Box)
node2FuncMap aSym_arg = evalContT $ callCC $ \qreturn -> do
  aSym <- liftIO (newIORef aSym_arg)
  qinit <- pure Nothing
  symMap <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- pure "symbol"
    arg1 <- do
      arg0 <- liftIO (readIORef aSym)
      liftIO (boxType arg0)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      qset <- do
        arg0 <- do
          arg0 <- pure "="
          liftIO (boxSymbol arg0)
        arg1 <- do
          arg0 <- pure "equal"
          liftIO (boxSymbol arg0)
        arg2 <- do
          arg0 <- do
            arg0 <- pure "sub-string"
            liftIO (boxSymbol arg0)
          arg1 <- do
            arg0 <- pure "sub_string"
            liftIO (boxSymbol arg0)
          arg2 <- do
            arg0 <- do
              arg0 <- pure "read-file"
              liftIO (boxSymbol arg0)
            arg1 <- do
              arg0 <- pure "read_file"
              liftIO (boxSymbol arg0)
            arg2 <- do
              arg0 <- do
                arg0 <- pure "write-file"
                liftIO (boxSymbol arg0)
              arg1 <- do
                arg0 <- pure "write_file"
                liftIO (boxSymbol arg0)
              arg2 <- do
                arg0 <- do
                  arg0 <- pure ">"
                  liftIO (boxSymbol arg0)
                arg1 <- do
                  arg0 <- pure "greaterthan"
                  liftIO (boxSymbol arg0)
                arg2 <- do
                  arg0 <- do
                    arg0 <- pure "string-length"
                    liftIO (boxSymbol arg0)
                  arg1 <- do
                    arg0 <- pure "string_length"
                    liftIO (boxSymbol arg0)
                  arg2 <- do
                    arg0 <- do
                      arg0 <- pure "new"
                      liftIO (boxSymbol arg0)
                    arg1 <- do
                      arg0 <- pure "new_"
                      liftIO (boxSymbol arg0)
                    arg2 <- do
                      arg0 <- do
                        arg0 <- pure "nil"
                        liftIO (boxSymbol arg0)
                      arg1 <- do
                        arg0 <- pure "null"
                        liftIO (boxSymbol arg0)
                      arg2 <- pure Nothing
                      liftIO (alistCons arg0 arg1 arg2)
                    liftIO (alistCons arg0 arg1 arg2)
                  liftIO (alistCons arg0 arg1 arg2)
                liftIO (alistCons arg0 arg1 arg2)
              liftIO (alistCons arg0 arg1 arg2)
            liftIO (alistCons arg0 arg1 arg2)
          liftIO (alistCons arg0 arg1 arg2)
        liftIO (alistCons arg0 arg1 arg2)
      liftIO (writeIORef symMap qset)
      hcond <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef aSym)
            liftIO (stringify arg0)
          arg1 <- liftIO (readIORef symMap)
          liftIO (assoc arg0 arg1)
        liftIO (truthy arg0)
      if hcond
        then do
          hret <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef aSym)
                liftIO (stringify arg0)
              arg1 <- liftIO (readIORef symMap)
              liftIO (assoc arg0 arg1)
            liftIO (cdr arg0)
          qreturn hret
          pure ()
        else do
          hret <- liftIO (readIORef aSym)
          qreturn hret
          pure ()
      pure ()
    else do
      hret <- liftIO (readIORef aSym)
      qreturn hret
      pure ()
  pure Nothing

node2MainEntry :: IO (Maybe Box)
node2MainEntry = evalContT $ callCC $ \qreturn -> do
  hret <- do
    arg0 <- do
      arg0 <- pure "\n// Main entry point\n"
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "function runQuon(args = [], io = {}) {\n"
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure "  configureQuonIO(io);\n"
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "  globalArgs = [\"fixmeprogname\", ...args];\n"
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure "  globalArgsCount = globalArgs.length;\n"
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure "  return start();\n"
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure "}\n"
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure "const __quonProgramApi = { runQuon, configureQuonIO, cformat, start };\n"
                    liftIO (boxString arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- pure "if (typeof compileBodyString === \"function\") __quonProgramApi.compileBodyString = compileBodyString;\n"
                      liftIO (boxString arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- pure "if (typeof compileBodySectionString === \"function\") __quonProgramApi.compileBodySectionString = compileBodySectionString;\n"
                        liftIO (boxString arg0)
                      arg1 <- do
                        arg0 <- do
                          arg0 <- pure "if (typeof compileFunctionsString === \"function\") __quonProgramApi.compileFunctionsString = compileFunctionsString;\n"
                          liftIO (boxString arg0)
                        arg1 <- do
                          arg0 <- do
                            arg0 <- pure "if (typeof compileFunctionsSectionString === \"function\") __quonProgramApi.compileFunctionsSectionString = compileFunctionsSectionString;\n"
                            liftIO (boxString arg0)
                          arg1 <- do
                            arg0 <- do
                              arg0 <- pure "if (typeof compileTypesString === \"function\") __quonProgramApi.compileTypesString = compileTypesString;\n"
                              liftIO (boxString arg0)
                            arg1 <- do
                              arg0 <- do
                                arg0 <- pure "if (typeof compileTypesSectionString === \"function\") __quonProgramApi.compileTypesSectionString = compileTypesSectionString;\n"
                                liftIO (boxString arg0)
                              arg1 <- do
                                arg0 <- do
                                  arg0 <- pure "if (typeof compileProgramBareString === \"function\") __quonProgramApi.compileProgramBareString = compileProgramBareString;\n"
                                  liftIO (boxString arg0)
                                arg1 <- do
                                  arg0 <- do
                                    arg0 <- pure "if (typeof readBodyFragment === \"function\") __quonProgramApi.readBodyFragment = readBodyFragment;\n"
                                    liftIO (boxString arg0)
                                  arg1 <- do
                                    arg0 <- do
                                      arg0 <- pure "if (typeof module !== \"undefined\" && module.exports) module.exports = __quonProgramApi;\n"
                                      liftIO (boxString arg0)
                                    arg1 <- do
                                      arg0 <- do
                                        arg0 <- pure "if (typeof globalThis !== \"undefined\") globalThis.QuonProgram = __quonProgramApi;\n"
                                        liftIO (boxString arg0)
                                      arg1 <- do
                                        arg0 <- do
                                          arg0 <- pure "if (typeof require === \"function\" && typeof module !== \"undefined\" && require.main === module) {\n"
                                          liftIO (boxString arg0)
                                        arg1 <- do
                                          arg0 <- do
                                            arg0 <- pure "  runQuon((typeof process !== \"undefined\" && process.argv) ? process.argv.slice(2) : []);\n"
                                            liftIO (boxString arg0)
                                          arg1 <- do
                                            arg0 <- do
                                              arg0 <- pure "}\n"
                                              liftIO (boxString arg0)
                                            arg1 <- pure Nothing
                                            liftIO (cons arg0 arg1)
                                          liftIO (cons arg0 arg1)
                                        liftIO (cons arg0 arg1)
                                      liftIO (cons arg0 arg1)
                                    liftIO (cons arg0 arg1)
                                  liftIO (cons arg0 arg1)
                                liftIO (cons arg0 arg1)
                              liftIO (cons arg0 arg1)
                            liftIO (cons arg0 arg1)
                          liftIO (cons arg0 arg1)
                        liftIO (cons arg0 arg1)
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

node2LoadProgram :: String -> IO (Maybe Box)
node2LoadProgram filename_arg = evalContT $ callCC $ \qreturn -> do
  filename <- liftIO (newIORef filename_arg)
  qinit <- pure Nothing
  tree <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  replace <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef filename)
    liftIO (loadQuon arg0)
  liftIO (writeIORef tree qset)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    arg1 <- pure "q/shims/node2.qon"
    liftIO (insertInclude arg0 arg1)
  liftIO (writeIORef tree qset)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    arg1 <- pure Nothing
    liftIO (loadIncludes arg0 arg1)
  liftIO (writeIORef tree qset)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (macrowalk arg0)
  liftIO (writeIORef tree qset)
  qset <- do
    arg0 <- do
      arg0 <- pure "fprintf"
      liftIO (boxSymbol arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "stderr"
        liftIO (boxSymbol arg0)
      arg1 <- pure Nothing
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef replace qset)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    arg1 <- do
      arg0 <- pure "q"
      arg1 <- pure "log"
      liftIO (stringConcatenate arg0 arg1)
    arg2 <- liftIO (readIORef replace)
    liftIO (macrolist arg0 arg1 arg2)
  liftIO (writeIORef tree qset)
  hret <- liftIO (readIORef tree)
  qreturn hret
  pure Nothing

node2ProgramTree :: Maybe Box -> IO (Maybe Box)
node2ProgramTree tree_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef tree)
            liftIO (first arg0)
          liftIO (cdr arg0)
        liftIO (node2Includes arg0)
      liftIO (qid arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (second arg0)
            liftIO (cdr arg0)
          liftIO (node2Types arg0)
        liftIO (qid arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (third arg0)
              liftIO (cdr arg0)
            liftIO (node2Functions arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- liftIO node2MainEntry
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure "\n"
              liftIO (boxString arg0)
            arg1 <- pure Nothing
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

node2Program :: Maybe Box -> IO (String)
node2Program tree_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef tree)
        liftIO (node2ProgramTree arg0)
      liftIO (flatten arg0)
    arg1 <- pure 0
    arg2 <- pure True
    arg3 <- pure False
    liftIO (listToString arg0 arg1 arg2 arg3)
  qreturn hret
  pure ""

node2CompileString :: String -> IO (String)
node2CompileString filename_arg = evalContT $ callCC $ \qreturn -> do
  filename <- liftIO (newIORef filename_arg)
  hret <- do
    arg0 <- do
      arg0 <- liftIO (readIORef filename)
      liftIO (node2LoadProgram arg0)
    liftIO (node2Program arg0)
  qreturn hret
  pure ""

node2Compile :: String -> IO (())
node2Compile filename_arg = evalContT $ callCC $ \qreturn -> do
  filename <- liftIO (newIORef filename_arg)
  qinit <- pure Nothing
  tree <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  replace <- liftIO (newIORef qinit)
  _ <- do
    arg0 <- pure stderr
    arg1 <- pure "//Scanning file...%s\n"
    arg2 <- liftIO (readIORef filename)
    liftIO (hPrintf arg0 arg1 arg2)
  qset <- do
    arg0 <- liftIO (readIORef filename)
    liftIO (loadQuon arg0)
  liftIO (writeIORef tree qset)
  _ <- do
    arg0 <- pure stderr
    arg1 <- pure "Loading shim node2\n"
    liftIO (hPrintf arg0 arg1)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    arg1 <- pure "q/shims/node2.qon"
    liftIO (insertInclude arg0 arg1)
  liftIO (writeIORef tree qset)
  _ <- do
    arg0 <- pure stderr
    arg1 <- pure "Loading all includes\n"
    liftIO (hPrintf arg0 arg1)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    arg1 <- pure Nothing
    liftIO (loadIncludes arg0 arg1)
  liftIO (writeIORef tree qset)
  _ <- do
    arg0 <- pure stderr
    arg1 <- pure "Applying macros\n"
    liftIO (hPrintf arg0 arg1)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (macrowalk arg0)
  liftIO (writeIORef tree qset)
  qset <- do
    arg0 <- do
      arg0 <- pure "fprintf"
      liftIO (boxSymbol arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "stderr"
        liftIO (boxSymbol arg0)
      arg1 <- pure Nothing
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef replace qset)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    arg1 <- do
      arg0 <- pure "q"
      arg1 <- pure "log"
      liftIO (stringConcatenate arg0 arg1)
    arg2 <- liftIO (readIORef replace)
    liftIO (macrolist arg0 arg1 arg2)
  liftIO (writeIORef tree qset)
  _ <- do
    arg0 <- pure stderr
    arg1 <- pure "//Printing program\n"
    liftIO (hPrintf arg0 arg1)
  _ <- do
    arg0 <- do
      arg0 <- liftIO (readIORef tree)
      liftIO (node2ProgramTree arg0)
    liftIO (printStringTree arg0)
  _ <- do
    arg0 <- pure stderr
    arg1 <- pure "//Done printing program\n"
    liftIO (hPrintf arg0 arg1)
  pure ()

test0 :: IO (())
test0 = evalContT $ callCC $ \qreturn -> do
  hcond <- do
    arg0 <- do
      arg0 <- do
        arg0 <- pure "hello"
        liftIO (boxString arg0)
      liftIO (stringify arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "hello"
        liftIO (boxString arg0)
      liftIO (stringify arg0)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "0.  pass string compare works\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "0.  pass string compare fails\n"
        liftIO (printf arg0)
      pure ()
  hcond <- do
    arg0 <- do
      arg0 <- do
        arg0 <- pure "hello"
        liftIO (boxString arg0)
      liftIO (stringify arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "hello"
        liftIO (boxSymbol arg0)
      liftIO (stringify arg0)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "0.  pass string compare works\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "0.  pass string compare fails\n"
        liftIO (printf arg0)
      pure ()
  pure ()

test1 :: IO (())
test1 = evalContT $ callCC $ \qreturn -> do
  _ <- do
    arg0 <- pure "1.  pass Function call and print work\n"
    liftIO (printf arg0)
  pure ()

test2_do :: String -> IO (())
test2_do message_arg = evalContT $ callCC $ \qreturn -> do
  message <- liftIO (newIORef message_arg)
  _ <- do
    arg0 <- pure "2.  pass Function call with arg works: %s\n"
    arg1 <- liftIO (readIORef message)
    liftIO (printf arg0 arg1)
  pure ()

test2 :: IO (())
test2 = evalContT $ callCC $ \qreturn -> do
  _ <- do
    arg0 <- pure "This is the argument"
    liftIO (test2_do arg0)
  pure ()

test3_do :: Int -> String -> IO (())
test3_do b_arg c_arg = evalContT $ callCC $ \qreturn -> do
  b <- liftIO (newIORef b_arg)
  c <- liftIO (newIORef c_arg)
  _ <- do
    arg0 <- pure "3.1 pass Two arg call, first arg: %d\n"
    arg1 <- liftIO (readIORef b)
    liftIO (printf arg0 arg1)
  _ <- do
    arg0 <- pure "3.2 pass Two arg call, second arg: %s\n"
    arg1 <- liftIO (readIORef c)
    liftIO (printf arg0 arg1)
  pure ()

test3 :: IO (())
test3 = evalContT $ callCC $ \qreturn -> do
  _ <- do
    arg0 <- pure 42
    arg1 <- pure "Fourty-two"
    liftIO (test3_do arg0 arg1)
  pure ()

test4_do :: IO (String)
test4_do = evalContT $ callCC $ \qreturn -> do
  hret <- pure "pass Return works"
  qreturn hret
  pure ""

returnThis :: String -> IO (String)
returnThis returnMessage_arg = evalContT $ callCC $ \qreturn -> do
  returnMessage <- liftIO (newIORef returnMessage_arg)
  hret <- liftIO (readIORef returnMessage)
  qreturn hret
  pure ""

test4 :: IO (())
test4 = evalContT $ callCC $ \qreturn -> do
  qinit <- pure "fail"
  message <- liftIO (newIORef qinit)
  qset <- liftIO test4_do
  liftIO (writeIORef message qset)
  _ <- do
    arg0 <- pure "4.  %s\n"
    arg1 <- liftIO (readIORef message)
    liftIO (printf arg0 arg1)
  pure ()

test5 :: IO (())
test5 = evalContT $ callCC $ \qreturn -> do
  qinit <- pure "fail"
  message <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- pure "pass return passthrough string"
    liftIO (returnThis arg0)
  liftIO (writeIORef message qset)
  _ <- do
    arg0 <- pure "5.  %s\n"
    arg1 <- liftIO (readIORef message)
    liftIO (printf arg0 arg1)
  pure ()

test6 :: IO (())
test6 = evalContT $ callCC $ \qreturn -> do
  hcond <- pure True
  if hcond
    then do
      _ <- do
        arg0 <- pure "6.  pass If statement works\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "6.  fail If statement works\n"
        liftIO (printf arg0)
      pure ()
  pure ()

test7_do :: Int -> IO (Int)
test7_do count_arg = evalContT $ callCC $ \qreturn -> do
  count <- liftIO (newIORef count_arg)
  qset <- do
    arg0 <- liftIO (readIORef count)
    arg1 <- pure 1
    liftIO (sub arg0 arg1)
  liftIO (writeIORef count qset)
  hcond <- do
    arg0 <- liftIO (readIORef count)
    arg1 <- pure 0
    liftIO (greaterthan arg0 arg1)
  if hcond
    then do
      qset <- do
        arg0 <- liftIO (readIORef count)
        liftIO (test7_do arg0)
      liftIO (writeIORef count qset)
      pure ()
    else do
      hret <- liftIO (readIORef count)
      qreturn hret
      pure ()
  hret <- liftIO (readIORef count)
  qreturn hret
  pure 0

test7 :: IO (())
test7 = evalContT $ callCC $ \qreturn -> do
  hcond <- do
    arg0 <- pure 0
    arg1 <- do
      arg0 <- pure 10
      liftIO (test7_do arg0)
    liftIO (equal arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "7.  pass count works\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "7.  fail count fails\n"
        liftIO (printf arg0)
      pure ()
  pure ()

beer :: IO (())
beer = evalContT $ callCC $ \qreturn -> do
  _ <- do
    arg0 <- pure "%d bottle of beer on the wall, %d bottle of beer.  Take one down, pass it round, no bottles of beer on the wall\n"
    arg1 <- pure 1
    arg2 <- pure 1
    liftIO (printf arg0 arg1 arg2)
  pure ()

plural :: Int -> IO (String)
plural num_arg = evalContT $ callCC $ \qreturn -> do
  num <- liftIO (newIORef num_arg)
  hcond <- do
    arg0 <- liftIO (readIORef num)
    arg1 <- pure 1
    liftIO (equal arg0 arg1)
  if hcond
    then do
      hret <- pure ""
      qreturn hret
      pure ()
    else do
      hret <- pure "s"
      qreturn hret
      pure ()
  pure ""

beers :: Int -> IO (Int)
beers count_arg = evalContT $ callCC $ \qreturn -> do
  count <- liftIO (newIORef count_arg)
  qinit <- pure 0
  newcount <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef count)
    arg1 <- pure 1
    liftIO (sub arg0 arg1)
  liftIO (writeIORef newcount qset)
  _ <- do
    arg0 <- pure "%d bottle%s of beer on the wall, %d bottle%s of beer.  Take one down, pass it round, %d bottle%s of beer on the wall\n"
    arg1 <- liftIO (readIORef count)
    arg2 <- do
      arg0 <- liftIO (readIORef count)
      liftIO (plural arg0)
    arg3 <- liftIO (readIORef count)
    arg4 <- do
      arg0 <- liftIO (readIORef count)
      liftIO (plural arg0)
    arg5 <- liftIO (readIORef newcount)
    arg6 <- do
      arg0 <- liftIO (readIORef newcount)
      liftIO (plural arg0)
    liftIO (printf arg0 arg1 arg2 arg3 arg4 arg5 arg6)
  hcond <- do
    arg0 <- liftIO (readIORef count)
    arg1 <- pure 1
    liftIO (greaterthan arg0 arg1)
  if hcond
    then do
      qset <- do
        arg0 <- liftIO (readIORef newcount)
        liftIO (beers arg0)
      liftIO (writeIORef count qset)
      pure ()
    else do
      hret <- liftIO (readIORef count)
      qreturn hret
      pure ()
  hret <- pure 0
  qreturn hret
  pure 0

test8 :: IO (())
test8 = evalContT $ callCC $ \qreturn -> do
  hcond <- do
    arg0 <- do
      arg0 <- do
        arg0 <- pure 2
        arg1 <- pure 1
        liftIO (sub arg0 arg1)
      arg1 <- do
        arg0 <- pure 3
        arg1 <- pure 1
        liftIO (sub arg0 arg1)
      liftIO (sub arg0 arg1)
    arg1 <- pure (-1)
    liftIO (equal arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "8.  pass Nested expressions work\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "8.  fail Nested expressions don't work\n"
        liftIO (printf arg0)
      pure ()
  pure ()

test9 :: IO (())
test9 = evalContT $ callCC $ \qreturn -> do
  qinit <- pure (-999999)
  answer <- liftIO (newIORef qinit)
  qinit <- pure 2
  a <- liftIO (newIORef qinit)
  qinit <- pure 3
  b <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- do
      arg0 <- pure 20
      arg1 <- pure 1
      liftIO (sub arg0 arg1)
    arg1 <- do
      arg0 <- pure 3
      arg1 <- pure 1
      liftIO (sub arg0 arg1)
    liftIO (sub arg0 arg1)
  liftIO (writeIORef answer qset)
  hcond <- do
    arg0 <- liftIO (readIORef answer)
    arg1 <- pure 17
    liftIO (equal arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "9.1  pass sub works\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "9.1  fail sub\n"
        liftIO (printf arg0)
      pure ()
  qset <- do
    arg0 <- pure 2
    arg1 <- pure 3
    liftIO (add arg0 arg1)
  liftIO (writeIORef answer qset)
  hcond <- do
    arg0 <- liftIO (readIORef answer)
    arg1 <- pure 5
    liftIO (equal arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "9.2  pass add works\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "9.2  fail add\n"
        liftIO (printf arg0)
      pure ()
  qset <- do
    arg0 <- liftIO (readIORef a)
    arg1 <- liftIO (readIORef b)
    liftIO (mult arg0 arg1)
  liftIO (writeIORef answer qset)
  hcond <- do
    arg0 <- liftIO (readIORef answer)
    arg1 <- pure 6
    liftIO (equal arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "9.3  pass mult works\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "9.3  fail mult\n"
        liftIO (printf arg0)
      pure ()
  hcond <- do
    arg0 <- pure 2
    arg1 <- pure 1
    liftIO (greaterthan arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "9.4  pass greaterthan works\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "9.4  fail greaterthan\n"
        liftIO (printf arg0)
      pure ()
  hcond <- do
    arg0 <- pure 1
    arg1 <- pure 1
    liftIO (equal arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "9.5  pass integer equal works\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "9.5  fail integer equal\n"
        liftIO (printf arg0)
      pure ()
  hcond <- do
    arg0 <- pure "hello"
    arg1 <- pure "hello"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "9.6  pass string equal works\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "9.6  fail string equal\n"
        liftIO (printf arg0)
      pure ()
  hcond <- do
    arg0 <- pure "hello"
    arg1 <- pure "world"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "9.7  fail string equal\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "9.7  pass string equal\n"
        liftIO (printf arg0)
      pure ()
  hcond <- do
    arg0 <- pure False
    arg1 <- pure False
    liftIO (andBool arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "9.8  fail andBool\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "9.8  pass andBool works\n"
        liftIO (printf arg0)
      pure ()
  hcond <- do
    arg0 <- pure True
    arg1 <- pure True
    liftIO (andBool arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "9.9  pass andBool works\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "9.9  fail andBool\n"
        liftIO (printf arg0)
      pure ()
  hcond <- do
    arg0 <- pure True
    arg1 <- pure False
    liftIO (andBool arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "9.10  fail andBool\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "9.10  pass andBool works\n"
        liftIO (printf arg0)
      pure ()
  hcond <- do
    arg0 <- pure "hello"
    arg1 <- pure "hello"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "9.11  pass string equal\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "9.11  fail string equal\n"
        liftIO (printf arg0)
      pure ()
  hcond <- do
    arg0 <- pure "!"
    arg1 <- do
      arg0 <- pure 33
      liftIO (character arg0)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "9.12  pass character\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "9.12  fail character\n"
        liftIO (printf arg0)
      pure ()
  hcond <- do
    arg0 <- pure "33"
    arg1 <- do
      arg0 <- pure 33
      liftIO (intToString arg0)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "9.13  pass intToString\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "9.13  fail intToString\n"
        liftIO (printf arg0)
      pure ()
  hcond <- do
    arg0 <- pure "llo"
    arg1 <- do
      arg0 <- pure "hello"
      arg1 <- liftIO (readIORef a)
      arg2 <- liftIO (readIORef b)
      liftIO (sub_string arg0 arg1 arg2)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "9.14  pass sub-string\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "9.14  fail sub-string: %s\n"
        arg1 <- do
          arg0 <- pure "hello"
          arg1 <- liftIO (readIORef a)
          arg2 <- liftIO (readIORef b)
          liftIO (sub_string arg0 arg1 arg2)
        liftIO (printf arg0 arg1)
      pure ()
  pure ()

test10 :: IO (())
test10 = evalContT $ callCC $ \qreturn -> do
  qinit <- pure "This is a test string"
  testString <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef testString)
    arg1 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef testString)
            liftIO (boxString arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (car arg0)
      liftIO (unBoxString arg0)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "10. pass cons and car work\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "10. fail cons and car fail\n"
        liftIO (printf arg0)
      pure ()
  pure ()

test12 :: IO (())
test12 = evalContT $ callCC $ \qreturn -> do
  qinit <- pure Nothing
  b <- liftIO (newIORef qinit)
  qset <- liftIO (Just <$> newBox)
  liftIO (writeIORef b qset)
  hobj <- liftIO (readIORef b)
  qset <- pure "12. pass structure accessors\n"
  liftIO (writeIORef (getField @"qf_str" (expect hobj)) qset)
  _ <- do
    arg0 <- pure "%s"
    arg1 <- do
      hobj <- liftIO (readIORef b)
      liftIO (readIORef (getField @"qf_str" (expect hobj)))
    liftIO (printf arg0 arg1)
  pure ()

test13 :: IO (())
test13 = evalContT $ callCC $ \qreturn -> do
  qinit <- pure "Hello from the filesystem!"
  testString <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  contentsBox <- liftIO (newIORef qinit)
  qinit <- pure ""
  contents <- liftIO (newIORef qinit)
  _ <- do
    arg0 <- pure "test.txt"
    arg1 <- liftIO (readIORef testString)
    liftIO (write_file arg0 arg1)
  qset <- do
    arg0 <- pure "test.txt"
    liftIO (read_file arg0)
  liftIO (writeIORef contentsBox qset)
  hcond <- do
    arg0 <- liftIO (readIORef contentsBox)
    liftIO (isNil arg0)
  if hcond
    then do
      _ <- do
        arg0 <- pure "13. fail Read and write files\n"
        liftIO (printf arg0)
      _ <- do
        arg0 <- pure "Expected: %s\n"
        arg1 <- liftIO (readIORef testString)
        liftIO (printf arg0 arg1)
      _ <- do
        arg0 <- pure "Got: nil\n"
        liftIO (printf arg0)
      pure ()
    else do
      qset <- do
        arg0 <- liftIO (readIORef contentsBox)
        liftIO (unBoxString arg0)
      liftIO (writeIORef contents qset)
      hcond <- do
        arg0 <- liftIO (readIORef testString)
        arg1 <- liftIO (readIORef contents)
        liftIO (equalString arg0 arg1)
      if hcond
        then do
          _ <- do
            arg0 <- pure "13. pass Read and write files\n"
            liftIO (printf arg0)
          pure ()
        else do
          _ <- do
            arg0 <- pure "13. fail Read and write files\n"
            liftIO (printf arg0)
          _ <- do
            arg0 <- pure "Expected: %s\n"
            arg1 <- liftIO (readIORef testString)
            liftIO (printf arg0 arg1)
          _ <- do
            arg0 <- pure "Got: %s\n"
            arg1 <- liftIO (readIORef contents)
            liftIO (printf arg0 arg1)
          pure ()
      pure ()
  pure ()

test14 :: IO (())
test14 = evalContT $ callCC $ \qreturn -> do
  qinit <- pure Nothing
  contentsBox <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- pure "q/this-file-should-not-exist.qon"
    liftIO (read_file arg0)
  liftIO (writeIORef contentsBox qset)
  hcond <- do
    arg0 <- liftIO (readIORef contentsBox)
    liftIO (isNil arg0)
  if hcond
    then do
      _ <- do
        arg0 <- pure "14. pass Missing read-file returns nil\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "14. fail Missing read-file returns nil\n"
        liftIO (printf arg0)
      _ <- do
        arg0 <- pure "Got: %s\n"
        arg1 <- do
          arg0 <- liftIO (readIORef contentsBox)
          liftIO (unBoxString arg0)
        liftIO (printf arg0 arg1)
      pure ()
  pure ()

test15 :: IO (())
test15 = evalContT $ callCC $ \qreturn -> do
  qinit <- pure "hello"
  a <- liftIO (newIORef qinit)
  qinit <- pure " world"
  b <- liftIO (newIORef qinit)
  qinit <- pure ""
  c <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef a)
    arg1 <- liftIO (readIORef b)
    liftIO (stringConcatenate arg0 arg1)
  liftIO (writeIORef c qset)
  hcond <- do
    arg0 <- liftIO (readIORef c)
    arg1 <- pure "hello world"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "15. pass String concatenate\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "15. fail String concatenate\n"
        liftIO (printf arg0)
      pure ()
  pure ()

test16 :: IO (())
test16 = evalContT $ callCC $ \qreturn -> do
  qinit <- pure Nothing
  assocCell1 <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  assList <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  assocCell2 <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  assocCell3 <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- do
      arg0 <- pure "Hello"
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- pure "world"
      liftIO (boxString arg0)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef assocCell1 qset)
  qset <- do
    arg0 <- do
      arg0 <- pure "goodnight"
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- pure "moon"
      liftIO (boxString arg0)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef assocCell2 qset)
  qset <- do
    arg0 <- do
      arg0 <- pure "ohio"
      liftIO (boxSymbol arg0)
    arg1 <- do
      arg0 <- pure "gozaimasu"
      liftIO (boxString arg0)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef assocCell3 qset)
  qset <- do
    arg0 <- liftIO (readIORef assocCell2)
    arg1 <- liftIO emptyList
    liftIO (cons arg0 arg1)
  liftIO (writeIORef assList qset)
  qset <- do
    arg0 <- liftIO (readIORef assocCell1)
    arg1 <- liftIO (readIORef assList)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef assList qset)
  qset <- do
    arg0 <- liftIO (readIORef assocCell3)
    arg1 <- liftIO (readIORef assList)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef assList qset)
  hcond <- do
    arg0 <- do
      arg0 <- do
        arg0 <- pure "Hello"
        arg1 <- liftIO (readIORef assList)
        liftIO (assoc arg0 arg1)
      liftIO (cdr arg0)
    arg1 <- do
      arg0 <- pure "world"
      liftIO (boxString arg0)
    liftIO (equalBox arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "16.1 pass Basic assoc works\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "16.1 fail Basic assoc fails\n"
        liftIO (printf arg0)
      pure ()
  hcond <- do
    arg0 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- pure "Hello"
            arg1 <- liftIO (readIORef assList)
            liftIO (assoc arg0 arg1)
          liftIO (cdr arg0)
        arg1 <- do
          arg0 <- pure "world"
          liftIO (boxString arg0)
        liftIO (equalBox arg0 arg1)
      arg1 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- pure "goodnight"
            arg1 <- liftIO (readIORef assList)
            liftIO (assoc arg0 arg1)
          liftIO (cdr arg0)
        arg1 <- do
          arg0 <- pure "moon"
          liftIO (boxString arg0)
        liftIO (equalBox arg0 arg1)
      liftIO (andBool arg0 arg1)
    arg1 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- pure "ohio"
          arg1 <- liftIO (readIORef assList)
          liftIO (assoc arg0 arg1)
        liftIO (cdr arg0)
      arg1 <- do
        arg0 <- pure "gozaimasu"
        liftIO (boxString arg0)
      liftIO (equalBox arg0 arg1)
    liftIO (andBool arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "16.2 pass assoc list\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "16.2 fail assoc list\n"
        liftIO (printf arg0)
      pure ()
  pure ()

test17 :: IO (())
test17 = evalContT $ callCC $ \qreturn -> do
  qinit <- pure Nothing
  l <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- do
      arg0 <- pure 1
      liftIO (boxInt arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure 2
        liftIO (boxInt arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure 3
          liftIO (boxInt arg0)
        arg1 <- pure Nothing
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef l qset)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef l)
      liftIO (car arg0)
    arg1 <- do
      arg0 <- pure 1
      liftIO (boxInt arg0)
    liftIO (equalBox arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "17. pass list literal works\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "17. fail list literal failed\n"
        liftIO (printf arg0)
      pure ()
  pure ()

test18 :: IO (())
test18 = evalContT $ callCC $ \qreturn -> do
  qinit <- pure "a"
  val1 <- liftIO (newIORef qinit)
  qinit <- pure "b"
  val2 <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  l <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- do
      arg0 <- liftIO (readIORef val1)
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef val2)
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure "c"
          liftIO (boxString arg0)
        arg1 <- pure Nothing
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef l qset)
  hcond <- do
    arg0 <- liftIO (readIORef l)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "a"
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure "b"
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "c"
            liftIO (boxString arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (equalList arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "18. pass string list constructor works\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "18. fail string list constructor failed\n"
        liftIO (printf arg0)
      pure ()
  pure ()

test19 :: IO (())
test19 = evalContT $ callCC $ \qreturn -> do
  qinit <- pure "a"
  val1 <- liftIO (newIORef qinit)
  qinit <- pure "b"
  val2 <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  l <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  revlist <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  answer <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- do
      arg0 <- liftIO (readIORef val1)
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef val2)
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure "c"
          liftIO (boxString arg0)
        arg1 <- pure Nothing
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef l qset)
  qset <- do
    arg0 <- do
      arg0 <- pure "c"
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef val2)
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- liftIO (readIORef val1)
          liftIO (boxString arg0)
        arg1 <- pure Nothing
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef answer qset)
  qset <- do
    arg0 <- liftIO (readIORef l)
    liftIO (reverseList arg0)
  liftIO (writeIORef revlist qset)
  hcond <- do
    arg0 <- liftIO (readIORef answer)
    arg1 <- liftIO (readIORef revlist)
    liftIO (equalList arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "19. pass reverseList\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "19. fail reverseList\n"
        liftIO (printf arg0)
      pure ()
  pure ()

concatenateLists :: Maybe Box -> Maybe Box -> IO (Maybe Box)
concatenateLists oldL_arg newL_arg = evalContT $ callCC $ \qreturn -> do
  oldL <- liftIO (newIORef oldL_arg)
  newL <- liftIO (newIORef newL_arg)
  hret <- do
    arg0 <- do
      arg0 <- liftIO (readIORef oldL)
      liftIO (reverseList arg0)
    arg1 <- liftIO (readIORef newL)
    liftIO (reverseRec arg0 arg1)
  qreturn hret
  pure Nothing

test20 :: IO (())
test20 = evalContT $ callCC $ \qreturn -> do
  qinit <- pure "a"
  val1 <- liftIO (newIORef qinit)
  qinit <- pure "b"
  val2 <- liftIO (newIORef qinit)
  qinit <- pure "c"
  val3 <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  l <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  l2 <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  l3 <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  combined <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- do
      arg0 <- liftIO (readIORef val1)
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef val2)
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure "c"
          liftIO (boxString arg0)
        arg1 <- pure Nothing
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef l qset)
  qset <- do
    arg0 <- do
      arg0 <- pure "d"
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "e"
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure "f"
          liftIO (boxString arg0)
        arg1 <- pure Nothing
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef l2 qset)
  qset <- do
    arg0 <- do
      arg0 <- liftIO (readIORef val1)
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef val2)
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- liftIO (readIORef val3)
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "d"
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure "e"
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure "f"
                liftIO (boxString arg0)
              arg1 <- pure Nothing
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef l3 qset)
  qset <- do
    arg0 <- liftIO (readIORef l)
    arg1 <- liftIO (readIORef l2)
    liftIO (concatenateLists arg0 arg1)
  liftIO (writeIORef combined qset)
  hcond <- do
    arg0 <- liftIO (readIORef l3)
    arg1 <- liftIO (readIORef combined)
    liftIO (equalList arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "21. pass concatenateLists\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "21. fail concatenateLists\n"
        liftIO (printf arg0)
      pure ()
  pure ()

test21 :: IO (())
test21 = evalContT $ callCC $ \qreturn -> do
  qinit <- pure "a"
  val1 <- liftIO (newIORef qinit)
  qinit <- pure "b"
  val2 <- liftIO (newIORef qinit)
  qinit <- pure "c"
  val3 <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  l <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  l2 <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- do
      arg0 <- liftIO (readIORef val1)
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef val2)
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- liftIO (readIORef val3)
          liftIO (boxString arg0)
        arg1 <- pure Nothing
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef l qset)
  qset <- do
    arg0 <- do
      arg0 <- pure "a"
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "b"
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure "c"
          liftIO (boxString arg0)
        arg1 <- pure Nothing
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef l2 qset)
  hcond <- do
    arg0 <- liftIO (readIORef l)
    arg1 <- liftIO (readIORef l2)
    liftIO (equalList arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "21. pass equalList\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "21. fail equalList\n"
        liftIO (printf arg0)
      pure ()
  pure ()

test22 :: IO (())
test22 = evalContT $ callCC $ \qreturn -> do
  qinit <- pure Nothing
  original <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  out <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  replace <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  correct <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- do
      arg0 <- do
        arg0 <- pure "q"
        arg1 <- pure "log"
        liftIO (stringConcatenate arg0 arg1)
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "%s"
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure "hello"
          liftIO (boxString arg0)
        arg1 <- pure Nothing
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef original qset)
  qset <- do
    arg0 <- do
      arg0 <- pure "fprintf"
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "stderr"
        liftIO (boxString arg0)
      arg1 <- pure Nothing
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef replace qset)
  qset <- do
    arg0 <- liftIO (readIORef original)
    arg1 <- do
      arg0 <- pure "q"
      arg1 <- pure "log"
      liftIO (stringConcatenate arg0 arg1)
    arg2 <- liftIO (readIORef replace)
    liftIO (macrolist arg0 arg1 arg2)
  liftIO (writeIORef out qset)
  qset <- do
    arg0 <- do
      arg0 <- pure "fprintf"
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "stderr"
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure "%s"
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "hello"
            liftIO (boxString arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef correct qset)
  hcond <- do
    arg0 <- liftIO (readIORef out)
    arg1 <- liftIO (readIORef correct)
    liftIO (equalList arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "22. pass macroList\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "22. fail macroList\n"
        liftIO (printf arg0)
      _ <- do
        arg0 <- pure "In: "
        liftIO (printf arg0)
      _ <- do
        arg0 <- liftIO (readIORef original)
        arg1 <- pure 0
        arg2 <- pure True
        liftIO (displayList arg0 arg1 arg2)
      _ <- do
        arg0 <- pure "\nOut: "
        liftIO (printf arg0)
      _ <- do
        arg0 <- liftIO (readIORef out)
        arg1 <- pure 0
        arg2 <- pure True
        liftIO (displayList arg0 arg1 arg2)
      _ <- do
        arg0 <- pure "\n"
        liftIO (printf arg0)
      pure ()
  pure ()

test23 :: IO (())
test23 = evalContT $ callCC $ \qreturn -> do
  qinit <- pure Nothing
  original <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  out <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  replace <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  correct <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- do
      arg0 <- do
        arg0 <- pure "q"
        arg1 <- pure "log"
        liftIO (stringConcatenate arg0 arg1)
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "%s"
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure "hello"
          liftIO (boxString arg0)
        arg1 <- pure Nothing
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef original qset)
  qset <- do
    arg0 <- do
      arg0 <- pure "fprintf"
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "stderr"
        liftIO (boxString arg0)
      arg1 <- pure Nothing
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef replace qset)
  qset <- do
    arg0 <- liftIO (readIORef original)
    arg1 <- liftIO (readIORef replace)
    liftIO (concatLists arg0 arg1)
  liftIO (writeIORef out qset)
  qset <- do
    arg0 <- do
      arg0 <- do
        arg0 <- pure "q"
        arg1 <- pure "log"
        liftIO (stringConcatenate arg0 arg1)
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "%s"
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure "hello"
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "fprintf"
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure "stderr"
              liftIO (boxString arg0)
            arg1 <- pure Nothing
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef correct qset)
  hcond <- do
    arg0 <- liftIO (readIORef out)
    arg1 <- liftIO (readIORef correct)
    liftIO (equalList arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "23. pass concatLists\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "23. fail concatLists\n"
        liftIO (printf arg0)
      _ <- do
        arg0 <- pure "In: "
        liftIO (printf arg0)
      _ <- do
        arg0 <- liftIO (readIORef original)
        arg1 <- pure 0
        arg2 <- pure True
        liftIO (displayList arg0 arg1 arg2)
      _ <- do
        arg0 <- pure "\nOut: "
        liftIO (printf arg0)
      _ <- do
        arg0 <- liftIO (readIORef out)
        arg1 <- pure 0
        arg2 <- pure True
        liftIO (displayList arg0 arg1 arg2)
      pure ()
  pure ()

test24 :: IO (())
test24 = evalContT $ callCC $ \qreturn -> do
  qinit <- pure "a b c"
  expected <- liftIO (newIORef qinit)
  qinit <- pure ""
  res <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- do
      arg0 <- do
        arg0 <- pure "a"
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure "b"
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "c"
            liftIO (boxString arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    arg1 <- pure " "
    liftIO (stringListJoin arg0 arg1)
  liftIO (writeIORef res qset)
  hcond <- do
    arg0 <- liftIO (readIORef expected)
    arg1 <- liftIO (readIORef res)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "24. pass StringListJoin\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "24. fail StringListJoin.  expected %s, got %s\n"
        arg1 <- liftIO (readIORef expected)
        arg2 <- liftIO (readIORef res)
        liftIO (printf arg0 arg1 arg2)
      pure ()
  pure ()

test25 :: IO (())
test25 = evalContT $ callCC $ \qreturn -> do
  qinit <- pure "( a b ) c d e"
  expected <- liftIO (newIORef qinit)
  qinit <- pure ""
  res <- liftIO (newIORef qinit)
  qinit <- do
    arg0 <- do
      arg0 <- pure "c "
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "d "
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure "e"
          liftIO (boxString arg0)
        arg1 <- pure Nothing
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  testsubstr <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  input <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- do
      arg0 <- pure "a "
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "b "
        liftIO (boxString arg0)
      arg1 <- pure Nothing
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef input qset)
  qset <- do
    arg0 <- liftIO (readIORef input)
    arg1 <- liftIO (readIORef testsubstr)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef input qset)
  qset <- do
    arg0 <- liftIO (readIORef input)
    arg1 <- pure 0
    arg2 <- pure True
    arg3 <- pure False
    liftIO (listToString arg0 arg1 arg2 arg3)
  liftIO (writeIORef res qset)
  hcond <- do
    arg0 <- liftIO (readIORef expected)
    arg1 <- liftIO (readIORef res)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "25. pass ListToString\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "25. fail ListToString.  expected %s, got %s\n"
        arg1 <- liftIO (readIORef expected)
        arg2 <- liftIO (readIORef res)
        liftIO (printf arg0 arg1 arg2)
      pure ()
  pure ()

test27 :: IO (())
test27 = evalContT $ callCC $ \qreturn -> do
  qinit <- pure "a b c d e"
  expected <- liftIO (newIORef qinit)
  qinit <- pure "6.5"
  floatExpected <- liftIO (newIORef qinit)
  qinit <- pure ""
  floatResult <- liftIO (newIORef qinit)
  qinit <- pure ""
  res <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  floatBox <- liftIO (newIORef qinit)
  qinit <- do
    arg0 <- do
      arg0 <- pure "c "
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "d "
        liftIO (boxString arg0)
      arg1 <- pure Nothing
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  variable <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  input <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- do
      arg0 <- pure "a "
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "b "
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- liftIO (readIORef variable)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "e"
            liftIO (boxString arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef input qset)
  qset <- do
    arg0 <- do
      arg0 <- liftIO (readIORef input)
      liftIO (flatten arg0)
    arg1 <- pure 0
    arg2 <- pure True
    arg3 <- pure False
    liftIO (listToString arg0 arg1 arg2 arg3)
  liftIO (writeIORef res qset)
  hcond <- do
    arg0 <- liftIO (readIORef expected)
    arg1 <- liftIO (readIORef res)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "27. pass Interpolated List\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "27. fail Interpolated List.  expected %s, got %s\n"
        arg1 <- liftIO (readIORef expected)
        arg2 <- liftIO (readIORef res)
        liftIO (printf arg0 arg1 arg2)
      pure ()
  qset <- do
    arg0 <- pure 6.5
    liftIO (boxFloat arg0)
  liftIO (writeIORef floatBox qset)
  qset <- do
    arg0 <- liftIO (readIORef floatBox)
    liftIO (stringify arg0)
  liftIO (writeIORef floatResult qset)
  hcond <- do
    arg0 <- liftIO (readIORef floatExpected)
    arg1 <- liftIO (readIORef floatResult)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "27. pass Float box stringify\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "27. fail Float box stringify.  expected %s, got %s\n"
        arg1 <- liftIO (readIORef floatExpected)
        arg2 <- liftIO (readIORef floatResult)
        liftIO (printf arg0 arg1 arg2)
      pure ()
  pure ()

test28 :: IO (())
test28 = evalContT $ callCC $ \qreturn -> do
  qinit <- pure Nothing
  splitExpected <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  splitResult <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- pure "aXYZc"
    arg1 <- do
      arg0 <- pure "b"
      arg1 <- pure "XYZ"
      arg2 <- pure "abc"
      liftIO (stringReplace arg0 arg1 arg2)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "28.1 pass stringReplace\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "28.1 fail stringReplace\n"
        liftIO (printf arg0)
      pure ()
  hcond <- do
    arg0 <- pure "abc"
    arg1 <- do
      arg0 <- pure " abc "
      liftIO (stringTrim arg0)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "28.2 pass stringTrim\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "28.2 fail stringTrim\n"
        liftIO (printf arg0)
      pure ()
  qset <- do
    arg0 <- do
      arg0 <- pure "a"
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "b"
        liftIO (boxString arg0)
      arg1 <- pure Nothing
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef splitExpected qset)
  qset <- do
    arg0 <- pure "a,b"
    arg1 <- pure ","
    liftIO (stringSplit arg0 arg1)
  liftIO (writeIORef splitResult qset)
  hcond <- do
    arg0 <- liftIO (readIORef splitExpected)
    arg1 <- liftIO (readIORef splitResult)
    liftIO (equalList arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "28.3 pass stringSplit\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "28.3 fail stringSplit\n"
        liftIO (printf arg0)
      pure ()
  pure ()

haskellBackslash :: IO (String)
haskellBackslash = evalContT $ callCC $ \qreturn -> do
  hret <- do
    arg0 <- pure 92
    liftIO (character arg0)
  qreturn hret
  pure ""

haskellDoubleQuote :: IO (String)
haskellDoubleQuote = evalContT $ callCC $ \qreturn -> do
  hret <- do
    arg0 <- pure 34
    liftIO (character arg0)
  qreturn hret
  pure ""

haskellEscapedBackslash :: IO (String)
haskellEscapedBackslash = evalContT $ callCC $ \qreturn -> do
  hret <- do
    arg0 <- liftIO haskellBackslash
    arg1 <- liftIO haskellBackslash
    liftIO (stringConcatenate arg0 arg1)
  qreturn hret
  pure ""

haskellEscapedDoubleQuote :: IO (String)
haskellEscapedDoubleQuote = evalContT $ callCC $ \qreturn -> do
  hret <- do
    arg0 <- liftIO haskellBackslash
    arg1 <- liftIO haskellDoubleQuote
    liftIO (stringConcatenate arg0 arg1)
  qreturn hret
  pure ""

haskellEscapeString :: String -> IO (String)
haskellEscapeString s_arg = evalContT $ callCC $ \qreturn -> do
  s <- liftIO (newIORef s_arg)
  qset <- do
    arg0 <- do
      arg0 <- pure 10
      liftIO (character arg0)
    arg1 <- do
      arg0 <- liftIO haskellBackslash
      arg1 <- pure "n"
      liftIO (stringConcatenate arg0 arg1)
    arg2 <- liftIO (readIORef s)
    liftIO (stringReplace arg0 arg1 arg2)
  liftIO (writeIORef s qset)
  qset <- do
    arg0 <- do
      arg0 <- pure 13
      liftIO (character arg0)
    arg1 <- do
      arg0 <- liftIO haskellBackslash
      arg1 <- pure "r"
      liftIO (stringConcatenate arg0 arg1)
    arg2 <- liftIO (readIORef s)
    liftIO (stringReplace arg0 arg1 arg2)
  liftIO (writeIORef s qset)
  qset <- do
    arg0 <- do
      arg0 <- pure 9
      liftIO (character arg0)
    arg1 <- do
      arg0 <- liftIO haskellBackslash
      arg1 <- pure "t"
      liftIO (stringConcatenate arg0 arg1)
    arg2 <- liftIO (readIORef s)
    liftIO (stringReplace arg0 arg1 arg2)
  liftIO (writeIORef s qset)
  hret <- liftIO (readIORef s)
  qreturn hret
  pure ""

haskellSafeNameString :: String -> IO (String)
haskellSafeNameString name_arg = evalContT $ callCC $ \qreturn -> do
  name <- liftIO (newIORef name_arg)
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "case"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "caseValue"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "class"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "classValue"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "data"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "dataValue"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "default"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "defaultValue"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "deriving"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "derivingValue"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "do"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "doValue"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "else"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "elseValue"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "foreign"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "foreignValue"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "if"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "ifValue"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "import"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "importValue"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "in"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "inValue"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "infix"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "infixValue"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "infixl"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "infixlValue"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "infixr"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "infixrValue"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "instance"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "instanceValue"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "let"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "letValue"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "module"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "moduleValue"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "newtype"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "newtypeValue"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "of"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "ofValue"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "then"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "thenValue"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "type"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "typeValue"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "where"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "whereValue"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "id"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "qid"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "old"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "oldValue"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "new"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "newValue"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "-"
    liftIO (haskellStringStartsWith arg0 arg1)
  if hcond
    then do
      hret <- liftIO (readIORef name)
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "StringListJoinRec"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "stringListJoinRec"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "StringListJoin"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "stringListJoin"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "ListToBoxString"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "listToBoxString"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "ListToString"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "listToString"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "StackTraceMove"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "stackTraceMove"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "StackTracePrint"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "stackTracePrint"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "StackTracePrintHelper"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "stackTracePrintHelper"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "NoStackTrace_list"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "noStackTrace_list"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "NoTrace_list"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "noTrace_list"
      qreturn hret
      pure ()
    else do
      pure ()
  qset <- do
    arg0 <- pure "-"
    arg1 <- pure "_"
    arg2 <- liftIO (readIORef name)
    liftIO (stringReplace arg0 arg1 arg2)
  liftIO (writeIORef name qset)
  qset <- do
    arg0 <- pure "?"
    arg1 <- pure "_q"
    arg2 <- liftIO (readIORef name)
    liftIO (stringReplace arg0 arg1 arg2)
  liftIO (writeIORef name qset)
  qset <- do
    arg0 <- pure "!"
    arg1 <- pure "_bang"
    arg2 <- liftIO (readIORef name)
    liftIO (stringReplace arg0 arg1 arg2)
  liftIO (writeIORef name qset)
  hret <- liftIO (readIORef name)
  qreturn hret
  pure ""

haskellSafeName :: Maybe Box -> IO (Maybe Box)
haskellSafeName aSym_arg = evalContT $ callCC $ \qreturn -> do
  aSym <- liftIO (newIORef aSym_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef aSym)
        liftIO (stringify arg0)
      liftIO (haskellSafeNameString arg0)
    liftIO (boxSymbol arg0)
  qreturn hret
  pure Nothing

haskellFieldName :: Maybe Box -> IO (String)
haskellFieldName aSym_arg = evalContT $ callCC $ \qreturn -> do
  aSym <- liftIO (newIORef aSym_arg)
  hret <- do
    arg0 <- pure "qf_"
    arg1 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef aSym)
        liftIO (stringify arg0)
      liftIO (haskellSafeNameString arg0)
    liftIO (stringConcatenate arg0 arg1)
  qreturn hret
  pure ""

haskellNewName :: Maybe Box -> IO (String)
haskellNewName aSym_arg = evalContT $ callCC $ \qreturn -> do
  aSym <- liftIO (newIORef aSym_arg)
  hret <- do
    arg0 <- pure "new"
    arg1 <- do
      arg0 <- liftIO (readIORef aSym)
      liftIO (stringify arg0)
    liftIO (stringConcatenate arg0 arg1)
  qreturn hret
  pure ""

haskellStringEndsWith :: String -> String -> IO (Bool)
haskellStringEndsWith s_arg suffix_arg = evalContT $ callCC $ \qreturn -> do
  s <- liftIO (newIORef s_arg)
  suffix <- liftIO (newIORef suffix_arg)
  qinit <- pure 0
  start <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef suffix)
      liftIO (string_length arg0)
    arg1 <- do
      arg0 <- liftIO (readIORef s)
      liftIO (string_length arg0)
    liftIO (greaterthan arg0 arg1)
  if hcond
    then do
      hret <- pure False
      qreturn hret
      pure ()
    else do
      qset <- do
        arg0 <- do
          arg0 <- liftIO (readIORef s)
          liftIO (string_length arg0)
        arg1 <- do
          arg0 <- liftIO (readIORef suffix)
          liftIO (string_length arg0)
        liftIO (sub arg0 arg1)
      liftIO (writeIORef start qset)
      hret <- do
        arg0 <- do
          arg0 <- liftIO (readIORef s)
          arg1 <- liftIO (readIORef start)
          arg2 <- do
            arg0 <- liftIO (readIORef suffix)
            liftIO (string_length arg0)
          liftIO (sub_string arg0 arg1 arg2)
        arg1 <- liftIO (readIORef suffix)
        liftIO (equalString arg0 arg1)
      qreturn hret
      pure ()
  pure False

haskellStringStartsWith :: String -> String -> IO (Bool)
haskellStringStartsWith s_arg prefix_arg = evalContT $ callCC $ \qreturn -> do
  s <- liftIO (newIORef s_arg)
  prefix <- liftIO (newIORef prefix_arg)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef prefix)
      liftIO (string_length arg0)
    arg1 <- do
      arg0 <- liftIO (readIORef s)
      liftIO (string_length arg0)
    liftIO (greaterthan arg0 arg1)
  if hcond
    then do
      hret <- pure False
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- liftIO (readIORef s)
          arg1 <- pure 0
          arg2 <- do
            arg0 <- liftIO (readIORef prefix)
            liftIO (string_length arg0)
          liftIO (sub_string arg0 arg1 arg2)
        arg1 <- liftIO (readIORef prefix)
        liftIO (equalString arg0 arg1)
      qreturn hret
      pure ()
  pure False

haskellPointerBase :: Maybe Box -> IO (Maybe Box)
haskellPointerBase aSym_arg = evalContT $ callCC $ \qreturn -> do
  aSym <- liftIO (newIORef aSym_arg)
  qinit <- pure ""
  name <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef aSym)
    liftIO (stringify arg0)
  liftIO (writeIORef name qset)
  hcond <- do
    arg0 <- liftIO (readIORef name)
    arg1 <- pure "*"
    liftIO (haskellStringEndsWith arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- liftIO (readIORef name)
          arg1 <- pure 0
          arg2 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef name)
              liftIO (string_length arg0)
            liftIO (sub1 arg0)
          liftIO (sub_string arg0 arg1 arg2)
        liftIO (boxSymbol arg0)
      qreturn hret
      pure ()
    else do
      hret <- liftIO (readIORef aSym)
      qreturn hret
      pure ()
  pure Nothing

haskellTypeIsPointer :: Maybe Box -> IO (Bool)
haskellTypeIsPointer aSym_arg = evalContT $ callCC $ \qreturn -> do
  aSym <- liftIO (newIORef aSym_arg)
  qinit <- pure ""
  mapped <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- do
      arg0 <- liftIO (readIORef aSym)
      liftIO (haskellTypeMap arg0)
    liftIO (stringify arg0)
  liftIO (writeIORef mapped qset)
  hret <- do
    arg0 <- liftIO (readIORef mapped)
    arg1 <- pure "Maybe "
    liftIO (haskellStringStartsWith arg0 arg1)
  qreturn hret
  pure False

haskellTypeMap :: Maybe Box -> IO (Maybe Box)
haskellTypeMap aSym_arg = evalContT $ callCC $ \qreturn -> do
  aSym <- liftIO (newIORef aSym_arg)
  qinit <- pure Nothing
  symMap <- liftIO (newIORef qinit)
  qinit <- pure ""
  name <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- do
      arg0 <- pure "pair"
      liftIO (boxSymbol arg0)
    arg1 <- do
      arg0 <- pure "Maybe Box"
      liftIO (boxSymbol arg0)
    arg2 <- do
      arg0 <- do
        arg0 <- pure "box"
        liftIO (boxSymbol arg0)
      arg1 <- do
        arg0 <- pure "Maybe Box"
        liftIO (boxSymbol arg0)
      arg2 <- do
        arg0 <- do
          arg0 <- pure "list"
          liftIO (boxSymbol arg0)
        arg1 <- do
          arg0 <- pure "Maybe Box"
          liftIO (boxSymbol arg0)
        arg2 <- do
          arg0 <- do
            arg0 <- pure "Box*"
            liftIO (boxSymbol arg0)
          arg1 <- do
            arg0 <- pure "Maybe Box"
            liftIO (boxSymbol arg0)
          arg2 <- do
            arg0 <- do
              arg0 <- pure "Pair"
              liftIO (boxSymbol arg0)
            arg1 <- do
              arg0 <- pure "Box"
              liftIO (boxSymbol arg0)
            arg2 <- do
              arg0 <- do
                arg0 <- pure "struct"
                liftIO (boxSymbol arg0)
              arg1 <- do
                arg0 <- pure ""
                liftIO (boxSymbol arg0)
              arg2 <- do
                arg0 <- do
                  arg0 <- pure "bool"
                  liftIO (boxSymbol arg0)
                arg1 <- do
                  arg0 <- pure "Bool"
                  liftIO (boxSymbol arg0)
                arg2 <- do
                  arg0 <- do
                    arg0 <- pure "uint"
                    liftIO (boxSymbol arg0)
                  arg1 <- do
                    arg0 <- pure "Int"
                    liftIO (boxSymbol arg0)
                  arg2 <- do
                    arg0 <- do
                      arg0 <- pure "int"
                      liftIO (boxSymbol arg0)
                    arg1 <- do
                      arg0 <- pure "Int"
                      liftIO (boxSymbol arg0)
                    arg2 <- do
                      arg0 <- do
                        arg0 <- pure "float"
                        liftIO (boxSymbol arg0)
                      arg1 <- do
                        arg0 <- pure "Double"
                        liftIO (boxSymbol arg0)
                      arg2 <- do
                        arg0 <- do
                          arg0 <- pure "void"
                          liftIO (boxSymbol arg0)
                        arg1 <- do
                          arg0 <- pure "()"
                          liftIO (boxSymbol arg0)
                        arg2 <- do
                          arg0 <- do
                            arg0 <- pure "stringArray"
                            liftIO (boxSymbol arg0)
                          arg1 <- do
                            arg0 <- pure "[String]"
                            liftIO (boxSymbol arg0)
                          arg2 <- do
                            arg0 <- do
                              arg0 <- pure "array"
                              liftIO (boxSymbol arg0)
                            arg1 <- do
                              arg0 <- pure "[String]"
                              liftIO (boxSymbol arg0)
                            arg2 <- do
                              arg0 <- do
                                arg0 <- pure "hashmap"
                                liftIO (boxSymbol arg0)
                              arg1 <- do
                                arg0 <- pure "IORef [(String, String)]"
                                liftIO (boxSymbol arg0)
                              arg2 <- do
                                arg0 <- do
                                  arg0 <- pure "string"
                                  liftIO (boxSymbol arg0)
                                arg1 <- do
                                  arg0 <- pure "String"
                                  liftIO (boxSymbol arg0)
                                arg2 <- pure Nothing
                                liftIO (alistCons arg0 arg1 arg2)
                              liftIO (alistCons arg0 arg1 arg2)
                            liftIO (alistCons arg0 arg1 arg2)
                          liftIO (alistCons arg0 arg1 arg2)
                        liftIO (alistCons arg0 arg1 arg2)
                      liftIO (alistCons arg0 arg1 arg2)
                    liftIO (alistCons arg0 arg1 arg2)
                  liftIO (alistCons arg0 arg1 arg2)
                liftIO (alistCons arg0 arg1 arg2)
              liftIO (alistCons arg0 arg1 arg2)
            liftIO (alistCons arg0 arg1 arg2)
          liftIO (alistCons arg0 arg1 arg2)
        liftIO (alistCons arg0 arg1 arg2)
      liftIO (alistCons arg0 arg1 arg2)
    liftIO (alistCons arg0 arg1 arg2)
  liftIO (writeIORef symMap qset)
  hcond <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef aSym)
        liftIO (stringify arg0)
      arg1 <- liftIO (readIORef symMap)
      liftIO (assoc arg0 arg1)
    liftIO (truthy arg0)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef aSym)
            liftIO (stringify arg0)
          arg1 <- liftIO (readIORef symMap)
          liftIO (assoc arg0 arg1)
        liftIO (cdr arg0)
      qreturn hret
      pure ()
    else do
      qset <- do
        arg0 <- liftIO (readIORef aSym)
        liftIO (stringify arg0)
      liftIO (writeIORef name qset)
      hcond <- do
        arg0 <- liftIO (readIORef name)
        arg1 <- pure "*"
        liftIO (haskellStringEndsWith arg0 arg1)
      if hcond
        then do
          hret <- do
            arg0 <- do
              arg0 <- pure "Maybe "
              arg1 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef aSym)
                  liftIO (haskellPointerBase arg0)
                liftIO (stringify arg0)
              liftIO (stringConcatenate arg0 arg1)
            liftIO (boxSymbol arg0)
          qreturn hret
          pure ()
        else do
          hret <- liftIO (readIORef aSym)
          qreturn hret
          pure ()
      pure ()
  pure Nothing

haskellDefaultValue :: Maybe Box -> IO (String)
haskellDefaultValue typeSym_arg = evalContT $ callCC $ \qreturn -> do
  typeSym <- liftIO (newIORef typeSym_arg)
  qinit <- pure ""
  typ <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- do
      arg0 <- liftIO (readIORef typeSym)
      liftIO (haskellTypeMap arg0)
    liftIO (stringify arg0)
  liftIO (writeIORef typ qset)
  hcond <- do
    arg0 <- liftIO (readIORef typ)
    arg1 <- pure "()"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "()"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef typ)
    arg1 <- pure "Bool"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "False"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef typ)
    arg1 <- pure "Int"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "0"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef typ)
    arg1 <- pure "Double"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "0.0"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef typ)
    arg1 <- pure "String"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "\"\""
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef typ)
    arg1 <- pure "[String]"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "[]"
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef typ)
    arg1 <- pure "Maybe "
    liftIO (haskellStringStartsWith arg0 arg1)
  if hcond
    then do
      hret <- pure "Nothing"
      qreturn hret
      pure ()
    else do
      pure ()
  hret <- do
    arg0 <- pure "(error \"no default value for "
    arg1 <- do
      arg0 <- liftIO (readIORef typ)
      arg1 <- pure "\")"
      liftIO (stringConcatenate arg0 arg1)
    liftIO (stringConcatenate arg0 arg1)
  qreturn hret
  pure ""

haskellRefType :: Maybe Box -> IO (String)
haskellRefType typeSym_arg = evalContT $ callCC $ \qreturn -> do
  typeSym <- liftIO (newIORef typeSym_arg)
  hret <- do
    arg0 <- pure "("
    arg1 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- liftIO (readIORef typeSym)
          liftIO (haskellTypeMap arg0)
        liftIO (stringify arg0)
      arg1 <- pure ")"
      liftIO (stringConcatenate arg0 arg1)
    liftIO (stringConcatenate arg0 arg1)
  qreturn hret
  pure ""

haskellGlobalVariables :: IO (Maybe Box)
haskellGlobalVariables = evalContT $ callCC $ \qreturn -> do
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- pure "globalArgsCount"
        liftIO (boxSymbol arg0)
      liftIO (qid arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- pure "globalArgs"
          liftIO (boxSymbol arg0)
        liftIO (qid arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- pure "releaseMode"
            liftIO (boxSymbol arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- pure "caller"
              liftIO (boxSymbol arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- pure "globalTrace"
                liftIO (boxSymbol arg0)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- pure "globalStepTrace"
                  liftIO (boxSymbol arg0)
                liftIO (qid arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- pure "globalStackTrace"
                    liftIO (boxSymbol arg0)
                  liftIO (qid arg0)
                arg1 <- pure Nothing
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

haskellCollectVariablesFromArgs :: Maybe Box -> IO (Maybe Box)
haskellCollectVariablesFromArgs args_arg = evalContT $ callCC $ \qreturn -> do
  args <- liftIO (newIORef args_arg)
  qinit <- pure Nothing
  variables <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef args)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- liftIO (readIORef variables)
      qreturn hret
      pure ()
    else do
      qset <- do
        arg0 <- do
          arg0 <- liftIO (readIORef args)
          liftIO (second arg0)
        arg1 <- liftIO (readIORef variables)
        liftIO (cons arg0 arg1)
      liftIO (writeIORef variables qset)
      hret <- do
        arg0 <- liftIO (readIORef variables)
        arg1 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef args)
            liftIO (cddr arg0)
          liftIO (haskellCollectVariablesFromArgs arg0)
        liftIO (appendVariables arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

haskellCollectVariablesFromDecls :: Maybe Box -> IO (Maybe Box)
haskellCollectVariablesFromDecls decls_arg = evalContT $ callCC $ \qreturn -> do
  decls <- liftIO (newIORef decls_arg)
  qinit <- pure Nothing
  variables <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  decl <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef decls)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- liftIO (readIORef variables)
      qreturn hret
      pure ()
    else do
      qset <- do
        arg0 <- liftIO (readIORef decls)
        liftIO (car arg0)
      liftIO (writeIORef decl qset)
      qset <- do
        arg0 <- do
          arg0 <- liftIO (readIORef decl)
          liftIO (second arg0)
        arg1 <- liftIO (readIORef variables)
        liftIO (cons arg0 arg1)
      liftIO (writeIORef variables qset)
      hret <- do
        arg0 <- liftIO (readIORef variables)
        arg1 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef decls)
            liftIO (cdr arg0)
          liftIO (haskellCollectVariablesFromDecls arg0)
        liftIO (appendVariables arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

haskellCollectVariables :: Maybe Box -> Maybe Box -> IO (Maybe Box)
haskellCollectVariables args_arg decls_arg = evalContT $ callCC $ \qreturn -> do
  args <- liftIO (newIORef args_arg)
  decls <- liftIO (newIORef decls_arg)
  qinit <- pure Nothing
  variables <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef args)
    liftIO (haskellCollectVariablesFromArgs arg0)
  liftIO (writeIORef variables qset)
  qset <- do
    arg0 <- liftIO (readIORef variables)
    arg1 <- do
      arg0 <- liftIO (readIORef decls)
      liftIO (haskellCollectVariablesFromDecls arg0)
    liftIO (appendVariables arg0 arg1)
  liftIO (writeIORef variables qset)
  qset <- do
    arg0 <- liftIO (readIORef variables)
    arg1 <- liftIO haskellGlobalVariables
    liftIO (appendVariables arg0 arg1)
  liftIO (writeIORef variables qset)
  hret <- liftIO (readIORef variables)
  qreturn hret
  pure Nothing

haskellFuncMap :: Maybe Box -> Maybe Box -> IO (Maybe Box)
haskellFuncMap aSym_arg variables_arg = evalContT $ callCC $ \qreturn -> do
  aSym <- liftIO (newIORef aSym_arg)
  variables <- liftIO (newIORef variables_arg)
  qinit <- pure Nothing
  symMap <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- do
      arg0 <- pure "symbol"
      arg1 <- do
        arg0 <- liftIO (readIORef aSym)
        liftIO (boxType arg0)
      liftIO (equalString arg0 arg1)
    arg1 <- do
      arg0 <- pure "string"
      arg1 <- do
        arg0 <- liftIO (readIORef aSym)
        liftIO (boxType arg0)
      liftIO (equalString arg0 arg1)
    liftIO (orBool arg0 arg1)
  if hcond
    then do
      hcond <- do
        arg0 <- liftIO (readIORef aSym)
        arg1 <- liftIO (readIORef variables)
        liftIO (inList arg0 arg1)
      if hcond
        then do
          hret <- do
            arg0 <- liftIO (readIORef aSym)
            liftIO (haskellSafeName arg0)
          qreturn hret
          pure ()
        else do
          qset <- do
            arg0 <- do
              arg0 <- pure "="
              liftIO (boxSymbol arg0)
            arg1 <- do
              arg0 <- pure "equal"
              liftIO (boxSymbol arg0)
            arg2 <- do
              arg0 <- do
                arg0 <- pure "sub-string"
                liftIO (boxSymbol arg0)
              arg1 <- do
                arg0 <- pure "sub_string"
                liftIO (boxSymbol arg0)
              arg2 <- do
                arg0 <- do
                  arg0 <- pure "read-file"
                  liftIO (boxSymbol arg0)
                arg1 <- do
                  arg0 <- pure "read_file"
                  liftIO (boxSymbol arg0)
                arg2 <- do
                  arg0 <- do
                    arg0 <- pure "write-file"
                    liftIO (boxSymbol arg0)
                  arg1 <- do
                    arg0 <- pure "write_file"
                    liftIO (boxSymbol arg0)
                  arg2 <- do
                    arg0 <- do
                      arg0 <- pure ">"
                      liftIO (boxSymbol arg0)
                    arg1 <- do
                      arg0 <- pure "greaterthan"
                      liftIO (boxSymbol arg0)
                    arg2 <- do
                      arg0 <- do
                        arg0 <- pure "string-length"
                        liftIO (boxSymbol arg0)
                      arg1 <- do
                        arg0 <- pure "string_length"
                        liftIO (boxSymbol arg0)
                      arg2 <- do
                        arg0 <- do
                          arg0 <- pure "nil"
                          liftIO (boxSymbol arg0)
                        arg1 <- do
                          arg0 <- pure "Nothing"
                          liftIO (boxSymbol arg0)
                        arg2 <- do
                          arg0 <- do
                            arg0 <- pure "true"
                            liftIO (boxSymbol arg0)
                          arg1 <- do
                            arg0 <- pure "True"
                            liftIO (boxSymbol arg0)
                          arg2 <- do
                            arg0 <- do
                              arg0 <- pure "false"
                              liftIO (boxSymbol arg0)
                            arg1 <- do
                              arg0 <- pure "False"
                              liftIO (boxSymbol arg0)
                            arg2 <- do
                              arg0 <- do
                                arg0 <- pure "old"
                                liftIO (boxSymbol arg0)
                              arg1 <- do
                                arg0 <- pure "oldValue"
                                liftIO (boxSymbol arg0)
                              arg2 <- do
                                arg0 <- do
                                  arg0 <- pure "new"
                                  liftIO (boxSymbol arg0)
                                arg1 <- do
                                  arg0 <- pure "newValue"
                                  liftIO (boxSymbol arg0)
                                arg2 <- pure Nothing
                                liftIO (alistCons arg0 arg1 arg2)
                              liftIO (alistCons arg0 arg1 arg2)
                            liftIO (alistCons arg0 arg1 arg2)
                          liftIO (alistCons arg0 arg1 arg2)
                        liftIO (alistCons arg0 arg1 arg2)
                      liftIO (alistCons arg0 arg1 arg2)
                    liftIO (alistCons arg0 arg1 arg2)
                  liftIO (alistCons arg0 arg1 arg2)
                liftIO (alistCons arg0 arg1 arg2)
              liftIO (alistCons arg0 arg1 arg2)
            liftIO (alistCons arg0 arg1 arg2)
          liftIO (writeIORef symMap qset)
          hcond <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef aSym)
                liftIO (stringify arg0)
              arg1 <- liftIO (readIORef symMap)
              liftIO (assoc arg0 arg1)
            liftIO (truthy arg0)
          if hcond
            then do
              hret <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef aSym)
                    liftIO (stringify arg0)
                  arg1 <- liftIO (readIORef symMap)
                  liftIO (assoc arg0 arg1)
                liftIO (cdr arg0)
              qreturn hret
              pure ()
            else do
              hret <- do
                arg0 <- liftIO (readIORef aSym)
                liftIO (haskellSafeName arg0)
              qreturn hret
              pure ()
          pure ()
      pure ()
    else do
      hret <- liftIO (readIORef aSym)
      qreturn hret
      pure ()
  pure Nothing

haskellNumberAtom :: Maybe Box -> IO (Maybe Box)
haskellNumberAtom tree_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  qinit <- pure ""
  val <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (stringify arg0)
  liftIO (writeIORef val qset)
  hcond <- do
    arg0 <- liftIO (readIORef val)
    arg1 <- pure "-"
    liftIO (haskellStringStartsWith arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- pure "pure ("
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef val)
              liftIO (boxString arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure ")"
              liftIO (boxString arg0)
            arg1 <- pure Nothing
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- pure "pure "
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef val)
              liftIO (boxString arg0)
            liftIO (qid arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

haskellAtom :: Maybe Box -> Maybe Box -> IO (Maybe Box)
haskellAtom tree_arg variables_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  variables <- liftIO (newIORef variables_arg)
  hcond <- do
    arg0 <- pure "int"
    arg1 <- do
      arg0 <- liftIO (readIORef tree)
      liftIO (boxType arg0)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- liftIO (readIORef tree)
        liftIO (haskellNumberAtom arg0)
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- pure "float"
        arg1 <- do
          arg0 <- liftIO (readIORef tree)
          liftIO (boxType arg0)
        liftIO (equalString arg0 arg1)
      if hcond
        then do
          hret <- do
            arg0 <- liftIO (readIORef tree)
            liftIO (haskellNumberAtom arg0)
          qreturn hret
          pure ()
        else do
          hcond <- do
            arg0 <- pure "string"
            arg1 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (boxType arg0)
            liftIO (equalString arg0 arg1)
          if hcond
            then do
              hret <- do
                arg0 <- do
                  arg0 <- pure "pure \""
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef tree)
                          liftIO (stringify arg0)
                        liftIO (haskellEscapeString arg0)
                      liftIO (boxString arg0)
                    liftIO (qid arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- pure "\""
                      liftIO (boxString arg0)
                    arg1 <- pure Nothing
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
            else do
              hcond <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef tree)
                  liftIO (stringify arg0)
                liftIO (isInt arg0)
              if hcond
                then do
                  hret <- do
                    arg0 <- liftIO (readIORef tree)
                    liftIO (haskellNumberAtom arg0)
                  qreturn hret
                  pure ()
                else do
                  hcond <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef tree)
                      liftIO (stringify arg0)
                    liftIO (isFloat arg0)
                  if hcond
                    then do
                      hret <- do
                        arg0 <- liftIO (readIORef tree)
                        liftIO (haskellNumberAtom arg0)
                      qreturn hret
                      pure ()
                    else do
                      hcond <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef tree)
                          liftIO (stringify arg0)
                        arg1 <- pure "-"
                        liftIO (haskellStringStartsWith arg0 arg1)
                      if hcond
                        then do
                          hret <- do
                            arg0 <- do
                              arg0 <- pure "pure ("
                              liftIO (boxString arg0)
                            arg1 <- do
                              arg0 <- do
                                arg0 <- do
                                  arg0 <- liftIO (readIORef tree)
                                  arg1 <- liftIO (readIORef variables)
                                  liftIO (haskellFuncMap arg0 arg1)
                                liftIO (qid arg0)
                              arg1 <- do
                                arg0 <- do
                                  arg0 <- pure ")"
                                  liftIO (boxString arg0)
                                arg1 <- pure Nothing
                                liftIO (cons arg0 arg1)
                              liftIO (cons arg0 arg1)
                            liftIO (cons arg0 arg1)
                          qreturn hret
                          pure ()
                        else do
                          hcond <- do
                            arg0 <- liftIO (readIORef tree)
                            arg1 <- liftIO (readIORef variables)
                            liftIO (inList arg0 arg1)
                          if hcond
                            then do
                              hret <- do
                                arg0 <- do
                                  arg0 <- pure "liftIO (readIORef "
                                  liftIO (boxString arg0)
                                arg1 <- do
                                  arg0 <- do
                                    arg0 <- do
                                      arg0 <- liftIO (readIORef tree)
                                      arg1 <- liftIO (readIORef variables)
                                      liftIO (haskellFuncMap arg0 arg1)
                                    liftIO (qid arg0)
                                  arg1 <- do
                                    arg0 <- do
                                      arg0 <- pure ")"
                                      liftIO (boxString arg0)
                                    arg1 <- pure Nothing
                                    liftIO (cons arg0 arg1)
                                  liftIO (cons arg0 arg1)
                                liftIO (cons arg0 arg1)
                              qreturn hret
                              pure ()
                            else do
                              hret <- do
                                arg0 <- do
                                  arg0 <- pure "pure "
                                  liftIO (boxString arg0)
                                arg1 <- do
                                  arg0 <- do
                                    arg0 <- do
                                      arg0 <- liftIO (readIORef tree)
                                      arg1 <- liftIO (readIORef variables)
                                      liftIO (haskellFuncMap arg0 arg1)
                                    liftIO (qid arg0)
                                  arg1 <- pure Nothing
                                  liftIO (cons arg0 arg1)
                                liftIO (cons arg0 arg1)
                              qreturn hret
                              pure ()
                          pure ()
                      pure ()
                  pure ()
              pure ()
          pure ()
      pure ()
  pure Nothing

haskellArgNames :: Maybe Box -> Int -> IO (Maybe Box)
haskellArgNames expr_arg pos_arg = evalContT $ callCC $ \qreturn -> do
  expr <- liftIO (newIORef expr_arg)
  pos <- liftIO (newIORef pos_arg)
  hcond <- do
    arg0 <- liftIO (readIORef expr)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- do
          arg0 <- liftIO (readIORef expr)
          liftIO (cdr arg0)
        liftIO (isNil arg0)
      if hcond
        then do
          hret <- do
            arg0 <- do
              arg0 <- pure " arg"
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef pos)
                    liftIO (intToString arg0)
                  liftIO (boxString arg0)
                liftIO (qid arg0)
              arg1 <- pure Nothing
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          qreturn hret
          pure ()
        else do
          hret <- do
            arg0 <- do
              arg0 <- pure " arg"
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef pos)
                    liftIO (intToString arg0)
                  liftIO (boxString arg0)
                liftIO (qid arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef expr)
                      liftIO (cdr arg0)
                    arg1 <- do
                      arg0 <- liftIO (readIORef pos)
                      liftIO (add1 arg0)
                    liftIO (haskellArgNames arg0 arg1)
                  liftIO (qid arg0)
                arg1 <- pure Nothing
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          qreturn hret
          pure ()
      pure ()
  pure Nothing

haskellBindArgs :: Maybe Box -> Int -> Maybe Box -> Int -> IO (Maybe Box)
haskellBindArgs expr_arg indent_arg variables_arg pos_arg = evalContT $ callCC $ \qreturn -> do
  expr <- liftIO (newIORef expr_arg)
  indent <- liftIO (newIORef indent_arg)
  variables <- liftIO (newIORef variables_arg)
  pos <- liftIO (newIORef pos_arg)
  hcond <- do
    arg0 <- liftIO (readIORef expr)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef indent)
            liftIO (listNewLine arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "arg"
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef pos)
                  liftIO (intToString arg0)
                liftIO (boxString arg0)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure " <- "
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef expr)
                      liftIO (car arg0)
                    arg1 <- liftIO (readIORef indent)
                    arg2 <- liftIO (readIORef variables)
                    liftIO (haskellExpression arg0 arg1 arg2)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef expr)
                        liftIO (cdr arg0)
                      arg1 <- liftIO (readIORef indent)
                      arg2 <- liftIO (readIORef variables)
                      arg3 <- do
                        arg0 <- liftIO (readIORef pos)
                        liftIO (add1 arg0)
                      liftIO (haskellBindArgs arg0 arg1 arg2 arg3)
                    liftIO (qid arg0)
                  arg1 <- pure Nothing
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

haskellCall :: Maybe Box -> Maybe Box -> Int -> Maybe Box -> IO (Maybe Box)
haskellCall name_arg args_arg indent_arg variables_arg = evalContT $ callCC $ \qreturn -> do
  name <- liftIO (newIORef name_arg)
  args <- liftIO (newIORef args_arg)
  indent <- liftIO (newIORef indent_arg)
  variables <- liftIO (newIORef variables_arg)
  hcond <- do
    arg0 <- liftIO (readIORef args)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- pure "liftIO "
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef name)
              arg1 <- pure Nothing
              liftIO (haskellFuncMap arg0 arg1)
            liftIO (qid arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- pure "do"
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef args)
              arg1 <- do
                arg0 <- liftIO (readIORef indent)
                liftIO (add1 arg0)
              arg2 <- liftIO (readIORef variables)
              arg3 <- pure 0
              liftIO (haskellBindArgs arg0 arg1 arg2 arg3)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef indent)
                  liftIO (add1 arg0)
                liftIO (listNewLine arg0)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure "liftIO ("
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef name)
                    arg1 <- pure Nothing
                    liftIO (haskellFuncMap arg0 arg1)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef args)
                      arg1 <- pure 0
                      liftIO (haskellArgNames arg0 arg1)
                    liftIO (qid arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- pure ")"
                      liftIO (boxString arg0)
                    arg1 <- pure Nothing
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

haskellBinop :: Maybe Box -> Int -> Maybe Box -> IO (Maybe Box)
haskellBinop tree_arg indent_arg variables_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  indent <- liftIO (newIORef indent_arg)
  variables <- liftIO (newIORef variables_arg)
  hret <- do
    arg0 <- do
      arg0 <- pure "do"
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef indent)
            liftIO (add1 arg0)
          liftIO (listNewLine arg0)
        liftIO (qid arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure "arg0 <- "
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (third arg0)
              arg1 <- do
                arg0 <- liftIO (readIORef indent)
                liftIO (add1 arg0)
              arg2 <- liftIO (readIORef variables)
              liftIO (haskellExpression arg0 arg1 arg2)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef indent)
                  liftIO (add1 arg0)
                liftIO (listNewLine arg0)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure "arg1 <- "
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef tree)
                      liftIO (fourth arg0)
                    arg1 <- do
                      arg0 <- liftIO (readIORef indent)
                      liftIO (add1 arg0)
                    arg2 <- liftIO (readIORef variables)
                    liftIO (haskellExpression arg0 arg1 arg2)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef indent)
                        liftIO (add1 arg0)
                      liftIO (listNewLine arg0)
                    liftIO (qid arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- pure "pure (arg0 "
                      liftIO (boxString arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef tree)
                          liftIO (second arg0)
                        liftIO (qid arg0)
                      arg1 <- do
                        arg0 <- do
                          arg0 <- pure " arg1)"
                          liftIO (boxString arg0)
                        arg1 <- pure Nothing
                        liftIO (cons arg0 arg1)
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

haskellGetStruct :: Maybe Box -> Int -> Maybe Box -> IO (Maybe Box)
haskellGetStruct tree_arg indent_arg variables_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  indent <- liftIO (newIORef indent_arg)
  variables <- liftIO (newIORef variables_arg)
  hret <- do
    arg0 <- do
      arg0 <- pure "do"
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef indent)
            liftIO (add1 arg0)
          liftIO (listNewLine arg0)
        liftIO (qid arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure "hobj <- "
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (second arg0)
              arg1 <- do
                arg0 <- liftIO (readIORef indent)
                liftIO (add1 arg0)
              arg2 <- liftIO (readIORef variables)
              liftIO (haskellExpression arg0 arg1 arg2)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef indent)
                  liftIO (add1 arg0)
                liftIO (listNewLine arg0)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure "liftIO (readIORef ("
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure "getField @\""
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef tree)
                          liftIO (third arg0)
                        liftIO (haskellFieldName arg0)
                      liftIO (boxString arg0)
                    liftIO (qid arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- pure "\" (expect hobj)))"
                      liftIO (boxString arg0)
                    arg1 <- pure Nothing
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

haskellNewExpression :: Maybe Box -> IO (Maybe Box)
haskellNewExpression tree_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef tree)
      liftIO (second arg0)
    liftIO (haskellTypeIsPointer arg0)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- pure "liftIO (Just <$> "
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef tree)
                  liftIO (third arg0)
                liftIO (haskellNewName arg0)
              liftIO (boxString arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure ")"
              liftIO (boxString arg0)
            arg1 <- pure Nothing
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- pure "liftIO "
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef tree)
                  liftIO (third arg0)
                liftIO (haskellNewName arg0)
              liftIO (boxString arg0)
            liftIO (qid arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

haskellExpression :: Maybe Box -> Int -> Maybe Box -> IO (Maybe Box)
haskellExpression tree_arg indent_arg variables_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  indent <- liftIO (newIORef indent_arg)
  variables <- liftIO (newIORef variables_arg)
  qinit <- pure Nothing
  thing <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef tree)
      liftIO (isList arg0)
    liftIO (notBool arg0)
  if hcond
    then do
      hret <- do
        arg0 <- liftIO (readIORef tree)
        arg1 <- liftIO (readIORef variables)
        liftIO (haskellAtom arg0 arg1)
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- pure 1
        arg1 <- do
          arg0 <- liftIO (readIORef tree)
          liftIO (listLength arg0)
        liftIO (equal arg0 arg1)
      if hcond
        then do
          hcond <- do
            arg0 <- do
              arg0 <- pure "return"
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (car arg0)
            liftIO (equalBox arg0 arg1)
          if hcond
            then do
              hret <- do
                arg0 <- do
                  arg0 <- pure "pure "
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef tree)
                        liftIO (car arg0)
                      arg1 <- liftIO (readIORef variables)
                      liftIO (haskellFuncMap arg0 arg1)
                    liftIO (qid arg0)
                  arg1 <- pure Nothing
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
            else do
              hret <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef tree)
                  liftIO (car arg0)
                arg1 <- pure Nothing
                arg2 <- liftIO (readIORef indent)
                arg3 <- liftIO (readIORef variables)
                liftIO (haskellCall arg0 arg1 arg2 arg3)
              qreturn hret
              pure ()
          pure ()
        else do
          qset <- do
            arg0 <- liftIO (readIORef tree)
            liftIO (first arg0)
          liftIO (writeIORef thing qset)
          hcond <- do
            arg0 <- do
              arg0 <- pure "get-struct"
              liftIO (boxSymbol arg0)
            arg1 <- liftIO (readIORef thing)
            liftIO (equalBox arg0 arg1)
          if hcond
            then do
              hret <- do
                arg0 <- liftIO (readIORef tree)
                arg1 <- liftIO (readIORef indent)
                arg2 <- liftIO (readIORef variables)
                liftIO (haskellGetStruct arg0 arg1 arg2)
              qreturn hret
              pure ()
            else do
              hcond <- do
                arg0 <- do
                  arg0 <- pure "new"
                  liftIO (boxSymbol arg0)
                arg1 <- liftIO (readIORef thing)
                liftIO (equalBox arg0 arg1)
              if hcond
                then do
                  hret <- do
                    arg0 <- liftIO (readIORef tree)
                    liftIO (haskellNewExpression arg0)
                  qreturn hret
                  pure ()
                else do
                  hcond <- do
                    arg0 <- do
                      arg0 <- pure "passthrough"
                      liftIO (boxSymbol arg0)
                    arg1 <- liftIO (readIORef thing)
                    liftIO (equalBox arg0 arg1)
                  if hcond
                    then do
                      hret <- do
                        arg0 <- do
                          arg0 <- pure "pure ("
                          liftIO (boxString arg0)
                        arg1 <- do
                          arg0 <- do
                            arg0 <- do
                              arg0 <- liftIO (readIORef tree)
                              liftIO (second arg0)
                            liftIO (qid arg0)
                          arg1 <- do
                            arg0 <- do
                              arg0 <- pure ")"
                              liftIO (boxString arg0)
                            arg1 <- pure Nothing
                            liftIO (cons arg0 arg1)
                          liftIO (cons arg0 arg1)
                        liftIO (cons arg0 arg1)
                      qreturn hret
                      pure ()
                    else do
                      hcond <- do
                        arg0 <- do
                          arg0 <- pure "binop"
                          liftIO (boxSymbol arg0)
                        arg1 <- liftIO (readIORef thing)
                        liftIO (equalBox arg0 arg1)
                      if hcond
                        then do
                          hret <- do
                            arg0 <- liftIO (readIORef tree)
                            arg1 <- liftIO (readIORef indent)
                            arg2 <- liftIO (readIORef variables)
                            liftIO (haskellBinop arg0 arg1 arg2)
                          qreturn hret
                          pure ()
                        else do
                          hret <- do
                            arg0 <- do
                              arg0 <- liftIO (readIORef tree)
                              liftIO (car arg0)
                            arg1 <- do
                              arg0 <- liftIO (readIORef tree)
                              liftIO (cdr arg0)
                            arg2 <- liftIO (readIORef indent)
                            arg3 <- liftIO (readIORef variables)
                            liftIO (haskellCall arg0 arg1 arg2 arg3)
                          qreturn hret
                          pure ()
                      pure ()
                  pure ()
              pure ()
          pure ()
      pure ()
  pure Nothing

haskellSet :: Maybe Box -> Int -> Maybe Box -> IO (Maybe Box)
haskellSet node_arg indent_arg variables_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  indent <- liftIO (newIORef indent_arg)
  variables <- liftIO (newIORef variables_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef indent)
        liftIO (listNewLine arg0)
      liftIO (qid arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "qset <- "
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef node)
              liftIO (third arg0)
            arg1 <- liftIO (readIORef indent)
            arg2 <- liftIO (readIORef variables)
            liftIO (haskellExpression arg0 arg1 arg2)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef indent)
              liftIO (listNewLine arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure "liftIO (writeIORef "
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef node)
                    liftIO (second arg0)
                  arg1 <- liftIO (readIORef variables)
                  liftIO (haskellFuncMap arg0 arg1)
                liftIO (qid arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure " qset)"
                  liftIO (boxString arg0)
                arg1 <- pure Nothing
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

haskellSetStruct :: Maybe Box -> Int -> Maybe Box -> IO (Maybe Box)
haskellSetStruct node_arg indent_arg variables_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  indent <- liftIO (newIORef indent_arg)
  variables <- liftIO (newIORef variables_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef indent)
        liftIO (listNewLine arg0)
      liftIO (qid arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "hobj <- "
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef node)
              liftIO (second arg0)
            arg1 <- liftIO (readIORef indent)
            arg2 <- liftIO (readIORef variables)
            liftIO (haskellExpression arg0 arg1 arg2)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef indent)
              liftIO (listNewLine arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure "qset <- "
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef node)
                    liftIO (fourth arg0)
                  arg1 <- liftIO (readIORef indent)
                  arg2 <- liftIO (readIORef variables)
                  liftIO (haskellExpression arg0 arg1 arg2)
                liftIO (qid arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef indent)
                    liftIO (listNewLine arg0)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure "liftIO (writeIORef ("
                    liftIO (boxString arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- pure "getField @\""
                      liftIO (boxString arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- do
                            arg0 <- do
                              arg0 <- liftIO (readIORef node)
                              liftIO (third arg0)
                            liftIO (haskellFieldName arg0)
                          liftIO (boxString arg0)
                        liftIO (qid arg0)
                      arg1 <- do
                        arg0 <- do
                          arg0 <- pure "\" (expect hobj)) qset)"
                          liftIO (boxString arg0)
                        arg1 <- pure Nothing
                        liftIO (cons arg0 arg1)
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

haskellReturn :: Maybe Box -> Int -> Maybe Box -> IO (Maybe Box)
haskellReturn node_arg indent_arg variables_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  indent <- liftIO (newIORef indent_arg)
  variables <- liftIO (newIORef variables_arg)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef node)
      liftIO (listLength arg0)
    arg1 <- pure 1
    liftIO (greaterthan arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef indent)
            liftIO (listNewLine arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "hret <- "
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef node)
                  liftIO (cadr arg0)
                arg1 <- liftIO (readIORef indent)
                arg2 <- liftIO (readIORef variables)
                liftIO (haskellExpression arg0 arg1 arg2)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef indent)
                  liftIO (listNewLine arg0)
                liftIO (qid arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure "qreturn hret"
                  liftIO (boxString arg0)
                arg1 <- pure Nothing
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef indent)
            liftIO (listNewLine arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "qreturn ()"
            liftIO (boxString arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

haskellIf :: Maybe Box -> Int -> Maybe Box -> IO (Maybe Box)
haskellIf node_arg indent_arg variables_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  indent <- liftIO (newIORef indent_arg)
  variables <- liftIO (newIORef variables_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef indent)
        liftIO (listNewLine arg0)
      liftIO (qid arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "hcond <- "
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef node)
              liftIO (second arg0)
            arg1 <- liftIO (readIORef indent)
            arg2 <- liftIO (readIORef variables)
            liftIO (haskellExpression arg0 arg1 arg2)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef indent)
              liftIO (listNewLine arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure "if hcond"
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef indent)
                  liftIO (listNewLine arg0)
                liftIO (qid arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure "  then do"
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef node)
                          liftIO (third arg0)
                        liftIO (cdr arg0)
                      arg1 <- do
                        arg0 <- liftIO (readIORef indent)
                        arg1 <- pure 2
                        liftIO (add arg0 arg1)
                      arg2 <- liftIO (readIORef variables)
                      liftIO (haskellBody arg0 arg1 arg2)
                    liftIO (qid arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef indent)
                          arg1 <- pure 2
                          liftIO (add arg0 arg1)
                        liftIO (listNewLine arg0)
                      liftIO (qid arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- pure "pure ()"
                        liftIO (boxString arg0)
                      arg1 <- do
                        arg0 <- do
                          arg0 <- do
                            arg0 <- liftIO (readIORef indent)
                            liftIO (listNewLine arg0)
                          liftIO (qid arg0)
                        arg1 <- do
                          arg0 <- do
                            arg0 <- pure "  else do"
                            liftIO (boxString arg0)
                          arg1 <- do
                            arg0 <- do
                              arg0 <- do
                                arg0 <- do
                                  arg0 <- do
                                    arg0 <- liftIO (readIORef node)
                                    liftIO (fourth arg0)
                                  liftIO (cdr arg0)
                                arg1 <- do
                                  arg0 <- liftIO (readIORef indent)
                                  arg1 <- pure 2
                                  liftIO (add arg0 arg1)
                                arg2 <- liftIO (readIORef variables)
                                liftIO (haskellBody arg0 arg1 arg2)
                              liftIO (qid arg0)
                            arg1 <- do
                              arg0 <- do
                                arg0 <- do
                                  arg0 <- do
                                    arg0 <- liftIO (readIORef indent)
                                    arg1 <- pure 2
                                    liftIO (add arg0 arg1)
                                  liftIO (listNewLine arg0)
                                liftIO (qid arg0)
                              arg1 <- do
                                arg0 <- do
                                  arg0 <- pure "pure ()"
                                  liftIO (boxString arg0)
                                arg1 <- pure Nothing
                                liftIO (cons arg0 arg1)
                              liftIO (cons arg0 arg1)
                            liftIO (cons arg0 arg1)
                          liftIO (cons arg0 arg1)
                        liftIO (cons arg0 arg1)
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

haskellStatement :: Maybe Box -> Int -> Maybe Box -> IO (Maybe Box)
haskellStatement node_arg indent_arg variables_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  indent <- liftIO (newIORef indent_arg)
  variables <- liftIO (newIORef variables_arg)
  hcond <- do
    arg0 <- do
      arg0 <- pure "set"
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- liftIO (readIORef node)
      liftIO (first arg0)
    liftIO (equalBox arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- liftIO (readIORef node)
        arg1 <- liftIO (readIORef indent)
        arg2 <- liftIO (readIORef variables)
        liftIO (haskellSet arg0 arg1 arg2)
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- do
          arg0 <- pure "set-struct"
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- liftIO (readIORef node)
          liftIO (first arg0)
        liftIO (equalBox arg0 arg1)
      if hcond
        then do
          hret <- do
            arg0 <- liftIO (readIORef node)
            arg1 <- liftIO (readIORef indent)
            arg2 <- liftIO (readIORef variables)
            liftIO (haskellSetStruct arg0 arg1 arg2)
          qreturn hret
          pure ()
        else do
          hcond <- do
            arg0 <- do
              arg0 <- pure "if"
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- liftIO (readIORef node)
              liftIO (first arg0)
            liftIO (equalBox arg0 arg1)
          if hcond
            then do
              hret <- do
                arg0 <- liftIO (readIORef node)
                arg1 <- liftIO (readIORef indent)
                arg2 <- liftIO (readIORef variables)
                liftIO (haskellIf arg0 arg1 arg2)
              qreturn hret
              pure ()
            else do
              hcond <- do
                arg0 <- do
                  arg0 <- pure "return"
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- liftIO (readIORef node)
                  liftIO (first arg0)
                liftIO (equalBox arg0 arg1)
              if hcond
                then do
                  hret <- do
                    arg0 <- liftIO (readIORef node)
                    arg1 <- liftIO (readIORef indent)
                    arg2 <- liftIO (readIORef variables)
                    liftIO (haskellReturn arg0 arg1 arg2)
                  qreturn hret
                  pure ()
                else do
                  hret <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef indent)
                        liftIO (listNewLine arg0)
                      liftIO (qid arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- pure "_ <- "
                        liftIO (boxString arg0)
                      arg1 <- do
                        arg0 <- do
                          arg0 <- do
                            arg0 <- liftIO (readIORef node)
                            arg1 <- liftIO (readIORef indent)
                            arg2 <- liftIO (readIORef variables)
                            liftIO (haskellExpression arg0 arg1 arg2)
                          liftIO (qid arg0)
                        arg1 <- pure Nothing
                        liftIO (cons arg0 arg1)
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  qreturn hret
                  pure ()
              pure ()
          pure ()
      pure ()
  pure Nothing

haskellBody :: Maybe Box -> Int -> Maybe Box -> IO (Maybe Box)
haskellBody tree_arg indent_arg variables_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  indent <- liftIO (newIORef indent_arg)
  variables <- liftIO (newIORef variables_arg)
  hcond <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (car arg0)
            arg1 <- liftIO (readIORef indent)
            arg2 <- liftIO (readIORef variables)
            liftIO (haskellStatement arg0 arg1 arg2)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (cdr arg0)
              arg1 <- liftIO (readIORef indent)
              arg2 <- liftIO (readIORef variables)
              liftIO (haskellBody arg0 arg1 arg2)
            liftIO (qid arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

haskellFunctionArgsSignature :: Maybe Box -> IO (Maybe Box)
haskellFunctionArgsSignature tree_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  hcond <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- do
          arg0 <- liftIO (readIORef tree)
          liftIO (cddr arg0)
        liftIO (isNil arg0)
      if hcond
        then do
          hret <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef tree)
                  liftIO (first arg0)
                liftIO (haskellTypeMap arg0)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure " -> "
                liftIO (boxString arg0)
              arg1 <- pure Nothing
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          qreturn hret
          pure ()
        else do
          hret <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef tree)
                  liftIO (first arg0)
                liftIO (haskellTypeMap arg0)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure " -> "
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef tree)
                      liftIO (cddr arg0)
                    liftIO (haskellFunctionArgsSignature arg0)
                  liftIO (qid arg0)
                arg1 <- pure Nothing
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          qreturn hret
          pure ()
      pure ()
  pure Nothing

haskellFunctionArgs :: Maybe Box -> IO (Maybe Box)
haskellFunctionArgs tree_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  hcond <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- do
          arg0 <- liftIO (readIORef tree)
          liftIO (cddr arg0)
        liftIO (isNil arg0)
      if hcond
        then do
          hret <- do
            arg0 <- do
              arg0 <- pure " "
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef tree)
                    liftIO (second arg0)
                  arg1 <- pure Nothing
                  liftIO (haskellFuncMap arg0 arg1)
                liftIO (qid arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure "_arg"
                  liftIO (boxString arg0)
                arg1 <- pure Nothing
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          qreturn hret
          pure ()
        else do
          hret <- do
            arg0 <- do
              arg0 <- pure " "
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef tree)
                    liftIO (second arg0)
                  arg1 <- pure Nothing
                  liftIO (haskellFuncMap arg0 arg1)
                liftIO (qid arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure "_arg"
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef tree)
                        liftIO (cddr arg0)
                      liftIO (haskellFunctionArgs arg0)
                    liftIO (qid arg0)
                  arg1 <- pure Nothing
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          qreturn hret
          pure ()
      pure ()
  pure Nothing

haskellArgRefs :: Maybe Box -> Int -> IO (Maybe Box)
haskellArgRefs args_arg indent_arg = evalContT $ callCC $ \qreturn -> do
  args <- liftIO (newIORef args_arg)
  indent <- liftIO (newIORef indent_arg)
  hcond <- do
    arg0 <- liftIO (readIORef args)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef indent)
            liftIO (listNewLine arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef args)
                liftIO (second arg0)
              arg1 <- pure Nothing
              liftIO (haskellFuncMap arg0 arg1)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure " <- liftIO (newIORef "
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef args)
                    liftIO (second arg0)
                  arg1 <- pure Nothing
                  liftIO (haskellFuncMap arg0 arg1)
                liftIO (qid arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure "_arg)"
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef args)
                        liftIO (cddr arg0)
                      arg1 <- liftIO (readIORef indent)
                      liftIO (haskellArgRefs arg0 arg1)
                    liftIO (qid arg0)
                  arg1 <- pure Nothing
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

haskellDeclarations :: Maybe Box -> Int -> Maybe Box -> IO (Maybe Box)
haskellDeclarations decls_arg indent_arg variables_arg = evalContT $ callCC $ \qreturn -> do
  decls <- liftIO (newIORef decls_arg)
  indent <- liftIO (newIORef indent_arg)
  variables <- liftIO (newIORef variables_arg)
  qinit <- pure Nothing
  decl <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef decls)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      qset <- do
        arg0 <- liftIO (readIORef decls)
        liftIO (car arg0)
      liftIO (writeIORef decl qset)
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef indent)
            liftIO (listNewLine arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "qinit <- "
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef decl)
                  liftIO (third arg0)
                arg1 <- liftIO (readIORef indent)
                arg2 <- liftIO (readIORef variables)
                liftIO (haskellExpression arg0 arg1 arg2)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef indent)
                  liftIO (listNewLine arg0)
                liftIO (qid arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef decl)
                      liftIO (second arg0)
                    arg1 <- pure Nothing
                    liftIO (haskellFuncMap arg0 arg1)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure " <- liftIO (newIORef qinit)"
                    liftIO (boxString arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef decls)
                          liftIO (cdr arg0)
                        arg1 <- liftIO (readIORef indent)
                        arg2 <- liftIO (readIORef variables)
                        liftIO (haskellDeclarations arg0 arg1 arg2)
                      liftIO (qid arg0)
                    arg1 <- pure Nothing
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

haskellFunction :: Maybe Box -> IO (Maybe Box)
haskellFunction node_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  qinit <- pure Nothing
  variables <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  args <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  decls <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef node)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      qset <- do
        arg0 <- liftIO (readIORef node)
        liftIO (third arg0)
      liftIO (writeIORef args qset)
      qset <- do
        arg0 <- do
          arg0 <- liftIO (readIORef node)
          liftIO (fourth arg0)
        liftIO (cdr arg0)
      liftIO (writeIORef decls qset)
      qset <- do
        arg0 <- liftIO (readIORef args)
        arg1 <- liftIO (readIORef decls)
        liftIO (haskellCollectVariables arg0 arg1)
      liftIO (writeIORef variables qset)
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- pure 0
            liftIO (listNewLine arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef node)
                liftIO (second arg0)
              arg1 <- pure Nothing
              liftIO (haskellFuncMap arg0 arg1)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure " :: "
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef args)
                  liftIO (haskellFunctionArgsSignature arg0)
                liftIO (qid arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure "IO "
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef node)
                          liftIO (first arg0)
                        liftIO (haskellRefType arg0)
                      liftIO (boxString arg0)
                    liftIO (qid arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- pure 0
                        liftIO (listNewLine arg0)
                      liftIO (qid arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- do
                            arg0 <- liftIO (readIORef node)
                            liftIO (second arg0)
                          arg1 <- pure Nothing
                          liftIO (haskellFuncMap arg0 arg1)
                        liftIO (qid arg0)
                      arg1 <- do
                        arg0 <- do
                          arg0 <- do
                            arg0 <- liftIO (readIORef args)
                            liftIO (haskellFunctionArgs arg0)
                          liftIO (qid arg0)
                        arg1 <- do
                          arg0 <- do
                            arg0 <- pure " = evalContT $ callCC $ \\qreturn -> do"
                            liftIO (boxString arg0)
                          arg1 <- do
                            arg0 <- do
                              arg0 <- do
                                arg0 <- liftIO (readIORef args)
                                arg1 <- pure 1
                                liftIO (haskellArgRefs arg0 arg1)
                              liftIO (qid arg0)
                            arg1 <- do
                              arg0 <- do
                                arg0 <- do
                                  arg0 <- liftIO (readIORef decls)
                                  arg1 <- pure 1
                                  arg2 <- liftIO (readIORef variables)
                                  liftIO (haskellDeclarations arg0 arg1 arg2)
                                liftIO (qid arg0)
                              arg1 <- do
                                arg0 <- do
                                  arg0 <- do
                                    arg0 <- do
                                      arg0 <- do
                                        arg0 <- liftIO (readIORef node)
                                        liftIO (fifth arg0)
                                      liftIO (cdr arg0)
                                    arg1 <- pure 1
                                    arg2 <- liftIO (readIORef variables)
                                    liftIO (haskellBody arg0 arg1 arg2)
                                  liftIO (qid arg0)
                                arg1 <- do
                                  arg0 <- do
                                    arg0 <- do
                                      arg0 <- pure 1
                                      liftIO (listNewLine arg0)
                                    liftIO (qid arg0)
                                  arg1 <- do
                                    arg0 <- do
                                      arg0 <- pure "pure "
                                      liftIO (boxString arg0)
                                    arg1 <- do
                                      arg0 <- do
                                        arg0 <- do
                                          arg0 <- do
                                            arg0 <- do
                                              arg0 <- liftIO (readIORef node)
                                              liftIO (first arg0)
                                            liftIO (haskellDefaultValue arg0)
                                          liftIO (boxString arg0)
                                        liftIO (qid arg0)
                                      arg1 <- do
                                        arg0 <- do
                                          arg0 <- pure "\n"
                                          liftIO (boxString arg0)
                                        arg1 <- pure Nothing
                                        liftIO (cons arg0 arg1)
                                      liftIO (cons arg0 arg1)
                                    liftIO (cons arg0 arg1)
                                  liftIO (cons arg0 arg1)
                                liftIO (cons arg0 arg1)
                              liftIO (cons arg0 arg1)
                            liftIO (cons arg0 arg1)
                          liftIO (cons arg0 arg1)
                        liftIO (cons arg0 arg1)
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

haskellFunctions :: Maybe Box -> IO (Maybe Box)
haskellFunctions tree_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  hcond <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (car arg0)
            liftIO (haskellFunction arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (cdr arg0)
              liftIO (haskellFunctions arg0)
            liftIO (qid arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

haskellTypeDecl :: Maybe Box -> IO (Maybe Box)
haskellTypeDecl l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  qinit <- pure Nothing
  fieldType <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef l)
      liftIO (listLength arg0)
    arg1 <- pure 2
    liftIO (greaterthan arg0 arg1)
  if hcond
    then do
      qset <- do
        arg0 <- liftIO (readIORef l)
        liftIO (listLast arg0)
      liftIO (writeIORef fieldType qset)
      pure ()
    else do
      qset <- do
        arg0 <- liftIO (readIORef l)
        liftIO (second arg0)
      liftIO (writeIORef fieldType qset)
      pure ()
  hret <- do
    arg0 <- do
      arg0 <- pure "  "
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef l)
              liftIO (first arg0)
            liftIO (haskellFieldName arg0)
          liftIO (boxString arg0)
        liftIO (qid arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure " :: IORef "
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef fieldType)
                liftIO (haskellRefType arg0)
              liftIO (boxString arg0)
            liftIO (qid arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

haskellStructFields :: Maybe Box -> IO (Maybe Box)
haskellStructFields node_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  hcond <- do
    arg0 <- liftIO (readIORef node)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- do
          arg0 <- liftIO (readIORef node)
          liftIO (cdr arg0)
        liftIO (isNil arg0)
      if hcond
        then do
          hret <- do
            arg0 <- do
              arg0 <- liftIO (readIORef node)
              liftIO (car arg0)
            liftIO (haskellTypeDecl arg0)
          qreturn hret
          pure ()
        else do
          hret <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef node)
                  liftIO (car arg0)
                liftIO (haskellTypeDecl arg0)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure "\n, "
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef node)
                      liftIO (cdr arg0)
                    liftIO (haskellStructFields arg0)
                  liftIO (qid arg0)
                arg1 <- pure Nothing
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          qreturn hret
          pure ()
      pure ()
  pure Nothing

haskellNewStructField :: Maybe Box -> Int -> IO (Maybe Box)
haskellNewStructField l_arg indent_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  indent <- liftIO (newIORef indent_arg)
  qinit <- pure Nothing
  fieldType <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef l)
      liftIO (listLength arg0)
    arg1 <- pure 2
    liftIO (greaterthan arg0 arg1)
  if hcond
    then do
      qset <- do
        arg0 <- liftIO (readIORef l)
        liftIO (listLast arg0)
      liftIO (writeIORef fieldType qset)
      pure ()
    else do
      qset <- do
        arg0 <- liftIO (readIORef l)
        liftIO (second arg0)
      liftIO (writeIORef fieldType qset)
      pure ()
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef indent)
        liftIO (listNewLine arg0)
      liftIO (qid arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "v_"
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef l)
                liftIO (first arg0)
              liftIO (haskellFieldName arg0)
            liftIO (boxString arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure " <- newIORef "
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef fieldType)
                  liftIO (haskellDefaultValue arg0)
                liftIO (boxString arg0)
              liftIO (qid arg0)
            arg1 <- pure Nothing
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

haskellNewStructFields :: Maybe Box -> Int -> IO (Maybe Box)
haskellNewStructFields fields_arg indent_arg = evalContT $ callCC $ \qreturn -> do
  fields <- liftIO (newIORef fields_arg)
  indent <- liftIO (newIORef indent_arg)
  hcond <- do
    arg0 <- liftIO (readIORef fields)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef fields)
              liftIO (car arg0)
            arg1 <- liftIO (readIORef indent)
            liftIO (haskellNewStructField arg0 arg1)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef fields)
                liftIO (cdr arg0)
              arg1 <- liftIO (readIORef indent)
              liftIO (haskellNewStructFields arg0 arg1)
            liftIO (qid arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

haskellStructCtorFields :: Maybe Box -> IO (Maybe Box)
haskellStructCtorFields fields_arg = evalContT $ callCC $ \qreturn -> do
  fields <- liftIO (newIORef fields_arg)
  hcond <- do
    arg0 <- liftIO (readIORef fields)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- do
          arg0 <- liftIO (readIORef fields)
          liftIO (cdr arg0)
        liftIO (isNil arg0)
      if hcond
        then do
          hret <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef fields)
                      liftIO (car arg0)
                    liftIO (first arg0)
                  liftIO (haskellFieldName arg0)
                liftIO (boxString arg0)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure " = v_"
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef fields)
                          liftIO (car arg0)
                        liftIO (first arg0)
                      liftIO (haskellFieldName arg0)
                    liftIO (boxString arg0)
                  liftIO (qid arg0)
                arg1 <- pure Nothing
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          qreturn hret
          pure ()
        else do
          hret <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef fields)
                      liftIO (car arg0)
                    liftIO (first arg0)
                  liftIO (haskellFieldName arg0)
                liftIO (boxString arg0)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure " = v_"
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef fields)
                          liftIO (car arg0)
                        liftIO (first arg0)
                      liftIO (haskellFieldName arg0)
                    liftIO (boxString arg0)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure ", "
                    liftIO (boxString arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef fields)
                          liftIO (cdr arg0)
                        liftIO (haskellStructCtorFields arg0)
                      liftIO (qid arg0)
                    arg1 <- pure Nothing
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          qreturn hret
          pure ()
      pure ()
  pure Nothing

haskellType :: Maybe Box -> IO (Maybe Box)
haskellType node_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  qinit <- pure Nothing
  fields <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef node)
      liftIO (second arg0)
    liftIO (isList arg0)
  if hcond
    then do
      qset <- do
        arg0 <- do
          arg0 <- liftIO (readIORef node)
          liftIO (second arg0)
        liftIO (cdr arg0)
      liftIO (writeIORef fields qset)
      hret <- do
        arg0 <- do
          arg0 <- pure "\ndata "
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef node)
              liftIO (first arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure " = "
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef node)
                  liftIO (first arg0)
                liftIO (qid arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure " { "
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef fields)
                      liftIO (haskellStructFields arg0)
                    liftIO (qid arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- pure "\n}\n\n"
                      liftIO (boxString arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- do
                            arg0 <- do
                              arg0 <- liftIO (readIORef node)
                              liftIO (first arg0)
                            liftIO (haskellNewName arg0)
                          liftIO (boxString arg0)
                        liftIO (qid arg0)
                      arg1 <- do
                        arg0 <- do
                          arg0 <- pure " :: IO "
                          liftIO (boxString arg0)
                        arg1 <- do
                          arg0 <- do
                            arg0 <- do
                              arg0 <- liftIO (readIORef node)
                              liftIO (first arg0)
                            liftIO (qid arg0)
                          arg1 <- do
                            arg0 <- do
                              arg0 <- pure "\n"
                              liftIO (boxString arg0)
                            arg1 <- do
                              arg0 <- do
                                arg0 <- do
                                  arg0 <- do
                                    arg0 <- do
                                      arg0 <- liftIO (readIORef node)
                                      liftIO (first arg0)
                                    liftIO (haskellNewName arg0)
                                  liftIO (boxString arg0)
                                liftIO (qid arg0)
                              arg1 <- do
                                arg0 <- do
                                  arg0 <- pure " = do"
                                  liftIO (boxString arg0)
                                arg1 <- do
                                  arg0 <- do
                                    arg0 <- do
                                      arg0 <- liftIO (readIORef fields)
                                      arg1 <- pure 1
                                      liftIO (haskellNewStructFields arg0 arg1)
                                    liftIO (qid arg0)
                                  arg1 <- do
                                    arg0 <- do
                                      arg0 <- do
                                        arg0 <- pure 1
                                        liftIO (listNewLine arg0)
                                      liftIO (qid arg0)
                                    arg1 <- do
                                      arg0 <- do
                                        arg0 <- pure "pure "
                                        liftIO (boxString arg0)
                                      arg1 <- do
                                        arg0 <- do
                                          arg0 <- do
                                            arg0 <- liftIO (readIORef node)
                                            liftIO (first arg0)
                                          liftIO (qid arg0)
                                        arg1 <- do
                                          arg0 <- do
                                            arg0 <- pure " { "
                                            liftIO (boxString arg0)
                                          arg1 <- do
                                            arg0 <- do
                                              arg0 <- do
                                                arg0 <- liftIO (readIORef fields)
                                                liftIO (haskellStructCtorFields arg0)
                                              liftIO (qid arg0)
                                            arg1 <- do
                                              arg0 <- do
                                                arg0 <- pure " }\n"
                                                liftIO (boxString arg0)
                                              arg1 <- pure Nothing
                                              liftIO (cons arg0 arg1)
                                            liftIO (cons arg0 arg1)
                                          liftIO (cons arg0 arg1)
                                        liftIO (cons arg0 arg1)
                                      liftIO (cons arg0 arg1)
                                    liftIO (cons arg0 arg1)
                                  liftIO (cons arg0 arg1)
                                liftIO (cons arg0 arg1)
                              liftIO (cons arg0 arg1)
                            liftIO (cons arg0 arg1)
                          liftIO (cons arg0 arg1)
                        liftIO (cons arg0 arg1)
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
    else do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
  pure Nothing

haskellTypes :: Maybe Box -> IO (Maybe Box)
haskellTypes nodes_arg = evalContT $ callCC $ \qreturn -> do
  nodes <- liftIO (newIORef nodes_arg)
  hcond <- do
    arg0 <- liftIO (readIORef nodes)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef nodes)
              liftIO (car arg0)
            liftIO (haskellType arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef nodes)
                liftIO (cdr arg0)
              liftIO (haskellTypes arg0)
            liftIO (qid arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

haskellIncludes :: Maybe Box -> IO (Maybe Box)
haskellIncludes nodes_arg = evalContT $ callCC $ \qreturn -> do
  nodes <- liftIO (newIORef nodes_arg)
  hret <- do
    arg0 <- do
      arg0 <- pure "{-# LANGUAGE DataKinds #-}\n"
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "{-# LANGUAGE DuplicateRecordFields #-}\n"
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure "{-# LANGUAGE ExtendedDefaultRules #-}\n"
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "{-# LANGUAGE TypeApplications #-}\n"
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure "import Control.Monad.Trans.Cont\n"
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure "import Control.Monad.IO.Class\n"
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure "import Data.Char (chr)\n"
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure "import Data.IORef\n"
                    liftIO (boxString arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- pure "import Data.Maybe (isNothing)\n"
                      liftIO (boxString arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- pure "import GHC.Records (getField)\n"
                        liftIO (boxString arg0)
                      arg1 <- do
                        arg0 <- do
                          arg0 <- pure "import System.Directory (doesFileExist)\n"
                          liftIO (boxString arg0)
                        arg1 <- do
                          arg0 <- do
                            arg0 <- pure "import System.Environment (getArgs, lookupEnv)\n"
                            liftIO (boxString arg0)
                          arg1 <- do
                            arg0 <- do
                              arg0 <- pure "import System.Exit (ExitCode(..), exitWith)\n"
                              liftIO (boxString arg0)
                            arg1 <- do
                              arg0 <- do
                                arg0 <- pure "import System.IO (Handle, stderr, hPutStr, hFlush)\n"
                                liftIO (boxString arg0)
                              arg1 <- do
                                arg0 <- do
                                  arg0 <- pure "import System.IO.Unsafe (unsafePerformIO)\n"
                                  liftIO (boxString arg0)
                                arg1 <- do
                                  arg0 <- do
                                    arg0 <- pure "import Text.Printf (printf, hPrintf)\n\n"
                                    liftIO (boxString arg0)
                                  arg1 <- do
                                    arg0 <- do
                                      arg0 <- pure "default (Int, Double)\n\n"
                                      liftIO (boxString arg0)
                                    arg1 <- do
                                      arg0 <- do
                                        arg0 <- pure "expect :: Maybe a -> a\n"
                                        liftIO (boxString arg0)
                                      arg1 <- do
                                        arg0 <- do
                                          arg0 <- pure "expect (Just x) = x\n"
                                          liftIO (boxString arg0)
                                        arg1 <- do
                                          arg0 <- do
                                            arg0 <- pure "expect Nothing = error \"Quon nil dereference\"\n\n"
                                            liftIO (boxString arg0)
                                          arg1 <- do
                                            arg0 <- do
                                              arg0 <- pure "globalTrace :: IORef Bool\n"
                                              liftIO (boxString arg0)
                                            arg1 <- do
                                              arg0 <- do
                                                arg0 <- pure "globalTrace = unsafePerformIO (newIORef False)\n"
                                                liftIO (boxString arg0)
                                              arg1 <- do
                                                arg0 <- do
                                                  arg0 <- pure "{-# NOINLINE globalTrace #-}\n\n"
                                                  liftIO (boxString arg0)
                                                arg1 <- do
                                                  arg0 <- do
                                                    arg0 <- pure "globalStepTrace :: IORef Bool\n"
                                                    liftIO (boxString arg0)
                                                  arg1 <- do
                                                    arg0 <- do
                                                      arg0 <- pure "globalStepTrace = unsafePerformIO (newIORef False)\n"
                                                      liftIO (boxString arg0)
                                                    arg1 <- do
                                                      arg0 <- do
                                                        arg0 <- pure "{-# NOINLINE globalStepTrace #-}\n\n"
                                                        liftIO (boxString arg0)
                                                      arg1 <- do
                                                        arg0 <- do
                                                          arg0 <- pure "releaseMode :: IORef Bool\n"
                                                          liftIO (boxString arg0)
                                                        arg1 <- do
                                                          arg0 <- do
                                                            arg0 <- pure "releaseMode = unsafePerformIO (newIORef False)\n"
                                                            liftIO (boxString arg0)
                                                          arg1 <- do
                                                            arg0 <- do
                                                              arg0 <- pure "{-# NOINLINE releaseMode #-}\n\n"
                                                              liftIO (boxString arg0)
                                                            arg1 <- do
                                                              arg0 <- do
                                                                arg0 <- pure "caller :: IORef String\n"
                                                                liftIO (boxString arg0)
                                                              arg1 <- do
                                                                arg0 <- do
                                                                  arg0 <- pure "caller = unsafePerformIO (newIORef \"\")\n"
                                                                  liftIO (boxString arg0)
                                                                arg1 <- do
                                                                  arg0 <- do
                                                                    arg0 <- pure "{-# NOINLINE caller #-}\n\n"
                                                                    liftIO (boxString arg0)
                                                                  arg1 <- do
                                                                    arg0 <- do
                                                                      arg0 <- pure "globalArgs :: IORef [String]\n"
                                                                      liftIO (boxString arg0)
                                                                    arg1 <- do
                                                                      arg0 <- do
                                                                        arg0 <- pure "globalArgs = unsafePerformIO (newIORef [])\n"
                                                                        liftIO (boxString arg0)
                                                                      arg1 <- do
                                                                        arg0 <- do
                                                                          arg0 <- pure "{-# NOINLINE globalArgs #-}\n\n"
                                                                          liftIO (boxString arg0)
                                                                        arg1 <- do
                                                                          arg0 <- do
                                                                            arg0 <- pure "globalArgsCount :: IORef Int\n"
                                                                            liftIO (boxString arg0)
                                                                          arg1 <- do
                                                                            arg0 <- do
                                                                              arg0 <- pure "globalArgsCount = unsafePerformIO (newIORef 0)\n"
                                                                              liftIO (boxString arg0)
                                                                            arg1 <- do
                                                                              arg0 <- do
                                                                                arg0 <- pure "{-# NOINLINE globalArgsCount #-}\n\n"
                                                                                liftIO (boxString arg0)
                                                                              arg1 <- do
                                                                                arg0 <- do
                                                                                  arg0 <- pure "globalStackTrace :: IORef (Maybe Box)\n"
                                                                                  liftIO (boxString arg0)
                                                                                arg1 <- do
                                                                                  arg0 <- do
                                                                                    arg0 <- pure "globalStackTrace = unsafePerformIO (newIORef Nothing)\n"
                                                                                    liftIO (boxString arg0)
                                                                                  arg1 <- do
                                                                                    arg0 <- do
                                                                                      arg0 <- pure "{-# NOINLINE globalStackTrace #-}\n\n"
                                                                                      liftIO (boxString arg0)
                                                                                    arg1 <- do
                                                                                      arg0 <- do
                                                                                        arg0 <- pure "hsIsNil :: Maybe a -> IO Bool\n"
                                                                                        liftIO (boxString arg0)
                                                                                      arg1 <- do
                                                                                        arg0 <- do
                                                                                          arg0 <- pure "hsIsNil = pure . isNothing\n\n"
                                                                                          liftIO (boxString arg0)
                                                                                        arg1 <- do
                                                                                          arg0 <- do
                                                                                            arg0 <- pure "hsGetEnv :: String -> IO String\n"
                                                                                            liftIO (boxString arg0)
                                                                                          arg1 <- do
                                                                                            arg0 <- do
                                                                                              arg0 <- pure "hsGetEnv key = do\n"
                                                                                              liftIO (boxString arg0)
                                                                                            arg1 <- do
                                                                                              arg0 <- do
                                                                                                arg0 <- pure "  value <- lookupEnv key\n"
                                                                                                liftIO (boxString arg0)
                                                                                              arg1 <- do
                                                                                                arg0 <- do
                                                                                                  arg0 <- pure "  pure (maybe \"\" (\\x -> x) value)\n\n"
                                                                                                  liftIO (boxString arg0)
                                                                                                arg1 <- do
                                                                                                  arg0 <- do
                                                                                                    arg0 <- pure "hsPanic :: String -> IO ()\n"
                                                                                                    liftIO (boxString arg0)
                                                                                                  arg1 <- do
                                                                                                    arg0 <- do
                                                                                                      arg0 <- pure "hsPanic = error\n\n"
                                                                                                      liftIO (boxString arg0)
                                                                                                    arg1 <- do
                                                                                                      arg0 <- do
                                                                                                        arg0 <- pure "hsExit :: Int -> IO ()\n"
                                                                                                        liftIO (boxString arg0)
                                                                                                      arg1 <- do
                                                                                                        arg0 <- do
                                                                                                          arg0 <- pure "hsExit 0 = exitWith ExitSuccess\n"
                                                                                                          liftIO (boxString arg0)
                                                                                                        arg1 <- do
                                                                                                          arg0 <- do
                                                                                                            arg0 <- pure "hsExit n = exitWith (ExitFailure n)\n\n"
                                                                                                            liftIO (boxString arg0)
                                                                                                          arg1 <- do
                                                                                                            arg0 <- do
                                                                                                              arg0 <- pure "hsStringLength :: String -> IO Int\n"
                                                                                                              liftIO (boxString arg0)
                                                                                                            arg1 <- do
                                                                                                              arg0 <- do
                                                                                                                arg0 <- pure "hsStringLength = pure . length\n\n"
                                                                                                                liftIO (boxString arg0)
                                                                                                              arg1 <- do
                                                                                                                arg0 <- do
                                                                                                                  arg0 <- pure "hsSubString :: String -> Int -> Int -> IO String\n"
                                                                                                                  liftIO (boxString arg0)
                                                                                                                arg1 <- do
                                                                                                                  arg0 <- do
                                                                                                                    arg0 <- pure "hsSubString s start len = pure (take len (drop start s))\n\n"
                                                                                                                    liftIO (boxString arg0)
                                                                                                                  arg1 <- do
                                                                                                                    arg0 <- do
                                                                                                                      arg0 <- pure "hsSetSubString :: String -> Int -> String -> IO String\n"
                                                                                                                      liftIO (boxString arg0)
                                                                                                                    arg1 <- do
                                                                                                                      arg0 <- do
                                                                                                                        arg0 <- pure "hsSetSubString target start source = pure (take start target ++ source ++ drop (start + 1) target)\n\n"
                                                                                                                        liftIO (boxString arg0)
                                                                                                                      arg1 <- do
                                                                                                                        arg0 <- do
                                                                                                                          arg0 <- pure "hsShowInt :: Int -> IO String\n"
                                                                                                                          liftIO (boxString arg0)
                                                                                                                        arg1 <- do
                                                                                                                          arg0 <- do
                                                                                                                            arg0 <- pure "hsShowInt = pure . show\n\n"
                                                                                                                            liftIO (boxString arg0)
                                                                                                                          arg1 <- do
                                                                                                                            arg0 <- do
                                                                                                                              arg0 <- pure "hsShowFloat :: Double -> IO String\n"
                                                                                                                              liftIO (boxString arg0)
                                                                                                                            arg1 <- do
                                                                                                                              arg0 <- do
                                                                                                                                arg0 <- pure "hsShowFloat = pure . show\n\n"
                                                                                                                                liftIO (boxString arg0)
                                                                                                                              arg1 <- do
                                                                                                                                arg0 <- do
                                                                                                                                  arg0 <- pure "hsReadFile :: String -> IO (Maybe Box)\n"
                                                                                                                                  liftIO (boxString arg0)
                                                                                                                                arg1 <- do
                                                                                                                                  arg0 <- do
                                                                                                                                    arg0 <- pure "hsReadFile filename = do\n"
                                                                                                                                    liftIO (boxString arg0)
                                                                                                                                  arg1 <- do
                                                                                                                                    arg0 <- do
                                                                                                                                      arg0 <- pure "  exists <- doesFileExist filename\n"
                                                                                                                                      liftIO (boxString arg0)
                                                                                                                                    arg1 <- do
                                                                                                                                      arg0 <- do
                                                                                                                                        arg0 <- pure "  if exists then do\n"
                                                                                                                                        liftIO (boxString arg0)
                                                                                                                                      arg1 <- do
                                                                                                                                        arg0 <- do
                                                                                                                                          arg0 <- pure "    contents <- readFile filename\n"
                                                                                                                                          liftIO (boxString arg0)
                                                                                                                                        arg1 <- do
                                                                                                                                          arg0 <- do
                                                                                                                                            arg0 <- pure "    boxString contents\n"
                                                                                                                                            liftIO (boxString arg0)
                                                                                                                                          arg1 <- do
                                                                                                                                            arg0 <- do
                                                                                                                                              arg0 <- pure "  else pure Nothing\n\n"
                                                                                                                                              liftIO (boxString arg0)
                                                                                                                                            arg1 <- do
                                                                                                                                              arg0 <- do
                                                                                                                                                arg0 <- pure "hsWriteFile :: String -> String -> IO ()\n"
                                                                                                                                                liftIO (boxString arg0)
                                                                                                                                              arg1 <- do
                                                                                                                                                arg0 <- do
                                                                                                                                                  arg0 <- pure "hsWriteFile = writeFile\n\n"
                                                                                                                                                  liftIO (boxString arg0)
                                                                                                                                                arg1 <- do
                                                                                                                                                  arg0 <- do
                                                                                                                                                    arg0 <- pure "hsGetStringArray :: Int -> [String] -> IO String\n"
                                                                                                                                                    liftIO (boxString arg0)
                                                                                                                                                  arg1 <- do
                                                                                                                                                    arg0 <- do
                                                                                                                                                      arg0 <- pure "hsGetStringArray index strs = pure (strs !! index)\n\n"
                                                                                                                                                      liftIO (boxString arg0)
                                                                                                                                                    arg1 <- do
                                                                                                                                                      arg0 <- do
                                                                                                                                                        arg0 <- pure "hsProgramArgs :: IO [String]\n"
                                                                                                                                                        liftIO (boxString arg0)
                                                                                                                                                      arg1 <- do
                                                                                                                                                        arg0 <- do
                                                                                                                                                          arg0 <- pure "hsProgramArgs = readIORef globalArgs\n\n"
                                                                                                                                                          liftIO (boxString arg0)
                                                                                                                                                        arg1 <- do
                                                                                                                                                          arg0 <- do
                                                                                                                                                            arg0 <- pure "hsProgramArgsCount :: IO Int\n"
                                                                                                                                                            liftIO (boxString arg0)
                                                                                                                                                          arg1 <- do
                                                                                                                                                            arg0 <- do
                                                                                                                                                              arg0 <- pure "hsProgramArgsCount = readIORef globalArgsCount\n\n"
                                                                                                                                                              liftIO (boxString arg0)
                                                                                                                                                            arg1 <- do
                                                                                                                                                              arg0 <- do
                                                                                                                                                                arg0 <- pure "hsCharacter :: Int -> IO String\n"
                                                                                                                                                                liftIO (boxString arg0)
                                                                                                                                                              arg1 <- do
                                                                                                                                                                arg0 <- do
                                                                                                                                                                  arg0 <- pure "hsCharacter num = pure [chr num]\n\n"
                                                                                                                                                                  liftIO (boxString arg0)
                                                                                                                                                                arg1 <- do
                                                                                                                                                                  arg0 <- do
                                                                                                                                                                    arg0 <- pure "hsRemainder :: Int -> Int -> IO Int\n"
                                                                                                                                                                    liftIO (boxString arg0)
                                                                                                                                                                  arg1 <- do
                                                                                                                                                                    arg0 <- do
                                                                                                                                                                      arg0 <- pure "hsRemainder a b = pure (a `mod` b)\n\n"
                                                                                                                                                                      liftIO (boxString arg0)
                                                                                                                                                                    arg1 <- do
                                                                                                                                                                      arg0 <- do
                                                                                                                                                                        arg0 <- pure "hsMakeHash :: IO (IORef [(String, String)])\n"
                                                                                                                                                                        liftIO (boxString arg0)
                                                                                                                                                                      arg1 <- do
                                                                                                                                                                        arg0 <- do
                                                                                                                                                                          arg0 <- pure "hsMakeHash = newIORef []\n\n"
                                                                                                                                                                          liftIO (boxString arg0)
                                                                                                                                                                        arg1 <- do
                                                                                                                                                                          arg0 <- do
                                                                                                                                                                            arg0 <- pure "hsSetHash :: IORef [(String, String)] -> String -> String -> IO ()\n"
                                                                                                                                                                            liftIO (boxString arg0)
                                                                                                                                                                          arg1 <- do
                                                                                                                                                                            arg0 <- do
                                                                                                                                                                              arg0 <- pure "hsSetHash hash key value = modifyIORef hash ((key, value) :)\n\n"
                                                                                                                                                                              liftIO (boxString arg0)
                                                                                                                                                                            arg1 <- do
                                                                                                                                                                              arg0 <- do
                                                                                                                                                                                arg0 <- pure "hsGetHash :: IORef [(String, String)] -> String -> IO String\n"
                                                                                                                                                                                liftIO (boxString arg0)
                                                                                                                                                                              arg1 <- do
                                                                                                                                                                                arg0 <- do
                                                                                                                                                                                  arg0 <- pure "hsGetHash hash key = do\n"
                                                                                                                                                                                  liftIO (boxString arg0)
                                                                                                                                                                                arg1 <- do
                                                                                                                                                                                  arg0 <- do
                                                                                                                                                                                    arg0 <- pure "  pairs <- readIORef hash\n"
                                                                                                                                                                                    liftIO (boxString arg0)
                                                                                                                                                                                  arg1 <- do
                                                                                                                                                                                    arg0 <- do
                                                                                                                                                                                      arg0 <- pure "  pure (maybe \"\" (\\x -> x) (lookup key pairs))\n\n"
                                                                                                                                                                                      liftIO (boxString arg0)
                                                                                                                                                                                    arg1 <- do
                                                                                                                                                                                      arg0 <- do
                                                                                                                                                                                        arg0 <- pure "hsInHash :: IORef [(String, String)] -> String -> IO Bool\n"
                                                                                                                                                                                        liftIO (boxString arg0)
                                                                                                                                                                                      arg1 <- do
                                                                                                                                                                                        arg0 <- do
                                                                                                                                                                                          arg0 <- pure "hsInHash hash key = do\n"
                                                                                                                                                                                          liftIO (boxString arg0)
                                                                                                                                                                                        arg1 <- do
                                                                                                                                                                                          arg0 <- do
                                                                                                                                                                                            arg0 <- pure "  pairs <- readIORef hash\n"
                                                                                                                                                                                            liftIO (boxString arg0)
                                                                                                                                                                                          arg1 <- do
                                                                                                                                                                                            arg0 <- do
                                                                                                                                                                                              arg0 <- pure "  pure (not (isNothing (lookup key pairs)))\n\n"
                                                                                                                                                                                              liftIO (boxString arg0)
                                                                                                                                                                                            arg1 <- do
                                                                                                                                                                                              arg0 <- do
                                                                                                                                                                                                arg0 <- pure "hsMakeArray :: Int -> IO [String]\n"
                                                                                                                                                                                                liftIO (boxString arg0)
                                                                                                                                                                                              arg1 <- do
                                                                                                                                                                                                arg0 <- do
                                                                                                                                                                                                  arg0 <- pure "hsMakeArray len = pure (replicate len \"\")\n\n"
                                                                                                                                                                                                  liftIO (boxString arg0)
                                                                                                                                                                                                arg1 <- do
                                                                                                                                                                                                  arg0 <- do
                                                                                                                                                                                                    arg0 <- pure "hsSetArray :: [String] -> Int -> String -> IO ()\n"
                                                                                                                                                                                                    liftIO (boxString arg0)
                                                                                                                                                                                                  arg1 <- do
                                                                                                                                                                                                    arg0 <- do
                                                                                                                                                                                                      arg0 <- pure "hsSetArray _ _ _ = pure ()\n\n"
                                                                                                                                                                                                      liftIO (boxString arg0)
                                                                                                                                                                                                    arg1 <- do
                                                                                                                                                                                                      arg0 <- do
                                                                                                                                                                                                        arg0 <- pure "hsGetArray :: [String] -> Int -> IO String\n"
                                                                                                                                                                                                        liftIO (boxString arg0)
                                                                                                                                                                                                      arg1 <- do
                                                                                                                                                                                                        arg0 <- do
                                                                                                                                                                                                          arg0 <- pure "hsGetArray array index = pure (array !! index)\n\n"
                                                                                                                                                                                                          liftIO (boxString arg0)
                                                                                                                                                                                                        arg1 <- pure Nothing
                                                                                                                                                                                                        liftIO (cons arg0 arg1)
                                                                                                                                                                                                      liftIO (cons arg0 arg1)
                                                                                                                                                                                                    liftIO (cons arg0 arg1)
                                                                                                                                                                                                  liftIO (cons arg0 arg1)
                                                                                                                                                                                                liftIO (cons arg0 arg1)
                                                                                                                                                                                              liftIO (cons arg0 arg1)
                                                                                                                                                                                            liftIO (cons arg0 arg1)
                                                                                                                                                                                          liftIO (cons arg0 arg1)
                                                                                                                                                                                        liftIO (cons arg0 arg1)
                                                                                                                                                                                      liftIO (cons arg0 arg1)
                                                                                                                                                                                    liftIO (cons arg0 arg1)
                                                                                                                                                                                  liftIO (cons arg0 arg1)
                                                                                                                                                                                liftIO (cons arg0 arg1)
                                                                                                                                                                              liftIO (cons arg0 arg1)
                                                                                                                                                                            liftIO (cons arg0 arg1)
                                                                                                                                                                          liftIO (cons arg0 arg1)
                                                                                                                                                                        liftIO (cons arg0 arg1)
                                                                                                                                                                      liftIO (cons arg0 arg1)
                                                                                                                                                                    liftIO (cons arg0 arg1)
                                                                                                                                                                  liftIO (cons arg0 arg1)
                                                                                                                                                                liftIO (cons arg0 arg1)
                                                                                                                                                              liftIO (cons arg0 arg1)
                                                                                                                                                            liftIO (cons arg0 arg1)
                                                                                                                                                          liftIO (cons arg0 arg1)
                                                                                                                                                        liftIO (cons arg0 arg1)
                                                                                                                                                      liftIO (cons arg0 arg1)
                                                                                                                                                    liftIO (cons arg0 arg1)
                                                                                                                                                  liftIO (cons arg0 arg1)
                                                                                                                                                liftIO (cons arg0 arg1)
                                                                                                                                              liftIO (cons arg0 arg1)
                                                                                                                                            liftIO (cons arg0 arg1)
                                                                                                                                          liftIO (cons arg0 arg1)
                                                                                                                                        liftIO (cons arg0 arg1)
                                                                                                                                      liftIO (cons arg0 arg1)
                                                                                                                                    liftIO (cons arg0 arg1)
                                                                                                                                  liftIO (cons arg0 arg1)
                                                                                                                                liftIO (cons arg0 arg1)
                                                                                                                              liftIO (cons arg0 arg1)
                                                                                                                            liftIO (cons arg0 arg1)
                                                                                                                          liftIO (cons arg0 arg1)
                                                                                                                        liftIO (cons arg0 arg1)
                                                                                                                      liftIO (cons arg0 arg1)
                                                                                                                    liftIO (cons arg0 arg1)
                                                                                                                  liftIO (cons arg0 arg1)
                                                                                                                liftIO (cons arg0 arg1)
                                                                                                              liftIO (cons arg0 arg1)
                                                                                                            liftIO (cons arg0 arg1)
                                                                                                          liftIO (cons arg0 arg1)
                                                                                                        liftIO (cons arg0 arg1)
                                                                                                      liftIO (cons arg0 arg1)
                                                                                                    liftIO (cons arg0 arg1)
                                                                                                  liftIO (cons arg0 arg1)
                                                                                                liftIO (cons arg0 arg1)
                                                                                              liftIO (cons arg0 arg1)
                                                                                            liftIO (cons arg0 arg1)
                                                                                          liftIO (cons arg0 arg1)
                                                                                        liftIO (cons arg0 arg1)
                                                                                      liftIO (cons arg0 arg1)
                                                                                    liftIO (cons arg0 arg1)
                                                                                  liftIO (cons arg0 arg1)
                                                                                liftIO (cons arg0 arg1)
                                                                              liftIO (cons arg0 arg1)
                                                                            liftIO (cons arg0 arg1)
                                                                          liftIO (cons arg0 arg1)
                                                                        liftIO (cons arg0 arg1)
                                                                      liftIO (cons arg0 arg1)
                                                                    liftIO (cons arg0 arg1)
                                                                  liftIO (cons arg0 arg1)
                                                                liftIO (cons arg0 arg1)
                                                              liftIO (cons arg0 arg1)
                                                            liftIO (cons arg0 arg1)
                                                          liftIO (cons arg0 arg1)
                                                        liftIO (cons arg0 arg1)
                                                      liftIO (cons arg0 arg1)
                                                    liftIO (cons arg0 arg1)
                                                  liftIO (cons arg0 arg1)
                                                liftIO (cons arg0 arg1)
                                              liftIO (cons arg0 arg1)
                                            liftIO (cons arg0 arg1)
                                          liftIO (cons arg0 arg1)
                                        liftIO (cons arg0 arg1)
                                      liftIO (cons arg0 arg1)
                                    liftIO (cons arg0 arg1)
                                  liftIO (cons arg0 arg1)
                                liftIO (cons arg0 arg1)
                              liftIO (cons arg0 arg1)
                            liftIO (cons arg0 arg1)
                          liftIO (cons arg0 arg1)
                        liftIO (cons arg0 arg1)
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

haskellMainEntry :: IO (Maybe Box)
haskellMainEntry = evalContT $ callCC $ \qreturn -> do
  hret <- do
    arg0 <- do
      arg0 <- pure "\nmain :: IO ()\n"
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "main = do\n"
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure "  args <- getArgs\n"
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "  let qargs = \"fixmeprogname\" : args\n"
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure "  writeIORef globalArgs qargs\n"
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure "  writeIORef globalArgsCount (length qargs)\n"
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure "  _ <- start\n"
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure "  pure ()\n"
                    liftIO (boxString arg0)
                  arg1 <- pure Nothing
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

haskellApplyTypeAliases :: Maybe Box -> Maybe Box -> IO (Maybe Box)
haskellApplyTypeAliases tree_arg types_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  types <- liftIO (newIORef types_arg)
  qinit <- pure Nothing
  node <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  alias <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  target <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef types)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO (readIORef tree)
      qreturn hret
      pure ()
    else do
      pure ()
  qset <- do
    arg0 <- liftIO (readIORef types)
    liftIO (car arg0)
  liftIO (writeIORef node qset)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef node)
      liftIO (second arg0)
    liftIO (isList arg0)
  if hcond
    then do
      hret <- do
        arg0 <- liftIO (readIORef tree)
        arg1 <- do
          arg0 <- liftIO (readIORef types)
          liftIO (cdr arg0)
        liftIO (haskellApplyTypeAliases arg0 arg1)
      qreturn hret
      pure ()
    else do
      pure ()
  qset <- do
    arg0 <- liftIO (readIORef node)
    liftIO (first arg0)
  liftIO (writeIORef alias qset)
  hcond <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef alias)
        liftIO (haskellTypeMap arg0)
      liftIO (stringify arg0)
    arg1 <- do
      arg0 <- liftIO (readIORef alias)
      liftIO (stringify arg0)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      qset <- do
        arg0 <- do
          arg0 <- liftIO (readIORef node)
          liftIO (second arg0)
        liftIO (haskellTypeMap arg0)
      liftIO (writeIORef target qset)
      hret <- do
        arg0 <- do
          arg0 <- liftIO (readIORef tree)
          arg1 <- do
            arg0 <- liftIO (readIORef alias)
            liftIO (stringify arg0)
          arg2 <- do
            arg0 <- liftIO (readIORef target)
            liftIO (stringify arg0)
          liftIO (macroSymbolSingle arg0 arg1 arg2)
        arg1 <- do
          arg0 <- liftIO (readIORef types)
          liftIO (cdr arg0)
        liftIO (haskellApplyTypeAliases arg0 arg1)
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- liftIO (readIORef tree)
        arg1 <- do
          arg0 <- liftIO (readIORef types)
          liftIO (cdr arg0)
        liftIO (haskellApplyTypeAliases arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

haskellLoadProgram :: String -> IO (Maybe Box)
haskellLoadProgram filename_arg = evalContT $ callCC $ \qreturn -> do
  filename <- liftIO (newIORef filename_arg)
  qinit <- pure Nothing
  tree <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  replace <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef filename)
    liftIO (loadQuon arg0)
  liftIO (writeIORef tree qset)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    arg1 <- pure "q/shims/haskell.qon"
    liftIO (insertInclude arg0 arg1)
  liftIO (writeIORef tree qset)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    arg1 <- pure Nothing
    liftIO (loadIncludes arg0 arg1)
  liftIO (writeIORef tree qset)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (macrowalk arg0)
  liftIO (writeIORef tree qset)
  qset <- do
    arg0 <- do
      arg0 <- pure "hPrintf"
      liftIO (boxSymbol arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "stderr"
        liftIO (boxSymbol arg0)
      arg1 <- pure Nothing
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef replace qset)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    arg1 <- do
      arg0 <- pure "q"
      arg1 <- pure "log"
      liftIO (stringConcatenate arg0 arg1)
    arg2 <- liftIO (readIORef replace)
    liftIO (macrolist arg0 arg1 arg2)
  liftIO (writeIORef tree qset)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    arg1 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef tree)
        liftIO (getTypes arg0)
      liftIO (cdr arg0)
    liftIO (haskellApplyTypeAliases arg0 arg1)
  liftIO (writeIORef tree qset)
  hret <- liftIO (readIORef tree)
  qreturn hret
  pure Nothing

haskellProgramTree :: Maybe Box -> IO (Maybe Box)
haskellProgramTree tree_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef tree)
            liftIO (first arg0)
          liftIO (cdr arg0)
        liftIO (haskellIncludes arg0)
      liftIO (qid arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (second arg0)
            liftIO (cdr arg0)
          liftIO (haskellTypes arg0)
        liftIO (qid arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (third arg0)
              liftIO (cdr arg0)
            liftIO (haskellFunctions arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- liftIO haskellMainEntry
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure "\n"
              liftIO (boxString arg0)
            arg1 <- pure Nothing
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

haskellProgram :: Maybe Box -> IO (String)
haskellProgram tree_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef tree)
        liftIO (haskellProgramTree arg0)
      liftIO (flatten arg0)
    arg1 <- pure 0
    arg2 <- pure True
    arg3 <- pure False
    liftIO (listToString arg0 arg1 arg2 arg3)
  qreturn hret
  pure ""

haskellCompileString :: String -> IO (String)
haskellCompileString filename_arg = evalContT $ callCC $ \qreturn -> do
  filename <- liftIO (newIORef filename_arg)
  hret <- do
    arg0 <- do
      arg0 <- liftIO (readIORef filename)
      liftIO (haskellLoadProgram arg0)
    liftIO (haskellProgram arg0)
  qreturn hret
  pure ""

haskellCompile :: String -> IO (())
haskellCompile filename_arg = evalContT $ callCC $ \qreturn -> do
  filename <- liftIO (newIORef filename_arg)
  qinit <- pure Nothing
  tree <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  replace <- liftIO (newIORef qinit)
  _ <- do
    arg0 <- pure stderr
    arg1 <- pure "Scanning file...%s\n"
    arg2 <- liftIO (readIORef filename)
    liftIO (hPrintf arg0 arg1 arg2)
  qset <- do
    arg0 <- liftIO (readIORef filename)
    liftIO (loadQuon arg0)
  liftIO (writeIORef tree qset)
  _ <- do
    arg0 <- pure stderr
    arg1 <- pure "Adding Haskell shim functions\n"
    liftIO (hPrintf arg0 arg1)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    arg1 <- pure "q/shims/haskell.qon"
    liftIO (insertInclude arg0 arg1)
  liftIO (writeIORef tree qset)
  _ <- do
    arg0 <- pure stderr
    arg1 <- pure "Loading includes\n"
    liftIO (hPrintf arg0 arg1)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    arg1 <- pure Nothing
    liftIO (loadIncludes arg0 arg1)
  liftIO (writeIORef tree qset)
  _ <- do
    arg0 <- pure stderr
    arg1 <- pure "Walking tree\n"
    liftIO (hPrintf arg0 arg1)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (macrowalk arg0)
  liftIO (writeIORef tree qset)
  _ <- do
    arg0 <- pure stderr
    arg1 <- pure "Replacing q log\n"
    liftIO (hPrintf arg0 arg1)
  qset <- do
    arg0 <- do
      arg0 <- pure "hPrintf"
      liftIO (boxSymbol arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "stderr"
        liftIO (boxSymbol arg0)
      arg1 <- pure Nothing
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef replace qset)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    arg1 <- do
      arg0 <- pure "q"
      arg1 <- pure "log"
      liftIO (stringConcatenate arg0 arg1)
    arg2 <- liftIO (readIORef replace)
    liftIO (macrolist arg0 arg1 arg2)
  liftIO (writeIORef tree qset)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    arg1 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef tree)
        liftIO (getTypes arg0)
      liftIO (cdr arg0)
    liftIO (haskellApplyTypeAliases arg0 arg1)
  liftIO (writeIORef tree qset)
  _ <- do
    arg0 <- pure stderr
    arg1 <- pure "Printing program\n"
    liftIO (hPrintf arg0 arg1)
  _ <- do
    arg0 <- do
      arg0 <- liftIO (readIORef tree)
      liftIO (haskellProgramTree arg0)
    liftIO (printStringTree arg0)
  pure ()

javaFunctionArgs :: Maybe Box -> IO (Maybe Box)
javaFunctionArgs tree_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  hcond <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef tree)
            liftIO (first arg0)
          liftIO (stringify arg0)
        arg1 <- pure "..."
        liftIO (equalString arg0 arg1)
      if hcond
        then do
          hcond <- do
            arg0 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (cddr arg0)
            liftIO (isNil arg0)
          if hcond
            then do
              hret <- do
                arg0 <- do
                  arg0 <- pure "Object... args"
                  liftIO (boxString arg0)
                arg1 <- pure Nothing
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
            else do
              hret <- do
                arg0 <- do
                  arg0 <- pure "Object... args, "
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef tree)
                        liftIO (cddr arg0)
                      liftIO (javaFunctionArgs arg0)
                    liftIO (qid arg0)
                  arg1 <- pure Nothing
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
          pure ()
        else do
          hcond <- do
            arg0 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (cddr arg0)
            liftIO (isNil arg0)
          if hcond
            then do
              hret <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef tree)
                      liftIO (first arg0)
                    liftIO (javaTypeMap arg0)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure " "
                    liftIO (boxString arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef tree)
                          liftIO (second arg0)
                        liftIO (javaFuncMap arg0)
                      liftIO (qid arg0)
                    arg1 <- pure Nothing
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
            else do
              hret <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef tree)
                      liftIO (first arg0)
                    liftIO (javaTypeMap arg0)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure " "
                    liftIO (boxString arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef tree)
                          liftIO (second arg0)
                        liftIO (javaFuncMap arg0)
                      liftIO (qid arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- pure ", "
                        liftIO (boxString arg0)
                      arg1 <- do
                        arg0 <- do
                          arg0 <- do
                            arg0 <- do
                              arg0 <- liftIO (readIORef tree)
                              liftIO (cddr arg0)
                            liftIO (javaFunctionArgs arg0)
                          liftIO (qid arg0)
                        arg1 <- pure Nothing
                        liftIO (cons arg0 arg1)
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
          pure ()
      pure ()
  pure Nothing

javaAtom :: Maybe Box -> IO (Maybe Box)
javaAtom tree_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  hcond <- do
    arg0 <- pure "string"
    arg1 <- do
      arg0 <- liftIO (readIORef tree)
      liftIO (boxType arg0)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- pure "\""
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (stringify arg0)
              liftIO (boxString arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure "\""
              liftIO (boxString arg0)
            arg1 <- pure Nothing
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef tree)
            liftIO (javaFuncMap arg0)
          liftIO (qid arg0)
        arg1 <- pure Nothing
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

javaExpression :: Maybe Box -> Int -> IO (Maybe Box)
javaExpression tree_arg indent_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  indent <- liftIO (newIORef indent_arg)
  qinit <- pure Nothing
  thing <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef tree)
      liftIO (isList arg0)
    liftIO (notBool arg0)
  if hcond
    then do
      hret <- do
        arg0 <- liftIO (readIORef tree)
        liftIO (javaAtom arg0)
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- pure 1
        arg1 <- do
          arg0 <- liftIO (readIORef tree)
          liftIO (listLength arg0)
        liftIO (equal arg0 arg1)
      if hcond
        then do
          hcond <- do
            arg0 <- do
              arg0 <- pure "return"
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (car arg0)
            liftIO (equalBox arg0 arg1)
          if hcond
            then do
              hret <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef tree)
                      liftIO (car arg0)
                    liftIO (javaFuncMap arg0)
                  liftIO (qid arg0)
                arg1 <- pure Nothing
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
            else do
              hret <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef tree)
                      liftIO (car arg0)
                    liftIO (javaFuncMap arg0)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure "()"
                    liftIO (boxString arg0)
                  arg1 <- pure Nothing
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
          pure ()
        else do
          qset <- do
            arg0 <- liftIO (readIORef tree)
            liftIO (first arg0)
          liftIO (writeIORef thing qset)
          hcond <- do
            arg0 <- do
              arg0 <- pure "get-struct"
              liftIO (boxSymbol arg0)
            arg1 <- liftIO (readIORef thing)
            liftIO (equalBox arg0 arg1)
          if hcond
            then do
              hret <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef tree)
                      liftIO (second arg0)
                    arg1 <- liftIO (readIORef indent)
                    liftIO (javaExpression arg0 arg1)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure "."
                    liftIO (boxString arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef tree)
                        liftIO (third arg0)
                      liftIO (qid arg0)
                    arg1 <- pure Nothing
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
            else do
              hcond <- do
                arg0 <- do
                  arg0 <- pure "new"
                  liftIO (boxSymbol arg0)
                arg1 <- liftIO (readIORef thing)
                liftIO (equalBox arg0 arg1)
              if hcond
                then do
                  hret <- do
                    arg0 <- do
                      arg0 <- pure "new "
                      liftIO (boxString arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- do
                            arg0 <- liftIO (readIORef tree)
                            liftIO (second arg0)
                          liftIO (javaTypeMap arg0)
                        liftIO (qid arg0)
                      arg1 <- do
                        arg0 <- do
                          arg0 <- pure "()"
                          liftIO (boxString arg0)
                        arg1 <- pure Nothing
                        liftIO (cons arg0 arg1)
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  qreturn hret
                  pure ()
                else do
                  hcond <- do
                    arg0 <- do
                      arg0 <- pure "passthrough"
                      liftIO (boxSymbol arg0)
                    arg1 <- liftIO (readIORef thing)
                    liftIO (equalBox arg0 arg1)
                  if hcond
                    then do
                      hret <- do
                        arg0 <- do
                          arg0 <- do
                            arg0 <- liftIO (readIORef tree)
                            liftIO (second arg0)
                          liftIO (qid arg0)
                        arg1 <- pure Nothing
                        liftIO (cons arg0 arg1)
                      qreturn hret
                      pure ()
                    else do
                      hcond <- do
                        arg0 <- do
                          arg0 <- pure "binop"
                          liftIO (boxSymbol arg0)
                        arg1 <- liftIO (readIORef thing)
                        liftIO (equalBox arg0 arg1)
                      if hcond
                        then do
                          hret <- do
                            arg0 <- do
                              arg0 <- pure "("
                              liftIO (boxString arg0)
                            arg1 <- do
                              arg0 <- do
                                arg0 <- do
                                  arg0 <- do
                                    arg0 <- liftIO (readIORef tree)
                                    liftIO (third arg0)
                                  arg1 <- liftIO (readIORef indent)
                                  liftIO (javaExpression arg0 arg1)
                                liftIO (qid arg0)
                              arg1 <- do
                                arg0 <- do
                                  arg0 <- pure " "
                                  liftIO (boxString arg0)
                                arg1 <- do
                                  arg0 <- do
                                    arg0 <- do
                                      arg0 <- liftIO (readIORef tree)
                                      liftIO (second arg0)
                                    liftIO (qid arg0)
                                  arg1 <- do
                                    arg0 <- do
                                      arg0 <- pure " "
                                      liftIO (boxString arg0)
                                    arg1 <- do
                                      arg0 <- do
                                        arg0 <- do
                                          arg0 <- do
                                            arg0 <- liftIO (readIORef tree)
                                            liftIO (fourth arg0)
                                          arg1 <- liftIO (readIORef indent)
                                          liftIO (javaExpression arg0 arg1)
                                        liftIO (qid arg0)
                                      arg1 <- do
                                        arg0 <- do
                                          arg0 <- pure ")"
                                          liftIO (boxString arg0)
                                        arg1 <- pure Nothing
                                        liftIO (cons arg0 arg1)
                                      liftIO (cons arg0 arg1)
                                    liftIO (cons arg0 arg1)
                                  liftIO (cons arg0 arg1)
                                liftIO (cons arg0 arg1)
                              liftIO (cons arg0 arg1)
                            liftIO (cons arg0 arg1)
                          qreturn hret
                          pure ()
                        else do
                          hret <- do
                            arg0 <- do
                              arg0 <- do
                                arg0 <- do
                                  arg0 <- liftIO (readIORef tree)
                                  liftIO (car arg0)
                                liftIO (javaFuncMap arg0)
                              liftIO (qid arg0)
                            arg1 <- do
                              arg0 <- do
                                arg0 <- pure "("
                                liftIO (boxString arg0)
                              arg1 <- do
                                arg0 <- do
                                  arg0 <- do
                                    arg0 <- do
                                      arg0 <- liftIO (readIORef tree)
                                      liftIO (cdr arg0)
                                    arg1 <- liftIO (readIORef indent)
                                    liftIO (javaRecurList arg0 arg1)
                                  liftIO (qid arg0)
                                arg1 <- do
                                  arg0 <- do
                                    arg0 <- pure ")"
                                    liftIO (boxString arg0)
                                  arg1 <- pure Nothing
                                  liftIO (cons arg0 arg1)
                                liftIO (cons arg0 arg1)
                              liftIO (cons arg0 arg1)
                            liftIO (cons arg0 arg1)
                          qreturn hret
                          pure ()
                      pure ()
                  pure ()
              pure ()
          pure ()
      pure ()
  pure Nothing

javaRecurList :: Maybe Box -> Int -> IO (Maybe Box)
javaRecurList expr_arg indent_arg = evalContT $ callCC $ \qreturn -> do
  expr <- liftIO (newIORef expr_arg)
  indent <- liftIO (newIORef indent_arg)
  hcond <- do
    arg0 <- liftIO (readIORef expr)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- do
          arg0 <- liftIO (readIORef expr)
          liftIO (cdr arg0)
        liftIO (isNil arg0)
      if hcond
        then do
          hret <- do
            arg0 <- do
              arg0 <- liftIO (readIORef expr)
              liftIO (car arg0)
            arg1 <- liftIO (readIORef indent)
            liftIO (javaExpression arg0 arg1)
          qreturn hret
          pure ()
        else do
          hret <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef expr)
                  liftIO (car arg0)
                arg1 <- liftIO (readIORef indent)
                liftIO (javaExpression arg0 arg1)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure ", "
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef expr)
                      liftIO (cdr arg0)
                    arg1 <- liftIO (readIORef indent)
                    liftIO (javaRecurList arg0 arg1)
                  liftIO (qid arg0)
                arg1 <- pure Nothing
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          qreturn hret
          pure ()
      pure ()
  pure Nothing

javaIf :: Maybe Box -> Int -> IO (Maybe Box)
javaIf node_arg indent_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  indent <- liftIO (newIORef indent_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef indent)
        liftIO (listNewLine arg0)
      liftIO (qid arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "if ( "
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef node)
              liftIO (second arg0)
            arg1 <- pure 0
            liftIO (javaExpression arg0 arg1)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure ") {"
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef node)
                    liftIO (third arg0)
                  liftIO (cdr arg0)
                arg1 <- do
                  arg0 <- liftIO (readIORef indent)
                  liftIO (add1 arg0)
                liftIO (javaBody arg0 arg1)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef indent)
                  liftIO (listNewLine arg0)
                liftIO (qid arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure "} else {"
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef node)
                          liftIO (fourth arg0)
                        liftIO (cdr arg0)
                      arg1 <- do
                        arg0 <- liftIO (readIORef indent)
                        liftIO (add1 arg0)
                      liftIO (javaBody arg0 arg1)
                    liftIO (qid arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef indent)
                        liftIO (listNewLine arg0)
                      liftIO (qid arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- pure "}"
                        liftIO (boxString arg0)
                      arg1 <- pure Nothing
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

javaSetStruct :: Maybe Box -> Int -> IO (Maybe Box)
javaSetStruct node_arg indent_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  indent <- liftIO (newIORef indent_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef indent)
        liftIO (listNewLine arg0)
      liftIO (qid arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef node)
            liftIO (second arg0)
          arg1 <- liftIO (readIORef indent)
          liftIO (javaExpression arg0 arg1)
        liftIO (qid arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure "."
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef node)
              liftIO (third arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure " = "
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef node)
                    liftIO (fourth arg0)
                  arg1 <- liftIO (readIORef indent)
                  liftIO (javaExpression arg0 arg1)
                liftIO (qid arg0)
              arg1 <- pure Nothing
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

javaSet :: Maybe Box -> Int -> IO (Maybe Box)
javaSet node_arg indent_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  indent <- liftIO (newIORef indent_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef indent)
        liftIO (listNewLine arg0)
      liftIO (qid arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef node)
            liftIO (second arg0)
          arg1 <- liftIO (readIORef indent)
          liftIO (javaExpression arg0 arg1)
        liftIO (qid arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure " = "
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef node)
                liftIO (third arg0)
              arg1 <- liftIO (readIORef indent)
              liftIO (javaExpression arg0 arg1)
            liftIO (qid arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

javaReturn :: Maybe Box -> Int -> IO (Maybe Box)
javaReturn node_arg indent_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  indent <- liftIO (newIORef indent_arg)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef node)
      liftIO (listLength arg0)
    arg1 <- pure 1
    liftIO (equal arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef indent)
            liftIO (listNewLine arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "return"
            liftIO (boxString arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef indent)
            liftIO (listNewLine arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "return "
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef node)
                  liftIO (cadr arg0)
                arg1 <- liftIO (readIORef indent)
                liftIO (javaExpression arg0 arg1)
              liftIO (qid arg0)
            arg1 <- pure Nothing
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

javaStatement :: Maybe Box -> Int -> IO (Maybe Box)
javaStatement node_arg indent_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  indent <- liftIO (newIORef indent_arg)
  hcond <- do
    arg0 <- do
      arg0 <- pure "set"
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- liftIO (readIORef node)
      liftIO (first arg0)
    liftIO (equalBox arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef node)
            arg1 <- liftIO (readIORef indent)
            liftIO (javaSet arg0 arg1)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure ";\n"
            liftIO (boxString arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- do
          arg0 <- pure "set-struct"
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- liftIO (readIORef node)
          liftIO (first arg0)
        liftIO (equalBox arg0 arg1)
      if hcond
        then do
          hret <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef node)
                arg1 <- liftIO (readIORef indent)
                liftIO (javaSetStruct arg0 arg1)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure ";\n"
                liftIO (boxString arg0)
              arg1 <- pure Nothing
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          qreturn hret
          pure ()
        else do
          hcond <- do
            arg0 <- do
              arg0 <- pure "if"
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- liftIO (readIORef node)
              liftIO (first arg0)
            liftIO (equalBox arg0 arg1)
          if hcond
            then do
              hret <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef node)
                    arg1 <- liftIO (readIORef indent)
                    liftIO (javaIf arg0 arg1)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure "\n"
                    liftIO (boxString arg0)
                  arg1 <- pure Nothing
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
            else do
              hcond <- do
                arg0 <- do
                  arg0 <- pure "return"
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- liftIO (readIORef node)
                  liftIO (first arg0)
                liftIO (equalBox arg0 arg1)
              if hcond
                then do
                  hret <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef node)
                        arg1 <- liftIO (readIORef indent)
                        liftIO (javaReturn arg0 arg1)
                      liftIO (qid arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- pure ";\n"
                        liftIO (boxString arg0)
                      arg1 <- pure Nothing
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  qreturn hret
                  pure ()
                else do
                  hret <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef indent)
                        liftIO (listNewLine arg0)
                      liftIO (qid arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef node)
                          arg1 <- liftIO (readIORef indent)
                          liftIO (javaExpression arg0 arg1)
                        liftIO (qid arg0)
                      arg1 <- do
                        arg0 <- do
                          arg0 <- pure ";\n"
                          liftIO (boxString arg0)
                        arg1 <- pure Nothing
                        liftIO (cons arg0 arg1)
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  qreturn hret
                  pure ()
              pure ()
          pure ()
      pure ()
  pure Nothing

javaBody :: Maybe Box -> Int -> IO (Maybe Box)
javaBody tree_arg indent_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  indent <- liftIO (newIORef indent_arg)
  qinit <- pure Nothing
  code <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      qset <- do
        arg0 <- liftIO (readIORef tree)
        liftIO (car arg0)
      liftIO (writeIORef code qset)
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef code)
            arg1 <- liftIO (readIORef indent)
            liftIO (javaStatement arg0 arg1)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (cdr arg0)
              arg1 <- liftIO (readIORef indent)
              liftIO (javaBody arg0 arg1)
            liftIO (qid arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

javaDeclarations :: Maybe Box -> Int -> IO (Maybe Box)
javaDeclarations decls_arg indent_arg = evalContT $ callCC $ \qreturn -> do
  decls <- liftIO (newIORef decls_arg)
  indent <- liftIO (newIORef indent_arg)
  qinit <- pure Nothing
  decl <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef decls)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      qset <- do
        arg0 <- liftIO (readIORef decls)
        liftIO (car arg0)
      liftIO (writeIORef decl qset)
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef decl)
              liftIO (first arg0)
            liftIO (javaTypeMap arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure " "
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef decl)
                  liftIO (second arg0)
                liftIO (javaFuncMap arg0)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure " = "
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef decl)
                      liftIO (third arg0)
                    arg1 <- liftIO (readIORef indent)
                    liftIO (javaExpression arg0 arg1)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure ";\n"
                    liftIO (boxString arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef decls)
                          liftIO (cdr arg0)
                        arg1 <- liftIO (readIORef indent)
                        liftIO (javaDeclarations arg0 arg1)
                      liftIO (qid arg0)
                    arg1 <- pure Nothing
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

javaFunction :: Maybe Box -> IO (Maybe Box)
javaFunction node_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  qinit <- pure Nothing
  name <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef node)
    liftIO (second arg0)
  liftIO (writeIORef name qset)
  hcond <- do
    arg0 <- liftIO (readIORef node)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- pure 0
            liftIO (listNewLine arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- pure 0
              liftIO (listNewLine arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef node)
                  liftIO (first arg0)
                liftIO (javaTypeMap arg0)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure " "
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef node)
                      liftIO (second arg0)
                    liftIO (javaFuncMap arg0)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure "("
                    liftIO (boxString arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef node)
                          liftIO (third arg0)
                        liftIO (javaFunctionArgs arg0)
                      liftIO (qid arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- pure ") {"
                        liftIO (boxString arg0)
                      arg1 <- do
                        arg0 <- do
                          arg0 <- do
                            arg0 <- pure 1
                            liftIO (listNewLine arg0)
                          liftIO (qid arg0)
                        arg1 <- do
                          arg0 <- do
                            arg0 <- do
                              arg0 <- do
                                arg0 <- do
                                  arg0 <- liftIO (readIORef node)
                                  liftIO (fourth arg0)
                                liftIO (cdr arg0)
                              arg1 <- pure 1
                              liftIO (javaDeclarations arg0 arg1)
                            liftIO (qid arg0)
                          arg1 <- do
                            arg0 <- do
                              arg0 <- do
                                arg0 <- do
                                  arg0 <- do
                                    arg0 <- liftIO (readIORef node)
                                    liftIO (fifth arg0)
                                  liftIO (cdr arg0)
                                arg1 <- pure 1
                                liftIO (javaBody arg0 arg1)
                              liftIO (qid arg0)
                            arg1 <- do
                              arg0 <- do
                                arg0 <- pure "\n}\n"
                                liftIO (boxString arg0)
                              arg1 <- pure Nothing
                              liftIO (cons arg0 arg1)
                            liftIO (cons arg0 arg1)
                          liftIO (cons arg0 arg1)
                        liftIO (cons arg0 arg1)
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

javaFunctions :: Maybe Box -> IO (Maybe Box)
javaFunctions tree_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  hcond <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (car arg0)
            liftIO (javaFunction arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (cdr arg0)
              liftIO (javaFunctions arg0)
            liftIO (qid arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

javaIncludes :: Maybe Box -> IO (Maybe Box)
javaIncludes nodes_arg = evalContT $ callCC $ \qreturn -> do
  nodes <- liftIO (newIORef nodes_arg)
  hret <- do
    arg0 <- do
      arg0 <- pure "import java.nio.charset.StandardCharsets;\n"
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "import java.nio.file.Files;\n"
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure "import java.nio.file.Paths;\n"
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "import java.util.HashMap;\n\n"
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure "class QuonProgram {\n"
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure "  boolean globalTrace = false;\n"
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure "  boolean globalStepTrace = false;\n"
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure "  boolean releaseMode = false;\n"
                    liftIO (boxString arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- pure "  Box globalStackTrace = null;\n"
                      liftIO (boxString arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- pure "  String caller = \"\";\n"
                        liftIO (boxString arg0)
                      arg1 <- do
                        arg0 <- do
                          arg0 <- pure "  String[] globalArgs = new String[0];\n"
                          liftIO (boxString arg0)
                        arg1 <- do
                          arg0 <- do
                            arg0 <- pure "  int globalArgsCount = 0;\n\n"
                            liftIO (boxString arg0)
                          arg1 <- do
                            arg0 <- do
                              arg0 <- pure "  Object stderr = new Object();\n\n"
                              liftIO (boxString arg0)
                            arg1 <- do
                              arg0 <- do
                                arg0 <- pure "  void fprintf(Object stream, String format, Object... args) {\n"
                                liftIO (boxString arg0)
                              arg1 <- do
                                arg0 <- do
                                  arg0 <- pure "    if (args.length == 0) {\n"
                                  liftIO (boxString arg0)
                                arg1 <- do
                                  arg0 <- do
                                    arg0 <- pure "      System.err.print(format);\n"
                                    liftIO (boxString arg0)
                                  arg1 <- do
                                    arg0 <- do
                                      arg0 <- pure "    } else {\n"
                                      liftIO (boxString arg0)
                                    arg1 <- do
                                      arg0 <- do
                                        arg0 <- pure "      System.err.printf(format, args);\n"
                                        liftIO (boxString arg0)
                                      arg1 <- do
                                        arg0 <- do
                                          arg0 <- pure "    }\n"
                                          liftIO (boxString arg0)
                                        arg1 <- do
                                          arg0 <- do
                                            arg0 <- pure "  }\n\n"
                                            liftIO (boxString arg0)
                                          arg1 <- do
                                            arg0 <- do
                                              arg0 <- pure "  void exit(int code) {\n"
                                              liftIO (boxString arg0)
                                            arg1 <- do
                                              arg0 <- do
                                                arg0 <- pure "    System.exit(code);\n"
                                                liftIO (boxString arg0)
                                              arg1 <- do
                                                arg0 <- do
                                                  arg0 <- pure "  }\n\n"
                                                  liftIO (boxString arg0)
                                                arg1 <- do
                                                  arg0 <- do
                                                    arg0 <- pure "  Box readFileBox(String filename) {\n"
                                                    liftIO (boxString arg0)
                                                  arg1 <- do
                                                    arg0 <- do
                                                      arg0 <- pure "    try {\n"
                                                      liftIO (boxString arg0)
                                                    arg1 <- do
                                                      arg0 <- do
                                                        arg0 <- pure "      return boxString(Files.readString(Paths.get(filename)));\n"
                                                        liftIO (boxString arg0)
                                                      arg1 <- do
                                                        arg0 <- do
                                                          arg0 <- pure "    } catch (Exception e) {\n"
                                                          liftIO (boxString arg0)
                                                        arg1 <- do
                                                          arg0 <- do
                                                            arg0 <- pure "      return null;\n"
                                                            liftIO (boxString arg0)
                                                          arg1 <- do
                                                            arg0 <- do
                                                              arg0 <- pure "    }\n"
                                                              liftIO (boxString arg0)
                                                            arg1 <- do
                                                              arg0 <- do
                                                                arg0 <- pure "  }\n\n"
                                                                liftIO (boxString arg0)
                                                              arg1 <- do
                                                                arg0 <- do
                                                                  arg0 <- pure "  void writeFileUnchecked(String filename, String data) {\n"
                                                                  liftIO (boxString arg0)
                                                                arg1 <- do
                                                                  arg0 <- do
                                                                    arg0 <- pure "    try {\n"
                                                                    liftIO (boxString arg0)
                                                                  arg1 <- do
                                                                    arg0 <- do
                                                                      arg0 <- pure "      Files.write(Paths.get(filename), data.getBytes(StandardCharsets.UTF_8));\n"
                                                                      liftIO (boxString arg0)
                                                                    arg1 <- do
                                                                      arg0 <- do
                                                                        arg0 <- pure "    } catch (Exception e) {\n"
                                                                        liftIO (boxString arg0)
                                                                      arg1 <- do
                                                                        arg0 <- do
                                                                          arg0 <- pure "      throw new RuntimeException(\"Could not write file: \" + filename, e);\n"
                                                                          liftIO (boxString arg0)
                                                                        arg1 <- do
                                                                          arg0 <- do
                                                                            arg0 <- pure "    }\n"
                                                                            liftIO (boxString arg0)
                                                                          arg1 <- do
                                                                            arg0 <- do
                                                                              arg0 <- pure "  }\n"
                                                                              liftIO (boxString arg0)
                                                                            arg1 <- pure Nothing
                                                                            liftIO (cons arg0 arg1)
                                                                          liftIO (cons arg0 arg1)
                                                                        liftIO (cons arg0 arg1)
                                                                      liftIO (cons arg0 arg1)
                                                                    liftIO (cons arg0 arg1)
                                                                  liftIO (cons arg0 arg1)
                                                                liftIO (cons arg0 arg1)
                                                              liftIO (cons arg0 arg1)
                                                            liftIO (cons arg0 arg1)
                                                          liftIO (cons arg0 arg1)
                                                        liftIO (cons arg0 arg1)
                                                      liftIO (cons arg0 arg1)
                                                    liftIO (cons arg0 arg1)
                                                  liftIO (cons arg0 arg1)
                                                liftIO (cons arg0 arg1)
                                              liftIO (cons arg0 arg1)
                                            liftIO (cons arg0 arg1)
                                          liftIO (cons arg0 arg1)
                                        liftIO (cons arg0 arg1)
                                      liftIO (cons arg0 arg1)
                                    liftIO (cons arg0 arg1)
                                  liftIO (cons arg0 arg1)
                                liftIO (cons arg0 arg1)
                              liftIO (cons arg0 arg1)
                            liftIO (cons arg0 arg1)
                          liftIO (cons arg0 arg1)
                        liftIO (cons arg0 arg1)
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

javaTypeMap :: Maybe Box -> IO (Maybe Box)
javaTypeMap aSym_arg = evalContT $ callCC $ \qreturn -> do
  aSym <- liftIO (newIORef aSym_arg)
  qinit <- pure Nothing
  symMap <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- do
      arg0 <- pure "pair"
      liftIO (boxSymbol arg0)
    arg1 <- do
      arg0 <- pure "Box"
      liftIO (boxSymbol arg0)
    arg2 <- do
      arg0 <- do
        arg0 <- pure "box"
        liftIO (boxSymbol arg0)
      arg1 <- do
        arg0 <- pure "Box"
        liftIO (boxSymbol arg0)
      arg2 <- do
        arg0 <- do
          arg0 <- pure "list"
          liftIO (boxSymbol arg0)
        arg1 <- do
          arg0 <- pure "Box"
          liftIO (boxSymbol arg0)
        arg2 <- do
          arg0 <- do
            arg0 <- pure "Box*"
            liftIO (boxSymbol arg0)
          arg1 <- do
            arg0 <- pure "Box"
            liftIO (boxSymbol arg0)
          arg2 <- do
            arg0 <- do
              arg0 <- pure "struct"
              liftIO (boxSymbol arg0)
            arg1 <- do
              arg0 <- pure ""
              liftIO (boxSymbol arg0)
            arg2 <- do
              arg0 <- do
                arg0 <- pure "bool"
                liftIO (boxSymbol arg0)
              arg1 <- do
                arg0 <- pure "boolean"
                liftIO (boxSymbol arg0)
              arg2 <- do
                arg0 <- do
                  arg0 <- pure "uint"
                  liftIO (boxSymbol arg0)
                arg1 <- do
                  arg0 <- pure "int"
                  liftIO (boxSymbol arg0)
                arg2 <- do
                  arg0 <- do
                    arg0 <- pure "float"
                    liftIO (boxSymbol arg0)
                  arg1 <- do
                    arg0 <- pure "double"
                    liftIO (boxSymbol arg0)
                  arg2 <- do
                    arg0 <- do
                      arg0 <- pure "stringArray"
                      liftIO (boxSymbol arg0)
                    arg1 <- do
                      arg0 <- pure "String[]"
                      liftIO (boxSymbol arg0)
                    arg2 <- do
                      arg0 <- do
                        arg0 <- pure "array"
                        liftIO (boxSymbol arg0)
                      arg1 <- do
                        arg0 <- pure "String[]"
                        liftIO (boxSymbol arg0)
                      arg2 <- do
                        arg0 <- do
                          arg0 <- pure "hashmap"
                          liftIO (boxSymbol arg0)
                        arg1 <- do
                          arg0 <- pure "HashMap<String, String>"
                          liftIO (boxSymbol arg0)
                        arg2 <- do
                          arg0 <- do
                            arg0 <- pure "string"
                            liftIO (boxSymbol arg0)
                          arg1 <- do
                            arg0 <- pure "String"
                            liftIO (boxSymbol arg0)
                          arg2 <- pure Nothing
                          liftIO (alistCons arg0 arg1 arg2)
                        liftIO (alistCons arg0 arg1 arg2)
                      liftIO (alistCons arg0 arg1 arg2)
                    liftIO (alistCons arg0 arg1 arg2)
                  liftIO (alistCons arg0 arg1 arg2)
                liftIO (alistCons arg0 arg1 arg2)
              liftIO (alistCons arg0 arg1 arg2)
            liftIO (alistCons arg0 arg1 arg2)
          liftIO (alistCons arg0 arg1 arg2)
        liftIO (alistCons arg0 arg1 arg2)
      liftIO (alistCons arg0 arg1 arg2)
    liftIO (alistCons arg0 arg1 arg2)
  liftIO (writeIORef symMap qset)
  hcond <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef aSym)
        liftIO (stringify arg0)
      arg1 <- liftIO (readIORef symMap)
      liftIO (assoc arg0 arg1)
    liftIO (truthy arg0)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef aSym)
            liftIO (stringify arg0)
          arg1 <- liftIO (readIORef symMap)
          liftIO (assoc arg0 arg1)
        liftIO (cdr arg0)
      qreturn hret
      pure ()
    else do
      hret <- liftIO (readIORef aSym)
      qreturn hret
      pure ()
  pure Nothing

javaPointerBase :: Maybe Box -> IO (Maybe Box)
javaPointerBase aSym_arg = evalContT $ callCC $ \qreturn -> do
  aSym <- liftIO (newIORef aSym_arg)
  qinit <- pure ""
  name <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef aSym)
    liftIO (stringify arg0)
  liftIO (writeIORef name qset)
  hcond <- do
    arg0 <- pure "*"
    arg1 <- do
      arg0 <- liftIO (readIORef name)
      arg1 <- do
        arg0 <- do
          arg0 <- liftIO (readIORef name)
          liftIO (string_length arg0)
        liftIO (sub1 arg0)
      arg2 <- pure 1
      liftIO (sub_string arg0 arg1 arg2)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- liftIO (readIORef name)
          arg1 <- pure 0
          arg2 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef name)
              liftIO (string_length arg0)
            liftIO (sub1 arg0)
          liftIO (sub_string arg0 arg1 arg2)
        liftIO (boxSymbol arg0)
      qreturn hret
      pure ()
    else do
      hret <- liftIO (readIORef aSym)
      qreturn hret
      pure ()
  pure Nothing

javaFuncMap :: Maybe Box -> IO (Maybe Box)
javaFuncMap aSym_arg = evalContT $ callCC $ \qreturn -> do
  aSym <- liftIO (newIORef aSym_arg)
  qinit <- pure Nothing
  symMap <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- pure "symbol"
    arg1 <- do
      arg0 <- liftIO (readIORef aSym)
      liftIO (boxType arg0)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      qset <- do
        arg0 <- do
          arg0 <- pure "printf"
          liftIO (boxSymbol arg0)
        arg1 <- do
          arg0 <- pure "System.out.printf"
          liftIO (boxSymbol arg0)
        arg2 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- pure "q"
              arg1 <- pure "log"
              liftIO (stringConcatenate arg0 arg1)
            liftIO (boxSymbol arg0)
          arg1 <- do
            arg0 <- pure "System.err.printf"
            liftIO (boxSymbol arg0)
          arg2 <- do
            arg0 <- do
              arg0 <- pure "="
              liftIO (boxSymbol arg0)
            arg1 <- do
              arg0 <- pure "equal"
              liftIO (boxSymbol arg0)
            arg2 <- do
              arg0 <- do
                arg0 <- pure "sub-string"
                liftIO (boxSymbol arg0)
              arg1 <- do
                arg0 <- pure "sub_string"
                liftIO (boxSymbol arg0)
              arg2 <- do
                arg0 <- do
                  arg0 <- pure "read-file"
                  liftIO (boxSymbol arg0)
                arg1 <- do
                  arg0 <- pure "read_file"
                  liftIO (boxSymbol arg0)
                arg2 <- do
                  arg0 <- do
                    arg0 <- pure "write-file"
                    liftIO (boxSymbol arg0)
                  arg1 <- do
                    arg0 <- pure "write_file"
                    liftIO (boxSymbol arg0)
                  arg2 <- do
                    arg0 <- do
                      arg0 <- pure ">"
                      liftIO (boxSymbol arg0)
                    arg1 <- do
                      arg0 <- pure "greaterthan"
                      liftIO (boxSymbol arg0)
                    arg2 <- do
                      arg0 <- do
                        arg0 <- pure "string-length"
                        liftIO (boxSymbol arg0)
                      arg1 <- do
                        arg0 <- pure "string_length"
                        liftIO (boxSymbol arg0)
                      arg2 <- do
                        arg0 <- do
                          arg0 <- pure "nil"
                          liftIO (boxSymbol arg0)
                        arg1 <- do
                          arg0 <- pure "null"
                          liftIO (boxSymbol arg0)
                        arg2 <- do
                          arg0 <- do
                            arg0 <- pure "old"
                            liftIO (boxSymbol arg0)
                          arg1 <- do
                            arg0 <- pure "oldValue"
                            liftIO (boxSymbol arg0)
                          arg2 <- do
                            arg0 <- do
                              arg0 <- pure "new"
                              liftIO (boxSymbol arg0)
                            arg1 <- do
                              arg0 <- pure "newValue"
                              liftIO (boxSymbol arg0)
                            arg2 <- pure Nothing
                            liftIO (alistCons arg0 arg1 arg2)
                          liftIO (alistCons arg0 arg1 arg2)
                        liftIO (alistCons arg0 arg1 arg2)
                      liftIO (alistCons arg0 arg1 arg2)
                    liftIO (alistCons arg0 arg1 arg2)
                  liftIO (alistCons arg0 arg1 arg2)
                liftIO (alistCons arg0 arg1 arg2)
              liftIO (alistCons arg0 arg1 arg2)
            liftIO (alistCons arg0 arg1 arg2)
          liftIO (alistCons arg0 arg1 arg2)
        liftIO (alistCons arg0 arg1 arg2)
      liftIO (writeIORef symMap qset)
      hcond <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef aSym)
            liftIO (stringify arg0)
          arg1 <- liftIO (readIORef symMap)
          liftIO (assoc arg0 arg1)
        liftIO (truthy arg0)
      if hcond
        then do
          hret <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef aSym)
                liftIO (stringify arg0)
              arg1 <- liftIO (readIORef symMap)
              liftIO (assoc arg0 arg1)
            liftIO (cdr arg0)
          qreturn hret
          pure ()
        else do
          hret <- liftIO (readIORef aSym)
          qreturn hret
          pure ()
      pure ()
    else do
      hret <- liftIO (readIORef aSym)
      qreturn hret
      pure ()
  pure Nothing

javaTypeDecl :: Maybe Box -> IO (Maybe Box)
javaTypeDecl l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef l)
      liftIO (listLength arg0)
    arg1 <- pure 2
    liftIO (greaterthan arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- pure 1
              liftIO (stringIndent arg0)
            liftIO (boxString arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef l)
                liftIO (listLast arg0)
              liftIO (javaTypeMap arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure " "
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef l)
                  liftIO (first arg0)
                liftIO (qid arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure ";\n"
                  liftIO (boxString arg0)
                arg1 <- pure Nothing
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- pure 1
              liftIO (stringIndent arg0)
            liftIO (boxString arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef l)
                liftIO (listLast arg0)
              liftIO (javaTypeMap arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure " "
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef l)
                  liftIO (car arg0)
                liftIO (qid arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure ";\n"
                  liftIO (boxString arg0)
                arg1 <- pure Nothing
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

javaStructComponents :: Maybe Box -> IO (Maybe Box)
javaStructComponents node_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  hcond <- do
    arg0 <- liftIO (readIORef node)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef node)
              liftIO (car arg0)
            liftIO (javaTypeDecl arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef node)
                liftIO (cdr arg0)
              liftIO (javaStructComponents arg0)
            liftIO (qid arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

javaStruct :: Maybe Box -> IO (Maybe Box)
javaStruct node_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  hret <- do
    arg0 <- do
      arg0 <- liftIO (readIORef node)
      liftIO (cdr arg0)
    liftIO (javaStructComponents arg0)
  qreturn hret
  pure Nothing

javaType :: Maybe Box -> IO (Maybe Box)
javaType node_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef node)
      liftIO (second arg0)
    liftIO (isList arg0)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- pure "\nclass "
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef node)
              liftIO (first arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure " {\n"
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef node)
                    liftIO (second arg0)
                  liftIO (javaStruct arg0)
                liftIO (qid arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure "}\n"
                  liftIO (boxString arg0)
                arg1 <- pure Nothing
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
    else do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
  pure Nothing

javaTypes :: Maybe Box -> IO (Maybe Box)
javaTypes nodes_arg = evalContT $ callCC $ \qreturn -> do
  nodes <- liftIO (newIORef nodes_arg)
  hcond <- do
    arg0 <- liftIO (readIORef nodes)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef nodes)
              liftIO (car arg0)
            liftIO (javaType arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef nodes)
                liftIO (cdr arg0)
              liftIO (javaTypes arg0)
            liftIO (qid arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

javaApplyTypeAliases :: Maybe Box -> Maybe Box -> IO (Maybe Box)
javaApplyTypeAliases tree_arg types_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  types <- liftIO (newIORef types_arg)
  qinit <- pure Nothing
  node <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  alias <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  target <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef types)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO (readIORef tree)
      qreturn hret
      pure ()
    else do
      pure ()
  qset <- do
    arg0 <- liftIO (readIORef types)
    liftIO (car arg0)
  liftIO (writeIORef node qset)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef node)
      liftIO (second arg0)
    liftIO (isList arg0)
  if hcond
    then do
      hret <- do
        arg0 <- liftIO (readIORef tree)
        arg1 <- do
          arg0 <- liftIO (readIORef types)
          liftIO (cdr arg0)
        liftIO (javaApplyTypeAliases arg0 arg1)
      qreturn hret
      pure ()
    else do
      pure ()
  qset <- do
    arg0 <- liftIO (readIORef node)
    liftIO (first arg0)
  liftIO (writeIORef alias qset)
  hcond <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef alias)
        liftIO (javaTypeMap arg0)
      liftIO (stringify arg0)
    arg1 <- do
      arg0 <- liftIO (readIORef alias)
      liftIO (stringify arg0)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      qset <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef node)
            liftIO (second arg0)
          liftIO (javaPointerBase arg0)
        liftIO (javaTypeMap arg0)
      liftIO (writeIORef target qset)
      hret <- do
        arg0 <- do
          arg0 <- liftIO (readIORef tree)
          arg1 <- do
            arg0 <- liftIO (readIORef alias)
            liftIO (stringify arg0)
          arg2 <- do
            arg0 <- liftIO (readIORef target)
            liftIO (stringify arg0)
          liftIO (macroSymbolSingle arg0 arg1 arg2)
        arg1 <- do
          arg0 <- liftIO (readIORef types)
          liftIO (cdr arg0)
        liftIO (javaApplyTypeAliases arg0 arg1)
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- liftIO (readIORef tree)
        arg1 <- do
          arg0 <- liftIO (readIORef types)
          liftIO (cdr arg0)
        liftIO (javaApplyTypeAliases arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

javaMainEntry :: IO (Maybe Box)
javaMainEntry = evalContT $ callCC $ \qreturn -> do
  hret <- do
    arg0 <- do
      arg0 <- pure "\npublic static void main(String[] args) {\n"
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "  QuonProgram program = new QuonProgram();\n"
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure "  program.globalArgs = new String[args.length + 1];\n"
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "  program.globalArgs[0] = \"fixmeprogname\";\n"
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure "  System.arraycopy(args, 0, program.globalArgs, 1, args.length);\n"
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure "  program.globalArgsCount = program.globalArgs.length;\n"
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure "  program.start();\n"
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure "}\n"
                    liftIO (boxString arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- pure "}\n"
                      liftIO (boxString arg0)
                    arg1 <- pure Nothing
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

javaLoadProgram :: String -> IO (Maybe Box)
javaLoadProgram filename_arg = evalContT $ callCC $ \qreturn -> do
  filename <- liftIO (newIORef filename_arg)
  qinit <- pure Nothing
  tree <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  replace <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef filename)
    liftIO (loadQuon arg0)
  liftIO (writeIORef tree qset)
  qset <- do
    arg0 <- do
      arg0 <- do
        arg0 <- pure "q/shims/java.qon"
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- liftIO (readIORef tree)
        liftIO (getIncludes arg0)
      liftIO (cons arg0 arg1)
    arg1 <- do
      arg0 <- liftIO (readIORef tree)
      liftIO (getTypes arg0)
    arg2 <- do
      arg0 <- liftIO (readIORef tree)
      liftIO (getFunctions arg0)
    liftIO (buildProg arg0 arg1 arg2)
  liftIO (writeIORef tree qset)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    arg1 <- pure Nothing
    liftIO (loadIncludes arg0 arg1)
  liftIO (writeIORef tree qset)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (macrowalk arg0)
  liftIO (writeIORef tree qset)
  qset <- do
    arg0 <- do
      arg0 <- pure "fprintf"
      liftIO (boxSymbol arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "stderr"
        liftIO (boxSymbol arg0)
      arg1 <- pure Nothing
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef replace qset)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    arg1 <- do
      arg0 <- pure "q"
      arg1 <- pure "log"
      liftIO (stringConcatenate arg0 arg1)
    arg2 <- liftIO (readIORef replace)
    liftIO (macrolist arg0 arg1 arg2)
  liftIO (writeIORef tree qset)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    arg1 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef tree)
        liftIO (getTypes arg0)
      liftIO (cdr arg0)
    liftIO (javaApplyTypeAliases arg0 arg1)
  liftIO (writeIORef tree qset)
  hret <- liftIO (readIORef tree)
  qreturn hret
  pure Nothing

javaProgramTree :: Maybe Box -> IO (Maybe Box)
javaProgramTree tree_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef tree)
            liftIO (first arg0)
          liftIO (cdr arg0)
        liftIO (javaIncludes arg0)
      liftIO (qid arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (second arg0)
            liftIO (cdr arg0)
          liftIO (javaTypes arg0)
        liftIO (qid arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (third arg0)
              liftIO (cdr arg0)
            liftIO (javaFunctions arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- liftIO javaMainEntry
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure "\n"
              liftIO (boxString arg0)
            arg1 <- pure Nothing
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

javaProgram :: Maybe Box -> IO (String)
javaProgram tree_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef tree)
        liftIO (javaProgramTree arg0)
      liftIO (flatten arg0)
    arg1 <- pure 0
    arg2 <- pure True
    arg3 <- pure False
    liftIO (listToString arg0 arg1 arg2 arg3)
  qreturn hret
  pure ""

javaCompileString :: String -> IO (String)
javaCompileString filename_arg = evalContT $ callCC $ \qreturn -> do
  filename <- liftIO (newIORef filename_arg)
  hret <- do
    arg0 <- do
      arg0 <- liftIO (readIORef filename)
      liftIO (javaLoadProgram arg0)
    liftIO (javaProgram arg0)
  qreturn hret
  pure ""

javaCompile :: String -> IO (())
javaCompile filename_arg = evalContT $ callCC $ \qreturn -> do
  filename <- liftIO (newIORef filename_arg)
  _ <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef filename)
        liftIO (javaLoadProgram arg0)
      liftIO (javaProgramTree arg0)
    liftIO (printStringTree arg0)
  _ <- do
    arg0 <- pure stderr
    arg1 <- pure "//Done printing program\n"
    liftIO (hPrintf arg0 arg1)
  pure ()

ansi3FunctionArgs :: Maybe Box -> IO (Maybe Box)
ansi3FunctionArgs tree_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  hcond <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef tree)
            liftIO (first arg0)
          liftIO (stringify arg0)
        arg1 <- pure "..."
        liftIO (equalString arg0 arg1)
      if hcond
        then do
          hcond <- do
            arg0 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (cddr arg0)
            liftIO (isNil arg0)
          if hcond
            then do
              hret <- do
                arg0 <- do
                  arg0 <- pure "..."
                  liftIO (boxString arg0)
                arg1 <- pure Nothing
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
            else do
              hret <- do
                arg0 <- do
                  arg0 <- pure "..."
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure ", "
                    liftIO (boxString arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef tree)
                          liftIO (cddr arg0)
                        liftIO (ansi3FunctionArgs arg0)
                      liftIO (qid arg0)
                    arg1 <- pure Nothing
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
          pure ()
        else do
          hcond <- do
            arg0 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (cddr arg0)
            liftIO (isNil arg0)
          if hcond
            then do
              hret <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef tree)
                      liftIO (first arg0)
                    liftIO (ansi3TypeMap arg0)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure " "
                    liftIO (boxString arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef tree)
                        liftIO (second arg0)
                      liftIO (qid arg0)
                    arg1 <- pure Nothing
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
            else do
              hret <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef tree)
                      liftIO (first arg0)
                    liftIO (ansi3TypeMap arg0)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure " "
                    liftIO (boxString arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef tree)
                        liftIO (second arg0)
                      liftIO (qid arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- pure ", "
                        liftIO (boxString arg0)
                      arg1 <- do
                        arg0 <- do
                          arg0 <- do
                            arg0 <- do
                              arg0 <- liftIO (readIORef tree)
                              liftIO (cddr arg0)
                            liftIO (ansi3FunctionArgs arg0)
                          liftIO (qid arg0)
                        arg1 <- pure Nothing
                        liftIO (cons arg0 arg1)
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
          pure ()
      pure ()
  pure Nothing

ansi3Atom :: Maybe Box -> IO (Maybe Box)
ansi3Atom tree_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  hcond <- do
    arg0 <- pure "string"
    arg1 <- do
      arg0 <- liftIO (readIORef tree)
      liftIO (boxType arg0)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- pure "\""
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (stringify arg0)
              liftIO (boxString arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure "\""
              liftIO (boxString arg0)
            arg1 <- pure Nothing
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef tree)
            liftIO (ansi3FuncMap arg0)
          liftIO (qid arg0)
        arg1 <- pure Nothing
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

ansi3Expression :: Maybe Box -> Int -> IO (Maybe Box)
ansi3Expression tree_arg indent_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  indent <- liftIO (newIORef indent_arg)
  qinit <- pure Nothing
  thing <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef tree)
      liftIO (isList arg0)
    liftIO (notBool arg0)
  if hcond
    then do
      hret <- do
        arg0 <- liftIO (readIORef tree)
        liftIO (ansi3Atom arg0)
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- pure 1
        arg1 <- do
          arg0 <- liftIO (readIORef tree)
          liftIO (listLength arg0)
        liftIO (equal arg0 arg1)
      if hcond
        then do
          hcond <- do
            arg0 <- do
              arg0 <- pure "return"
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (car arg0)
            liftIO (equalBox arg0 arg1)
          if hcond
            then do
              hret <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef tree)
                      liftIO (car arg0)
                    liftIO (ansi3FuncMap arg0)
                  liftIO (qid arg0)
                arg1 <- pure Nothing
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
            else do
              hret <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef tree)
                      liftIO (car arg0)
                    liftIO (ansi3FuncMap arg0)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure "()"
                    liftIO (boxString arg0)
                  arg1 <- pure Nothing
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
          pure ()
        else do
          qset <- do
            arg0 <- liftIO (readIORef tree)
            liftIO (first arg0)
          liftIO (writeIORef thing qset)
          hcond <- do
            arg0 <- do
              arg0 <- pure "get-struct"
              liftIO (boxSymbol arg0)
            arg1 <- liftIO (readIORef thing)
            liftIO (equalBox arg0 arg1)
          if hcond
            then do
              hret <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef tree)
                    liftIO (second arg0)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure "->"
                    liftIO (boxString arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef tree)
                        liftIO (third arg0)
                      liftIO (qid arg0)
                    arg1 <- pure Nothing
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
            else do
              hcond <- do
                arg0 <- do
                  arg0 <- pure "new"
                  liftIO (boxSymbol arg0)
                arg1 <- liftIO (readIORef thing)
                liftIO (equalBox arg0 arg1)
              if hcond
                then do
                  hret <- do
                    arg0 <- do
                      arg0 <- pure "malloc(sizeof("
                      liftIO (boxString arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef tree)
                          liftIO (third arg0)
                        liftIO (qid arg0)
                      arg1 <- do
                        arg0 <- do
                          arg0 <- pure "))"
                          liftIO (boxString arg0)
                        arg1 <- pure Nothing
                        liftIO (cons arg0 arg1)
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  qreturn hret
                  pure ()
                else do
                  hcond <- do
                    arg0 <- do
                      arg0 <- pure "passthrough"
                      liftIO (boxSymbol arg0)
                    arg1 <- liftIO (readIORef thing)
                    liftIO (equalBox arg0 arg1)
                  if hcond
                    then do
                      hret <- do
                        arg0 <- do
                          arg0 <- do
                            arg0 <- liftIO (readIORef tree)
                            liftIO (second arg0)
                          liftIO (qid arg0)
                        arg1 <- pure Nothing
                        liftIO (cons arg0 arg1)
                      qreturn hret
                      pure ()
                    else do
                      hcond <- do
                        arg0 <- do
                          arg0 <- pure "binop"
                          liftIO (boxSymbol arg0)
                        arg1 <- liftIO (readIORef thing)
                        liftIO (equalBox arg0 arg1)
                      if hcond
                        then do
                          hret <- do
                            arg0 <- do
                              arg0 <- pure "("
                              liftIO (boxString arg0)
                            arg1 <- do
                              arg0 <- do
                                arg0 <- do
                                  arg0 <- do
                                    arg0 <- liftIO (readIORef tree)
                                    liftIO (third arg0)
                                  arg1 <- liftIO (readIORef indent)
                                  liftIO (ansi3Expression arg0 arg1)
                                liftIO (qid arg0)
                              arg1 <- do
                                arg0 <- do
                                  arg0 <- pure " "
                                  liftIO (boxString arg0)
                                arg1 <- do
                                  arg0 <- do
                                    arg0 <- do
                                      arg0 <- liftIO (readIORef tree)
                                      liftIO (second arg0)
                                    liftIO (qid arg0)
                                  arg1 <- do
                                    arg0 <- do
                                      arg0 <- pure " "
                                      liftIO (boxString arg0)
                                    arg1 <- do
                                      arg0 <- do
                                        arg0 <- do
                                          arg0 <- do
                                            arg0 <- liftIO (readIORef tree)
                                            liftIO (fourth arg0)
                                          arg1 <- liftIO (readIORef indent)
                                          liftIO (ansi3Expression arg0 arg1)
                                        liftIO (qid arg0)
                                      arg1 <- do
                                        arg0 <- do
                                          arg0 <- pure ")"
                                          liftIO (boxString arg0)
                                        arg1 <- pure Nothing
                                        liftIO (cons arg0 arg1)
                                      liftIO (cons arg0 arg1)
                                    liftIO (cons arg0 arg1)
                                  liftIO (cons arg0 arg1)
                                liftIO (cons arg0 arg1)
                              liftIO (cons arg0 arg1)
                            liftIO (cons arg0 arg1)
                          qreturn hret
                          pure ()
                        else do
                          hret <- do
                            arg0 <- do
                              arg0 <- do
                                arg0 <- do
                                  arg0 <- liftIO (readIORef tree)
                                  liftIO (car arg0)
                                liftIO (ansi3FuncMap arg0)
                              liftIO (qid arg0)
                            arg1 <- do
                              arg0 <- do
                                arg0 <- pure "("
                                liftIO (boxString arg0)
                              arg1 <- do
                                arg0 <- do
                                  arg0 <- do
                                    arg0 <- do
                                      arg0 <- liftIO (readIORef tree)
                                      liftIO (cdr arg0)
                                    arg1 <- liftIO (readIORef indent)
                                    liftIO (ansi3RecurList arg0 arg1)
                                  liftIO (qid arg0)
                                arg1 <- do
                                  arg0 <- do
                                    arg0 <- pure ")"
                                    liftIO (boxString arg0)
                                  arg1 <- pure Nothing
                                  liftIO (cons arg0 arg1)
                                liftIO (cons arg0 arg1)
                              liftIO (cons arg0 arg1)
                            liftIO (cons arg0 arg1)
                          qreturn hret
                          pure ()
                      pure ()
                  pure ()
              pure ()
          pure ()
      pure ()
  pure Nothing

ansi3RecurList :: Maybe Box -> Int -> IO (Maybe Box)
ansi3RecurList expr_arg indent_arg = evalContT $ callCC $ \qreturn -> do
  expr <- liftIO (newIORef expr_arg)
  indent <- liftIO (newIORef indent_arg)
  hcond <- do
    arg0 <- liftIO (readIORef expr)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- do
          arg0 <- liftIO (readIORef expr)
          liftIO (cdr arg0)
        liftIO (isNil arg0)
      if hcond
        then do
          hret <- do
            arg0 <- do
              arg0 <- liftIO (readIORef expr)
              liftIO (car arg0)
            arg1 <- liftIO (readIORef indent)
            liftIO (ansi3Expression arg0 arg1)
          qreturn hret
          pure ()
        else do
          hret <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef expr)
                  liftIO (car arg0)
                arg1 <- liftIO (readIORef indent)
                liftIO (ansi3Expression arg0 arg1)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure ", "
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef expr)
                      liftIO (cdr arg0)
                    arg1 <- liftIO (readIORef indent)
                    liftIO (ansi3RecurList arg0 arg1)
                  liftIO (qid arg0)
                arg1 <- pure Nothing
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          qreturn hret
          pure ()
      pure ()
  pure Nothing

ansi3If :: Maybe Box -> Int -> String -> IO (Maybe Box)
ansi3If node_arg indent_arg functionName_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  indent <- liftIO (newIORef indent_arg)
  functionName <- liftIO (newIORef functionName_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef indent)
        liftIO (listNewLine arg0)
      liftIO (qid arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "if ( "
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef node)
              liftIO (second arg0)
            arg1 <- pure 0
            liftIO (ansi3Expression arg0 arg1)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure ") {"
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef node)
                    liftIO (third arg0)
                  liftIO (cdr arg0)
                arg1 <- do
                  arg0 <- liftIO (readIORef indent)
                  liftIO (add1 arg0)
                arg2 <- liftIO (readIORef functionName)
                liftIO (ansi3Body arg0 arg1 arg2)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef indent)
                  liftIO (listNewLine arg0)
                liftIO (qid arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure "} else {"
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef node)
                          liftIO (fourth arg0)
                        liftIO (cdr arg0)
                      arg1 <- do
                        arg0 <- liftIO (readIORef indent)
                        liftIO (add1 arg0)
                      arg2 <- liftIO (readIORef functionName)
                      liftIO (ansi3Body arg0 arg1 arg2)
                    liftIO (qid arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef indent)
                        liftIO (listNewLine arg0)
                      liftIO (qid arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- pure "}"
                        liftIO (boxString arg0)
                      arg1 <- pure Nothing
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

ansi3SetStruct :: Maybe Box -> Int -> IO (Maybe Box)
ansi3SetStruct node_arg indent_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  indent <- liftIO (newIORef indent_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef indent)
        liftIO (listNewLine arg0)
      liftIO (qid arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- liftIO (readIORef node)
          liftIO (second arg0)
        liftIO (qid arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure "->"
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef node)
              liftIO (third arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure " = "
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef node)
                    liftIO (fourth arg0)
                  arg1 <- liftIO (readIORef indent)
                  liftIO (ansi3Expression arg0 arg1)
                liftIO (qid arg0)
              arg1 <- pure Nothing
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

ansi3Set :: Maybe Box -> Int -> IO (Maybe Box)
ansi3Set node_arg indent_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  indent <- liftIO (newIORef indent_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef indent)
        liftIO (listNewLine arg0)
      liftIO (qid arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef node)
            liftIO (second arg0)
          arg1 <- liftIO (readIORef indent)
          liftIO (ansi3Expression arg0 arg1)
        liftIO (qid arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure " = "
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef node)
                liftIO (third arg0)
              arg1 <- liftIO (readIORef indent)
              liftIO (ansi3Expression arg0 arg1)
            liftIO (qid arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

ansi3Return :: Maybe Box -> Int -> IO (Maybe Box)
ansi3Return node_arg indent_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  indent <- liftIO (newIORef indent_arg)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef node)
      liftIO (listLength arg0)
    arg1 <- pure 1
    liftIO (equal arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef indent)
            liftIO (listNewLine arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "return;"
            liftIO (boxString arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef indent)
            liftIO (listNewLine arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "return "
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef node)
                  liftIO (cadr arg0)
                arg1 <- liftIO (readIORef indent)
                liftIO (ansi3Expression arg0 arg1)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure ";"
                liftIO (boxString arg0)
              arg1 <- pure Nothing
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

ansi3TraceReturn :: Maybe Box -> Int -> String -> IO (Maybe Box)
ansi3TraceReturn node_arg indent_arg functionName_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  indent <- liftIO (newIORef indent_arg)
  functionName <- liftIO (newIORef functionName_arg)
  hcond <- liftIO (readIORef releaseMode)
  if hcond
    then do
      hret <- do
        arg0 <- liftIO (readIORef node)
        arg1 <- liftIO (readIORef indent)
        liftIO (ansi3Return arg0 arg1)
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- do
          arg0 <- liftIO (readIORef functionName)
          liftIO (boxString arg0)
        arg1 <- liftIO noStackTrace_list
        liftIO (inList arg0 arg1)
      if hcond
        then do
          hret <- do
            arg0 <- liftIO (readIORef node)
            arg1 <- liftIO (readIORef indent)
            liftIO (ansi3Return arg0 arg1)
          qreturn hret
          pure ()
        else do
          hret <- do
            arg0 <- do
              arg0 <- pure "\n"
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef indent)
                    liftIO (stringIndent arg0)
                  liftIO (boxString arg0)
                liftIO (qid arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure "StackTraceMove(\"out\", \"\", \"\", \"\");\n"
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef node)
                      arg1 <- liftIO (readIORef indent)
                      liftIO (ansi3Return arg0 arg1)
                    liftIO (qid arg0)
                  arg1 <- pure Nothing
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          qreturn hret
          pure ()
      pure ()
  pure Nothing

ansi3Statement :: Maybe Box -> Int -> String -> IO (Maybe Box)
ansi3Statement node_arg indent_arg functionName_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  indent <- liftIO (newIORef indent_arg)
  functionName <- liftIO (newIORef functionName_arg)
  hcond <- do
    arg0 <- do
      arg0 <- pure "set"
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- liftIO (readIORef node)
      liftIO (first arg0)
    liftIO (equalBox arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef node)
            arg1 <- liftIO (readIORef indent)
            liftIO (ansi3Set arg0 arg1)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure ";\n"
            liftIO (boxString arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- do
          arg0 <- pure "set-struct"
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- liftIO (readIORef node)
          liftIO (first arg0)
        liftIO (equalBox arg0 arg1)
      if hcond
        then do
          hret <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef node)
                arg1 <- liftIO (readIORef indent)
                liftIO (ansi3SetStruct arg0 arg1)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure ";\n"
                liftIO (boxString arg0)
              arg1 <- pure Nothing
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          qreturn hret
          pure ()
        else do
          hcond <- do
            arg0 <- do
              arg0 <- pure "if"
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- liftIO (readIORef node)
              liftIO (first arg0)
            liftIO (equalBox arg0 arg1)
          if hcond
            then do
              hret <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef node)
                    arg1 <- liftIO (readIORef indent)
                    arg2 <- liftIO (readIORef functionName)
                    liftIO (ansi3If arg0 arg1 arg2)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure ";\n"
                    liftIO (boxString arg0)
                  arg1 <- pure Nothing
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
            else do
              hcond <- do
                arg0 <- do
                  arg0 <- pure "return"
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- liftIO (readIORef node)
                  liftIO (first arg0)
                liftIO (equalBox arg0 arg1)
              if hcond
                then do
                  hret <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef node)
                        arg1 <- liftIO (readIORef indent)
                        arg2 <- liftIO (readIORef functionName)
                        liftIO (ansi3TraceReturn arg0 arg1 arg2)
                      liftIO (qid arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- pure ";\n"
                        liftIO (boxString arg0)
                      arg1 <- pure Nothing
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  qreturn hret
                  pure ()
                else do
                  hret <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef indent)
                        liftIO (listNewLine arg0)
                      liftIO (qid arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef node)
                          arg1 <- liftIO (readIORef indent)
                          liftIO (ansi3Expression arg0 arg1)
                        liftIO (qid arg0)
                      arg1 <- do
                        arg0 <- do
                          arg0 <- pure ";\n"
                          liftIO (boxString arg0)
                        arg1 <- pure Nothing
                        liftIO (cons arg0 arg1)
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  qreturn hret
                  pure ()
              pure ()
          pure ()
      pure ()
  pure Nothing

ansi3StatementTrace :: Maybe Box -> Int -> String -> IO (Maybe Box)
ansi3StatementTrace code_arg indent_arg functionName_arg = evalContT $ callCC $ \qreturn -> do
  code <- liftIO (newIORef code_arg)
  indent <- liftIO (newIORef indent_arg)
  functionName <- liftIO (newIORef functionName_arg)
  hcond <- liftIO (readIORef releaseMode)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- do
          arg0 <- liftIO (readIORef functionName)
          liftIO (boxString arg0)
        arg1 <- liftIO noTrace_list
        liftIO (inList arg0 arg1)
      if hcond
        then do
          hret <- liftIO emptyList
          qreturn hret
          pure ()
        else do
          hret <- do
            arg0 <- do
              arg0 <- pure "\nif (globalTrace)\n    snprintf(caller, 1024, \"from "
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef code)
                    liftIO (car arg0)
                  arg1 <- do
                    arg0 <- pure "filename"
                    liftIO (boxString arg0)
                  arg2 <- do
                    arg0 <- pure "Unknown file (not provided by parser)"
                    liftIO (boxString arg0)
                  liftIO (getTagFail arg0 arg1 arg2)
                liftIO (qid arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure ":"
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef code)
                        liftIO (car arg0)
                      arg1 <- do
                        arg0 <- pure "line"
                        liftIO (boxString arg0)
                      arg2 <- do
                        arg0 <- pure "Line missing"
                        liftIO (boxString arg0)
                      liftIO (getTagFail arg0 arg1 arg2)
                    liftIO (qid arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- pure "\");\n"
                      liftIO (boxString arg0)
                    arg1 <- pure Nothing
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          qreturn hret
          pure ()
      pure ()
  pure Nothing

ansi3StepTrace :: Int -> IO (Maybe Box)
ansi3StepTrace indent_arg = evalContT $ callCC $ \qreturn -> do
  indent <- liftIO (newIORef indent_arg)
  hcond <- liftIO (readIORef releaseMode)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef indent)
              liftIO (stringIndent arg0)
            liftIO (boxString arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "if (globalStepTrace) printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__);\n"
            liftIO (boxString arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

ansi3Body :: Maybe Box -> Int -> String -> IO (Maybe Box)
ansi3Body tree_arg indent_arg functionName_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  indent <- liftIO (newIORef indent_arg)
  functionName <- liftIO (newIORef functionName_arg)
  qinit <- pure Nothing
  code <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      qset <- do
        arg0 <- liftIO (readIORef tree)
        liftIO (car arg0)
      liftIO (writeIORef code qset)
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef code)
            arg1 <- liftIO (readIORef indent)
            arg2 <- liftIO (readIORef functionName)
            liftIO (ansi3StatementTrace arg0 arg1 arg2)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef indent)
              liftIO (ansi3StepTrace arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef code)
                arg1 <- liftIO (readIORef indent)
                arg2 <- liftIO (readIORef functionName)
                liftIO (ansi3Statement arg0 arg1 arg2)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef tree)
                    liftIO (cdr arg0)
                  arg1 <- liftIO (readIORef indent)
                  arg2 <- liftIO (readIORef functionName)
                  liftIO (ansi3Body arg0 arg1 arg2)
                liftIO (qid arg0)
              arg1 <- pure Nothing
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

ansi3Declarations :: Maybe Box -> Int -> IO (Maybe Box)
ansi3Declarations decls_arg indent_arg = evalContT $ callCC $ \qreturn -> do
  decls <- liftIO (newIORef decls_arg)
  indent <- liftIO (newIORef indent_arg)
  qinit <- pure Nothing
  decl <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef decls)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      qset <- do
        arg0 <- liftIO (readIORef decls)
        liftIO (car arg0)
      liftIO (writeIORef decl qset)
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef decl)
              liftIO (first arg0)
            liftIO (ansi3TypeMap arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure " "
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef decl)
                liftIO (second arg0)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure " = "
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef decl)
                      liftIO (third arg0)
                    arg1 <- liftIO (readIORef indent)
                    liftIO (ansi3Expression arg0 arg1)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure ";\n"
                    liftIO (boxString arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef decls)
                          liftIO (cdr arg0)
                        arg1 <- liftIO (readIORef indent)
                        liftIO (ansi3Declarations arg0 arg1)
                      liftIO (qid arg0)
                    arg1 <- pure Nothing
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

ansi3FunctionTrace :: Maybe Box -> IO (Maybe Box)
ansi3FunctionTrace name_arg = evalContT $ callCC $ \qreturn -> do
  name <- liftIO (newIORef name_arg)
  hcond <- liftIO (readIORef releaseMode)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- liftIO (readIORef name)
        arg1 <- liftIO noTrace_list
        liftIO (inList arg0 arg1)
      if hcond
        then do
          hret <- liftIO emptyList
          qreturn hret
          pure ()
        else do
          hret <- do
            arg0 <- do
              arg0 <- pure "\nif (globalTrace)\n    printf(\""
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef name)
                liftIO (qid arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure " at "
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef name)
                      arg1 <- do
                        arg0 <- pure "filename"
                        liftIO (boxString arg0)
                      liftIO (getTag arg0 arg1)
                    liftIO (qid arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- pure ":"
                      liftIO (boxString arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef name)
                          arg1 <- do
                            arg0 <- pure "line"
                            liftIO (boxString arg0)
                          liftIO (getTag arg0 arg1)
                        liftIO (qid arg0)
                      arg1 <- do
                        arg0 <- do
                          arg0 <- pure " (%s)\\n\", caller);\n"
                          liftIO (boxString arg0)
                        arg1 <- pure Nothing
                        liftIO (cons arg0 arg1)
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          qreturn hret
          pure ()
      pure ()
  pure Nothing

ansi3FunctionStackTrace :: Maybe Box -> IO (Maybe Box)
ansi3FunctionStackTrace name_arg = evalContT $ callCC $ \qreturn -> do
  name <- liftIO (newIORef name_arg)
  hcond <- liftIO (readIORef releaseMode)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- liftIO (readIORef name)
        arg1 <- liftIO noStackTrace_list
        liftIO (inList arg0 arg1)
      if hcond
        then do
          hret <- liftIO emptyList
          qreturn hret
          pure ()
        else do
          hret <- do
            arg0 <- do
              arg0 <- pure "\n  StackTraceMove(\"in\", \""
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef name)
                  arg1 <- do
                    arg0 <- pure "filename"
                    liftIO (boxString arg0)
                  liftIO (getTag arg0 arg1)
                liftIO (qid arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure "\", \""
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef name)
                    liftIO (qid arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- pure "\", \""
                      liftIO (boxString arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef name)
                          arg1 <- do
                            arg0 <- pure "line"
                            liftIO (boxString arg0)
                          liftIO (getTag arg0 arg1)
                        liftIO (qid arg0)
                      arg1 <- do
                        arg0 <- do
                          arg0 <- pure "\" );\n"
                          liftIO (boxString arg0)
                        arg1 <- pure Nothing
                        liftIO (cons arg0 arg1)
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          qreturn hret
          pure ()
      pure ()
  pure Nothing

ansi3Function :: Maybe Box -> IO (Maybe Box)
ansi3Function node_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  qinit <- pure Nothing
  name <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef node)
    liftIO (second arg0)
  liftIO (writeIORef name qset)
  hcond <- do
    arg0 <- liftIO (readIORef node)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- pure 0
            liftIO (listNewLine arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- pure 0
              liftIO (listNewLine arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef node)
                  liftIO (first arg0)
                liftIO (ansi3TypeMap arg0)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure " "
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef node)
                    liftIO (second arg0)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure "("
                    liftIO (boxString arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef node)
                          liftIO (third arg0)
                        liftIO (ansi3FunctionArgs arg0)
                      liftIO (qid arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- pure ") {"
                        liftIO (boxString arg0)
                      arg1 <- do
                        arg0 <- do
                          arg0 <- do
                            arg0 <- pure 1
                            liftIO (listNewLine arg0)
                          liftIO (qid arg0)
                        arg1 <- do
                          arg0 <- do
                            arg0 <- do
                              arg0 <- do
                                arg0 <- do
                                  arg0 <- liftIO (readIORef node)
                                  liftIO (fourth arg0)
                                liftIO (cdr arg0)
                              arg1 <- pure 1
                              liftIO (ansi3Declarations arg0 arg1)
                            liftIO (qid arg0)
                          arg1 <- do
                            arg0 <- do
                              arg0 <- do
                                arg0 <- liftIO (readIORef name)
                                liftIO (ansi3FunctionTrace arg0)
                              liftIO (qid arg0)
                            arg1 <- do
                              arg0 <- do
                                arg0 <- do
                                  arg0 <- liftIO (readIORef name)
                                  liftIO (ansi3FunctionStackTrace arg0)
                                liftIO (qid arg0)
                              arg1 <- do
                                arg0 <- do
                                  arg0 <- do
                                    arg0 <- do
                                      arg0 <- do
                                        arg0 <- liftIO (readIORef node)
                                        liftIO (fifth arg0)
                                      liftIO (cdr arg0)
                                    arg1 <- pure 1
                                    arg2 <- do
                                      arg0 <- liftIO (readIORef name)
                                      liftIO (stringify arg0)
                                    liftIO (ansi3Body arg0 arg1 arg2)
                                  liftIO (qid arg0)
                                arg1 <- do
                                  arg0 <- do
                                    arg0 <- pure "\n}\n"
                                    liftIO (boxString arg0)
                                  arg1 <- pure Nothing
                                  liftIO (cons arg0 arg1)
                                liftIO (cons arg0 arg1)
                              liftIO (cons arg0 arg1)
                            liftIO (cons arg0 arg1)
                          liftIO (cons arg0 arg1)
                        liftIO (cons arg0 arg1)
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

ansi3ForwardDeclaration :: Maybe Box -> IO (Maybe Box)
ansi3ForwardDeclaration node_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  hcond <- do
    arg0 <- liftIO (readIORef node)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- pure "\n"
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef node)
                liftIO (first arg0)
              liftIO (ansi3TypeMap arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure " "
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef node)
                  liftIO (second arg0)
                liftIO (qid arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure "("
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef node)
                        liftIO (third arg0)
                      liftIO (ansi3FunctionArgs arg0)
                    liftIO (qid arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- pure ");"
                      liftIO (boxString arg0)
                    arg1 <- pure Nothing
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

ansi3ForwardDeclarations :: Maybe Box -> IO (Maybe Box)
ansi3ForwardDeclarations tree_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  hcond <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (car arg0)
            liftIO (ansi3ForwardDeclaration arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (cdr arg0)
              liftIO (ansi3ForwardDeclarations arg0)
            liftIO (qid arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

ansi3Functions :: Maybe Box -> IO (Maybe Box)
ansi3Functions tree_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  hcond <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (car arg0)
            liftIO (ansi3Function arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (cdr arg0)
              liftIO (ansi3Functions arg0)
            liftIO (qid arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

ansi3Includes :: Maybe Box -> IO (Maybe Box)
ansi3Includes nodes_arg = evalContT $ callCC $ \qreturn -> do
  nodes <- liftIO (newIORef nodes_arg)
  hret <- do
    arg0 <- do
      arg0 <- pure "\n//Start include block\n#include <stdarg.h>\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n\n#include <unistd.h>\n\ntypedef int*  array;\ntypedef int bool;\n#define true 1\n#define false 0\n\n\n\nint start();  //Forwards declare the user's main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\nbool releaseMode = false;\n\n"
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }\n//End include block\n"
        liftIO (boxString arg0)
      arg1 <- pure Nothing
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

ansi3TypeDecl :: Maybe Box -> IO (Maybe Box)
ansi3TypeDecl l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef l)
      liftIO (listLength arg0)
    arg1 <- pure 2
    liftIO (greaterthan arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- pure 1
              liftIO (stringIndent arg0)
            liftIO (boxString arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef l)
              liftIO (second arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure " "
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef l)
                    liftIO (listLast arg0)
                  liftIO (ansi3TypeMap arg0)
                liftIO (qid arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure " "
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef l)
                      liftIO (first arg0)
                    liftIO (qid arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- pure ";\n"
                      liftIO (boxString arg0)
                    arg1 <- pure Nothing
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- pure 1
              liftIO (stringIndent arg0)
            liftIO (boxString arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef l)
                liftIO (listLast arg0)
              liftIO (ansi3TypeMap arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure " "
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef l)
                  liftIO (car arg0)
                liftIO (qid arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure ";\n"
                  liftIO (boxString arg0)
                arg1 <- pure Nothing
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

ansi3StructComponents :: Maybe Box -> IO (Maybe Box)
ansi3StructComponents node_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  hcond <- do
    arg0 <- liftIO (readIORef node)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef node)
              liftIO (car arg0)
            liftIO (ansi3TypeDecl arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef node)
                liftIO (cdr arg0)
              liftIO (ansi3StructComponents arg0)
            liftIO (qid arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

ansi3Struct :: Maybe Box -> IO (Maybe Box)
ansi3Struct node_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  hret <- do
    arg0 <- do
      arg0 <- liftIO (readIORef node)
      liftIO (cdr arg0)
    liftIO (ansi3StructComponents arg0)
  qreturn hret
  pure Nothing

ansi3TypeMap :: Maybe Box -> IO (Maybe Box)
ansi3TypeMap aSym_arg = evalContT $ callCC $ \qreturn -> do
  aSym <- liftIO (newIORef aSym_arg)
  qinit <- pure Nothing
  symMap <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- do
      arg0 <- pure "stringArray"
      liftIO (boxSymbol arg0)
    arg1 <- do
      arg0 <- pure "char**"
      liftIO (boxSymbol arg0)
    arg2 <- do
      arg0 <- do
        arg0 <- pure "string"
        liftIO (boxSymbol arg0)
      arg1 <- do
        arg0 <- pure "char*"
        liftIO (boxSymbol arg0)
      arg2 <- pure Nothing
      liftIO (alistCons arg0 arg1 arg2)
    liftIO (alistCons arg0 arg1 arg2)
  liftIO (writeIORef symMap qset)
  hcond <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef aSym)
        liftIO (stringify arg0)
      arg1 <- liftIO (readIORef symMap)
      liftIO (assoc arg0 arg1)
    liftIO (truthy arg0)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef aSym)
            liftIO (stringify arg0)
          arg1 <- liftIO (readIORef symMap)
          liftIO (assoc arg0 arg1)
        liftIO (cdr arg0)
      qreturn hret
      pure ()
    else do
      hret <- liftIO (readIORef aSym)
      qreturn hret
      pure ()
  pure Nothing

ansi3FuncMap :: Maybe Box -> IO (Maybe Box)
ansi3FuncMap aSym_arg = evalContT $ callCC $ \qreturn -> do
  aSym <- liftIO (newIORef aSym_arg)
  qinit <- pure Nothing
  symMap <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- pure "symbol"
    arg1 <- do
      arg0 <- liftIO (readIORef aSym)
      liftIO (boxType arg0)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      qset <- do
        arg0 <- do
          arg0 <- pure "="
          liftIO (boxSymbol arg0)
        arg1 <- do
          arg0 <- pure "equal"
          liftIO (boxSymbol arg0)
        arg2 <- do
          arg0 <- do
            arg0 <- pure "sub-string"
            liftIO (boxSymbol arg0)
          arg1 <- do
            arg0 <- pure "sub_string"
            liftIO (boxSymbol arg0)
          arg2 <- do
            arg0 <- do
              arg0 <- pure "read-file"
              liftIO (boxSymbol arg0)
            arg1 <- do
              arg0 <- pure "read_file"
              liftIO (boxSymbol arg0)
            arg2 <- do
              arg0 <- do
                arg0 <- pure "write-file"
                liftIO (boxSymbol arg0)
              arg1 <- do
                arg0 <- pure "write_file"
                liftIO (boxSymbol arg0)
              arg2 <- do
                arg0 <- do
                  arg0 <- pure ">"
                  liftIO (boxSymbol arg0)
                arg1 <- do
                  arg0 <- pure "greaterthan"
                  liftIO (boxSymbol arg0)
                arg2 <- do
                  arg0 <- do
                    arg0 <- pure "string-length"
                    liftIO (boxSymbol arg0)
                  arg1 <- do
                    arg0 <- pure "string_length"
                    liftIO (boxSymbol arg0)
                  arg2 <- do
                    arg0 <- do
                      arg0 <- pure "nil"
                      liftIO (boxSymbol arg0)
                    arg1 <- do
                      arg0 <- pure "NULL"
                      liftIO (boxSymbol arg0)
                    arg2 <- pure Nothing
                    liftIO (alistCons arg0 arg1 arg2)
                  liftIO (alistCons arg0 arg1 arg2)
                liftIO (alistCons arg0 arg1 arg2)
              liftIO (alistCons arg0 arg1 arg2)
            liftIO (alistCons arg0 arg1 arg2)
          liftIO (alistCons arg0 arg1 arg2)
        liftIO (alistCons arg0 arg1 arg2)
      liftIO (writeIORef symMap qset)
      hcond <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef aSym)
            liftIO (stringify arg0)
          arg1 <- liftIO (readIORef symMap)
          liftIO (assoc arg0 arg1)
        liftIO (truthy arg0)
      if hcond
        then do
          hret <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef aSym)
                liftIO (stringify arg0)
              arg1 <- liftIO (readIORef symMap)
              liftIO (assoc arg0 arg1)
            liftIO (cdr arg0)
          qreturn hret
          pure ()
        else do
          hret <- liftIO (readIORef aSym)
          qreturn hret
          pure ()
      pure ()
    else do
      hret <- liftIO (readIORef aSym)
      qreturn hret
      pure ()
  pure Nothing

ansi3Type :: Maybe Box -> IO (Maybe Box)
ansi3Type node_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef node)
      liftIO (second arg0)
    liftIO (isList arg0)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- pure "\ntypedef struct "
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef node)
              liftIO (first arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure " {\n"
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef node)
                    liftIO (second arg0)
                  liftIO (ansi3Struct arg0)
                liftIO (qid arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure "\n} "
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef node)
                      liftIO (first arg0)
                    liftIO (qid arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- pure ";\n"
                      liftIO (boxString arg0)
                    arg1 <- pure Nothing
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- pure "typedef "
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef node)
              liftIO (ansi3TypeDecl arg0)
            liftIO (qid arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

ansi3Types :: Maybe Box -> IO (Maybe Box)
ansi3Types nodes_arg = evalContT $ callCC $ \qreturn -> do
  nodes <- liftIO (newIORef nodes_arg)
  hcond <- do
    arg0 <- liftIO (readIORef nodes)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef nodes)
              liftIO (car arg0)
            liftIO (ansi3Type arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef nodes)
                liftIO (cdr arg0)
              liftIO (ansi3Types arg0)
            liftIO (qid arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

ansi3LoadProgram :: String -> IO (Maybe Box)
ansi3LoadProgram filename_arg = evalContT $ callCC $ \qreturn -> do
  filename <- liftIO (newIORef filename_arg)
  qinit <- pure Nothing
  tree <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  replace <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef filename)
    liftIO (loadQuon arg0)
  liftIO (writeIORef tree qset)
  qset <- do
    arg0 <- do
      arg0 <- do
        arg0 <- pure "q/shims/ansi3.qon"
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- liftIO (readIORef tree)
        liftIO (getIncludes arg0)
      liftIO (cons arg0 arg1)
    arg1 <- do
      arg0 <- liftIO (readIORef tree)
      liftIO (getTypes arg0)
    arg2 <- do
      arg0 <- liftIO (readIORef tree)
      liftIO (getFunctions arg0)
    liftIO (buildProg arg0 arg1 arg2)
  liftIO (writeIORef tree qset)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    arg1 <- pure Nothing
    liftIO (loadIncludes arg0 arg1)
  liftIO (writeIORef tree qset)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (macrowalk arg0)
  liftIO (writeIORef tree qset)
  qset <- do
    arg0 <- do
      arg0 <- pure "fprintf"
      liftIO (boxSymbol arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "stderr"
        liftIO (boxSymbol arg0)
      arg1 <- pure Nothing
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef replace qset)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    arg1 <- do
      arg0 <- pure "q"
      arg1 <- pure "log"
      liftIO (stringConcatenate arg0 arg1)
    arg2 <- liftIO (readIORef replace)
    liftIO (macrolist arg0 arg1 arg2)
  liftIO (writeIORef tree qset)
  hret <- liftIO (readIORef tree)
  qreturn hret
  pure Nothing

ansi3ProgramTree :: Maybe Box -> IO (Maybe Box)
ansi3ProgramTree tree_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef tree)
            liftIO (first arg0)
          liftIO (cdr arg0)
        liftIO (ansi3Includes arg0)
      liftIO (qid arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (second arg0)
            liftIO (cdr arg0)
          liftIO (ansi3Types arg0)
        liftIO (qid arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure "Box* globalStackTrace = NULL;\n"
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n"
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef tree)
                    liftIO (third arg0)
                  liftIO (cdr arg0)
                liftIO (ansi3ForwardDeclarations arg0)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure "\n\n//End forward declarations\n\n"
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef tree)
                        liftIO (third arg0)
                      liftIO (cdr arg0)
                    liftIO (ansi3Functions arg0)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure "\n"
                    liftIO (boxString arg0)
                  arg1 <- pure Nothing
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

ansi3Program :: Maybe Box -> IO (String)
ansi3Program tree_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef tree)
        liftIO (ansi3ProgramTree arg0)
      liftIO (flatten arg0)
    arg1 <- pure 0
    arg2 <- pure True
    arg3 <- pure False
    liftIO (listToString arg0 arg1 arg2 arg3)
  qreturn hret
  pure ""

ansi3CompileString :: String -> IO (String)
ansi3CompileString filename_arg = evalContT $ callCC $ \qreturn -> do
  filename <- liftIO (newIORef filename_arg)
  hret <- do
    arg0 <- do
      arg0 <- liftIO (readIORef filename)
      liftIO (ansi3LoadProgram arg0)
    liftIO (ansi3Program arg0)
  qreturn hret
  pure ""

ansi3Compile :: String -> IO (())
ansi3Compile filename_arg = evalContT $ callCC $ \qreturn -> do
  filename <- liftIO (newIORef filename_arg)
  _ <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef filename)
        liftIO (ansi3LoadProgram arg0)
      liftIO (ansi3ProgramTree arg0)
    liftIO (printStringTree arg0)
  _ <- do
    arg0 <- pure stderr
    arg1 <- pure "//Done printing program\n"
    liftIO (hPrintf arg0 arg1)
  pure ()

dollar :: IO (String)
dollar = evalContT $ callCC $ \qreturn -> do
  hret <- do
    arg0 <- pure 36
    liftIO (character arg0)
  qreturn hret
  pure ""

atsymbol :: IO (String)
atsymbol = evalContT $ callCC $ \qreturn -> do
  hret <- do
    arg0 <- pure 64
    liftIO (character arg0)
  qreturn hret
  pure ""

singleQuote :: IO (String)
singleQuote = evalContT $ callCC $ \qreturn -> do
  hret <- pure "'"
  qreturn hret
  pure ""

escapedSingleQuote :: IO (String)
escapedSingleQuote = evalContT $ callCC $ \qreturn -> do
  hret <- pure "\\'"
  qreturn hret
  pure ""

backslash :: IO (String)
backslash = evalContT $ callCC $ \qreturn -> do
  hret <- do
    arg0 <- pure 92
    liftIO (character arg0)
  qreturn hret
  pure ""

escapedDollar :: IO (String)
escapedDollar = evalContT $ callCC $ \qreturn -> do
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO backslash
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- liftIO dollar
          liftIO (boxString arg0)
        arg1 <- pure Nothing
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    arg1 <- pure ""
    liftIO (stringListJoin arg0 arg1)
  qreturn hret
  pure ""

escapedAtSign :: IO (String)
escapedAtSign = evalContT $ callCC $ \qreturn -> do
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO backslash
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- liftIO atsymbol
          liftIO (boxString arg0)
        arg1 <- pure Nothing
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    arg1 <- pure ""
    liftIO (stringListJoin arg0 arg1)
  qreturn hret
  pure ""

escapeSingleQuotes :: String -> IO (String)
escapeSingleQuotes s_arg = evalContT $ callCC $ \qreturn -> do
  s <- liftIO (newIORef s_arg)
  hret <- do
    arg0 <- liftIO singleQuote
    arg1 <- liftIO escapedSingleQuote
    arg2 <- liftIO (readIORef s)
    liftIO (stringReplace arg0 arg1 arg2)
  qreturn hret
  pure ""

escapePerlString :: String -> IO (String)
escapePerlString s_arg = evalContT $ callCC $ \qreturn -> do
  s <- liftIO (newIORef s_arg)
  hret <- do
    arg0 <- liftIO atsymbol
    arg1 <- liftIO escapedAtSign
    arg2 <- do
      arg0 <- liftIO dollar
      arg1 <- liftIO escapedDollar
      arg2 <- liftIO (readIORef s)
      liftIO (stringReplace arg0 arg1 arg2)
    liftIO (stringReplace arg0 arg1 arg2)
  qreturn hret
  pure ""

getGlobalVariables :: IO (Maybe Box)
getGlobalVariables = evalContT $ callCC $ \qreturn -> do
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- pure "stderr"
        liftIO (boxSymbol arg0)
      liftIO (qid arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- pure "true"
          liftIO (boxSymbol arg0)
        liftIO (qid arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- pure "false"
            liftIO (boxSymbol arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- pure "releaseMode"
              liftIO (boxSymbol arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- pure "caller"
                liftIO (boxSymbol arg0)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- pure "globalTrace"
                  liftIO (boxSymbol arg0)
                liftIO (qid arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- pure "globalStepTrace"
                    liftIO (boxSymbol arg0)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- pure "globalStackTrace"
                      liftIO (boxSymbol arg0)
                    liftIO (qid arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- pure "globalArgsCount"
                        liftIO (boxSymbol arg0)
                      liftIO (qid arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- pure "globalArgs"
                          liftIO (boxSymbol arg0)
                        liftIO (qid arg0)
                      arg1 <- do
                        arg0 <- do
                          arg0 <- do
                            arg0 <- pure "quonGlobalArgs"
                            liftIO (boxSymbol arg0)
                          liftIO (qid arg0)
                        arg1 <- pure Nothing
                        liftIO (cons arg0 arg1)
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

collectVariables :: Maybe Box -> Maybe Box -> IO (Maybe Box)
collectVariables args_arg decls_arg = evalContT $ callCC $ \qreturn -> do
  args <- liftIO (newIORef args_arg)
  decls <- liftIO (newIORef decls_arg)
  qinit <- pure Nothing
  variables <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  decl <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef args)
    liftIO (collectVariablesFromArgs arg0)
  liftIO (writeIORef variables qset)
  qset <- do
    arg0 <- liftIO (readIORef variables)
    arg1 <- do
      arg0 <- liftIO (readIORef decls)
      liftIO (collectVariablesFromDecls arg0)
    liftIO (appendVariables arg0 arg1)
  liftIO (writeIORef variables qset)
  qset <- do
    arg0 <- liftIO (readIORef variables)
    arg1 <- liftIO getGlobalVariables
    liftIO (appendVariables arg0 arg1)
  liftIO (writeIORef variables qset)
  hret <- liftIO (readIORef variables)
  qreturn hret
  pure Nothing

perlGlobalVariables :: IO (Maybe Box)
perlGlobalVariables = evalContT $ callCC $ \qreturn -> do
  hret <- do
    arg0 <- do
      arg0 <- pure "our "
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- liftIO dollar
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure "globalArgsCount;\n"
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "our "
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- liftIO dollar
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure "globalArgs;\n"
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure "our "
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- liftIO dollar
                    liftIO (boxString arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- pure "releaseMode;\n"
                      liftIO (boxString arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- pure "our "
                        liftIO (boxString arg0)
                      arg1 <- do
                        arg0 <- do
                          arg0 <- liftIO dollar
                          liftIO (boxString arg0)
                        arg1 <- do
                          arg0 <- do
                            arg0 <- pure "globalTrace;\n"
                            liftIO (boxString arg0)
                          arg1 <- do
                            arg0 <- do
                              arg0 <- pure "our "
                              liftIO (boxString arg0)
                            arg1 <- do
                              arg0 <- do
                                arg0 <- liftIO dollar
                                liftIO (boxString arg0)
                              arg1 <- do
                                arg0 <- do
                                  arg0 <- pure "globalStepTrace;\n"
                                  liftIO (boxString arg0)
                                arg1 <- do
                                  arg0 <- do
                                    arg0 <- pure "our "
                                    liftIO (boxString arg0)
                                  arg1 <- do
                                    arg0 <- do
                                      arg0 <- liftIO dollar
                                      liftIO (boxString arg0)
                                    arg1 <- do
                                      arg0 <- do
                                        arg0 <- pure "globalStackTrace;\n"
                                        liftIO (boxString arg0)
                                      arg1 <- do
                                        arg0 <- do
                                          arg0 <- pure "our "
                                          liftIO (boxString arg0)
                                        arg1 <- do
                                          arg0 <- do
                                            arg0 <- liftIO dollar
                                            liftIO (boxString arg0)
                                          arg1 <- do
                                            arg0 <- do
                                              arg0 <- pure "caller;\n"
                                              liftIO (boxString arg0)
                                            arg1 <- do
                                              arg0 <- do
                                                arg0 <- pure "our "
                                                liftIO (boxString arg0)
                                              arg1 <- do
                                                arg0 <- do
                                                  arg0 <- liftIO dollar
                                                  liftIO (boxString arg0)
                                                arg1 <- do
                                                  arg0 <- do
                                                    arg0 <- pure "false = 0;\n"
                                                    liftIO (boxString arg0)
                                                  arg1 <- do
                                                    arg0 <- do
                                                      arg0 <- pure "our "
                                                      liftIO (boxString arg0)
                                                    arg1 <- do
                                                      arg0 <- do
                                                        arg0 <- liftIO dollar
                                                        liftIO (boxString arg0)
                                                      arg1 <- do
                                                        arg0 <- do
                                                          arg0 <- pure "true = 1;\n"
                                                          liftIO (boxString arg0)
                                                        arg1 <- do
                                                          arg0 <- do
                                                            arg0 <- pure "my "
                                                            liftIO (boxString arg0)
                                                          arg1 <- do
                                                            arg0 <- do
                                                              arg0 <- liftIO dollar
                                                              liftIO (boxString arg0)
                                                            arg1 <- do
                                                              arg0 <- do
                                                                arg0 <- pure "stderr = \\*STDERR;\n"
                                                                liftIO (boxString arg0)
                                                              arg1 <- do
                                                                arg0 <- do
                                                                  arg0 <- pure "our "
                                                                  liftIO (boxString arg0)
                                                                arg1 <- do
                                                                  arg0 <- do
                                                                    arg0 <- liftIO dollar
                                                                    liftIO (boxString arg0)
                                                                  arg1 <- do
                                                                    arg0 <- do
                                                                      arg0 <- pure "quonGlobalArgs;\n"
                                                                      liftIO (boxString arg0)
                                                                    arg1 <- pure Nothing
                                                                    liftIO (cons arg0 arg1)
                                                                  liftIO (cons arg0 arg1)
                                                                liftIO (cons arg0 arg1)
                                                              liftIO (cons arg0 arg1)
                                                            liftIO (cons arg0 arg1)
                                                          liftIO (cons arg0 arg1)
                                                        liftIO (cons arg0 arg1)
                                                      liftIO (cons arg0 arg1)
                                                    liftIO (cons arg0 arg1)
                                                  liftIO (cons arg0 arg1)
                                                liftIO (cons arg0 arg1)
                                              liftIO (cons arg0 arg1)
                                            liftIO (cons arg0 arg1)
                                          liftIO (cons arg0 arg1)
                                        liftIO (cons arg0 arg1)
                                      liftIO (cons arg0 arg1)
                                    liftIO (cons arg0 arg1)
                                  liftIO (cons arg0 arg1)
                                liftIO (cons arg0 arg1)
                              liftIO (cons arg0 arg1)
                            liftIO (cons arg0 arg1)
                          liftIO (cons arg0 arg1)
                        liftIO (cons arg0 arg1)
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

perlMainEntry :: IO (Maybe Box)
perlMainEntry = evalContT $ callCC $ \qreturn -> do
  hret <- do
    arg0 <- do
      arg0 <- pure "\n# Main entry point\n"
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- liftIO dollar
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure "globalArgsCount = scalar("
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- liftIO atsymbol
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure "ARGV) + 1;\n"
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- liftIO dollar
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure "globalArgs = \\"
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- liftIO atsymbol
                    liftIO (boxString arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- pure "ARGV;\n"
                      liftIO (boxString arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- pure "unshift "
                        liftIO (boxString arg0)
                      arg1 <- do
                        arg0 <- do
                          arg0 <- liftIO atsymbol
                          liftIO (boxString arg0)
                        arg1 <- do
                          arg0 <- do
                            arg0 <- liftIO dollar
                            liftIO (boxString arg0)
                          arg1 <- do
                            arg0 <- do
                              arg0 <- pure "globalArgs, 'fixmeprogname' ;\n"
                              liftIO (boxString arg0)
                            arg1 <- do
                              arg0 <- do
                                arg0 <- liftIO dollar
                                liftIO (boxString arg0)
                              arg1 <- do
                                arg0 <- do
                                  arg0 <- pure "quonGlobalArgs = [];\n"
                                  liftIO (boxString arg0)
                                arg1 <- do
                                  arg0 <- do
                                    arg0 <- pure "for my "
                                    liftIO (boxString arg0)
                                  arg1 <- do
                                    arg0 <- do
                                      arg0 <- liftIO dollar
                                      liftIO (boxString arg0)
                                    arg1 <- do
                                      arg0 <- do
                                        arg0 <- pure "arg ("
                                        liftIO (boxString arg0)
                                      arg1 <- do
                                        arg0 <- do
                                          arg0 <- liftIO atsymbol
                                          liftIO (boxString arg0)
                                        arg1 <- do
                                          arg0 <- do
                                            arg0 <- liftIO dollar
                                            liftIO (boxString arg0)
                                          arg1 <- do
                                            arg0 <- do
                                              arg0 <- pure "globalArgs) {\n"
                                              liftIO (boxString arg0)
                                            arg1 <- do
                                              arg0 <- do
                                                arg0 <- pure "    push "
                                                liftIO (boxString arg0)
                                              arg1 <- do
                                                arg0 <- do
                                                  arg0 <- liftIO atsymbol
                                                  liftIO (boxString arg0)
                                                arg1 <- do
                                                  arg0 <- do
                                                    arg0 <- liftIO dollar
                                                    liftIO (boxString arg0)
                                                  arg1 <- do
                                                    arg0 <- do
                                                      arg0 <- pure "quonGlobalArgs, {car => "
                                                      liftIO (boxString arg0)
                                                    arg1 <- do
                                                      arg0 <- do
                                                        arg0 <- liftIO dollar
                                                        liftIO (boxString arg0)
                                                      arg1 <- do
                                                        arg0 <- do
                                                          arg0 <- pure "arg, cdr => undef};\n"
                                                          liftIO (boxString arg0)
                                                        arg1 <- do
                                                          arg0 <- do
                                                            arg0 <- pure "}\n"
                                                            liftIO (boxString arg0)
                                                          arg1 <- do
                                                            arg0 <- do
                                                              arg0 <- pure "for (my "
                                                              liftIO (boxString arg0)
                                                            arg1 <- do
                                                              arg0 <- do
                                                                arg0 <- liftIO dollar
                                                                liftIO (boxString arg0)
                                                              arg1 <- do
                                                                arg0 <- do
                                                                  arg0 <- pure "i = scalar("
                                                                  liftIO (boxString arg0)
                                                                arg1 <- do
                                                                  arg0 <- do
                                                                    arg0 <- liftIO atsymbol
                                                                    liftIO (boxString arg0)
                                                                  arg1 <- do
                                                                    arg0 <- do
                                                                      arg0 <- liftIO dollar
                                                                      liftIO (boxString arg0)
                                                                    arg1 <- do
                                                                      arg0 <- do
                                                                        arg0 <- pure "quonGlobalArgs) - 1; "
                                                                        liftIO (boxString arg0)
                                                                      arg1 <- do
                                                                        arg0 <- do
                                                                          arg0 <- liftIO dollar
                                                                          liftIO (boxString arg0)
                                                                        arg1 <- do
                                                                          arg0 <- do
                                                                            arg0 <- pure "i >= 0; "
                                                                            liftIO (boxString arg0)
                                                                          arg1 <- do
                                                                            arg0 <- do
                                                                              arg0 <- liftIO dollar
                                                                              liftIO (boxString arg0)
                                                                            arg1 <- do
                                                                              arg0 <- do
                                                                                arg0 <- pure "i--) {\n"
                                                                                liftIO (boxString arg0)
                                                                              arg1 <- do
                                                                                arg0 <- do
                                                                                  arg0 <- pure "    "
                                                                                  liftIO (boxString arg0)
                                                                                arg1 <- do
                                                                                  arg0 <- do
                                                                                    arg0 <- liftIO dollar
                                                                                    liftIO (boxString arg0)
                                                                                  arg1 <- do
                                                                                    arg0 <- do
                                                                                      arg0 <- pure "quonGlobalArgs->["
                                                                                      liftIO (boxString arg0)
                                                                                    arg1 <- do
                                                                                      arg0 <- do
                                                                                        arg0 <- liftIO dollar
                                                                                        liftIO (boxString arg0)
                                                                                      arg1 <- do
                                                                                        arg0 <- do
                                                                                          arg0 <- pure "i]->{cdr} = "
                                                                                          liftIO (boxString arg0)
                                                                                        arg1 <- do
                                                                                          arg0 <- do
                                                                                            arg0 <- liftIO dollar
                                                                                            liftIO (boxString arg0)
                                                                                          arg1 <- do
                                                                                            arg0 <- do
                                                                                              arg0 <- pure "quonGlobalArgs->["
                                                                                              liftIO (boxString arg0)
                                                                                            arg1 <- do
                                                                                              arg0 <- do
                                                                                                arg0 <- liftIO dollar
                                                                                                liftIO (boxString arg0)
                                                                                              arg1 <- do
                                                                                                arg0 <- do
                                                                                                  arg0 <- pure "i + 1];\n"
                                                                                                  liftIO (boxString arg0)
                                                                                                arg1 <- do
                                                                                                  arg0 <- do
                                                                                                    arg0 <- pure "}\n"
                                                                                                    liftIO (boxString arg0)
                                                                                                  arg1 <- do
                                                                                                    arg0 <- do
                                                                                                      arg0 <- pure "*stderr = *STDERR;\n"
                                                                                                      liftIO (boxString arg0)
                                                                                                    arg1 <- do
                                                                                                      arg0 <- do
                                                                                                        arg0 <- pure "sub fprintf { my "
                                                                                                        liftIO (boxString arg0)
                                                                                                      arg1 <- do
                                                                                                        arg0 <- do
                                                                                                          arg0 <- liftIO dollar
                                                                                                          liftIO (boxString arg0)
                                                                                                        arg1 <- do
                                                                                                          arg0 <- do
                                                                                                            arg0 <- pure "f = shift; printf "
                                                                                                            liftIO (boxString arg0)
                                                                                                          arg1 <- do
                                                                                                            arg0 <- do
                                                                                                              arg0 <- liftIO dollar
                                                                                                              liftIO (boxString arg0)
                                                                                                            arg1 <- do
                                                                                                              arg0 <- do
                                                                                                                arg0 <- pure "f "
                                                                                                                liftIO (boxString arg0)
                                                                                                              arg1 <- do
                                                                                                                arg0 <- do
                                                                                                                  arg0 <- liftIO atsymbol
                                                                                                                  liftIO (boxString arg0)
                                                                                                                arg1 <- do
                                                                                                                  arg0 <- do
                                                                                                                    arg0 <- pure "_ }\n"
                                                                                                                    liftIO (boxString arg0)
                                                                                                                  arg1 <- do
                                                                                                                    arg0 <- do
                                                                                                                      arg0 <- pure "start();\n"
                                                                                                                      liftIO (boxString arg0)
                                                                                                                    arg1 <- pure Nothing
                                                                                                                    liftIO (cons arg0 arg1)
                                                                                                                  liftIO (cons arg0 arg1)
                                                                                                                liftIO (cons arg0 arg1)
                                                                                                              liftIO (cons arg0 arg1)
                                                                                                            liftIO (cons arg0 arg1)
                                                                                                          liftIO (cons arg0 arg1)
                                                                                                        liftIO (cons arg0 arg1)
                                                                                                      liftIO (cons arg0 arg1)
                                                                                                    liftIO (cons arg0 arg1)
                                                                                                  liftIO (cons arg0 arg1)
                                                                                                liftIO (cons arg0 arg1)
                                                                                              liftIO (cons arg0 arg1)
                                                                                            liftIO (cons arg0 arg1)
                                                                                          liftIO (cons arg0 arg1)
                                                                                        liftIO (cons arg0 arg1)
                                                                                      liftIO (cons arg0 arg1)
                                                                                    liftIO (cons arg0 arg1)
                                                                                  liftIO (cons arg0 arg1)
                                                                                liftIO (cons arg0 arg1)
                                                                              liftIO (cons arg0 arg1)
                                                                            liftIO (cons arg0 arg1)
                                                                          liftIO (cons arg0 arg1)
                                                                        liftIO (cons arg0 arg1)
                                                                      liftIO (cons arg0 arg1)
                                                                    liftIO (cons arg0 arg1)
                                                                  liftIO (cons arg0 arg1)
                                                                liftIO (cons arg0 arg1)
                                                              liftIO (cons arg0 arg1)
                                                            liftIO (cons arg0 arg1)
                                                          liftIO (cons arg0 arg1)
                                                        liftIO (cons arg0 arg1)
                                                      liftIO (cons arg0 arg1)
                                                    liftIO (cons arg0 arg1)
                                                  liftIO (cons arg0 arg1)
                                                liftIO (cons arg0 arg1)
                                              liftIO (cons arg0 arg1)
                                            liftIO (cons arg0 arg1)
                                          liftIO (cons arg0 arg1)
                                        liftIO (cons arg0 arg1)
                                      liftIO (cons arg0 arg1)
                                    liftIO (cons arg0 arg1)
                                  liftIO (cons arg0 arg1)
                                liftIO (cons arg0 arg1)
                              liftIO (cons arg0 arg1)
                            liftIO (cons arg0 arg1)
                          liftIO (cons arg0 arg1)
                        liftIO (cons arg0 arg1)
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

collectVariablesFromArgs :: Maybe Box -> IO (Maybe Box)
collectVariablesFromArgs args_arg = evalContT $ callCC $ \qreturn -> do
  args <- liftIO (newIORef args_arg)
  qinit <- pure Nothing
  variables <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef args)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- liftIO (readIORef variables)
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef args)
            liftIO (first arg0)
          liftIO (stringify arg0)
        arg1 <- pure "list"
        liftIO (equalString arg0 arg1)
      if hcond
        then do
          qset <- do
            arg0 <- do
              arg0 <- liftIO (readIORef args)
              liftIO (second arg0)
            arg1 <- liftIO (readIORef variables)
            liftIO (cons arg0 arg1)
          liftIO (writeIORef variables qset)
          hret <- do
            arg0 <- liftIO (readIORef variables)
            arg1 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef args)
                liftIO (cddr arg0)
              liftIO (collectVariablesFromArgs arg0)
            liftIO (appendVariables arg0 arg1)
          qreturn hret
          pure ()
        else do
          qset <- do
            arg0 <- do
              arg0 <- liftIO (readIORef args)
              liftIO (second arg0)
            arg1 <- liftIO (readIORef variables)
            liftIO (cons arg0 arg1)
          liftIO (writeIORef variables qset)
          hret <- do
            arg0 <- liftIO (readIORef variables)
            arg1 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef args)
                liftIO (cddr arg0)
              liftIO (collectVariablesFromArgs arg0)
            liftIO (appendVariables arg0 arg1)
          qreturn hret
          pure ()
      pure ()
  pure Nothing

collectVariablesFromDecls :: Maybe Box -> IO (Maybe Box)
collectVariablesFromDecls decls_arg = evalContT $ callCC $ \qreturn -> do
  decls <- liftIO (newIORef decls_arg)
  qinit <- pure Nothing
  variables <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  decl <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef decls)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- liftIO (readIORef variables)
      qreturn hret
      pure ()
    else do
      qset <- do
        arg0 <- liftIO (readIORef decls)
        liftIO (car arg0)
      liftIO (writeIORef decl qset)
      qset <- do
        arg0 <- do
          arg0 <- liftIO (readIORef decl)
          liftIO (second arg0)
        arg1 <- liftIO (readIORef variables)
        liftIO (cons arg0 arg1)
      liftIO (writeIORef variables qset)
      hret <- do
        arg0 <- liftIO (readIORef variables)
        arg1 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef decls)
            liftIO (cdr arg0)
          liftIO (collectVariablesFromDecls arg0)
        liftIO (appendVariables arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

appendVariables :: Maybe Box -> Maybe Box -> IO (Maybe Box)
appendVariables vars1_arg vars2_arg = evalContT $ callCC $ \qreturn -> do
  vars1 <- liftIO (newIORef vars1_arg)
  vars2 <- liftIO (newIORef vars2_arg)
  hcond <- do
    arg0 <- liftIO (readIORef vars2)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- liftIO (readIORef vars1)
      qreturn hret
      pure ()
    else do
      qset <- do
        arg0 <- do
          arg0 <- liftIO (readIORef vars2)
          liftIO (car arg0)
        arg1 <- liftIO (readIORef vars1)
        liftIO (cons arg0 arg1)
      liftIO (writeIORef vars1 qset)
      hret <- do
        arg0 <- liftIO (readIORef vars1)
        arg1 <- do
          arg0 <- liftIO (readIORef vars2)
          liftIO (cdr arg0)
        liftIO (appendVariables arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

perlFunctionArgs :: Maybe Box -> IO (Maybe Box)
perlFunctionArgs tree_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  hcond <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- do
          arg0 <- liftIO (readIORef tree)
          liftIO (cddr arg0)
        liftIO (isNil arg0)
      if hcond
        then do
          hret <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO dollar
                liftIO (boxString arg0)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef tree)
                  liftIO (second arg0)
                liftIO (qid arg0)
              arg1 <- pure Nothing
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          qreturn hret
          pure ()
        else do
          hret <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO dollar
                liftIO (boxString arg0)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef tree)
                  liftIO (second arg0)
                liftIO (qid arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure ", "
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef tree)
                        liftIO (cddr arg0)
                      liftIO (perlFunctionArgs arg0)
                    liftIO (qid arg0)
                  arg1 <- pure Nothing
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          qreturn hret
          pure ()
      pure ()
  pure Nothing

perlAtom :: Maybe Box -> Maybe Box -> IO (Maybe Box)
perlAtom tree_arg variables_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  variables <- liftIO (newIORef variables_arg)
  hcond <- do
    arg0 <- pure "string"
    arg1 <- do
      arg0 <- liftIO (readIORef tree)
      liftIO (boxType arg0)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- pure "\""
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef tree)
                  liftIO (stringify arg0)
                liftIO (escapePerlString arg0)
              liftIO (boxString arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure "\""
              liftIO (boxString arg0)
            arg1 <- pure Nothing
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef tree)
            arg1 <- liftIO (readIORef variables)
            liftIO (perlFuncMap arg0 arg1)
          liftIO (qid arg0)
        arg1 <- pure Nothing
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

perlExpression :: Maybe Box -> Int -> Maybe Box -> IO (Maybe Box)
perlExpression tree_arg indent_arg variables_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  indent <- liftIO (newIORef indent_arg)
  variables <- liftIO (newIORef variables_arg)
  qinit <- pure Nothing
  thing <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef tree)
      liftIO (isList arg0)
    liftIO (notBool arg0)
  if hcond
    then do
      hret <- do
        arg0 <- liftIO (readIORef tree)
        arg1 <- liftIO (readIORef variables)
        liftIO (perlAtom arg0 arg1)
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- pure 1
        arg1 <- do
          arg0 <- liftIO (readIORef tree)
          liftIO (listLength arg0)
        liftIO (equal arg0 arg1)
      if hcond
        then do
          hcond <- do
            arg0 <- do
              arg0 <- pure "return"
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (car arg0)
            liftIO (equalBox arg0 arg1)
          if hcond
            then do
              hret <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef tree)
                      liftIO (car arg0)
                    arg1 <- liftIO (readIORef variables)
                    liftIO (perlFuncMap arg0 arg1)
                  liftIO (qid arg0)
                arg1 <- pure Nothing
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
            else do
              hret <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef tree)
                      liftIO (car arg0)
                    arg1 <- liftIO (readIORef variables)
                    liftIO (perlFuncMap arg0 arg1)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure "()"
                    liftIO (boxString arg0)
                  arg1 <- pure Nothing
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
          pure ()
        else do
          qset <- do
            arg0 <- liftIO (readIORef tree)
            liftIO (first arg0)
          liftIO (writeIORef thing qset)
          hcond <- do
            arg0 <- do
              arg0 <- pure "get-struct"
              liftIO (boxSymbol arg0)
            arg1 <- liftIO (readIORef thing)
            liftIO (equalBox arg0 arg1)
          if hcond
            then do
              hret <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO dollar
                    liftIO (boxString arg0)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef tree)
                      liftIO (second arg0)
                    liftIO (qid arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- pure "->{"
                      liftIO (boxString arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef tree)
                          liftIO (third arg0)
                        liftIO (qid arg0)
                      arg1 <- do
                        arg0 <- do
                          arg0 <- pure "}"
                          liftIO (boxString arg0)
                        arg1 <- pure Nothing
                        liftIO (cons arg0 arg1)
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
            else do
              hcond <- do
                arg0 <- do
                  arg0 <- pure "new"
                  liftIO (boxSymbol arg0)
                arg1 <- liftIO (readIORef thing)
                liftIO (equalBox arg0 arg1)
              if hcond
                then do
                  hret <- do
                    arg0 <- do
                      arg0 <- pure "{}"
                      liftIO (boxString arg0)
                    arg1 <- pure Nothing
                    liftIO (cons arg0 arg1)
                  qreturn hret
                  pure ()
                else do
                  hcond <- do
                    arg0 <- do
                      arg0 <- pure "passthrough"
                      liftIO (boxSymbol arg0)
                    arg1 <- liftIO (readIORef thing)
                    liftIO (equalBox arg0 arg1)
                  if hcond
                    then do
                      hret <- do
                        arg0 <- do
                          arg0 <- do
                            arg0 <- liftIO (readIORef tree)
                            liftIO (second arg0)
                          liftIO (qid arg0)
                        arg1 <- pure Nothing
                        liftIO (cons arg0 arg1)
                      qreturn hret
                      pure ()
                    else do
                      hcond <- do
                        arg0 <- do
                          arg0 <- pure "binop"
                          liftIO (boxSymbol arg0)
                        arg1 <- liftIO (readIORef thing)
                        liftIO (equalBox arg0 arg1)
                      if hcond
                        then do
                          hret <- do
                            arg0 <- do
                              arg0 <- pure "("
                              liftIO (boxString arg0)
                            arg1 <- do
                              arg0 <- do
                                arg0 <- do
                                  arg0 <- do
                                    arg0 <- liftIO (readIORef tree)
                                    liftIO (third arg0)
                                  arg1 <- liftIO (readIORef indent)
                                  arg2 <- liftIO (readIORef variables)
                                  liftIO (perlExpression arg0 arg1 arg2)
                                liftIO (qid arg0)
                              arg1 <- do
                                arg0 <- do
                                  arg0 <- pure " "
                                  liftIO (boxString arg0)
                                arg1 <- do
                                  arg0 <- do
                                    arg0 <- do
                                      arg0 <- liftIO (readIORef tree)
                                      liftIO (second arg0)
                                    liftIO (qid arg0)
                                  arg1 <- do
                                    arg0 <- do
                                      arg0 <- pure " "
                                      liftIO (boxString arg0)
                                    arg1 <- do
                                      arg0 <- do
                                        arg0 <- do
                                          arg0 <- do
                                            arg0 <- liftIO (readIORef tree)
                                            liftIO (fourth arg0)
                                          arg1 <- liftIO (readIORef indent)
                                          arg2 <- liftIO (readIORef variables)
                                          liftIO (perlExpression arg0 arg1 arg2)
                                        liftIO (qid arg0)
                                      arg1 <- do
                                        arg0 <- do
                                          arg0 <- pure ")"
                                          liftIO (boxString arg0)
                                        arg1 <- pure Nothing
                                        liftIO (cons arg0 arg1)
                                      liftIO (cons arg0 arg1)
                                    liftIO (cons arg0 arg1)
                                  liftIO (cons arg0 arg1)
                                liftIO (cons arg0 arg1)
                              liftIO (cons arg0 arg1)
                            liftIO (cons arg0 arg1)
                          qreturn hret
                          pure ()
                        else do
                          hret <- do
                            arg0 <- do
                              arg0 <- do
                                arg0 <- do
                                  arg0 <- liftIO (readIORef tree)
                                  liftIO (car arg0)
                                arg1 <- liftIO (readIORef variables)
                                liftIO (perlFuncMap arg0 arg1)
                              liftIO (qid arg0)
                            arg1 <- do
                              arg0 <- do
                                arg0 <- pure "("
                                liftIO (boxString arg0)
                              arg1 <- do
                                arg0 <- do
                                  arg0 <- do
                                    arg0 <- do
                                      arg0 <- liftIO (readIORef tree)
                                      liftIO (cdr arg0)
                                    arg1 <- liftIO (readIORef indent)
                                    arg2 <- liftIO (readIORef variables)
                                    liftIO (perlRecurList arg0 arg1 arg2)
                                  liftIO (qid arg0)
                                arg1 <- do
                                  arg0 <- do
                                    arg0 <- pure ")"
                                    liftIO (boxString arg0)
                                  arg1 <- pure Nothing
                                  liftIO (cons arg0 arg1)
                                liftIO (cons arg0 arg1)
                              liftIO (cons arg0 arg1)
                            liftIO (cons arg0 arg1)
                          qreturn hret
                          pure ()
                      pure ()
                  pure ()
              pure ()
          pure ()
      pure ()
  pure Nothing

perlRecurList :: Maybe Box -> Int -> Maybe Box -> IO (Maybe Box)
perlRecurList expr_arg indent_arg variables_arg = evalContT $ callCC $ \qreturn -> do
  expr <- liftIO (newIORef expr_arg)
  indent <- liftIO (newIORef indent_arg)
  variables <- liftIO (newIORef variables_arg)
  hcond <- do
    arg0 <- liftIO (readIORef expr)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- do
          arg0 <- liftIO (readIORef expr)
          liftIO (cdr arg0)
        liftIO (isNil arg0)
      if hcond
        then do
          hret <- do
            arg0 <- do
              arg0 <- liftIO (readIORef expr)
              liftIO (car arg0)
            arg1 <- liftIO (readIORef indent)
            arg2 <- liftIO (readIORef variables)
            liftIO (perlExpression arg0 arg1 arg2)
          qreturn hret
          pure ()
        else do
          hret <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef expr)
                  liftIO (car arg0)
                arg1 <- liftIO (readIORef indent)
                arg2 <- liftIO (readIORef variables)
                liftIO (perlExpression arg0 arg1 arg2)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure ", "
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef expr)
                      liftIO (cdr arg0)
                    arg1 <- liftIO (readIORef indent)
                    arg2 <- liftIO (readIORef variables)
                    liftIO (perlRecurList arg0 arg1 arg2)
                  liftIO (qid arg0)
                arg1 <- pure Nothing
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          qreturn hret
          pure ()
      pure ()
  pure Nothing

perlSet :: Maybe Box -> Int -> Maybe Box -> IO (Maybe Box)
perlSet node_arg indent_arg variables_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  indent <- liftIO (newIORef indent_arg)
  variables <- liftIO (newIORef variables_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef indent)
        liftIO (listNewLine arg0)
      liftIO (qid arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef node)
            liftIO (second arg0)
          arg1 <- liftIO (readIORef variables)
          liftIO (perlFuncMap arg0 arg1)
        liftIO (qid arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure " = "
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef node)
                liftIO (third arg0)
              arg1 <- liftIO (readIORef indent)
              arg2 <- liftIO (readIORef variables)
              liftIO (perlExpression arg0 arg1 arg2)
            liftIO (qid arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

perlSetStruct :: Maybe Box -> Int -> Maybe Box -> IO (Maybe Box)
perlSetStruct node_arg indent_arg variables_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  indent <- liftIO (newIORef indent_arg)
  variables <- liftIO (newIORef variables_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef indent)
        liftIO (listNewLine arg0)
      liftIO (qid arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef node)
            liftIO (second arg0)
          arg1 <- liftIO (readIORef variables)
          liftIO (perlFuncMap arg0 arg1)
        liftIO (qid arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure "->{"
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef node)
              liftIO (third arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure "} = "
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef node)
                    liftIO (fourth arg0)
                  arg1 <- liftIO (readIORef indent)
                  arg2 <- liftIO (readIORef variables)
                  liftIO (perlExpression arg0 arg1 arg2)
                liftIO (qid arg0)
              arg1 <- pure Nothing
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

perlReturn :: Maybe Box -> Int -> Maybe Box -> IO (Maybe Box)
perlReturn node_arg indent_arg variables_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  indent <- liftIO (newIORef indent_arg)
  variables <- liftIO (newIORef variables_arg)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef node)
      liftIO (listLength arg0)
    arg1 <- pure 1
    liftIO (greaterthan arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef indent)
            liftIO (listNewLine arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "return "
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef node)
                  liftIO (cadr arg0)
                arg1 <- liftIO (readIORef indent)
                arg2 <- liftIO (readIORef variables)
                liftIO (perlExpression arg0 arg1 arg2)
              liftIO (qid arg0)
            arg1 <- pure Nothing
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef indent)
            liftIO (listNewLine arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "return"
            liftIO (boxString arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

perlIf :: Maybe Box -> Int -> Maybe Box -> IO (Maybe Box)
perlIf node_arg indent_arg variables_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  indent <- liftIO (newIORef indent_arg)
  variables <- liftIO (newIORef variables_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef indent)
        liftIO (listNewLine arg0)
      liftIO (qid arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "if ( "
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef node)
              liftIO (second arg0)
            arg1 <- pure 0
            arg2 <- liftIO (readIORef variables)
            liftIO (perlExpression arg0 arg1 arg2)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure " ) {"
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef node)
                    liftIO (third arg0)
                  liftIO (cdr arg0)
                arg1 <- do
                  arg0 <- liftIO (readIORef indent)
                  liftIO (add1 arg0)
                arg2 <- liftIO (readIORef variables)
                liftIO (perlBody arg0 arg1 arg2)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef indent)
                  liftIO (listNewLine arg0)
                liftIO (qid arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure "} else {"
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef node)
                          liftIO (fourth arg0)
                        liftIO (cdr arg0)
                      arg1 <- do
                        arg0 <- liftIO (readIORef indent)
                        liftIO (add1 arg0)
                      arg2 <- liftIO (readIORef variables)
                      liftIO (perlBody arg0 arg1 arg2)
                    liftIO (qid arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef indent)
                        liftIO (listNewLine arg0)
                      liftIO (qid arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- pure "}"
                        liftIO (boxString arg0)
                      arg1 <- pure Nothing
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

perlStatement :: Maybe Box -> Int -> Maybe Box -> IO (Maybe Box)
perlStatement node_arg indent_arg variables_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  indent <- liftIO (newIORef indent_arg)
  variables <- liftIO (newIORef variables_arg)
  hcond <- do
    arg0 <- do
      arg0 <- pure "set"
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- liftIO (readIORef node)
      liftIO (first arg0)
    liftIO (equalBox arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef node)
            arg1 <- liftIO (readIORef indent)
            arg2 <- liftIO (readIORef variables)
            liftIO (perlSet arg0 arg1 arg2)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure ";\n"
            liftIO (boxString arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- do
          arg0 <- pure "set-struct"
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- liftIO (readIORef node)
          liftIO (first arg0)
        liftIO (equalBox arg0 arg1)
      if hcond
        then do
          hret <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef node)
                arg1 <- liftIO (readIORef indent)
                arg2 <- liftIO (readIORef variables)
                liftIO (perlSetStruct arg0 arg1 arg2)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure ";\n"
                liftIO (boxString arg0)
              arg1 <- pure Nothing
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          qreturn hret
          pure ()
        else do
          hcond <- do
            arg0 <- do
              arg0 <- pure "if"
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- liftIO (readIORef node)
              liftIO (first arg0)
            liftIO (equalBox arg0 arg1)
          if hcond
            then do
              hret <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef node)
                    arg1 <- liftIO (readIORef indent)
                    arg2 <- liftIO (readIORef variables)
                    liftIO (perlIf arg0 arg1 arg2)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure ";\n"
                    liftIO (boxString arg0)
                  arg1 <- pure Nothing
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
            else do
              hcond <- do
                arg0 <- do
                  arg0 <- pure "return"
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- liftIO (readIORef node)
                  liftIO (first arg0)
                liftIO (equalBox arg0 arg1)
              if hcond
                then do
                  hret <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef node)
                        arg1 <- liftIO (readIORef indent)
                        arg2 <- liftIO (readIORef variables)
                        liftIO (perlReturn arg0 arg1 arg2)
                      liftIO (qid arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- pure ";\n"
                        liftIO (boxString arg0)
                      arg1 <- pure Nothing
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  qreturn hret
                  pure ()
                else do
                  hret <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef indent)
                        liftIO (listNewLine arg0)
                      liftIO (qid arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef node)
                          arg1 <- liftIO (readIORef indent)
                          arg2 <- liftIO (readIORef variables)
                          liftIO (perlExpression arg0 arg1 arg2)
                        liftIO (qid arg0)
                      arg1 <- do
                        arg0 <- do
                          arg0 <- pure ";\n"
                          liftIO (boxString arg0)
                        arg1 <- pure Nothing
                        liftIO (cons arg0 arg1)
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  qreturn hret
                  pure ()
              pure ()
          pure ()
      pure ()
  pure Nothing

perlBody :: Maybe Box -> Int -> Maybe Box -> IO (Maybe Box)
perlBody tree_arg indent_arg variables_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  indent <- liftIO (newIORef indent_arg)
  variables <- liftIO (newIORef variables_arg)
  qinit <- pure Nothing
  code <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      qset <- do
        arg0 <- liftIO (readIORef tree)
        liftIO (car arg0)
      liftIO (writeIORef code qset)
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef code)
            arg1 <- liftIO (readIORef indent)
            arg2 <- liftIO (readIORef variables)
            liftIO (perlStatement arg0 arg1 arg2)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (cdr arg0)
              arg1 <- liftIO (readIORef indent)
              arg2 <- liftIO (readIORef variables)
              liftIO (perlBody arg0 arg1 arg2)
            liftIO (qid arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

perlGetStruct :: Maybe Box -> Int -> IO (Maybe Box)
perlGetStruct node_arg indent_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  indent <- liftIO (newIORef indent_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef indent)
        liftIO (listNewLine arg0)
      liftIO (qid arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- liftIO dollar
          liftIO (boxString arg0)
        liftIO (qid arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef node)
            liftIO (first arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "->{"
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef node)
                liftIO (second arg0)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure "}"
                liftIO (boxString arg0)
              arg1 <- pure Nothing
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

perlDeclarations :: Maybe Box -> Int -> Maybe Box -> IO (Maybe Box)
perlDeclarations decls_arg indent_arg variables_arg = evalContT $ callCC $ \qreturn -> do
  decls <- liftIO (newIORef decls_arg)
  indent <- liftIO (newIORef indent_arg)
  variables <- liftIO (newIORef variables_arg)
  qinit <- pure Nothing
  decl <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef decls)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      qset <- do
        arg0 <- liftIO (readIORef decls)
        liftIO (car arg0)
      liftIO (writeIORef decl qset)
      hret <- do
        arg0 <- do
          arg0 <- pure "my "
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO dollar
              liftIO (boxString arg0)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef decl)
                liftIO (second arg0)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure " = "
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef decl)
                      liftIO (third arg0)
                    arg1 <- liftIO (readIORef indent)
                    arg2 <- liftIO (readIORef variables)
                    liftIO (perlExpression arg0 arg1 arg2)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure ";\n"
                    liftIO (boxString arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef decls)
                          liftIO (cdr arg0)
                        arg1 <- liftIO (readIORef indent)
                        arg2 <- liftIO (readIORef variables)
                        liftIO (perlDeclarations arg0 arg1 arg2)
                      liftIO (qid arg0)
                    arg1 <- pure Nothing
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

perlFunction :: Maybe Box -> IO (Maybe Box)
perlFunction node_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  qinit <- pure Nothing
  name <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  variables <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  args <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  decls <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef node)
    liftIO (second arg0)
  liftIO (writeIORef name qset)
  hcond <- do
    arg0 <- liftIO (readIORef node)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      qset <- do
        arg0 <- liftIO (readIORef node)
        liftIO (third arg0)
      liftIO (writeIORef args qset)
      qset <- do
        arg0 <- do
          arg0 <- liftIO (readIORef node)
          liftIO (fourth arg0)
        liftIO (cdr arg0)
      liftIO (writeIORef decls qset)
      qset <- do
        arg0 <- liftIO (readIORef args)
        arg1 <- liftIO (readIORef decls)
        liftIO (collectVariables arg0 arg1)
      liftIO (writeIORef variables qset)
      hret <- do
        arg0 <- do
          arg0 <- pure "\n\n# Function "
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef name)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure " from line "
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef name)
                  arg1 <- do
                    arg0 <- pure "line"
                    liftIO (boxString arg0)
                  liftIO (getTag arg0 arg1)
                liftIO (qid arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- pure 0
                    liftIO (listNewLine arg0)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- pure 0
                      liftIO (listNewLine arg0)
                    liftIO (qid arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- pure "sub "
                      liftIO (boxString arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- do
                            arg0 <- liftIO (readIORef node)
                            liftIO (second arg0)
                          arg1 <- pure Nothing
                          liftIO (perlFuncMap arg0 arg1)
                        liftIO (qid arg0)
                      arg1 <- do
                        arg0 <- do
                          arg0 <- pure " {"
                          liftIO (boxString arg0)
                        arg1 <- do
                          arg0 <- do
                            arg0 <- do
                              arg0 <- pure 1
                              liftIO (listNewLine arg0)
                            liftIO (qid arg0)
                          arg1 <- do
                            arg0 <- do
                              arg0 <- pure "my ("
                              liftIO (boxString arg0)
                            arg1 <- do
                              arg0 <- do
                                arg0 <- do
                                  arg0 <- liftIO (readIORef args)
                                  liftIO (perlFunctionArgs arg0)
                                liftIO (qid arg0)
                              arg1 <- do
                                arg0 <- do
                                  arg0 <- pure ") = "
                                  liftIO (boxString arg0)
                                arg1 <- do
                                  arg0 <- do
                                    arg0 <- do
                                      arg0 <- liftIO atsymbol
                                      liftIO (boxString arg0)
                                    liftIO (qid arg0)
                                  arg1 <- do
                                    arg0 <- do
                                      arg0 <- pure "_;"
                                      liftIO (boxString arg0)
                                    arg1 <- do
                                      arg0 <- do
                                        arg0 <- do
                                          arg0 <- pure 1
                                          liftIO (listNewLine arg0)
                                        liftIO (qid arg0)
                                      arg1 <- do
                                        arg0 <- do
                                          arg0 <- do
                                            arg0 <- liftIO (readIORef decls)
                                            arg1 <- pure 1
                                            arg2 <- liftIO (readIORef variables)
                                            liftIO (perlDeclarations arg0 arg1 arg2)
                                          liftIO (qid arg0)
                                        arg1 <- do
                                          arg0 <- do
                                            arg0 <- do
                                              arg0 <- do
                                                arg0 <- do
                                                  arg0 <- liftIO (readIORef node)
                                                  liftIO (fifth arg0)
                                                liftIO (cdr arg0)
                                              arg1 <- pure 1
                                              arg2 <- liftIO (readIORef variables)
                                              liftIO (perlBody arg0 arg1 arg2)
                                            liftIO (qid arg0)
                                          arg1 <- do
                                            arg0 <- do
                                              arg0 <- pure "\n}\n"
                                              liftIO (boxString arg0)
                                            arg1 <- pure Nothing
                                            liftIO (cons arg0 arg1)
                                          liftIO (cons arg0 arg1)
                                        liftIO (cons arg0 arg1)
                                      liftIO (cons arg0 arg1)
                                    liftIO (cons arg0 arg1)
                                  liftIO (cons arg0 arg1)
                                liftIO (cons arg0 arg1)
                              liftIO (cons arg0 arg1)
                            liftIO (cons arg0 arg1)
                          liftIO (cons arg0 arg1)
                        liftIO (cons arg0 arg1)
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

perlForwardDeclaration :: Maybe Box -> IO (Maybe Box)
perlForwardDeclaration node_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  hcond <- do
    arg0 <- liftIO (readIORef node)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- pure "sub "
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef node)
                liftIO (second arg0)
              arg1 <- pure Nothing
              liftIO (perlFuncMap arg0 arg1)
            liftIO (qid arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure ";\n"
              liftIO (boxString arg0)
            arg1 <- pure Nothing
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

perlForwardDeclarations :: Maybe Box -> IO (Maybe Box)
perlForwardDeclarations tree_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  hcond <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (car arg0)
            liftIO (perlForwardDeclaration arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (cdr arg0)
              liftIO (perlForwardDeclarations arg0)
            liftIO (qid arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

perlFunctions :: Maybe Box -> IO (Maybe Box)
perlFunctions tree_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  hcond <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (car arg0)
            liftIO (perlFunction arg0)
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (cdr arg0)
              liftIO (perlFunctions arg0)
            liftIO (qid arg0)
          arg1 <- pure Nothing
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

perlIncludes :: Maybe Box -> IO (Maybe Box)
perlIncludes nodes_arg = evalContT $ callCC $ \qreturn -> do
  nodes <- liftIO (newIORef nodes_arg)
  hret <- do
    arg0 <- do
      arg0 <- pure "use strict;\n"
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "use warnings;\n"
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure "use v5.10;\n\n"
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "no warnings 'recursion';\n"
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure "our "
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- liftIO dollar
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure "^M = 10_000;\n"
                  liftIO (boxString arg0)
                arg1 <- pure Nothing
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

perlTypes :: Maybe Box -> IO (Maybe Box)
perlTypes nodes_arg = evalContT $ callCC $ \qreturn -> do
  nodes <- liftIO (newIORef nodes_arg)
  hret <- liftIO emptyList
  qreturn hret
  pure Nothing

perlTypeMap :: Maybe Box -> IO (Maybe Box)
perlTypeMap aSym_arg = evalContT $ callCC $ \qreturn -> do
  aSym <- liftIO (newIORef aSym_arg)
  qinit <- pure Nothing
  symMap <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- do
      arg0 <- pure "stringArray"
      liftIO (boxSymbol arg0)
    arg1 <- do
      arg0 <- pure "array"
      liftIO (boxSymbol arg0)
    arg2 <- do
      arg0 <- do
        arg0 <- pure "string"
        liftIO (boxSymbol arg0)
      arg1 <- do
        arg0 <- pure "string"
        liftIO (boxSymbol arg0)
      arg2 <- pure Nothing
      liftIO (alistCons arg0 arg1 arg2)
    liftIO (alistCons arg0 arg1 arg2)
  liftIO (writeIORef symMap qset)
  hcond <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef aSym)
        liftIO (stringify arg0)
      arg1 <- liftIO (readIORef symMap)
      liftIO (assoc arg0 arg1)
    liftIO (truthy arg0)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef aSym)
            liftIO (stringify arg0)
          arg1 <- liftIO (readIORef symMap)
          liftIO (assoc arg0 arg1)
        liftIO (cdr arg0)
      qreturn hret
      pure ()
    else do
      hret <- liftIO (readIORef aSym)
      qreturn hret
      pure ()
  pure Nothing

perlFuncMap :: Maybe Box -> Maybe Box -> IO (Maybe Box)
perlFuncMap aSym_arg variables_arg = evalContT $ callCC $ \qreturn -> do
  aSym <- liftIO (newIORef aSym_arg)
  variables <- liftIO (newIORef variables_arg)
  qinit <- pure Nothing
  symMap <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- pure "symbol"
    arg1 <- do
      arg0 <- liftIO (readIORef aSym)
      liftIO (boxType arg0)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hcond <- do
        arg0 <- liftIO (readIORef aSym)
        arg1 <- liftIO (readIORef variables)
        liftIO (inList arg0 arg1)
      if hcond
        then do
          hret <- do
            arg0 <- do
              arg0 <- liftIO dollar
              arg1 <- do
                arg0 <- liftIO (readIORef aSym)
                liftIO (stringify arg0)
              liftIO (stringConcatenate arg0 arg1)
            liftIO (boxSymbol arg0)
          qreturn hret
          pure ()
        else do
          qset <- do
            arg0 <- do
              arg0 <- pure "sub"
              liftIO (boxSymbol arg0)
            arg1 <- do
              arg0 <- pure "subtract"
              liftIO (boxSymbol arg0)
            arg2 <- do
              arg0 <- do
                arg0 <- pure "="
                liftIO (boxSymbol arg0)
              arg1 <- do
                arg0 <- pure "equal"
                liftIO (boxSymbol arg0)
              arg2 <- do
                arg0 <- do
                  arg0 <- pure "sub-string"
                  liftIO (boxSymbol arg0)
                arg1 <- do
                  arg0 <- pure "substr"
                  liftIO (boxSymbol arg0)
                arg2 <- do
                  arg0 <- do
                    arg0 <- pure "read-file"
                    liftIO (boxSymbol arg0)
                  arg1 <- do
                    arg0 <- pure "read_file"
                    liftIO (boxSymbol arg0)
                  arg2 <- do
                    arg0 <- do
                      arg0 <- pure "write-file"
                      liftIO (boxSymbol arg0)
                    arg1 <- do
                      arg0 <- pure "write_file"
                      liftIO (boxSymbol arg0)
                    arg2 <- do
                      arg0 <- do
                        arg0 <- pure ">"
                        liftIO (boxSymbol arg0)
                      arg1 <- do
                        arg0 <- pure "greaterthan"
                        liftIO (boxSymbol arg0)
                      arg2 <- do
                        arg0 <- do
                          arg0 <- pure "string-length"
                          liftIO (boxSymbol arg0)
                        arg1 <- do
                          arg0 <- pure "length"
                          liftIO (boxSymbol arg0)
                        arg2 <- do
                          arg0 <- do
                            arg0 <- pure "say"
                            liftIO (boxSymbol arg0)
                          arg1 <- do
                            arg0 <- pure "say_"
                            liftIO (boxSymbol arg0)
                          arg2 <- do
                            arg0 <- do
                              arg0 <- pure "nil"
                              liftIO (boxSymbol arg0)
                            arg1 <- do
                              arg0 <- pure "undef"
                              liftIO (boxSymbol arg0)
                            arg2 <- pure Nothing
                            liftIO (alistCons arg0 arg1 arg2)
                          liftIO (alistCons arg0 arg1 arg2)
                        liftIO (alistCons arg0 arg1 arg2)
                      liftIO (alistCons arg0 arg1 arg2)
                    liftIO (alistCons arg0 arg1 arg2)
                  liftIO (alistCons arg0 arg1 arg2)
                liftIO (alistCons arg0 arg1 arg2)
              liftIO (alistCons arg0 arg1 arg2)
            liftIO (alistCons arg0 arg1 arg2)
          liftIO (writeIORef symMap qset)
          hcond <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef aSym)
                liftIO (stringify arg0)
              arg1 <- liftIO (readIORef symMap)
              liftIO (assoc arg0 arg1)
            liftIO (truthy arg0)
          if hcond
            then do
              hret <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef aSym)
                    liftIO (stringify arg0)
                  arg1 <- liftIO (readIORef symMap)
                  liftIO (assoc arg0 arg1)
                liftIO (cdr arg0)
              qreturn hret
              pure ()
            else do
              hret <- liftIO (readIORef aSym)
              qreturn hret
              pure ()
          pure ()
      pure ()
    else do
      hret <- liftIO (readIORef aSym)
      qreturn hret
      pure ()
  pure Nothing

perlLoadProgram :: String -> IO (Maybe Box)
perlLoadProgram filename_arg = evalContT $ callCC $ \qreturn -> do
  filename <- liftIO (newIORef filename_arg)
  qinit <- pure Nothing
  tree <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  replace <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef filename)
    liftIO (loadQuon arg0)
  liftIO (writeIORef tree qset)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    arg1 <- pure "q/shims/perl.qon"
    liftIO (insertInclude arg0 arg1)
  liftIO (writeIORef tree qset)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    arg1 <- pure Nothing
    liftIO (loadIncludes arg0 arg1)
  liftIO (writeIORef tree qset)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (macrowalk arg0)
  liftIO (writeIORef tree qset)
  qset <- do
    arg0 <- do
      arg0 <- pure "fprintf"
      liftIO (boxSymbol arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "stderr"
        liftIO (boxSymbol arg0)
      arg1 <- pure Nothing
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef replace qset)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    arg1 <- do
      arg0 <- pure "q"
      arg1 <- pure "log"
      liftIO (stringConcatenate arg0 arg1)
    arg2 <- liftIO (readIORef replace)
    liftIO (macrolist arg0 arg1 arg2)
  liftIO (writeIORef tree qset)
  hret <- liftIO (readIORef tree)
  qreturn hret
  pure Nothing

perlProgramTree :: Maybe Box -> IO (Maybe Box)
perlProgramTree tree_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef tree)
            liftIO (first arg0)
          liftIO (cdr arg0)
        liftIO (perlIncludes arg0)
      liftIO (qid arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (second arg0)
            liftIO (cdr arg0)
          liftIO (perlTypes arg0)
        liftIO (qid arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- liftIO perlGlobalVariables
          liftIO (qid arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "\n# Forward declarations\n"
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef tree)
                    liftIO (third arg0)
                  liftIO (cdr arg0)
                liftIO (perlForwardDeclarations arg0)
              liftIO (qid arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure "\n# End forward declarations\n"
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef tree)
                        liftIO (third arg0)
                      liftIO (cdr arg0)
                    liftIO (perlFunctions arg0)
                  liftIO (qid arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- liftIO perlMainEntry
                    liftIO (qid arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- pure "\n"
                      liftIO (boxString arg0)
                    arg1 <- pure Nothing
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

perlProgram :: Maybe Box -> IO (String)
perlProgram tree_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef tree)
        liftIO (perlProgramTree arg0)
      liftIO (flatten arg0)
    arg1 <- pure 0
    arg2 <- pure True
    arg3 <- pure False
    liftIO (listToString arg0 arg1 arg2 arg3)
  qreturn hret
  pure ""

perlCompileString :: String -> IO (String)
perlCompileString filename_arg = evalContT $ callCC $ \qreturn -> do
  filename <- liftIO (newIORef filename_arg)
  hret <- do
    arg0 <- do
      arg0 <- liftIO (readIORef filename)
      liftIO (perlLoadProgram arg0)
    liftIO (perlProgram arg0)
  qreturn hret
  pure ""

perlCompile :: String -> IO (())
perlCompile filename_arg = evalContT $ callCC $ \qreturn -> do
  filename <- liftIO (newIORef filename_arg)
  qinit <- pure Nothing
  tree <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  replace <- liftIO (newIORef qinit)
  _ <- do
    arg0 <- pure stderr
    arg1 <- pure "Scanning file...%s\n"
    arg2 <- liftIO (readIORef filename)
    liftIO (hPrintf arg0 arg1 arg2)
  qset <- do
    arg0 <- liftIO (readIORef filename)
    liftIO (loadQuon arg0)
  liftIO (writeIORef tree qset)
  _ <- do
    arg0 <- pure stderr
    arg1 <- pure "Adding shim functions\n"
    liftIO (hPrintf arg0 arg1)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    arg1 <- pure "q/shims/perl.qon"
    liftIO (insertInclude arg0 arg1)
  liftIO (writeIORef tree qset)
  _ <- do
    arg0 <- pure stderr
    arg1 <- pure "Loading includes\n"
    liftIO (hPrintf arg0 arg1)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    arg1 <- pure Nothing
    liftIO (loadIncludes arg0 arg1)
  liftIO (writeIORef tree qset)
  _ <- do
    arg0 <- pure stderr
    arg1 <- pure "Walking tree\n"
    liftIO (hPrintf arg0 arg1)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (macrowalk arg0)
  liftIO (writeIORef tree qset)
  _ <- do
    arg0 <- pure stderr
    arg1 <- pure "Replacing q log\n"
    liftIO (hPrintf arg0 arg1)
  qset <- do
    arg0 <- do
      arg0 <- pure "fprintf"
      liftIO (boxSymbol arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "stderr"
        liftIO (boxSymbol arg0)
      arg1 <- pure Nothing
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef replace qset)
  qset <- do
    arg0 <- liftIO (readIORef tree)
    arg1 <- do
      arg0 <- pure "q"
      arg1 <- pure "log"
      liftIO (stringConcatenate arg0 arg1)
    arg2 <- liftIO (readIORef replace)
    liftIO (macrolist arg0 arg1 arg2)
  liftIO (writeIORef tree qset)
  _ <- do
    arg0 <- pure stderr
    arg1 <- pure "Printing program\n"
    liftIO (hPrintf arg0 arg1)
  _ <- do
    arg0 <- do
      arg0 <- liftIO (readIORef tree)
      liftIO (perlProgramTree arg0)
    liftIO (printStringTree arg0)
  pure ()

readSexpr :: String -> String -> IO (Maybe Box)
readSexpr aStr_arg filename_arg = evalContT $ callCC $ \qreturn -> do
  aStr <- liftIO (newIORef aStr_arg)
  filename <- liftIO (newIORef filename_arg)
  qinit <- pure Nothing
  tokens <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  as <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  tree <- liftIO (newIORef qinit)
  qset <- liftIO emptyList
  liftIO (writeIORef tokens qset)
  qset <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef aStr)
        arg1 <- pure 0
        arg2 <- pure 1
        arg3 <- pure 0
        arg4 <- pure 0
        arg5 <- liftIO (readIORef filename)
        liftIO (scan arg0 arg1 arg2 arg3 arg4 arg5)
      liftIO (filterVoid arg0)
    liftIO (filterTokens arg0)
  liftIO (writeIORef tokens qset)
  _ <- do
    arg0 <- liftIO (readIORef tokens)
    arg1 <- pure Nothing
    arg2 <- liftIO (readIORef filename)
    liftIO (parserValidateParens arg0 arg1 arg2)
  qset <- do
    arg0 <- liftIO (readIORef tokens)
    liftIO (sexprTree arg0)
  liftIO (writeIORef as qset)
  _ <- do
    arg0 <- liftIO (readIORef as)
    arg1 <- liftIO (readIORef filename)
    liftIO (parserValidateRoot arg0 arg1)
  qset <- do
    arg0 <- liftIO (readIORef as)
    liftIO (car arg0)
  liftIO (writeIORef tree qset)
  _ <- do
    arg0 <- liftIO (readIORef tree)
    arg1 <- liftIO (readIORef filename)
    liftIO (parserValidateProgram arg0 arg1)
  hret <- liftIO (readIORef tree)
  qreturn hret
  pure Nothing

parserPanicAt :: String -> Maybe Box -> String -> IO (())
parserPanicAt filename_arg token_arg message_arg = evalContT $ callCC $ \qreturn -> do
  filename <- liftIO (newIORef filename_arg)
  token <- liftIO (newIORef token_arg)
  message <- liftIO (newIORef message_arg)
  hcond <- do
    arg0 <- liftIO (readIORef token)
    liftIO (isNil arg0)
  if hcond
    then do
      _ <- do
        arg0 <- pure "Parse error in %s: %s\n"
        arg1 <- liftIO (readIORef filename)
        arg2 <- liftIO (readIORef message)
        liftIO (printf arg0 arg1 arg2)
      pure ()
    else do
      _ <- do
        arg0 <- pure "Parse error in %s:%s:%s: %s\n"
        arg1 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef token)
            arg1 <- do
              arg0 <- pure "filename"
              liftIO (boxString arg0)
            arg2 <- do
              arg0 <- liftIO (readIORef filename)
              liftIO (boxString arg0)
            liftIO (getTagFail arg0 arg1 arg2)
          liftIO (stringify arg0)
        arg2 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef token)
            arg1 <- do
              arg0 <- pure "line"
              liftIO (boxString arg0)
            arg2 <- do
              arg0 <- pure "?"
              liftIO (boxString arg0)
            liftIO (getTagFail arg0 arg1 arg2)
          liftIO (stringify arg0)
        arg3 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef token)
            arg1 <- do
              arg0 <- pure "column"
              liftIO (boxString arg0)
            arg2 <- do
              arg0 <- pure "?"
              liftIO (boxString arg0)
            liftIO (getTagFail arg0 arg1 arg2)
          liftIO (stringify arg0)
        arg4 <- liftIO (readIORef message)
        liftIO (printf arg0 arg1 arg2 arg3 arg4)
      pure ()
  _ <- do
    arg0 <- pure 1
    liftIO (exit arg0)
  pure ()

parserPanicAtNode :: String -> Maybe Box -> String -> IO (())
parserPanicAtNode filename_arg node_arg message_arg = evalContT $ callCC $ \qreturn -> do
  filename <- liftIO (newIORef filename_arg)
  node <- liftIO (newIORef node_arg)
  message <- liftIO (newIORef message_arg)
  hcond <- do
    arg0 <- liftIO (readIORef node)
    liftIO (isNil arg0)
  if hcond
    then do
      _ <- do
        arg0 <- liftIO (readIORef filename)
        arg1 <- pure Nothing
        arg2 <- liftIO (readIORef message)
        liftIO (parserPanicAt arg0 arg1 arg2)
      pure ()
    else do
      hcond <- do
        arg0 <- liftIO (readIORef node)
        liftIO (isList arg0)
      if hcond
        then do
          hcond <- do
            arg0 <- liftIO (readIORef node)
            liftIO (isEmpty arg0)
          if hcond
            then do
              _ <- do
                arg0 <- liftIO (readIORef filename)
                arg1 <- pure Nothing
                arg2 <- liftIO (readIORef message)
                liftIO (parserPanicAt arg0 arg1 arg2)
              pure ()
            else do
              _ <- do
                arg0 <- liftIO (readIORef filename)
                arg1 <- do
                  arg0 <- liftIO (readIORef node)
                  liftIO (car arg0)
                arg2 <- liftIO (readIORef message)
                liftIO (parserPanicAt arg0 arg1 arg2)
              pure ()
          pure ()
        else do
          _ <- do
            arg0 <- liftIO (readIORef filename)
            arg1 <- liftIO (readIORef node)
            arg2 <- liftIO (readIORef message)
            liftIO (parserPanicAt arg0 arg1 arg2)
          pure ()
      pure ()
  pure ()

parserSymbolIs :: Maybe Box -> String -> IO (Bool)
parserSymbolIs b_arg name_arg = evalContT $ callCC $ \qreturn -> do
  b <- liftIO (newIORef b_arg)
  name <- liftIO (newIORef name_arg)
  hcond <- do
    arg0 <- liftIO (readIORef b)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- pure False
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef b)
    liftIO (isList arg0)
  if hcond
    then do
      hret <- pure False
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- pure "symbol"
    arg1 <- do
      arg0 <- liftIO (readIORef b)
      liftIO (boxType arg0)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- liftIO (readIORef name)
        arg1 <- do
          arg0 <- liftIO (readIORef b)
          liftIO (stringify arg0)
        liftIO (equalString arg0 arg1)
      qreturn hret
      pure ()
    else do
      hret <- pure False
      qreturn hret
      pure ()
  pure False

parserListStartsWith :: Maybe Box -> String -> IO (Bool)
parserListStartsWith node_arg name_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  name <- liftIO (newIORef name_arg)
  hcond <- do
    arg0 <- liftIO (readIORef node)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- pure False
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef node)
    liftIO (isList arg0)
  if hcond
    then do
      hcond <- do
        arg0 <- liftIO (readIORef node)
        liftIO (isEmpty arg0)
      if hcond
        then do
          hret <- pure False
          qreturn hret
          pure ()
        else do
          hret <- do
            arg0 <- do
              arg0 <- liftIO (readIORef node)
              liftIO (car arg0)
            arg1 <- liftIO (readIORef name)
            liftIO (parserSymbolIs arg0 arg1)
          qreturn hret
          pure ()
      pure ()
    else do
      hret <- pure False
      qreturn hret
      pure ()
  pure False

parserValidateParens :: Maybe Box -> Maybe Box -> String -> IO (())
parserValidateParens tokens_arg openStack_arg filename_arg = evalContT $ callCC $ \qreturn -> do
  tokens <- liftIO (newIORef tokens_arg)
  openStack <- liftIO (newIORef openStack_arg)
  filename <- liftIO (newIORef filename_arg)
  qinit <- pure Nothing
  token <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef tokens)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hcond <- do
        arg0 <- liftIO (readIORef openStack)
        liftIO (isEmpty arg0)
      if hcond
        then do
          qreturn ()
          pure ()
        else do
          _ <- do
            arg0 <- liftIO (readIORef filename)
            arg1 <- do
              arg0 <- liftIO (readIORef openStack)
              liftIO (car arg0)
            arg2 <- pure "missing ')'"
            liftIO (parserPanicAt arg0 arg1 arg2)
          pure ()
      pure ()
    else do
      qset <- do
        arg0 <- liftIO (readIORef tokens)
        liftIO (car arg0)
      liftIO (writeIORef token qset)
      hcond <- do
        arg0 <- liftIO (readIORef token)
        liftIO (isOpenBrace arg0)
      if hcond
        then do
          _ <- do
            arg0 <- do
              arg0 <- liftIO (readIORef tokens)
              liftIO (cdr arg0)
            arg1 <- do
              arg0 <- liftIO (readIORef token)
              arg1 <- liftIO (readIORef openStack)
              liftIO (cons arg0 arg1)
            arg2 <- liftIO (readIORef filename)
            liftIO (parserValidateParens arg0 arg1 arg2)
          pure ()
        else do
          hcond <- do
            arg0 <- liftIO (readIORef token)
            liftIO (isCloseBrace arg0)
          if hcond
            then do
              hcond <- do
                arg0 <- liftIO (readIORef openStack)
                liftIO (isEmpty arg0)
              if hcond
                then do
                  _ <- do
                    arg0 <- liftIO (readIORef filename)
                    arg1 <- liftIO (readIORef token)
                    arg2 <- pure "unexpected ')'"
                    liftIO (parserPanicAt arg0 arg1 arg2)
                  pure ()
                else do
                  _ <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef tokens)
                      liftIO (cdr arg0)
                    arg1 <- do
                      arg0 <- liftIO (readIORef openStack)
                      liftIO (cdr arg0)
                    arg2 <- liftIO (readIORef filename)
                    liftIO (parserValidateParens arg0 arg1 arg2)
                  pure ()
              pure ()
            else do
              _ <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef tokens)
                  liftIO (cdr arg0)
                arg1 <- liftIO (readIORef openStack)
                arg2 <- liftIO (readIORef filename)
                liftIO (parserValidateParens arg0 arg1 arg2)
              pure ()
          pure ()
      pure ()
  pure ()

parserValidateRoot :: Maybe Box -> String -> IO (())
parserValidateRoot roots_arg filename_arg = evalContT $ callCC $ \qreturn -> do
  roots <- liftIO (newIORef roots_arg)
  filename <- liftIO (newIORef filename_arg)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef roots)
      liftIO (listLength arg0)
    arg1 <- pure 1
    liftIO (equal arg0 arg1)
  if hcond
    then do
      qreturn ()
      pure ()
    else do
      hcond <- do
        arg0 <- liftIO (readIORef roots)
        liftIO (isEmpty arg0)
      if hcond
        then do
          _ <- do
            arg0 <- liftIO (readIORef filename)
            arg1 <- pure Nothing
            arg2 <- pure "expected one top-level program form"
            liftIO (parserPanicAt arg0 arg1 arg2)
          pure ()
        else do
          _ <- do
            arg0 <- liftIO (readIORef filename)
            arg1 <- do
              arg0 <- liftIO (readIORef roots)
              liftIO (second arg0)
            arg2 <- pure "extra top-level form after program"
            liftIO (parserPanicAtNode arg0 arg1 arg2)
          pure ()
      pure ()
  pure ()

parserValidateSection :: Maybe Box -> String -> String -> IO (())
parserValidateSection section_arg name_arg filename_arg = evalContT $ callCC $ \qreturn -> do
  section <- liftIO (newIORef section_arg)
  name <- liftIO (newIORef name_arg)
  filename <- liftIO (newIORef filename_arg)
  hcond <- do
    arg0 <- liftIO (readIORef section)
    liftIO (isNil arg0)
  if hcond
    then do
      _ <- do
        arg0 <- liftIO (readIORef filename)
        arg1 <- pure Nothing
        arg2 <- pure "missing program section"
        liftIO (parserPanicAt arg0 arg1 arg2)
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef section)
    liftIO (isList arg0)
  if hcond
    then do
      pure ()
    else do
      _ <- do
        arg0 <- liftIO (readIORef filename)
        arg1 <- liftIO (readIORef section)
        arg2 <- pure "program section must be a list"
        liftIO (parserPanicAtNode arg0 arg1 arg2)
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef section)
    arg1 <- liftIO (readIORef name)
    liftIO (parserListStartsWith arg0 arg1)
  if hcond
    then do
      qreturn ()
      pure ()
    else do
      _ <- do
        arg0 <- liftIO (readIORef filename)
        arg1 <- liftIO (readIORef section)
        arg2 <- do
          arg0 <- pure "expected program section "
          arg1 <- liftIO (readIORef name)
          liftIO (stringConcatenate arg0 arg1)
        liftIO (parserPanicAtNode arg0 arg1 arg2)
      pure ()
  pure ()

parserIsFunctionDefinition :: Maybe Box -> IO (Bool)
parserIsFunctionDefinition node_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  hcond <- do
    arg0 <- liftIO (readIORef node)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- pure False
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef node)
    liftIO (isList arg0)
  if hcond
    then do
      pure ()
    else do
      hret <- pure False
      qreturn hret
      pure ()
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef node)
      liftIO (listLength arg0)
    arg1 <- pure 5
    liftIO (equal arg0 arg1)
  if hcond
    then do
      pure ()
    else do
      hret <- pure False
      qreturn hret
      pure ()
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef node)
      liftIO (first arg0)
    liftIO (isList arg0)
  if hcond
    then do
      hret <- pure False
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef node)
      liftIO (second arg0)
    liftIO (isList arg0)
  if hcond
    then do
      hret <- pure False
      qreturn hret
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef node)
      liftIO (third arg0)
    liftIO (isList arg0)
  if hcond
    then do
      pure ()
    else do
      hret <- pure False
      qreturn hret
      pure ()
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef node)
      liftIO (fourth arg0)
    arg1 <- pure "declare"
    liftIO (parserListStartsWith arg0 arg1)
  if hcond
    then do
      pure ()
    else do
      hret <- pure False
      qreturn hret
      pure ()
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef node)
      liftIO (fifth arg0)
    arg1 <- pure "body"
    liftIO (parserListStartsWith arg0 arg1)
  if hcond
    then do
      hret <- pure True
      qreturn hret
      pure ()
    else do
      hret <- pure False
      qreturn hret
      pure ()
  pure False

parserRejectFunctionDefinitions :: Maybe Box -> String -> IO (())
parserRejectFunctionDefinitions node_arg filename_arg = evalContT $ callCC $ \qreturn -> do
  node <- liftIO (newIORef node_arg)
  filename <- liftIO (newIORef filename_arg)
  hcond <- do
    arg0 <- liftIO (readIORef node)
    liftIO (isNil arg0)
  if hcond
    then do
      qreturn ()
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef node)
    liftIO (parserIsFunctionDefinition arg0)
  if hcond
    then do
      _ <- do
        arg0 <- liftIO (readIORef filename)
        arg1 <- liftIO (readIORef node)
        arg2 <- pure "function definition is not allowed here"
        liftIO (parserPanicAtNode arg0 arg1 arg2)
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef node)
    liftIO (isList arg0)
  if hcond
    then do
      _ <- do
        arg0 <- liftIO (readIORef node)
        arg1 <- liftIO (readIORef filename)
        liftIO (parserRejectFunctionDefinitionsList arg0 arg1)
      pure ()
    else do
      qreturn ()
      pure ()
  pure ()

parserRejectFunctionDefinitionsList :: Maybe Box -> String -> IO (())
parserRejectFunctionDefinitionsList nodes_arg filename_arg = evalContT $ callCC $ \qreturn -> do
  nodes <- liftIO (newIORef nodes_arg)
  filename <- liftIO (newIORef filename_arg)
  hcond <- do
    arg0 <- liftIO (readIORef nodes)
    liftIO (isEmpty arg0)
  if hcond
    then do
      qreturn ()
      pure ()
    else do
      _ <- do
        arg0 <- do
          arg0 <- liftIO (readIORef nodes)
          liftIO (car arg0)
        arg1 <- liftIO (readIORef filename)
        liftIO (parserRejectFunctionDefinitions arg0 arg1)
      _ <- do
        arg0 <- do
          arg0 <- liftIO (readIORef nodes)
          liftIO (cdr arg0)
        arg1 <- liftIO (readIORef filename)
        liftIO (parserRejectFunctionDefinitionsList arg0 arg1)
      pure ()
  pure ()

parserValidateProgram :: Maybe Box -> String -> IO (())
parserValidateProgram program_arg filename_arg = evalContT $ callCC $ \qreturn -> do
  program <- liftIO (newIORef program_arg)
  filename <- liftIO (newIORef filename_arg)
  hcond <- do
    arg0 <- liftIO (readIORef program)
    liftIO (isNil arg0)
  if hcond
    then do
      _ <- do
        arg0 <- liftIO (readIORef filename)
        arg1 <- pure Nothing
        arg2 <- pure "empty program"
        liftIO (parserPanicAt arg0 arg1 arg2)
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef program)
    liftIO (isList arg0)
  if hcond
    then do
      pure ()
    else do
      _ <- do
        arg0 <- liftIO (readIORef filename)
        arg1 <- liftIO (readIORef program)
        arg2 <- pure "program must be a list"
        liftIO (parserPanicAtNode arg0 arg1 arg2)
      pure ()
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef program)
      liftIO (listLength arg0)
    arg1 <- pure 3
    liftIO (equal arg0 arg1)
  if hcond
    then do
      pure ()
    else do
      hcond <- do
        arg0 <- do
          arg0 <- liftIO (readIORef program)
          liftIO (listLength arg0)
        arg1 <- pure 4
        liftIO (equal arg0 arg1)
      if hcond
        then do
          pure ()
        else do
          _ <- do
            arg0 <- liftIO (readIORef filename)
            arg1 <- liftIO (readIORef program)
            arg2 <- pure "program must contain includes, types, and functions sections"
            liftIO (parserPanicAtNode arg0 arg1 arg2)
          pure ()
      pure ()
  _ <- do
    arg0 <- do
      arg0 <- liftIO (readIORef program)
      liftIO (first arg0)
    arg1 <- pure "includes"
    arg2 <- liftIO (readIORef filename)
    liftIO (parserValidateSection arg0 arg1 arg2)
  _ <- do
    arg0 <- do
      arg0 <- liftIO (readIORef program)
      liftIO (second arg0)
    arg1 <- pure "types"
    arg2 <- liftIO (readIORef filename)
    liftIO (parserValidateSection arg0 arg1 arg2)
  _ <- do
    arg0 <- do
      arg0 <- liftIO (readIORef program)
      liftIO (third arg0)
    arg1 <- pure "functions"
    arg2 <- liftIO (readIORef filename)
    liftIO (parserValidateSection arg0 arg1 arg2)
  _ <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef program)
        liftIO (first arg0)
      liftIO (cdr arg0)
    arg1 <- liftIO (readIORef filename)
    liftIO (parserRejectFunctionDefinitions arg0 arg1)
  _ <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef program)
        liftIO (second arg0)
      liftIO (cdr arg0)
    arg1 <- liftIO (readIORef filename)
    liftIO (parserRejectFunctionDefinitions arg0 arg1)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef program)
      liftIO (listLength arg0)
    arg1 <- pure 4
    liftIO (equal arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- do
          arg0 <- liftIO (readIORef program)
          liftIO (fourth arg0)
        arg1 <- pure "globals"
        arg2 <- liftIO (readIORef filename)
        liftIO (parserValidateSection arg0 arg1 arg2)
      _ <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef program)
            liftIO (fourth arg0)
          liftIO (cdr arg0)
        arg1 <- liftIO (readIORef filename)
        liftIO (parserRejectFunctionDefinitions arg0 arg1)
      pure ()
    else do
      pure ()
  _ <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef program)
        liftIO (third arg0)
      liftIO (cdr arg0)
    arg1 <- liftIO (readIORef filename)
    liftIO (parserValidateFunctions arg0 arg1)
  pure ()

parserValidateFunctions :: Maybe Box -> String -> IO (())
parserValidateFunctions functions_arg filename_arg = evalContT $ callCC $ \qreturn -> do
  functions <- liftIO (newIORef functions_arg)
  filename <- liftIO (newIORef filename_arg)
  qinit <- pure Nothing
  fn <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef functions)
    liftIO (isEmpty arg0)
  if hcond
    then do
      qreturn ()
      pure ()
    else do
      qset <- do
        arg0 <- liftIO (readIORef functions)
        liftIO (car arg0)
      liftIO (writeIORef fn qset)
      hcond <- do
        arg0 <- liftIO (readIORef fn)
        liftIO (parserIsFunctionDefinition arg0)
      if hcond
        then do
          _ <- do
            arg0 <- liftIO (readIORef fn)
            arg1 <- liftIO (readIORef filename)
            liftIO (parserValidateFunction arg0 arg1)
          pure ()
        else do
          _ <- do
            arg0 <- liftIO (readIORef filename)
            arg1 <- liftIO (readIORef fn)
            arg2 <- pure "invalid function definition"
            liftIO (parserPanicAtNode arg0 arg1 arg2)
          pure ()
      _ <- do
        arg0 <- do
          arg0 <- liftIO (readIORef functions)
          liftIO (cdr arg0)
        arg1 <- liftIO (readIORef filename)
        liftIO (parserValidateFunctions arg0 arg1)
      pure ()
  pure ()

parserValidateFunction :: Maybe Box -> String -> IO (())
parserValidateFunction fn_arg filename_arg = evalContT $ callCC $ \qreturn -> do
  fn <- liftIO (newIORef fn_arg)
  filename <- liftIO (newIORef filename_arg)
  _ <- do
    arg0 <- do
      arg0 <- liftIO (readIORef fn)
      liftIO (third arg0)
    arg1 <- liftIO (readIORef filename)
    liftIO (parserRejectFunctionDefinitions arg0 arg1)
  _ <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef fn)
        liftIO (fourth arg0)
      liftIO (cdr arg0)
    arg1 <- liftIO (readIORef filename)
    liftIO (parserRejectFunctionDefinitions arg0 arg1)
  _ <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef fn)
        liftIO (fifth arg0)
      liftIO (cdr arg0)
    arg1 <- liftIO (readIORef filename)
    liftIO (parserValidateBody arg0 arg1)
  pure ()

parserValidateBody :: Maybe Box -> String -> IO (())
parserValidateBody forms_arg filename_arg = evalContT $ callCC $ \qreturn -> do
  forms <- liftIO (newIORef forms_arg)
  filename <- liftIO (newIORef filename_arg)
  hcond <- do
    arg0 <- liftIO (readIORef forms)
    liftIO (isEmpty arg0)
  if hcond
    then do
      qreturn ()
      pure ()
    else do
      _ <- do
        arg0 <- do
          arg0 <- liftIO (readIORef forms)
          liftIO (car arg0)
        arg1 <- liftIO (readIORef filename)
        liftIO (parserValidateStatement arg0 arg1)
      _ <- do
        arg0 <- do
          arg0 <- liftIO (readIORef forms)
          liftIO (cdr arg0)
        arg1 <- liftIO (readIORef filename)
        liftIO (parserValidateBody arg0 arg1)
      pure ()
  pure ()

parserValidateStatement :: Maybe Box -> String -> IO (())
parserValidateStatement stmt_arg filename_arg = evalContT $ callCC $ \qreturn -> do
  stmt <- liftIO (newIORef stmt_arg)
  filename <- liftIO (newIORef filename_arg)
  hcond <- do
    arg0 <- liftIO (readIORef stmt)
    liftIO (isNil arg0)
  if hcond
    then do
      qreturn ()
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef stmt)
    liftIO (isList arg0)
  if hcond
    then do
      pure ()
    else do
      _ <- do
        arg0 <- liftIO (readIORef filename)
        arg1 <- liftIO (readIORef stmt)
        arg2 <- pure "statement must be a list"
        liftIO (parserPanicAtNode arg0 arg1 arg2)
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef stmt)
    liftIO (isEmpty arg0)
  if hcond
    then do
      qreturn ()
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef stmt)
    liftIO (parserIsFunctionDefinition arg0)
  if hcond
    then do
      _ <- do
        arg0 <- liftIO (readIORef filename)
        arg1 <- liftIO (readIORef stmt)
        arg2 <- pure "function definition nested inside body"
        liftIO (parserPanicAtNode arg0 arg1 arg2)
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef stmt)
    arg1 <- pure "if"
    liftIO (parserListStartsWith arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- liftIO (readIORef stmt)
        arg1 <- liftIO (readIORef filename)
        liftIO (parserValidateIf arg0 arg1)
      qreturn ()
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef stmt)
    arg1 <- pure "then"
    liftIO (parserListStartsWith arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- liftIO (readIORef filename)
        arg1 <- liftIO (readIORef stmt)
        arg2 <- pure "then branch outside if"
        liftIO (parserPanicAtNode arg0 arg1 arg2)
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef stmt)
    arg1 <- pure "else"
    liftIO (parserListStartsWith arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- liftIO (readIORef filename)
        arg1 <- liftIO (readIORef stmt)
        arg2 <- pure "else branch outside if"
        liftIO (parserPanicAtNode arg0 arg1 arg2)
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef stmt)
    arg1 <- pure "declare"
    liftIO (parserListStartsWith arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- liftIO (readIORef filename)
        arg1 <- liftIO (readIORef stmt)
        arg2 <- pure "declare block outside function header"
        liftIO (parserPanicAtNode arg0 arg1 arg2)
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef stmt)
    arg1 <- pure "body"
    liftIO (parserListStartsWith arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- liftIO (readIORef filename)
        arg1 <- liftIO (readIORef stmt)
        arg2 <- pure "body block nested inside body"
        liftIO (parserPanicAtNode arg0 arg1 arg2)
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef stmt)
    arg1 <- pure "functions"
    liftIO (parserListStartsWith arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- liftIO (readIORef filename)
        arg1 <- liftIO (readIORef stmt)
        arg2 <- pure "functions section nested inside body"
        liftIO (parserPanicAtNode arg0 arg1 arg2)
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef stmt)
    arg1 <- pure "types"
    liftIO (parserListStartsWith arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- liftIO (readIORef filename)
        arg1 <- liftIO (readIORef stmt)
        arg2 <- pure "types section nested inside body"
        liftIO (parserPanicAtNode arg0 arg1 arg2)
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef stmt)
    arg1 <- pure "includes"
    liftIO (parserListStartsWith arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- liftIO (readIORef filename)
        arg1 <- liftIO (readIORef stmt)
        arg2 <- pure "includes section nested inside body"
        liftIO (parserPanicAtNode arg0 arg1 arg2)
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef stmt)
    arg1 <- pure "return"
    liftIO (parserListStartsWith arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- liftIO (readIORef stmt)
        arg1 <- liftIO (readIORef filename)
        liftIO (parserValidateReturn arg0 arg1)
      qreturn ()
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef stmt)
    arg1 <- pure "set"
    liftIO (parserListStartsWith arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- liftIO (readIORef stmt)
        arg1 <- liftIO (readIORef filename)
        liftIO (parserValidateSet arg0 arg1)
      qreturn ()
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef stmt)
    arg1 <- pure "set-struct"
    liftIO (parserListStartsWith arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- liftIO (readIORef stmt)
        arg1 <- liftIO (readIORef filename)
        liftIO (parserValidateSetStruct arg0 arg1)
      qreturn ()
      pure ()
    else do
      pure ()
  _ <- do
    arg0 <- liftIO (readIORef stmt)
    arg1 <- liftIO (readIORef filename)
    liftIO (parserValidateExpression arg0 arg1)
  pure ()

parserValidateReturn :: Maybe Box -> String -> IO (())
parserValidateReturn stmt_arg filename_arg = evalContT $ callCC $ \qreturn -> do
  stmt <- liftIO (newIORef stmt_arg)
  filename <- liftIO (newIORef filename_arg)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef stmt)
      liftIO (listLength arg0)
    arg1 <- pure 2
    liftIO (greaterthan arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- liftIO (readIORef filename)
        arg1 <- liftIO (readIORef stmt)
        arg2 <- pure "return takes zero or one value"
        liftIO (parserPanicAtNode arg0 arg1 arg2)
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef stmt)
      liftIO (listLength arg0)
    arg1 <- pure 2
    liftIO (equal arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- do
          arg0 <- liftIO (readIORef stmt)
          liftIO (second arg0)
        arg1 <- liftIO (readIORef filename)
        liftIO (parserValidateExpression arg0 arg1)
      pure ()
    else do
      qreturn ()
      pure ()
  pure ()

parserValidateSet :: Maybe Box -> String -> IO (())
parserValidateSet stmt_arg filename_arg = evalContT $ callCC $ \qreturn -> do
  stmt <- liftIO (newIORef stmt_arg)
  filename <- liftIO (newIORef filename_arg)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef stmt)
      liftIO (listLength arg0)
    arg1 <- pure 3
    liftIO (equal arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- do
          arg0 <- liftIO (readIORef stmt)
          liftIO (second arg0)
        arg1 <- liftIO (readIORef filename)
        liftIO (parserValidateExpression arg0 arg1)
      _ <- do
        arg0 <- do
          arg0 <- liftIO (readIORef stmt)
          liftIO (third arg0)
        arg1 <- liftIO (readIORef filename)
        liftIO (parserValidateExpression arg0 arg1)
      pure ()
    else do
      _ <- do
        arg0 <- liftIO (readIORef filename)
        arg1 <- liftIO (readIORef stmt)
        arg2 <- pure "set takes a target and value"
        liftIO (parserPanicAtNode arg0 arg1 arg2)
      pure ()
  pure ()

parserValidateSetStruct :: Maybe Box -> String -> IO (())
parserValidateSetStruct stmt_arg filename_arg = evalContT $ callCC $ \qreturn -> do
  stmt <- liftIO (newIORef stmt_arg)
  filename <- liftIO (newIORef filename_arg)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef stmt)
      liftIO (listLength arg0)
    arg1 <- pure 4
    liftIO (equal arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- do
          arg0 <- liftIO (readIORef stmt)
          liftIO (second arg0)
        arg1 <- liftIO (readIORef filename)
        liftIO (parserValidateExpression arg0 arg1)
      _ <- do
        arg0 <- do
          arg0 <- liftIO (readIORef stmt)
          liftIO (third arg0)
        arg1 <- liftIO (readIORef filename)
        liftIO (parserValidateExpression arg0 arg1)
      _ <- do
        arg0 <- do
          arg0 <- liftIO (readIORef stmt)
          liftIO (fourth arg0)
        arg1 <- liftIO (readIORef filename)
        liftIO (parserValidateExpression arg0 arg1)
      pure ()
    else do
      _ <- do
        arg0 <- liftIO (readIORef filename)
        arg1 <- liftIO (readIORef stmt)
        arg2 <- pure "set-struct takes a target, field, and value"
        liftIO (parserPanicAtNode arg0 arg1 arg2)
      pure ()
  pure ()

parserValidateIf :: Maybe Box -> String -> IO (())
parserValidateIf stmt_arg filename_arg = evalContT $ callCC $ \qreturn -> do
  stmt <- liftIO (newIORef stmt_arg)
  filename <- liftIO (newIORef filename_arg)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef stmt)
      liftIO (listLength arg0)
    arg1 <- pure 4
    liftIO (equal arg0 arg1)
  if hcond
    then do
      pure ()
    else do
      _ <- do
        arg0 <- liftIO (readIORef filename)
        arg1 <- liftIO (readIORef stmt)
        arg2 <- pure "if must contain condition, then, and else"
        liftIO (parserPanicAtNode arg0 arg1 arg2)
      pure ()
  _ <- do
    arg0 <- do
      arg0 <- liftIO (readIORef stmt)
      liftIO (second arg0)
    arg1 <- liftIO (readIORef filename)
    liftIO (parserValidateExpression arg0 arg1)
  _ <- do
    arg0 <- do
      arg0 <- liftIO (readIORef stmt)
      liftIO (third arg0)
    arg1 <- pure "then"
    arg2 <- liftIO (readIORef filename)
    liftIO (parserValidateBranch arg0 arg1 arg2)
  _ <- do
    arg0 <- do
      arg0 <- liftIO (readIORef stmt)
      liftIO (fourth arg0)
    arg1 <- pure "else"
    arg2 <- liftIO (readIORef filename)
    liftIO (parserValidateBranch arg0 arg1 arg2)
  pure ()

parserValidateBranch :: Maybe Box -> String -> String -> IO (())
parserValidateBranch branch_arg name_arg filename_arg = evalContT $ callCC $ \qreturn -> do
  branch <- liftIO (newIORef branch_arg)
  name <- liftIO (newIORef name_arg)
  filename <- liftIO (newIORef filename_arg)
  hcond <- do
    arg0 <- liftIO (readIORef branch)
    arg1 <- liftIO (readIORef name)
    liftIO (parserListStartsWith arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- do
          arg0 <- liftIO (readIORef branch)
          liftIO (cdr arg0)
        arg1 <- liftIO (readIORef filename)
        liftIO (parserValidateBody arg0 arg1)
      pure ()
    else do
      _ <- do
        arg0 <- liftIO (readIORef filename)
        arg1 <- liftIO (readIORef branch)
        arg2 <- do
          arg0 <- pure "expected "
          arg1 <- liftIO (readIORef name)
          liftIO (stringConcatenate arg0 arg1)
        liftIO (parserPanicAtNode arg0 arg1 arg2)
      pure ()
  pure ()

parserValidateExpression :: Maybe Box -> String -> IO (())
parserValidateExpression expr_arg filename_arg = evalContT $ callCC $ \qreturn -> do
  expr <- liftIO (newIORef expr_arg)
  filename <- liftIO (newIORef filename_arg)
  hcond <- do
    arg0 <- liftIO (readIORef expr)
    liftIO (isNil arg0)
  if hcond
    then do
      qreturn ()
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef expr)
    liftIO (isList arg0)
  if hcond
    then do
      pure ()
    else do
      qreturn ()
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef expr)
    liftIO (isEmpty arg0)
  if hcond
    then do
      qreturn ()
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef expr)
    liftIO (parserIsFunctionDefinition arg0)
  if hcond
    then do
      _ <- do
        arg0 <- liftIO (readIORef filename)
        arg1 <- liftIO (readIORef expr)
        arg2 <- pure "function definition nested inside expression"
        liftIO (parserPanicAtNode arg0 arg1 arg2)
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef expr)
    arg1 <- pure "if"
    liftIO (parserListStartsWith arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- liftIO (readIORef expr)
        arg1 <- liftIO (readIORef filename)
        liftIO (parserValidateIf arg0 arg1)
      qreturn ()
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef expr)
    arg1 <- pure "then"
    liftIO (parserListStartsWith arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- liftIO (readIORef filename)
        arg1 <- liftIO (readIORef expr)
        arg2 <- pure "then branch outside if"
        liftIO (parserPanicAtNode arg0 arg1 arg2)
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef expr)
    arg1 <- pure "else"
    liftIO (parserListStartsWith arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- liftIO (readIORef filename)
        arg1 <- liftIO (readIORef expr)
        arg2 <- pure "else branch outside if"
        liftIO (parserPanicAtNode arg0 arg1 arg2)
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef expr)
    arg1 <- pure "declare"
    liftIO (parserListStartsWith arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- liftIO (readIORef filename)
        arg1 <- liftIO (readIORef expr)
        arg2 <- pure "declare block inside expression"
        liftIO (parserPanicAtNode arg0 arg1 arg2)
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef expr)
    arg1 <- pure "body"
    liftIO (parserListStartsWith arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- liftIO (readIORef filename)
        arg1 <- liftIO (readIORef expr)
        arg2 <- pure "body block inside expression"
        liftIO (parserPanicAtNode arg0 arg1 arg2)
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef expr)
    arg1 <- pure "functions"
    liftIO (parserListStartsWith arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- liftIO (readIORef filename)
        arg1 <- liftIO (readIORef expr)
        arg2 <- pure "functions section inside expression"
        liftIO (parserPanicAtNode arg0 arg1 arg2)
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef expr)
    arg1 <- pure "types"
    liftIO (parserListStartsWith arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- liftIO (readIORef filename)
        arg1 <- liftIO (readIORef expr)
        arg2 <- pure "types section inside expression"
        liftIO (parserPanicAtNode arg0 arg1 arg2)
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef expr)
    arg1 <- pure "includes"
    liftIO (parserListStartsWith arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- liftIO (readIORef filename)
        arg1 <- liftIO (readIORef expr)
        arg2 <- pure "includes section inside expression"
        liftIO (parserPanicAtNode arg0 arg1 arg2)
      pure ()
    else do
      pure ()
  _ <- do
    arg0 <- liftIO (readIORef expr)
    arg1 <- liftIO (readIORef filename)
    liftIO (parserValidateExpressionList arg0 arg1)
  pure ()

parserValidateExpressionList :: Maybe Box -> String -> IO (())
parserValidateExpressionList exprs_arg filename_arg = evalContT $ callCC $ \qreturn -> do
  exprs <- liftIO (newIORef exprs_arg)
  filename <- liftIO (newIORef filename_arg)
  hcond <- do
    arg0 <- liftIO (readIORef exprs)
    liftIO (isEmpty arg0)
  if hcond
    then do
      qreturn ()
      pure ()
    else do
      _ <- do
        arg0 <- do
          arg0 <- liftIO (readIORef exprs)
          liftIO (car arg0)
        arg1 <- liftIO (readIORef filename)
        liftIO (parserValidateExpression arg0 arg1)
      _ <- do
        arg0 <- do
          arg0 <- liftIO (readIORef exprs)
          liftIO (cdr arg0)
        arg1 <- liftIO (readIORef filename)
        liftIO (parserValidateExpressionList arg0 arg1)
      pure ()
  pure ()

sexprTree :: Maybe Box -> IO (Maybe Box)
sexprTree l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  qinit <- pure Nothing
  b <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef l)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      qset <- do
        arg0 <- liftIO (readIORef l)
        liftIO (car arg0)
      liftIO (writeIORef b qset)
      hcond <- do
        arg0 <- liftIO (readIORef b)
        liftIO (isOpenBrace arg0)
      if hcond
        then do
          hret <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef l)
                liftIO (cdr arg0)
              liftIO (sexprTree arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef l)
                  liftIO (cdr arg0)
                liftIO (skipList arg0)
              liftIO (sexprTree arg0)
            liftIO (cons arg0 arg1)
          qreturn hret
          pure ()
        else do
          hcond <- do
            arg0 <- liftIO (readIORef b)
            liftIO (isCloseBrace arg0)
          if hcond
            then do
              hret <- liftIO emptyList
              qreturn hret
              pure ()
            else do
              hret <- do
                arg0 <- do
                  arg0 <- pure "line"
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- liftIO (readIORef b)
                  arg1 <- do
                    arg0 <- pure "line"
                    liftIO (boxString arg0)
                  arg2 <- do
                    arg0 <- pure (-1)
                    liftIO (boxInt arg0)
                  liftIO (getTagFail arg0 arg1 arg2)
                arg2 <- do
                  arg0 <- liftIO (readIORef b)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef l)
                      liftIO (cdr arg0)
                    liftIO (sexprTree arg0)
                  liftIO (cons arg0 arg1)
                liftIO (setTag arg0 arg1 arg2)
              qreturn hret
              pure ()
          pure ()
      pure ()
  pure Nothing

loadQuon :: String -> IO (Maybe Box)
loadQuon filename_arg = evalContT $ callCC $ \qreturn -> do
  filename <- liftIO (newIORef filename_arg)
  qinit <- pure Nothing
  programBox <- liftIO (newIORef qinit)
  qinit <- pure ""
  programStr <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  tree <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef filename)
    liftIO (read_file arg0)
  liftIO (writeIORef programBox qset)
  hcond <- do
    arg0 <- liftIO (readIORef programBox)
    liftIO (isNil arg0)
  if hcond
    then do
      _ <- do
        arg0 <- pure stderr
        arg1 <- pure "Could not read file: "
        liftIO (hPrintf arg0 arg1)
      _ <- do
        arg0 <- pure stderr
        arg1 <- liftIO (readIORef filename)
        liftIO (hPrintf arg0 arg1)
      _ <- do
        arg0 <- pure stderr
        arg1 <- pure "\n"
        liftIO (hPrintf arg0 arg1)
      _ <- do
        arg0 <- pure 1
        liftIO (exit arg0)
      pure ()
    else do
      pure ()
  qset <- do
    arg0 <- liftIO (readIORef programBox)
    liftIO (unBoxString arg0)
  liftIO (writeIORef programStr qset)
  qset <- do
    arg0 <- liftIO (readIORef programStr)
    arg1 <- liftIO (readIORef filename)
    liftIO (readSexpr arg0 arg1)
  liftIO (writeIORef tree qset)
  hret <- liftIO (readIORef tree)
  qreturn hret
  pure Nothing

getIncludes :: Maybe Box -> IO (Maybe Box)
getIncludes program_arg = evalContT $ callCC $ \qreturn -> do
  program <- liftIO (newIORef program_arg)
  hret <- do
    arg0 <- do
      arg0 <- liftIO (readIORef program)
      liftIO (first arg0)
    liftIO (cdr arg0)
  qreturn hret
  pure Nothing

getTypes :: Maybe Box -> IO (Maybe Box)
getTypes program_arg = evalContT $ callCC $ \qreturn -> do
  program <- liftIO (newIORef program_arg)
  hret <- do
    arg0 <- do
      arg0 <- liftIO (readIORef program)
      liftIO (second arg0)
    liftIO (cdr arg0)
  qreturn hret
  pure Nothing

getFunctions :: Maybe Box -> IO (Maybe Box)
getFunctions program_arg = evalContT $ callCC $ \qreturn -> do
  program <- liftIO (newIORef program_arg)
  hret <- do
    arg0 <- do
      arg0 <- liftIO (readIORef program)
      liftIO (third arg0)
    liftIO (cdr arg0)
  qreturn hret
  pure Nothing

insertInclude :: Maybe Box -> String -> IO (Maybe Box)
insertInclude tree_arg extra_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  extra <- liftIO (newIORef extra_arg)
  qinit <- pure Nothing
  newProg <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  includes <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  types <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  functions <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  boxedExtra <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  newIncludes <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (isNil arg0)
  if hcond
    then do
      _ <- do
        arg0 <- pure "insertInlcude: tree is nil"
        liftIO (printf arg0)
      hret <- pure Nothing
      qreturn hret
      pure ()
    else do
      qset <- do
        arg0 <- liftIO (readIORef tree)
        liftIO (getIncludes arg0)
      liftIO (writeIORef includes qset)
      qset <- do
        arg0 <- liftIO (readIORef tree)
        liftIO (getTypes arg0)
      liftIO (writeIORef types qset)
      qset <- do
        arg0 <- liftIO (readIORef tree)
        liftIO (getFunctions arg0)
      liftIO (writeIORef functions qset)
      qset <- do
        arg0 <- liftIO (readIORef extra)
        liftIO (boxSymbol arg0)
      liftIO (writeIORef boxedExtra qset)
      qset <- do
        arg0 <- liftIO (readIORef boxedExtra)
        arg1 <- liftIO (readIORef includes)
        liftIO (cons arg0 arg1)
      liftIO (writeIORef newIncludes qset)
      qset <- do
        arg0 <- liftIO (readIORef newIncludes)
        arg1 <- liftIO (readIORef types)
        arg2 <- liftIO (readIORef functions)
        liftIO (buildProg arg0 arg1 arg2)
      liftIO (writeIORef newProg qset)
      hret <- liftIO (readIORef newProg)
      qreturn hret
      pure ()
  pure Nothing

stringInList :: String -> Maybe Box -> IO (Bool)
stringInList item_arg l_arg = evalContT $ callCC $ \qreturn -> do
  item <- liftIO (newIORef item_arg)
  l <- liftIO (newIORef l_arg)
  hcond <- do
    arg0 <- liftIO (readIORef l)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- pure False
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- liftIO (readIORef item)
        arg1 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef l)
            liftIO (car arg0)
          liftIO (stringify arg0)
        liftIO (equalString arg0 arg1)
      if hcond
        then do
          hret <- pure True
          qreturn hret
          pure ()
        else do
          hret <- do
            arg0 <- liftIO (readIORef item)
            arg1 <- do
              arg0 <- liftIO (readIORef l)
              liftIO (cdr arg0)
            liftIO (stringInList arg0 arg1)
          qreturn hret
          pure ()
      pure ()
  pure False

appendMissingIncludes :: Maybe Box -> Maybe Box -> Maybe Box -> IO (Maybe Box)
appendMissingIncludes candidates_arg pending_arg seen_arg = evalContT $ callCC $ \qreturn -> do
  candidates <- liftIO (newIORef candidates_arg)
  pending <- liftIO (newIORef pending_arg)
  seen <- liftIO (newIORef seen_arg)
  qinit <- pure Nothing
  candidate <- liftIO (newIORef qinit)
  qinit <- pure ""
  candidateFile <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef candidates)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- liftIO (readIORef pending)
      qreturn hret
      pure ()
    else do
      qset <- do
        arg0 <- liftIO (readIORef candidates)
        liftIO (car arg0)
      liftIO (writeIORef candidate qset)
      qset <- do
        arg0 <- liftIO (readIORef candidate)
        liftIO (stringify arg0)
      liftIO (writeIORef candidateFile qset)
      hcond <- do
        arg0 <- do
          arg0 <- liftIO (readIORef candidateFile)
          arg1 <- liftIO (readIORef seen)
          liftIO (stringInList arg0 arg1)
        arg1 <- do
          arg0 <- liftIO (readIORef candidateFile)
          arg1 <- liftIO (readIORef pending)
          liftIO (stringInList arg0 arg1)
        liftIO (orBool arg0 arg1)
      if hcond
        then do
          hret <- do
            arg0 <- do
              arg0 <- liftIO (readIORef candidates)
              liftIO (cdr arg0)
            arg1 <- liftIO (readIORef pending)
            arg2 <- liftIO (readIORef seen)
            liftIO (appendMissingIncludes arg0 arg1 arg2)
          qreturn hret
          pure ()
        else do
          hret <- do
            arg0 <- liftIO (readIORef candidate)
            arg1 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef candidates)
                liftIO (cdr arg0)
              arg1 <- liftIO (readIORef pending)
              arg2 <- liftIO (readIORef seen)
              liftIO (appendMissingIncludes arg0 arg1 arg2)
            liftIO (cons arg0 arg1)
          qreturn hret
          pure ()
      pure ()
  pure Nothing

loadIncludes :: Maybe Box -> Maybe Box -> IO (Maybe Box)
loadIncludes tree_arg seen_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  seen <- liftIO (newIORef seen_arg)
  qinit <- pure Nothing
  newProg <- liftIO (newIORef qinit)
  qinit <- pure ""
  includeFile <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  functionsCombined <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  typesCombined <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  includeTree <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  pendingIncludes <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  nextIncludes <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  nextSeen <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  contentsBox <- liftIO (newIORef qinit)
  qinit <- pure ""
  contents <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef tree)
        liftIO (getIncludes arg0)
      liftIO (listLength arg0)
    arg1 <- pure 0
    liftIO (greaterthan arg0 arg1)
  if hcond
    then do
      qset <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef tree)
            liftIO (getIncludes arg0)
          liftIO (first arg0)
        liftIO (stringify arg0)
      liftIO (writeIORef includeFile qset)
      hcond <- do
        arg0 <- liftIO (readIORef includeFile)
        arg1 <- liftIO (readIORef seen)
        liftIO (stringInList arg0 arg1)
      if hcond
        then do
          qset <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (getIncludes arg0)
              liftIO (cdr arg0)
            arg1 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (getTypes arg0)
            arg2 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (getFunctions arg0)
            liftIO (buildProg arg0 arg1 arg2)
          liftIO (writeIORef newProg qset)
          hret <- do
            arg0 <- liftIO (readIORef newProg)
            arg1 <- liftIO (readIORef seen)
            liftIO (loadIncludes arg0 arg1)
          qreturn hret
          pure ()
        else do
          pure ()
      qset <- do
        arg0 <- do
          arg0 <- liftIO (readIORef includeFile)
          liftIO (boxString arg0)
        arg1 <- liftIO (readIORef seen)
        liftIO (cons arg0 arg1)
      liftIO (writeIORef nextSeen qset)
      qset <- do
        arg0 <- liftIO (readIORef includeFile)
        liftIO (read_file arg0)
      liftIO (writeIORef contentsBox qset)
      hcond <- do
        arg0 <- liftIO (readIORef contentsBox)
        liftIO (isNil arg0)
      if hcond
        then do
          _ <- do
            arg0 <- pure stderr
            arg1 <- pure "Could not read include file: "
            liftIO (hPrintf arg0 arg1)
          _ <- do
            arg0 <- pure stderr
            arg1 <- liftIO (readIORef includeFile)
            liftIO (hPrintf arg0 arg1)
          _ <- do
            arg0 <- pure stderr
            arg1 <- pure "\n"
            liftIO (hPrintf arg0 arg1)
          _ <- do
            arg0 <- pure 1
            liftIO (exit arg0)
          hret <- pure Nothing
          qreturn hret
          pure ()
        else do
          pure ()
      qset <- do
        arg0 <- liftIO (readIORef contentsBox)
        liftIO (unBoxString arg0)
      liftIO (writeIORef contents qset)
      qset <- do
        arg0 <- liftIO (readIORef contents)
        arg1 <- liftIO (readIORef includeFile)
        liftIO (readSexpr arg0 arg1)
      liftIO (writeIORef includeTree qset)
      hcond <- do
        arg0 <- liftIO (readIORef includeTree)
        liftIO (isNil arg0)
      if hcond
        then do
          _ <- do
            arg0 <- pure stderr
            arg1 <- pure "Could not parse include file: "
            liftIO (hPrintf arg0 arg1)
          _ <- do
            arg0 <- pure stderr
            arg1 <- liftIO (readIORef includeFile)
            liftIO (hPrintf arg0 arg1)
          _ <- do
            arg0 <- pure stderr
            arg1 <- pure "\n"
            liftIO (hPrintf arg0 arg1)
          _ <- do
            arg0 <- pure 1
            liftIO (exit arg0)
          hret <- pure Nothing
          qreturn hret
          pure ()
        else do
          qset <- do
            arg0 <- do
              arg0 <- liftIO (readIORef includeTree)
              liftIO (getFunctions arg0)
            arg1 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (getFunctions arg0)
            liftIO (concatLists arg0 arg1)
          liftIO (writeIORef functionsCombined qset)
          qset <- do
            arg0 <- do
              arg0 <- liftIO (readIORef includeTree)
              liftIO (getTypes arg0)
            arg1 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (getTypes arg0)
            liftIO (concatLists arg0 arg1)
          liftIO (writeIORef typesCombined qset)
          qset <- do
            arg0 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (getIncludes arg0)
            liftIO (cdr arg0)
          liftIO (writeIORef pendingIncludes qset)
          qset <- do
            arg0 <- do
              arg0 <- liftIO (readIORef includeTree)
              liftIO (getIncludes arg0)
            arg1 <- liftIO (readIORef pendingIncludes)
            arg2 <- liftIO (readIORef nextSeen)
            liftIO (appendMissingIncludes arg0 arg1 arg2)
          liftIO (writeIORef nextIncludes qset)
          qset <- do
            arg0 <- liftIO (readIORef nextIncludes)
            arg1 <- liftIO (readIORef typesCombined)
            arg2 <- liftIO (readIORef functionsCombined)
            liftIO (buildProg arg0 arg1 arg2)
          liftIO (writeIORef newProg qset)
          hret <- do
            arg0 <- liftIO (readIORef newProg)
            arg1 <- liftIO (readIORef nextSeen)
            liftIO (loadIncludes arg0 arg1)
          qreturn hret
          pure ()
      pure ()
    else do
      hret <- liftIO (readIORef tree)
      qreturn hret
      pure ()
  pure Nothing

buildProg :: Maybe Box -> Maybe Box -> Maybe Box -> IO (Maybe Box)
buildProg includes_arg types_arg functions_arg = evalContT $ callCC $ \qreturn -> do
  includes <- liftIO (newIORef includes_arg)
  types <- liftIO (newIORef types_arg)
  functions <- liftIO (newIORef functions_arg)
  qinit <- pure Nothing
  program <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- do
      arg0 <- pure "includes"
      liftIO (boxSymbol arg0)
    arg1 <- liftIO (readIORef includes)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef includes qset)
  qset <- do
    arg0 <- do
      arg0 <- pure "types"
      liftIO (boxSymbol arg0)
    arg1 <- liftIO (readIORef types)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef types qset)
  qset <- do
    arg0 <- do
      arg0 <- pure "functions"
      liftIO (boxSymbol arg0)
    arg1 <- liftIO (readIORef functions)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef functions qset)
  qset <- do
    arg0 <- liftIO (readIORef includes)
    arg1 <- do
      arg0 <- liftIO (readIORef types)
      arg1 <- do
        arg0 <- liftIO (readIORef functions)
        arg1 <- pure Nothing
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  liftIO (writeIORef program qset)
  hret <- liftIO (readIORef program)
  qreturn hret
  pure Nothing

car :: Maybe Box -> IO (Maybe Box)
car l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  hcond <- do
    arg0 <- liftIO (readIORef l)
    liftIO (isNil arg0)
  if hcond
    then do
      _ <- do
        arg0 <- pure "Cannot call car on empty list!\n"
        liftIO (printf arg0)
      _ <- do
        arg0 <- pure "Cannot call car on empty list!\n"
        liftIO (panic arg0)
      hret <- pure Nothing
      qreturn hret
      pure ()
    else do
      _ <- do
        arg0 <- pure "list"
        arg1 <- liftIO (readIORef l)
        arg2 <- pure 18
        arg3 <- pure "q/lists.qon"
        liftIO (assertType arg0 arg1 arg2 arg3)
      hcond <- do
        arg0 <- do
          hobj <- liftIO (readIORef l)
          liftIO (readIORef (getField @"qf_car" (expect hobj)))
        liftIO (isNil arg0)
      if hcond
        then do
          hret <- pure Nothing
          qreturn hret
          pure ()
        else do
          hret <- do
            hobj <- liftIO (readIORef l)
            liftIO (readIORef (getField @"qf_car" (expect hobj)))
          qreturn hret
          pure ()
      pure ()
  pure Nothing

cdr :: Maybe Box -> IO (Maybe Box)
cdr l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  hcond <- do
    arg0 <- liftIO (readIORef l)
    liftIO (isEmpty arg0)
  if hcond
    then do
      _ <- do
        arg0 <- pure "Attempt to cdr an empty list!!!!\n"
        liftIO (printf arg0)
      _ <- do
        arg0 <- pure "Attempt to cdr an empty list!!!!\n"
        liftIO (panic arg0)
      hret <- pure Nothing
      qreturn hret
      pure ()
    else do
      hret <- do
        hobj <- liftIO (readIORef l)
        liftIO (readIORef (getField @"qf_cdr" (expect hobj)))
      qreturn hret
      pure ()
  pure Nothing

cons :: Maybe Box -> Maybe Box -> IO (Maybe Box)
cons dataValue_arg l_arg = evalContT $ callCC $ \qreturn -> do
  dataValue <- liftIO (newIORef dataValue_arg)
  l <- liftIO (newIORef l_arg)
  qinit <- pure Nothing
  p <- liftIO (newIORef qinit)
  qset <- liftIO makePair
  liftIO (writeIORef p qset)
  hobj <- liftIO (readIORef p)
  qset <- liftIO (readIORef l)
  liftIO (writeIORef (getField @"qf_cdr" (expect hobj)) qset)
  hobj <- liftIO (readIORef p)
  qset <- liftIO (readIORef dataValue)
  liftIO (writeIORef (getField @"qf_car" (expect hobj)) qset)
  hobj <- liftIO (readIORef p)
  qset <- pure "list"
  liftIO (writeIORef (getField @"qf_typ" (expect hobj)) qset)
  hret <- liftIO (readIORef p)
  qreturn hret
  pure Nothing

caar :: Maybe Box -> IO (Maybe Box)
caar l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  hret <- do
    arg0 <- do
      arg0 <- liftIO (readIORef l)
      liftIO (car arg0)
    liftIO (car arg0)
  qreturn hret
  pure Nothing

cadr :: Maybe Box -> IO (Maybe Box)
cadr l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  hret <- do
    arg0 <- do
      arg0 <- liftIO (readIORef l)
      liftIO (cdr arg0)
    liftIO (car arg0)
  qreturn hret
  pure Nothing

caddr :: Maybe Box -> IO (Maybe Box)
caddr l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef l)
        liftIO (cdr arg0)
      liftIO (cdr arg0)
    liftIO (car arg0)
  qreturn hret
  pure Nothing

cadddr :: Maybe Box -> IO (Maybe Box)
cadddr l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- liftIO (readIORef l)
          liftIO (cdr arg0)
        liftIO (cdr arg0)
      liftIO (cdr arg0)
    liftIO (car arg0)
  qreturn hret
  pure Nothing

caddddr :: Maybe Box -> IO (Maybe Box)
caddddr l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef l)
            liftIO (cdr arg0)
          liftIO (cdr arg0)
        liftIO (cdr arg0)
      liftIO (cdr arg0)
    liftIO (car arg0)
  qreturn hret
  pure Nothing

cddr :: Maybe Box -> IO (Maybe Box)
cddr l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  hret <- do
    arg0 <- do
      arg0 <- liftIO (readIORef l)
      liftIO (cdr arg0)
    liftIO (cdr arg0)
  qreturn hret
  pure Nothing

first :: Maybe Box -> IO (Maybe Box)
first l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  hret <- do
    arg0 <- liftIO (readIORef l)
    liftIO (car arg0)
  qreturn hret
  pure Nothing

second :: Maybe Box -> IO (Maybe Box)
second l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  hret <- do
    arg0 <- liftIO (readIORef l)
    liftIO (cadr arg0)
  qreturn hret
  pure Nothing

third :: Maybe Box -> IO (Maybe Box)
third l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  hret <- do
    arg0 <- liftIO (readIORef l)
    liftIO (caddr arg0)
  qreturn hret
  pure Nothing

fourth :: Maybe Box -> IO (Maybe Box)
fourth l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  hret <- do
    arg0 <- liftIO (readIORef l)
    liftIO (cadddr arg0)
  qreturn hret
  pure Nothing

fifth :: Maybe Box -> IO (Maybe Box)
fifth l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  hret <- do
    arg0 <- liftIO (readIORef l)
    liftIO (caddddr arg0)
  qreturn hret
  pure Nothing

sixth :: Maybe Box -> IO (Maybe Box)
sixth l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef l)
              liftIO (cdr arg0)
            liftIO (cdr arg0)
          liftIO (cdr arg0)
        liftIO (cdr arg0)
      liftIO (cdr arg0)
    liftIO (car arg0)
  qreturn hret
  pure Nothing

seventh :: Maybe Box -> IO (Maybe Box)
seventh l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef l)
                liftIO (cdr arg0)
              liftIO (cdr arg0)
            liftIO (cdr arg0)
          liftIO (cdr arg0)
        liftIO (cdr arg0)
      liftIO (cdr arg0)
    liftIO (car arg0)
  qreturn hret
  pure Nothing

eighth :: Maybe Box -> IO (Maybe Box)
eighth l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef l)
                  liftIO (cdr arg0)
                liftIO (cdr arg0)
              liftIO (cdr arg0)
            liftIO (cdr arg0)
          liftIO (cdr arg0)
        liftIO (cdr arg0)
      liftIO (cdr arg0)
    liftIO (car arg0)
  qreturn hret
  pure Nothing

ninth :: Maybe Box -> IO (Maybe Box)
ninth l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef l)
                    liftIO (cdr arg0)
                  liftIO (cdr arg0)
                liftIO (cdr arg0)
              liftIO (cdr arg0)
            liftIO (cdr arg0)
          liftIO (cdr arg0)
        liftIO (cdr arg0)
      liftIO (cdr arg0)
    liftIO (car arg0)
  qreturn hret
  pure Nothing

tenth :: Maybe Box -> IO (Maybe Box)
tenth l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef l)
                      liftIO (cdr arg0)
                    liftIO (cdr arg0)
                  liftIO (cdr arg0)
                liftIO (cdr arg0)
              liftIO (cdr arg0)
            liftIO (cdr arg0)
          liftIO (cdr arg0)
        liftIO (cdr arg0)
      liftIO (cdr arg0)
    liftIO (car arg0)
  qreturn hret
  pure Nothing

eleventh :: Maybe Box -> IO (Maybe Box)
eleventh l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef l)
                        liftIO (cdr arg0)
                      liftIO (cdr arg0)
                    liftIO (cdr arg0)
                  liftIO (cdr arg0)
                liftIO (cdr arg0)
              liftIO (cdr arg0)
            liftIO (cdr arg0)
          liftIO (cdr arg0)
        liftIO (cdr arg0)
      liftIO (cdr arg0)
    liftIO (car arg0)
  qreturn hret
  pure Nothing

twelfth :: Maybe Box -> IO (Maybe Box)
twelfth l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef l)
                          liftIO (cdr arg0)
                        liftIO (cdr arg0)
                      liftIO (cdr arg0)
                    liftIO (cdr arg0)
                  liftIO (cdr arg0)
                liftIO (cdr arg0)
              liftIO (cdr arg0)
            liftIO (cdr arg0)
          liftIO (cdr arg0)
        liftIO (cdr arg0)
      liftIO (cdr arg0)
    liftIO (car arg0)
  qreturn hret
  pure Nothing

rest :: Maybe Box -> IO (Maybe Box)
rest l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  hret <- do
    arg0 <- liftIO (readIORef l)
    liftIO (cdr arg0)
  qreturn hret
  pure Nothing

isList :: Maybe Box -> IO (Bool)
isList b_arg = evalContT $ callCC $ \qreturn -> do
  b <- liftIO (newIORef b_arg)
  hcond <- do
    arg0 <- liftIO (readIORef b)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- pure True
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- pure "list"
        arg1 <- do
          hobj <- liftIO (readIORef b)
          liftIO (readIORef (getField @"qf_typ" (expect hobj)))
        liftIO (equalString arg0 arg1)
      qreturn hret
      pure ()
  pure False

emptyList :: IO (Maybe Box)
emptyList = evalContT $ callCC $ \qreturn -> do
  hret <- pure Nothing
  qreturn hret
  pure Nothing

isEmpty :: Maybe Box -> IO (Bool)
isEmpty b_arg = evalContT $ callCC $ \qreturn -> do
  b <- liftIO (newIORef b_arg)
  hcond <- do
    arg0 <- liftIO (readIORef b)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- pure True
      qreturn hret
      pure ()
    else do
      hret <- pure False
      qreturn hret
      pure ()
  pure False

listLength :: Maybe Box -> IO (Int)
listLength l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  hcond <- do
    arg0 <- liftIO (readIORef l)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- pure 0
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef l)
            liftIO (cdr arg0)
          liftIO (listLength arg0)
        liftIO (add1 arg0)
      qreturn hret
      pure ()
  pure 0

alistCons :: Maybe Box -> Maybe Box -> Maybe Box -> IO (Maybe Box)
alistCons key_arg value_arg alist_arg = evalContT $ callCC $ \qreturn -> do
  key <- liftIO (newIORef key_arg)
  value <- liftIO (newIORef value_arg)
  alist <- liftIO (newIORef alist_arg)
  hret <- do
    arg0 <- do
      arg0 <- liftIO (readIORef key)
      arg1 <- liftIO (readIORef value)
      liftIO (cons arg0 arg1)
    arg1 <- liftIO (readIORef alist)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

assoc :: String -> Maybe Box -> IO (Maybe Box)
assoc searchTerm_arg l_arg = evalContT $ callCC $ \qreturn -> do
  searchTerm <- liftIO (newIORef searchTerm_arg)
  l <- liftIO (newIORef l_arg)
  qinit <- pure Nothing
  elem <- liftIO (newIORef qinit)
  _ <- do
    arg0 <- pure "list"
    arg1 <- liftIO (readIORef l)
    arg2 <- pure 96
    arg3 <- pure "q/lists.qon"
    liftIO (assertType arg0 arg1 arg2 arg3)
  hcond <- do
    arg0 <- liftIO (readIORef l)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- do
        arg0 <- pure False
        liftIO (boxBool arg0)
      qreturn hret
      pure ()
    else do
      qset <- do
        arg0 <- liftIO (readIORef l)
        liftIO (car arg0)
      liftIO (writeIORef elem qset)
      _ <- do
        arg0 <- pure "list"
        arg1 <- liftIO (readIORef elem)
        arg2 <- pure 102
        arg3 <- pure "q/lists.qon"
        liftIO (assertType arg0 arg1 arg2 arg3)
      hcond <- do
        arg0 <- liftIO (readIORef elem)
        liftIO (isEmpty arg0)
      if hcond
        then do
          hret <- do
            arg0 <- liftIO (readIORef searchTerm)
            arg1 <- do
              arg0 <- liftIO (readIORef l)
              liftIO (cdr arg0)
            liftIO (assoc arg0 arg1)
          qreturn hret
          pure ()
        else do
          hcond <- pure False
          if hcond
            then do
              _ <- do
                arg0 <- pure "Comparing %s and %s\n"
                arg1 <- liftIO (readIORef searchTerm)
                arg2 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef elem)
                    liftIO (car arg0)
                  liftIO (stringify arg0)
                liftIO (printf arg0 arg1 arg2)
              pure ()
            else do
              _ <- do
                arg0 <- pure ""
                liftIO (printf arg0)
              pure ()
          hcond <- do
            arg0 <- liftIO (readIORef searchTerm)
            arg1 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef elem)
                liftIO (car arg0)
              liftIO (stringify arg0)
            liftIO (equalString arg0 arg1)
          if hcond
            then do
              hret <- liftIO (readIORef elem)
              qreturn hret
              pure ()
            else do
              hret <- do
                arg0 <- liftIO (readIORef searchTerm)
                arg1 <- do
                  arg0 <- liftIO (readIORef l)
                  liftIO (cdr arg0)
                liftIO (assoc arg0 arg1)
              qreturn hret
              pure ()
          pure ()
      pure ()
  pure Nothing

chooseBox :: String -> IO (String)
chooseBox aType_arg = evalContT $ callCC $ \qreturn -> do
  aType <- liftIO (newIORef aType_arg)
  hcond <- do
    arg0 <- pure "string"
    arg1 <- liftIO (readIORef aType)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "boxString"
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- pure "symbol"
        arg1 <- liftIO (readIORef aType)
        liftIO (equalString arg0 arg1)
      if hcond
        then do
          hret <- pure "boxSymbol"
          qreturn hret
          pure ()
        else do
          hcond <- do
            arg0 <- pure "bool"
            arg1 <- liftIO (readIORef aType)
            liftIO (equalString arg0 arg1)
          if hcond
            then do
              hret <- pure "boxBool"
              qreturn hret
              pure ()
            else do
              hcond <- do
                arg0 <- pure "int"
                arg1 <- liftIO (readIORef aType)
                liftIO (equalString arg0 arg1)
              if hcond
                then do
                  hret <- pure "boxInt"
                  qreturn hret
                  pure ()
                else do
                  hcond <- do
                    arg0 <- pure "float"
                    arg1 <- liftIO (readIORef aType)
                    liftIO (equalString arg0 arg1)
                  if hcond
                    then do
                      hret <- pure "boxFloat"
                      qreturn hret
                      pure ()
                    else do
                      _ <- do
                        arg0 <- pure "Invalid type"
                        liftIO (panic arg0)
                      pure ()
                  pure ()
              pure ()
          pure ()
      pure ()
  hret <- pure ""
  qreturn hret
  pure ""

mlistLiteral :: Maybe Box -> IO (Maybe Box)
mlistLiteral b_arg = evalContT $ callCC $ \qreturn -> do
  b <- liftIO (newIORef b_arg)
  hcond <- do
    arg0 <- liftIO (readIORef b)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- pure Nothing
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- pure "string"
        arg1 <- do
          arg0 <- liftIO (readIORef b)
          liftIO (boxType arg0)
        liftIO (equalString arg0 arg1)
      if hcond
        then do
          hret <- liftIO (readIORef b)
          qreturn hret
          pure ()
        else do
          hcond <- do
            arg0 <- pure "bool"
            arg1 <- do
              arg0 <- liftIO (readIORef b)
              liftIO (boxType arg0)
            liftIO (equalString arg0 arg1)
          if hcond
            then do
              hret <- liftIO (readIORef b)
              qreturn hret
              pure ()
            else do
              hcond <- do
                arg0 <- pure "int"
                arg1 <- do
                  arg0 <- liftIO (readIORef b)
                  liftIO (boxType arg0)
                liftIO (equalString arg0 arg1)
              if hcond
                then do
                  hret <- liftIO (readIORef b)
                  qreturn hret
                  pure ()
                else do
                  hcond <- do
                    arg0 <- pure "symbol"
                    arg1 <- do
                      arg0 <- liftIO (readIORef b)
                      liftIO (boxType arg0)
                    liftIO (equalString arg0 arg1)
                  if hcond
                    then do
                      hret <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef b)
                          liftIO (unBoxSymbol arg0)
                        liftIO (boxString arg0)
                      qreturn hret
                      pure ()
                    else do
                      hret <- do
                        arg0 <- do
                          arg0 <- pure "Unsupported type in mlistLiteral: "
                          arg1 <- do
                            arg0 <- liftIO (readIORef b)
                            liftIO (boxType arg0)
                          liftIO (stringConcatenate arg0 arg1)
                        liftIO (boxString arg0)
                      qreturn hret
                      pure ()
                  pure ()
              pure ()
          pure ()
      pure ()
  pure Nothing

doMultiList :: Maybe Box -> IO (Maybe Box)
doMultiList l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  qinit <- pure Nothing
  newlist <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  ret <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  elem <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef l)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- pure "nil"
          liftIO (boxSymbol arg0)
        arg1 <- pure Nothing
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- liftIO (readIORef l)
        liftIO (isEmpty arg0)
      if hcond
        then do
          hret <- pure Nothing
          qreturn hret
          pure ()
        else do
          qset <- do
            arg0 <- liftIO (readIORef l)
            liftIO (first arg0)
          liftIO (writeIORef elem qset)
          qset <- do
            arg0 <- do
              arg0 <- do
                arg0 <- do
                  hobj <- liftIO (readIORef elem)
                  liftIO (readIORef (getField @"qf_typ" (expect hobj)))
                liftIO (chooseBox arg0)
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef l)
                  liftIO (first arg0)
                liftIO (mlistLiteral arg0)
              arg1 <- liftIO (readIORef newlist)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (writeIORef newlist qset)
          qset <- do
            arg0 <- do
              arg0 <- do
                arg0 <- pure "cons"
                liftIO (boxSymbol arg0)
              arg1 <- do
                arg0 <- liftIO (readIORef newlist)
                arg1 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef l)
                    liftIO (cdr arg0)
                  liftIO (doMultiList arg0)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            arg1 <- pure Nothing
            liftIO (cons arg0 arg1)
          liftIO (writeIORef ret qset)
          hret <- liftIO (readIORef ret)
          qreturn hret
          pure ()
      pure ()
  pure Nothing

isDigit :: String -> IO (Bool)
isDigit val_arg = evalContT $ callCC $ \qreturn -> do
  val <- liftIO (newIORef val_arg)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef val)
      liftIO (string_length arg0)
    arg1 <- pure 1
    liftIO (equal arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- pure "0123456789"
        arg1 <- liftIO (readIORef val)
        liftIO (stringContains arg0 arg1)
      qreturn hret
      pure ()
    else do
      hret <- pure False
      qreturn hret
      pure ()
  pure False

isUnsignedIntFrom :: String -> Int -> IO (Bool)
isUnsignedIntFrom val_arg pos_arg = evalContT $ callCC $ \qreturn -> do
  val <- liftIO (newIORef val_arg)
  pos <- liftIO (newIORef pos_arg)
  qinit <- pure 0
  len <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef val)
    liftIO (string_length arg0)
  liftIO (writeIORef len qset)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef pos)
      liftIO (add1 arg0)
    arg1 <- liftIO (readIORef len)
    liftIO (greaterthan arg0 arg1)
  if hcond
    then do
      hret <- pure True
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- do
          arg0 <- liftIO (readIORef val)
          arg1 <- liftIO (readIORef pos)
          arg2 <- pure 1
          liftIO (sub_string arg0 arg1 arg2)
        liftIO (isDigit arg0)
      if hcond
        then do
          hret <- do
            arg0 <- liftIO (readIORef val)
            arg1 <- do
              arg0 <- liftIO (readIORef pos)
              liftIO (add1 arg0)
            liftIO (isUnsignedIntFrom arg0 arg1)
          qreturn hret
          pure ()
        else do
          hret <- pure False
          qreturn hret
          pure ()
      pure ()
  pure False

isInt :: String -> IO (Bool)
isInt val_arg = evalContT $ callCC $ \qreturn -> do
  val <- liftIO (newIORef val_arg)
  qinit <- pure 0
  len <- liftIO (newIORef qinit)
  qinit <- pure ""
  firstLetter <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef val)
    liftIO (string_length arg0)
  liftIO (writeIORef len qset)
  hcond <- do
    arg0 <- liftIO (readIORef len)
    arg1 <- pure 0
    liftIO (equal arg0 arg1)
  if hcond
    then do
      hret <- pure False
      qreturn hret
      pure ()
    else do
      pure ()
  qset <- do
    arg0 <- liftIO (readIORef val)
    arg1 <- pure 0
    arg2 <- pure 1
    liftIO (sub_string arg0 arg1 arg2)
  liftIO (writeIORef firstLetter qset)
  hcond <- do
    arg0 <- pure "-"
    arg1 <- liftIO (readIORef firstLetter)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hcond <- do
        arg0 <- liftIO (readIORef len)
        arg1 <- pure 1
        liftIO (equal arg0 arg1)
      if hcond
        then do
          hret <- pure False
          qreturn hret
          pure ()
        else do
          hret <- do
            arg0 <- liftIO (readIORef val)
            arg1 <- pure 1
            liftIO (isUnsignedIntFrom arg0 arg1)
          qreturn hret
          pure ()
      pure ()
    else do
      hret <- do
        arg0 <- liftIO (readIORef val)
        arg1 <- pure 0
        liftIO (isUnsignedIntFrom arg0 arg1)
      qreturn hret
      pure ()
  pure False

isFloatFrom :: String -> Int -> Bool -> Bool -> Bool -> IO (Bool)
isFloatFrom val_arg pos_arg seenDot_arg seenDigit_arg digitAfterDot_arg = evalContT $ callCC $ \qreturn -> do
  val <- liftIO (newIORef val_arg)
  pos <- liftIO (newIORef pos_arg)
  seenDot <- liftIO (newIORef seenDot_arg)
  seenDigit <- liftIO (newIORef seenDigit_arg)
  digitAfterDot <- liftIO (newIORef digitAfterDot_arg)
  qinit <- pure 0
  len <- liftIO (newIORef qinit)
  qinit <- pure ""
  ch <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef val)
    liftIO (string_length arg0)
  liftIO (writeIORef len qset)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef pos)
      liftIO (add1 arg0)
    arg1 <- liftIO (readIORef len)
    liftIO (greaterthan arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- liftIO (readIORef seenDot)
        arg1 <- do
          arg0 <- liftIO (readIORef seenDigit)
          arg1 <- liftIO (readIORef digitAfterDot)
          liftIO (andBool arg0 arg1)
        liftIO (andBool arg0 arg1)
      qreturn hret
      pure ()
    else do
      pure ()
  qset <- do
    arg0 <- liftIO (readIORef val)
    arg1 <- liftIO (readIORef pos)
    arg2 <- pure 1
    liftIO (sub_string arg0 arg1 arg2)
  liftIO (writeIORef ch qset)
  hcond <- do
    arg0 <- liftIO (readIORef ch)
    liftIO (isDigit arg0)
  if hcond
    then do
      hret <- do
        arg0 <- liftIO (readIORef val)
        arg1 <- do
          arg0 <- liftIO (readIORef pos)
          liftIO (add1 arg0)
        arg2 <- liftIO (readIORef seenDot)
        arg3 <- pure True
        arg4 <- do
          arg0 <- liftIO (readIORef digitAfterDot)
          arg1 <- liftIO (readIORef seenDot)
          liftIO (orBool arg0 arg1)
        liftIO (isFloatFrom arg0 arg1 arg2 arg3 arg4)
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- pure "."
        arg1 <- liftIO (readIORef ch)
        liftIO (equalString arg0 arg1)
      if hcond
        then do
          hcond <- liftIO (readIORef seenDot)
          if hcond
            then do
              hret <- pure False
              qreturn hret
              pure ()
            else do
              hret <- do
                arg0 <- liftIO (readIORef val)
                arg1 <- do
                  arg0 <- liftIO (readIORef pos)
                  liftIO (add1 arg0)
                arg2 <- pure True
                arg3 <- liftIO (readIORef seenDigit)
                arg4 <- pure False
                liftIO (isFloatFrom arg0 arg1 arg2 arg3 arg4)
              qreturn hret
              pure ()
          pure ()
        else do
          hret <- pure False
          qreturn hret
          pure ()
      pure ()
  pure False

isFloat :: String -> IO (Bool)
isFloat val_arg = evalContT $ callCC $ \qreturn -> do
  val <- liftIO (newIORef val_arg)
  qinit <- pure 0
  len <- liftIO (newIORef qinit)
  qinit <- pure ""
  firstLetter <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef val)
    liftIO (string_length arg0)
  liftIO (writeIORef len qset)
  hcond <- do
    arg0 <- liftIO (readIORef len)
    arg1 <- pure 0
    liftIO (equal arg0 arg1)
  if hcond
    then do
      hret <- pure False
      qreturn hret
      pure ()
    else do
      pure ()
  qset <- do
    arg0 <- liftIO (readIORef val)
    arg1 <- pure 0
    arg2 <- pure 1
    liftIO (sub_string arg0 arg1 arg2)
  liftIO (writeIORef firstLetter qset)
  hcond <- do
    arg0 <- pure "-"
    arg1 <- liftIO (readIORef firstLetter)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hcond <- do
        arg0 <- liftIO (readIORef len)
        arg1 <- pure 1
        liftIO (equal arg0 arg1)
      if hcond
        then do
          hret <- pure False
          qreturn hret
          pure ()
        else do
          hret <- do
            arg0 <- liftIO (readIORef val)
            arg1 <- pure 1
            arg2 <- pure False
            arg3 <- pure False
            arg4 <- pure False
            liftIO (isFloatFrom arg0 arg1 arg2 arg3 arg4)
          qreturn hret
          pure ()
      pure ()
    else do
      hret <- do
        arg0 <- liftIO (readIORef val)
        arg1 <- pure 0
        arg2 <- pure False
        arg3 <- pure False
        arg4 <- pure False
        liftIO (isFloatFrom arg0 arg1 arg2 arg3 arg4)
      qreturn hret
      pure ()
  pure False

qid :: Maybe Box -> IO (Maybe Box)
qid b_arg = evalContT $ callCC $ \qreturn -> do
  b <- liftIO (newIORef b_arg)
  hret <- liftIO (readIORef b)
  qreturn hret
  pure Nothing

chooseBoxInterp :: Maybe Box -> IO (String)
chooseBoxInterp b_arg = evalContT $ callCC $ \qreturn -> do
  b <- liftIO (newIORef b_arg)
  qinit <- do
    arg0 <- liftIO (readIORef b)
    liftIO (stringify arg0)
  val <- liftIO (newIORef qinit)
  qinit <- do
    arg0 <- liftIO (readIORef val)
    arg1 <- pure 0
    arg2 <- pure 1
    liftIO (sub_string arg0 arg1 arg2)
  firstLetter <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- pure "string"
    arg1 <- do
      arg0 <- liftIO (readIORef b)
      liftIO (boxType arg0)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure "boxString"
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- pure "\""
        arg1 <- liftIO (readIORef firstLetter)
        liftIO (equalString arg0 arg1)
      if hcond
        then do
          hret <- pure "boxString"
          qreturn hret
          pure ()
        else do
          hcond <- do
            arg0 <- pure "true"
            arg1 <- liftIO (readIORef val)
            liftIO (equalString arg0 arg1)
          if hcond
            then do
              hret <- pure "boxBool"
              qreturn hret
              pure ()
            else do
              hcond <- do
                arg0 <- pure "false"
                arg1 <- liftIO (readIORef val)
                liftIO (equalString arg0 arg1)
              if hcond
                then do
                  hret <- pure "boxBool"
                  qreturn hret
                  pure ()
                else do
                  hcond <- do
                    arg0 <- liftIO (readIORef val)
                    liftIO (isFloat arg0)
                  if hcond
                    then do
                      hret <- pure "boxFloat"
                      qreturn hret
                      pure ()
                    else do
                      hcond <- do
                        arg0 <- liftIO (readIORef val)
                        liftIO (isInt arg0)
                      if hcond
                        then do
                          hret <- pure "boxInt"
                          qreturn hret
                          pure ()
                        else do
                          hret <- pure "id"
                          qreturn hret
                          pure ()
                      pure ()
                  pure ()
              pure ()
          pure ()
      pure ()
  pure ""

doInterpolatedList :: Maybe Box -> IO (Maybe Box)
doInterpolatedList l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  qinit <- pure Nothing
  newlist <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  ret <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  elem <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef l)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- pure "nil"
          liftIO (boxSymbol arg0)
        arg1 <- pure Nothing
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- liftIO (readIORef l)
        liftIO (isEmpty arg0)
      if hcond
        then do
          hret <- pure Nothing
          qreturn hret
          pure ()
        else do
          qset <- do
            arg0 <- liftIO (readIORef l)
            liftIO (first arg0)
          liftIO (writeIORef elem qset)
          qset <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef elem)
                liftIO (chooseBoxInterp arg0)
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef l)
                liftIO (first arg0)
              arg1 <- liftIO (readIORef newlist)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (writeIORef newlist qset)
          qset <- do
            arg0 <- do
              arg0 <- do
                arg0 <- pure "cons"
                liftIO (boxSymbol arg0)
              arg1 <- do
                arg0 <- liftIO (readIORef newlist)
                arg1 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef l)
                    liftIO (cdr arg0)
                  liftIO (doInterpolatedList arg0)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            arg1 <- pure Nothing
            liftIO (cons arg0 arg1)
          liftIO (writeIORef ret qset)
          hret <- liftIO (readIORef ret)
          qreturn hret
          pure ()
      pure ()
  pure Nothing

doStringList :: Maybe Box -> IO (Maybe Box)
doStringList l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  qinit <- pure Nothing
  newlist <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  ret <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef l)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- pure "nil"
          liftIO (boxSymbol arg0)
        arg1 <- pure Nothing
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
    else do
      qset <- do
        arg0 <- do
          arg0 <- pure "boxString"
          liftIO (boxSymbol arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef l)
            liftIO (first arg0)
          arg1 <- liftIO (readIORef newlist)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (writeIORef newlist qset)
      qset <- do
        arg0 <- do
          arg0 <- do
            arg0 <- pure "cons"
            liftIO (boxSymbol arg0)
          arg1 <- do
            arg0 <- liftIO (readIORef newlist)
            arg1 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef l)
                liftIO (cdr arg0)
              liftIO (doStringList arg0)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        arg1 <- pure Nothing
        liftIO (cons arg0 arg1)
      liftIO (writeIORef ret qset)
      hret <- liftIO (readIORef ret)
      qreturn hret
      pure ()
  pure Nothing

doSymbolList :: Maybe Box -> IO (Maybe Box)
doSymbolList l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  qinit <- pure Nothing
  newlist <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  ret <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef l)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- pure "nil"
          liftIO (boxSymbol arg0)
        arg1 <- pure Nothing
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
    else do
      qset <- do
        arg0 <- do
          arg0 <- pure "boxSymbol"
          liftIO (boxSymbol arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef l)
            liftIO (first arg0)
          arg1 <- liftIO (readIORef newlist)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (writeIORef newlist qset)
      qset <- do
        arg0 <- do
          arg0 <- do
            arg0 <- pure "cons"
            liftIO (boxSymbol arg0)
          arg1 <- do
            arg0 <- liftIO (readIORef newlist)
            arg1 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef l)
                liftIO (cdr arg0)
              liftIO (doSymbolList arg0)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        arg1 <- pure Nothing
        liftIO (cons arg0 arg1)
      liftIO (writeIORef ret qset)
      hret <- liftIO (readIORef ret)
      qreturn hret
      pure ()
  pure Nothing

doBoxList :: Maybe Box -> IO (Maybe Box)
doBoxList l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  hcond <- do
    arg0 <- liftIO (readIORef l)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- pure "nil"
          liftIO (boxSymbol arg0)
        arg1 <- pure Nothing
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- pure "cons"
            liftIO (boxSymbol arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef l)
              liftIO (first arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef l)
                liftIO (cdr arg0)
              liftIO (doBoxList arg0)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        arg1 <- pure Nothing
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

concatLists :: Maybe Box -> Maybe Box -> IO (Maybe Box)
concatLists seq1_arg seq2_arg = evalContT $ callCC $ \qreturn -> do
  seq1 <- liftIO (newIORef seq1_arg)
  seq2 <- liftIO (newIORef seq2_arg)
  hcond <- do
    arg0 <- liftIO (readIORef seq1)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- liftIO (readIORef seq2)
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- liftIO (readIORef seq1)
          liftIO (car arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef seq1)
            liftIO (cdr arg0)
          arg1 <- liftIO (readIORef seq2)
          liftIO (concatLists arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

alistKeys :: Maybe Box -> IO (Maybe Box)
alistKeys alist_arg = evalContT $ callCC $ \qreturn -> do
  alist <- liftIO (newIORef alist_arg)
  hcond <- do
    arg0 <- liftIO (readIORef alist)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- pure Nothing
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef alist)
            liftIO (car arg0)
          liftIO (car arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef alist)
            liftIO (cdr arg0)
          liftIO (alistKeys arg0)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

display :: Maybe Box -> IO (())
display l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  hcond <- do
    arg0 <- liftIO (readIORef l)
    liftIO (isEmpty arg0)
  if hcond
    then do
      _ <- do
        arg0 <- pure "nil "
        liftIO (printf arg0)
      qreturn ()
      pure ()
    else do
      hcond <- do
        arg0 <- liftIO (readIORef l)
        liftIO (isList arg0)
      if hcond
        then do
          _ <- do
            arg0 <- pure "["
            liftIO (printf arg0)
          _ <- do
            arg0 <- liftIO (readIORef l)
            arg1 <- pure 0
            arg2 <- pure True
            liftIO (displayList arg0 arg1 arg2)
          _ <- do
            arg0 <- pure "]"
            liftIO (printf arg0)
          pure ()
        else do
          _ <- do
            arg0 <- liftIO (readIORef l)
            arg1 <- pure 0
            arg2 <- pure True
            liftIO (displayList arg0 arg1 arg2)
          pure ()
      pure ()
  pure ()

displayList :: Maybe Box -> Int -> Bool -> IO (())
displayList l_arg indent_arg first_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  indent <- liftIO (newIORef indent_arg)
  first <- liftIO (newIORef first_arg)
  qinit <- pure Nothing
  val <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef l)
    liftIO (isEmpty arg0)
  if hcond
    then do
      qreturn ()
      pure ()
    else do
      hcond <- do
        arg0 <- liftIO (readIORef l)
        liftIO (isList arg0)
      if hcond
        then do
          hcond <- do
            arg0 <- liftIO (readIORef l)
            liftIO (isEmpty arg0)
          if hcond
            then do
              qreturn ()
              pure ()
            else do
              hcond <- liftIO (readIORef first)
              if hcond
                then do
                  pure ()
                else do
                  _ <- do
                    arg0 <- pure " "
                    liftIO (printf arg0)
                  pure ()
              qset <- do
                arg0 <- liftIO (readIORef l)
                liftIO (car arg0)
              liftIO (writeIORef val qset)
              hcond <- do
                arg0 <- liftIO (readIORef val)
                liftIO (isList arg0)
              if hcond
                then do
                  _ <- do
                    arg0 <- liftIO (readIORef indent)
                    liftIO (newLine arg0)
                  _ <- do
                    arg0 <- pure "%s"
                    arg1 <- liftIO openBrace
                    liftIO (printf arg0 arg1)
                  _ <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef l)
                      liftIO (car arg0)
                    arg1 <- do
                      arg0 <- liftIO (readIORef indent)
                      liftIO (add1 arg0)
                    arg2 <- pure True
                    liftIO (displayList arg0 arg1 arg2)
                  _ <- do
                    arg0 <- pure "%s"
                    arg1 <- liftIO closeBrace
                    liftIO (printf arg0 arg1)
                  _ <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef l)
                      liftIO (cdr arg0)
                    arg1 <- liftIO (readIORef indent)
                    arg2 <- pure False
                    liftIO (displayList arg0 arg1 arg2)
                  pure ()
                else do
                  hcond <- do
                    arg0 <- pure "string"
                    arg1 <- do
                      hobj <- liftIO (readIORef val)
                      liftIO (readIORef (getField @"qf_typ" (expect hobj)))
                    liftIO (equalString arg0 arg1)
                  if hcond
                    then do
                      _ <- do
                        arg0 <- pure "\"%s\""
                        arg1 <- do
                          arg0 <- liftIO (readIORef val)
                          liftIO (unBoxString arg0)
                        liftIO (printf arg0 arg1)
                      pure ()
                    else do
                      _ <- do
                        arg0 <- pure "%s"
                        arg1 <- do
                          arg0 <- liftIO (readIORef val)
                          liftIO (stringify arg0)
                        liftIO (printf arg0 arg1)
                      pure ()
                  _ <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef l)
                      liftIO (cdr arg0)
                    arg1 <- liftIO (readIORef indent)
                    arg2 <- pure False
                    liftIO (displayList arg0 arg1 arg2)
                  pure ()
              pure ()
          pure ()
        else do
          hcond <- do
            arg0 <- pure "string"
            arg1 <- do
              hobj <- liftIO (readIORef l)
              liftIO (readIORef (getField @"qf_typ" (expect hobj)))
            liftIO (equalString arg0 arg1)
          if hcond
            then do
              _ <- do
                arg0 <- pure "\"%s\""
                arg1 <- do
                  arg0 <- liftIO (readIORef l)
                  liftIO (unBoxString arg0)
                liftIO (printf arg0 arg1)
              pure ()
            else do
              _ <- do
                arg0 <- pure "%s"
                arg1 <- do
                  arg0 <- liftIO (readIORef l)
                  liftIO (stringify arg0)
                liftIO (printf arg0 arg1)
              pure ()
          pure ()
      pure ()
  pure ()

stringListJoinRec :: Maybe Box -> String -> IO (String)
stringListJoinRec l_arg sep_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  sep <- liftIO (newIORef sep_arg)
  qinit <- pure Nothing
  val <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef l)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- pure ""
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- liftIO (readIORef l)
        liftIO (isList arg0)
      if hcond
        then do
          hcond <- do
            arg0 <- liftIO (readIORef l)
            liftIO (isEmpty arg0)
          if hcond
            then do
              hret <- pure ""
              qreturn hret
              pure ()
            else do
              hcond <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef l)
                  liftIO (listLength arg0)
                arg1 <- pure 1
                liftIO (equal arg0 arg1)
              if hcond
                then do
                  hret <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef l)
                      liftIO (car arg0)
                    liftIO (stringify arg0)
                  qreturn hret
                  pure ()
                else do
                  hret <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef l)
                        liftIO (car arg0)
                      liftIO (stringify arg0)
                    arg1 <- do
                      arg0 <- liftIO (readIORef sep)
                      arg1 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef l)
                          liftIO (cdr arg0)
                        arg1 <- liftIO (readIORef sep)
                        liftIO (stringListJoinRec arg0 arg1)
                      liftIO (stringConcatenate arg0 arg1)
                    liftIO (stringConcatenate arg0 arg1)
                  qreturn hret
                  pure ()
              pure ()
          pure ()
        else do
          hret <- pure ""
          qreturn hret
          pure ()
      pure ()
  pure ""

stringListJoin :: Maybe Box -> String -> IO (String)
stringListJoin l_arg sep_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  sep <- liftIO (newIORef sep_arg)
  qinit <- pure Nothing
  val <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef l)
      liftIO (listLength arg0)
    arg1 <- pure 1
    liftIO (greaterthan arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef l)
            liftIO (car arg0)
          liftIO (stringify arg0)
        arg1 <- do
          arg0 <- liftIO (readIORef sep)
          arg1 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef l)
              liftIO (cdr arg0)
            arg1 <- liftIO (readIORef sep)
            liftIO (stringListJoinRec arg0 arg1)
          liftIO (stringConcatenate arg0 arg1)
        liftIO (stringConcatenate arg0 arg1)
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- liftIO (readIORef l)
          liftIO (car arg0)
        liftIO (stringify arg0)
      qreturn hret
      pure ()
  pure ""

listToBoxString :: Maybe Box -> Int -> IO (Maybe Box)
listToBoxString l_arg indent_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  indent <- liftIO (newIORef indent_arg)
  hret <- do
    arg0 <- do
      arg0 <- liftIO (readIORef l)
      arg1 <- liftIO (readIORef indent)
      arg2 <- pure True
      arg3 <- pure False
      liftIO (listToString arg0 arg1 arg2 arg3)
    liftIO (boxString arg0)
  qreturn hret
  pure Nothing

listToString :: Maybe Box -> Int -> Bool -> Bool -> IO (String)
listToString l_arg indent_arg first_arg withNewLines_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  indent <- liftIO (newIORef indent_arg)
  first <- liftIO (newIORef first_arg)
  withNewLines <- liftIO (newIORef withNewLines_arg)
  qinit <- pure Nothing
  val <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef l)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- pure ""
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- liftIO (readIORef l)
        liftIO (isList arg0)
      if hcond
        then do
          hcond <- do
            arg0 <- liftIO (readIORef l)
            liftIO (isEmpty arg0)
          if hcond
            then do
              hret <- pure ""
              qreturn hret
              pure ()
            else do
              qset <- do
                arg0 <- liftIO (readIORef l)
                liftIO (car arg0)
              liftIO (writeIORef val qset)
              hcond <- do
                arg0 <- liftIO (readIORef val)
                liftIO (isList arg0)
              if hcond
                then do
                  hret <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- do
                            arg0 <- liftIO (readIORef withNewLines)
                            arg1 <- do
                              arg0 <- pure "\n"
                              liftIO (boxString arg0)
                            arg2 <- do
                              arg0 <- do
                                arg0 <- liftIO (readIORef indent)
                                liftIO (stringIndent arg0)
                              liftIO (boxString arg0)
                            liftIO (tern arg0 arg1 arg2)
                          liftIO (stringify arg0)
                        liftIO (boxString arg0)
                      arg1 <- do
                        arg0 <- do
                          arg0 <- liftIO openBrace
                          liftIO (boxString arg0)
                        arg1 <- do
                          arg0 <- do
                            arg0 <- pure " "
                            liftIO (boxString arg0)
                          arg1 <- do
                            arg0 <- do
                              arg0 <- do
                                arg0 <- do
                                  arg0 <- liftIO (readIORef l)
                                  liftIO (car arg0)
                                arg1 <- do
                                  arg0 <- liftIO (readIORef indent)
                                  liftIO (add1 arg0)
                                arg2 <- pure True
                                arg3 <- liftIO (readIORef withNewLines)
                                liftIO (listToString arg0 arg1 arg2 arg3)
                              liftIO (boxString arg0)
                            arg1 <- do
                              arg0 <- do
                                arg0 <- liftIO closeBrace
                                liftIO (boxString arg0)
                              arg1 <- do
                                arg0 <- do
                                  arg0 <- pure " "
                                  liftIO (boxString arg0)
                                arg1 <- do
                                  arg0 <- do
                                    arg0 <- do
                                      arg0 <- do
                                        arg0 <- liftIO (readIORef l)
                                        liftIO (cdr arg0)
                                      arg1 <- liftIO (readIORef indent)
                                      arg2 <- pure False
                                      arg3 <- liftIO (readIORef withNewLines)
                                      liftIO (listToString arg0 arg1 arg2 arg3)
                                    liftIO (boxString arg0)
                                  arg1 <- pure Nothing
                                  liftIO (cons arg0 arg1)
                                liftIO (cons arg0 arg1)
                              liftIO (cons arg0 arg1)
                            liftIO (cons arg0 arg1)
                          liftIO (cons arg0 arg1)
                        liftIO (cons arg0 arg1)
                      liftIO (cons arg0 arg1)
                    arg1 <- pure ""
                    liftIO (stringListJoin arg0 arg1)
                  qreturn hret
                  pure ()
                else do
                  hret <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef val)
                      liftIO (stringify arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef l)
                        liftIO (cdr arg0)
                      arg1 <- liftIO (readIORef indent)
                      arg2 <- pure False
                      arg3 <- liftIO (readIORef withNewLines)
                      liftIO (listToString arg0 arg1 arg2 arg3)
                    liftIO (stringConcatenate arg0 arg1)
                  qreturn hret
                  pure ()
              pure ()
          pure ()
        else do
          hret <- do
            arg0 <- liftIO (readIORef l)
            liftIO (stringify arg0)
          qreturn hret
          pure ()
      pure ()
  pure ""

listReverse :: Maybe Box -> IO (Maybe Box)
listReverse l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  hcond <- do
    arg0 <- liftIO (readIORef l)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- pure Nothing
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- liftIO (readIORef l)
          liftIO (car arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef l)
            liftIO (cdr arg0)
          liftIO (listReverse arg0)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

inList :: Maybe Box -> Maybe Box -> IO (Bool)
inList item_arg l_arg = evalContT $ callCC $ \qreturn -> do
  item <- liftIO (newIORef item_arg)
  l <- liftIO (newIORef l_arg)
  hcond <- do
    arg0 <- liftIO (readIORef l)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- pure False
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- do
          arg0 <- liftIO (readIORef l)
          liftIO (car arg0)
        arg1 <- liftIO (readIORef item)
        liftIO (equalBox arg0 arg1)
      if hcond
        then do
          hret <- pure True
          qreturn hret
          pure ()
        else do
          hret <- do
            arg0 <- liftIO (readIORef item)
            arg1 <- do
              arg0 <- liftIO (readIORef l)
              liftIO (cdr arg0)
            liftIO (inList arg0 arg1)
          qreturn hret
          pure ()
      pure ()
  pure False

equalList :: Maybe Box -> Maybe Box -> IO (Bool)
equalList a_arg b_arg = evalContT $ callCC $ \qreturn -> do
  a <- liftIO (newIORef a_arg)
  b <- liftIO (newIORef b_arg)
  hcond <- do
    arg0 <- liftIO (readIORef a)
    liftIO (isNil arg0)
  if hcond
    then do
      hcond <- do
        arg0 <- liftIO (readIORef b)
        liftIO (isNil arg0)
      if hcond
        then do
          hret <- pure True
          qreturn hret
          pure ()
        else do
          hret <- pure False
          qreturn hret
          pure ()
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- liftIO (readIORef b)
    liftIO (isNil arg0)
  if hcond
    then do
      hcond <- do
        arg0 <- liftIO (readIORef a)
        liftIO (isNil arg0)
      if hcond
        then do
          hret <- pure True
          qreturn hret
          pure ()
        else do
          hret <- pure False
          qreturn hret
          pure ()
      pure ()
    else do
      pure ()
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef a)
      liftIO (car arg0)
    arg1 <- do
      arg0 <- liftIO (readIORef b)
      liftIO (car arg0)
    liftIO (equalBox arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- liftIO (readIORef a)
          liftIO (cdr arg0)
        arg1 <- do
          arg0 <- liftIO (readIORef b)
          liftIO (cdr arg0)
        liftIO (equalList arg0 arg1)
      qreturn hret
      pure ()
    else do
      hret <- pure False
      qreturn hret
      pure ()
  pure False

reverseRec :: Maybe Box -> Maybe Box -> IO (Maybe Box)
reverseRec oldL_arg newL_arg = evalContT $ callCC $ \qreturn -> do
  oldL <- liftIO (newIORef oldL_arg)
  newL <- liftIO (newIORef newL_arg)
  hcond <- do
    arg0 <- liftIO (readIORef oldL)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO (readIORef newL)
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- liftIO (readIORef oldL)
          liftIO (cdr arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef oldL)
            liftIO (first arg0)
          arg1 <- liftIO (readIORef newL)
          liftIO (cons arg0 arg1)
        liftIO (reverseRec arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

reverseList :: Maybe Box -> IO (Maybe Box)
reverseList l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  hret <- do
    arg0 <- liftIO (readIORef l)
    arg1 <- pure Nothing
    liftIO (reverseRec arg0 arg1)
  qreturn hret
  pure Nothing

flatten :: Maybe Box -> IO (Maybe Box)
flatten tree_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  hcond <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- do
          arg0 <- liftIO (readIORef tree)
          liftIO (car arg0)
        liftIO (isList arg0)
      if hcond
        then do
          hret <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (car arg0)
              liftIO (flatten arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (cdr arg0)
              liftIO (flatten arg0)
            liftIO (concatLists arg0 arg1)
          qreturn hret
          pure ()
        else do
          hret <- do
            arg0 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (car arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (cdr arg0)
              liftIO (flatten arg0)
            liftIO (cons arg0 arg1)
          qreturn hret
          pure ()
      pure ()
  pure Nothing

printStringTree :: Maybe Box -> IO (())
printStringTree tree_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  qinit <- pure Nothing
  val <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (isEmpty arg0)
  if hcond
    then do
      qreturn ()
      pure ()
    else do
      pure ()
  qset <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (car arg0)
  liftIO (writeIORef val qset)
  hcond <- do
    arg0 <- liftIO (readIORef val)
    liftIO (isList arg0)
  if hcond
    then do
      _ <- do
        arg0 <- do
          arg0 <- liftIO (readIORef tree)
          liftIO (car arg0)
        liftIO (printStringTree arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure "%s"
        arg1 <- do
          arg0 <- liftIO (readIORef val)
          liftIO (stringify arg0)
        liftIO (printf arg0 arg1)
      pure ()
  _ <- do
    arg0 <- do
      arg0 <- liftIO (readIORef tree)
      liftIO (cdr arg0)
    liftIO (printStringTree arg0)
  pure ()

macrowalk :: Maybe Box -> IO (Maybe Box)
macrowalk l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  hcond <- do
    arg0 <- liftIO (readIORef l)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- pure Nothing
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- liftIO (readIORef l)
        liftIO (isList arg0)
      if hcond
        then do
          hcond <- do
            arg0 <- do
              arg0 <- pure "box"
              arg1 <- pure "List"
              liftIO (stringConcatenate arg0 arg1)
            arg1 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef l)
                liftIO (car arg0)
              liftIO (stringify arg0)
            liftIO (equalString arg0 arg1)
          if hcond
            then do
              hret <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef l)
                    liftIO (cdr arg0)
                  liftIO (doBoxList arg0)
                liftIO (car arg0)
              qreturn hret
              pure ()
            else do
              pure ()
          hcond <- do
            arg0 <- do
              arg0 <- pure "string"
              arg1 <- pure "List"
              liftIO (stringConcatenate arg0 arg1)
            arg1 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef l)
                liftIO (car arg0)
              liftIO (stringify arg0)
            liftIO (equalString arg0 arg1)
          if hcond
            then do
              hret <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef l)
                    liftIO (cdr arg0)
                  liftIO (doStringList arg0)
                liftIO (car arg0)
              qreturn hret
              pure ()
            else do
              pure ()
          hcond <- do
            arg0 <- do
              arg0 <- pure "symbol"
              arg1 <- pure "List"
              liftIO (stringConcatenate arg0 arg1)
            arg1 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef l)
                liftIO (car arg0)
              liftIO (stringify arg0)
            liftIO (equalString arg0 arg1)
          if hcond
            then do
              hret <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef l)
                    liftIO (cdr arg0)
                  liftIO (doSymbolList arg0)
                liftIO (car arg0)
              qreturn hret
              pure ()
            else do
              pure ()
          hcond <- do
            arg0 <- do
              arg0 <- pure "multi"
              arg1 <- pure "List"
              liftIO (stringConcatenate arg0 arg1)
            arg1 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef l)
                liftIO (car arg0)
              liftIO (stringify arg0)
            liftIO (equalString arg0 arg1)
          if hcond
            then do
              hret <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef l)
                    liftIO (cdr arg0)
                  liftIO (doMultiList arg0)
                liftIO (car arg0)
              qreturn hret
              pure ()
            else do
              pure ()
          hcond <- do
            arg0 <- do
              arg0 <- pure "makeL"
              arg1 <- pure "ist"
              liftIO (stringConcatenate arg0 arg1)
            arg1 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef l)
                liftIO (car arg0)
              liftIO (stringify arg0)
            liftIO (equalString arg0 arg1)
          if hcond
            then do
              hret <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef l)
                    liftIO (cdr arg0)
                  liftIO (doInterpolatedList arg0)
                liftIO (car arg0)
              qreturn hret
              pure ()
            else do
              pure ()
          hret <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef l)
                liftIO (car arg0)
              liftIO (macrowalk arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef l)
                liftIO (cdr arg0)
              liftIO (macrowalk arg0)
            liftIO (cons arg0 arg1)
          qreturn hret
          pure ()
        else do
          hret <- liftIO (readIORef l)
          qreturn hret
          pure ()
      pure ()
  pure Nothing

macrosingle :: Maybe Box -> String -> String -> IO (Maybe Box)
macrosingle tree_arg search_arg replace_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  search <- liftIO (newIORef search_arg)
  replace <- liftIO (newIORef replace_arg)
  qinit <- pure Nothing
  val <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- pure Nothing
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- liftIO (readIORef tree)
        liftIO (isList arg0)
      if hcond
        then do
          hret <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (car arg0)
              arg1 <- liftIO (readIORef search)
              arg2 <- liftIO (readIORef replace)
              liftIO (macrosingle arg0 arg1 arg2)
            arg1 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (cdr arg0)
              arg1 <- liftIO (readIORef search)
              arg2 <- liftIO (readIORef replace)
              liftIO (macrosingle arg0 arg1 arg2)
            liftIO (cons arg0 arg1)
          qreturn hret
          pure ()
        else do
          hcond <- do
            arg0 <- liftIO (readIORef search)
            arg1 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (stringify arg0)
            liftIO (equalString arg0 arg1)
          if hcond
            then do
              qset <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (clone arg0)
              liftIO (writeIORef val qset)
              hobj <- liftIO (readIORef val)
              qset <- liftIO (readIORef replace)
              liftIO (writeIORef (getField @"qf_str" (expect hobj)) qset)
              hret <- liftIO (readIORef val)
              qreturn hret
              pure ()
            else do
              pure ()
          hret <- liftIO (readIORef tree)
          qreturn hret
          pure ()
      pure ()
  pure Nothing

macroSymbolSingle :: Maybe Box -> String -> String -> IO (Maybe Box)
macroSymbolSingle tree_arg search_arg replace_arg = evalContT $ callCC $ \qreturn -> do
  tree <- liftIO (newIORef tree_arg)
  search <- liftIO (newIORef search_arg)
  replace <- liftIO (newIORef replace_arg)
  qinit <- pure Nothing
  val <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef tree)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- pure Nothing
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- liftIO (readIORef tree)
        liftIO (isList arg0)
      if hcond
        then do
          hret <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (car arg0)
              arg1 <- liftIO (readIORef search)
              arg2 <- liftIO (readIORef replace)
              liftIO (macroSymbolSingle arg0 arg1 arg2)
            arg1 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef tree)
                liftIO (cdr arg0)
              arg1 <- liftIO (readIORef search)
              arg2 <- liftIO (readIORef replace)
              liftIO (macroSymbolSingle arg0 arg1 arg2)
            liftIO (cons arg0 arg1)
          qreturn hret
          pure ()
        else do
          hcond <- do
            arg0 <- pure "symbol"
            arg1 <- do
              arg0 <- liftIO (readIORef tree)
              liftIO (boxType arg0)
            liftIO (equalString arg0 arg1)
          if hcond
            then do
              hcond <- do
                arg0 <- liftIO (readIORef search)
                arg1 <- do
                  arg0 <- liftIO (readIORef tree)
                  liftIO (stringify arg0)
                liftIO (equalString arg0 arg1)
              if hcond
                then do
                  qset <- do
                    arg0 <- liftIO (readIORef tree)
                    liftIO (clone arg0)
                  liftIO (writeIORef val qset)
                  hobj <- liftIO (readIORef val)
                  qset <- liftIO (readIORef replace)
                  liftIO (writeIORef (getField @"qf_str" (expect hobj)) qset)
                  hret <- liftIO (readIORef val)
                  qreturn hret
                  pure ()
                else do
                  pure ()
              pure ()
            else do
              pure ()
          hret <- liftIO (readIORef tree)
          qreturn hret
          pure ()
      pure ()
  pure Nothing

macrolist :: Maybe Box -> String -> Maybe Box -> IO (Maybe Box)
macrolist l_arg search_arg replace_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  search <- liftIO (newIORef search_arg)
  replace <- liftIO (newIORef replace_arg)
  qinit <- pure Nothing
  val <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef l)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- pure Nothing
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- liftIO (readIORef l)
        liftIO (isList arg0)
      if hcond
        then do
          hcond <- do
            arg0 <- liftIO (readIORef search)
            arg1 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef l)
                liftIO (car arg0)
              liftIO (stringify arg0)
            liftIO (equalString arg0 arg1)
          if hcond
            then do
              hret <- do
                arg0 <- liftIO (readIORef replace)
                arg1 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef l)
                    liftIO (cdr arg0)
                  arg1 <- liftIO (readIORef search)
                  arg2 <- liftIO (readIORef replace)
                  liftIO (macrolist arg0 arg1 arg2)
                liftIO (concatLists arg0 arg1)
              qreturn hret
              pure ()
            else do
              hret <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef l)
                    liftIO (car arg0)
                  arg1 <- liftIO (readIORef search)
                  arg2 <- liftIO (readIORef replace)
                  liftIO (macrolist arg0 arg1 arg2)
                arg1 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef l)
                    liftIO (cdr arg0)
                  arg1 <- liftIO (readIORef search)
                  arg2 <- liftIO (readIORef replace)
                  liftIO (macrolist arg0 arg1 arg2)
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
          pure ()
        else do
          hret <- liftIO (readIORef l)
          qreturn hret
          pure ()
      pure ()
  pure Nothing

filterVoid :: Maybe Box -> IO (Maybe Box)
filterVoid l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  qinit <- pure Nothing
  token <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef l)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      qset <- do
        arg0 <- liftIO (readIORef l)
        liftIO (car arg0)
      liftIO (writeIORef token qset)
      hcond <- do
        arg0 <- pure "void"
        arg1 <- do
          hobj <- liftIO (readIORef token)
          liftIO (readIORef (getField @"qf_typ" (expect hobj)))
        liftIO (equalString arg0 arg1)
      if hcond
        then do
          hret <- do
            arg0 <- do
              arg0 <- liftIO (readIORef l)
              liftIO (cdr arg0)
            liftIO (filterVoid arg0)
          qreturn hret
          pure ()
        else do
          hret <- do
            arg0 <- liftIO (readIORef token)
            arg1 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef l)
                liftIO (cdr arg0)
              liftIO (filterVoid arg0)
            liftIO (cons arg0 arg1)
          qreturn hret
          pure ()
      pure ()
  pure Nothing

filterTokens :: Maybe Box -> IO (Maybe Box)
filterTokens l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  qinit <- pure Nothing
  token <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef l)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      qset <- do
        arg0 <- liftIO (readIORef l)
        liftIO (car arg0)
      liftIO (writeIORef token qset)
      hcond <- do
        arg0 <- do
          arg0 <- liftIO (readIORef token)
          liftIO (boxType arg0)
        arg1 <- pure "symbol"
        liftIO (equalString arg0 arg1)
      if hcond
        then do
          hcond <- do
            arg0 <- pure "__LINE__"
            arg1 <- do
              arg0 <- liftIO (readIORef token)
              liftIO (stringify arg0)
            liftIO (equalString arg0 arg1)
          if hcond
            then do
              hret <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef token)
                  arg1 <- do
                    arg0 <- pure "line"
                    liftIO (boxString arg0)
                  arg2 <- do
                    arg0 <- pure (-1)
                    liftIO (boxInt arg0)
                  liftIO (getTagFail arg0 arg1 arg2)
                arg1 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef l)
                    liftIO (cdr arg0)
                  liftIO (filterTokens arg0)
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
            else do
              hcond <- do
                arg0 <- pure "__COLUMN__"
                arg1 <- do
                  arg0 <- liftIO (readIORef token)
                  liftIO (stringify arg0)
                liftIO (equalString arg0 arg1)
              if hcond
                then do
                  hret <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef token)
                      arg1 <- do
                        arg0 <- pure "column"
                        liftIO (boxString arg0)
                      arg2 <- do
                        arg0 <- pure (-1)
                        liftIO (boxInt arg0)
                      liftIO (getTagFail arg0 arg1 arg2)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- liftIO (readIORef l)
                        liftIO (cdr arg0)
                      liftIO (filterTokens arg0)
                    liftIO (cons arg0 arg1)
                  qreturn hret
                  pure ()
                else do
                  hcond <- do
                    arg0 <- pure "__FILE__"
                    arg1 <- do
                      arg0 <- liftIO (readIORef token)
                      liftIO (stringify arg0)
                    liftIO (equalString arg0 arg1)
                  if hcond
                    then do
                      hret <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef token)
                          arg1 <- do
                            arg0 <- pure "filename"
                            liftIO (boxString arg0)
                          arg2 <- do
                            arg0 <- pure "Unknown file"
                            liftIO (boxString arg0)
                          liftIO (getTagFail arg0 arg1 arg2)
                        arg1 <- do
                          arg0 <- do
                            arg0 <- liftIO (readIORef l)
                            liftIO (cdr arg0)
                          liftIO (filterTokens arg0)
                        liftIO (cons arg0 arg1)
                      qreturn hret
                      pure ()
                    else do
                      hret <- do
                        arg0 <- liftIO (readIORef token)
                        arg1 <- do
                          arg0 <- do
                            arg0 <- liftIO (readIORef l)
                            liftIO (cdr arg0)
                          liftIO (filterTokens arg0)
                        liftIO (cons arg0 arg1)
                      qreturn hret
                      pure ()
                  pure ()
              pure ()
          pure ()
        else do
          hret <- do
            arg0 <- liftIO (readIORef token)
            arg1 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef l)
                liftIO (cdr arg0)
              liftIO (filterTokens arg0)
            liftIO (cons arg0 arg1)
          qreturn hret
          pure ()
      pure ()
  pure Nothing

finish_token :: String -> Int -> Int -> Int -> Int -> String -> IO (Maybe Box)
finish_token prog_arg start_arg len_arg line_arg column_arg filename_arg = evalContT $ callCC $ \qreturn -> do
  prog <- liftIO (newIORef prog_arg)
  start <- liftIO (newIORef start_arg)
  len <- liftIO (newIORef len_arg)
  line <- liftIO (newIORef line_arg)
  column <- liftIO (newIORef column_arg)
  filename <- liftIO (newIORef filename_arg)
  qinit <- pure Nothing
  token <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef len)
    arg1 <- pure 0
    liftIO (greaterthan arg0 arg1)
  if hcond
    then do
      qset <- do
        arg0 <- do
          arg0 <- liftIO (readIORef prog)
          arg1 <- liftIO (readIORef start)
          arg2 <- liftIO (readIORef len)
          liftIO (sub_string arg0 arg1 arg2)
        liftIO (boxSymbol arg0)
      liftIO (writeIORef token qset)
      hobj <- liftIO (readIORef token)
      qset <- do
        arg0 <- do
          arg0 <- pure "filename"
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- liftIO (readIORef filename)
          liftIO (boxString arg0)
        arg2 <- do
          arg0 <- do
            arg0 <- pure "column"
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- liftIO (readIORef column)
            liftIO (boxInt arg0)
          arg2 <- do
            arg0 <- do
              arg0 <- pure "line"
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- liftIO (readIORef line)
              liftIO (boxInt arg0)
            arg2 <- do
              arg0 <- do
                arg0 <- pure "totalCharPos"
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- liftIO (readIORef start)
                liftIO (boxInt arg0)
              arg2 <- pure Nothing
              liftIO (alistCons arg0 arg1 arg2)
            liftIO (alistCons arg0 arg1 arg2)
          liftIO (alistCons arg0 arg1 arg2)
        liftIO (alistCons arg0 arg1 arg2)
      liftIO (writeIORef (getField @"qf_tag" (expect hobj)) qset)
      hret <- liftIO (readIORef token)
      qreturn hret
      pure ()
    else do
      hret <- liftIO newVoid
      qreturn hret
      pure ()
  pure Nothing

readString :: String -> Int -> Int -> IO (String)
readString prog_arg start_arg len_arg = evalContT $ callCC $ \qreturn -> do
  prog <- liftIO (newIORef prog_arg)
  start <- liftIO (newIORef start_arg)
  len <- liftIO (newIORef len_arg)
  qinit <- pure ""
  token <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef prog)
    arg1 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef start)
        arg1 <- liftIO (readIORef len)
        liftIO (add arg0 arg1)
      liftIO (sub1 arg0)
    arg2 <- pure 1
    liftIO (sub_string arg0 arg1 arg2)
  liftIO (writeIORef token qset)
  hcond <- do
    arg0 <- pure "\""
    arg1 <- liftIO (readIORef token)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- liftIO (readIORef prog)
        arg1 <- liftIO (readIORef start)
        arg2 <- do
          arg0 <- liftIO (readIORef len)
          liftIO (sub1 arg0)
        liftIO (sub_string arg0 arg1 arg2)
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- pure "\\"
        arg1 <- liftIO (readIORef token)
        liftIO (equalString arg0 arg1)
      if hcond
        then do
          hret <- do
            arg0 <- liftIO (readIORef prog)
            arg1 <- liftIO (readIORef start)
            arg2 <- do
              arg0 <- pure 2
              arg1 <- liftIO (readIORef len)
              liftIO (add arg0 arg1)
            liftIO (readString arg0 arg1 arg2)
          qreturn hret
          pure ()
        else do
          hret <- do
            arg0 <- liftIO (readIORef prog)
            arg1 <- liftIO (readIORef start)
            arg2 <- do
              arg0 <- liftIO (readIORef len)
              liftIO (add1 arg0)
            liftIO (readString arg0 arg1 arg2)
          qreturn hret
          pure ()
      pure ()
  pure ""

readComment :: String -> Int -> Int -> IO (String)
readComment prog_arg start_arg len_arg = evalContT $ callCC $ \qreturn -> do
  prog <- liftIO (newIORef prog_arg)
  start <- liftIO (newIORef start_arg)
  len <- liftIO (newIORef len_arg)
  qinit <- pure ""
  token <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef start)
      arg1 <- liftIO (readIORef len)
      liftIO (add arg0 arg1)
    arg1 <- do
      arg0 <- liftIO (readIORef prog)
      liftIO (string_length arg0)
    liftIO (greaterthan arg0 arg1)
  if hcond
    then do
      hret <- pure ""
      qreturn hret
      pure ()
    else do
      qset <- do
        arg0 <- liftIO (readIORef prog)
        arg1 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef start)
            arg1 <- liftIO (readIORef len)
            liftIO (add arg0 arg1)
          liftIO (sub1 arg0)
        arg2 <- pure 1
        liftIO (sub_string arg0 arg1 arg2)
      liftIO (writeIORef token qset)
      hcond <- do
        arg0 <- liftIO (readIORef token)
        liftIO (isLineBreak arg0)
      if hcond
        then do
          hret <- do
            arg0 <- liftIO (readIORef prog)
            arg1 <- liftIO (readIORef start)
            arg2 <- do
              arg0 <- liftIO (readIORef len)
              liftIO (sub1 arg0)
            liftIO (sub_string arg0 arg1 arg2)
          qreturn hret
          pure ()
        else do
          hret <- do
            arg0 <- liftIO (readIORef prog)
            arg1 <- liftIO (readIORef start)
            arg2 <- do
              arg0 <- liftIO (readIORef len)
              liftIO (add1 arg0)
            liftIO (readComment arg0 arg1 arg2)
          qreturn hret
          pure ()
      pure ()
  pure ""

isLineBreak :: String -> IO (Bool)
isLineBreak s_arg = evalContT $ callCC $ \qreturn -> do
  s <- liftIO (newIORef s_arg)
  hcond <- do
    arg0 <- pure "\n"
    arg1 <- liftIO (readIORef s)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure True
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- pure "\r"
        arg1 <- liftIO (readIORef s)
        liftIO (equalString arg0 arg1)
      if hcond
        then do
          hret <- pure True
          qreturn hret
          pure ()
        else do
          hret <- pure False
          qreturn hret
          pure ()
      pure ()
  pure False

incForNewLine :: Maybe Box -> Int -> IO (Int)
incForNewLine token_arg val_arg = evalContT $ callCC $ \qreturn -> do
  token <- liftIO (newIORef token_arg)
  val <- liftIO (newIORef val_arg)
  hcond <- do
    arg0 <- pure "\n"
    arg1 <- do
      arg0 <- liftIO (readIORef token)
      liftIO (stringify arg0)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- liftIO (readIORef val)
        liftIO (add1 arg0)
      qreturn hret
      pure ()
    else do
      hret <- liftIO (readIORef val)
      qreturn hret
      pure ()
  pure 0

annotateReadPosition :: String -> Int -> Int -> Int -> Maybe Box -> IO (Maybe Box)
annotateReadPosition filename_arg linecount_arg column_arg start_arg newBox_arg = evalContT $ callCC $ \qreturn -> do
  filename <- liftIO (newIORef filename_arg)
  linecount <- liftIO (newIORef linecount_arg)
  column <- liftIO (newIORef column_arg)
  start <- liftIO (newIORef start_arg)
  newBox <- liftIO (newIORef newBox_arg)
  hret <- do
    arg0 <- do
      arg0 <- pure "filename"
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- liftIO (readIORef filename)
      liftIO (boxString arg0)
    arg2 <- do
      arg0 <- do
        arg0 <- pure "column"
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- liftIO (readIORef column)
        liftIO (boxInt arg0)
      arg2 <- do
        arg0 <- do
          arg0 <- pure "line"
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- liftIO (readIORef linecount)
          liftIO (boxInt arg0)
        arg2 <- do
          arg0 <- do
            arg0 <- pure "totalCharPos"
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- liftIO (readIORef start)
            liftIO (boxInt arg0)
          arg2 <- liftIO (readIORef newBox)
          liftIO (setTag arg0 arg1 arg2)
        liftIO (setTag arg0 arg1 arg2)
      liftIO (setTag arg0 arg1 arg2)
    liftIO (setTag arg0 arg1 arg2)
  qreturn hret
  pure Nothing

scan :: String -> Int -> Int -> Int -> Int -> String -> IO (Maybe Box)
scan prog_arg start_arg len_arg linecount_arg column_arg filename_arg = evalContT $ callCC $ \qreturn -> do
  prog <- liftIO (newIORef prog_arg)
  start <- liftIO (newIORef start_arg)
  len <- liftIO (newIORef len_arg)
  linecount <- liftIO (newIORef linecount_arg)
  column <- liftIO (newIORef column_arg)
  filename <- liftIO (newIORef filename_arg)
  qinit <- pure Nothing
  token <- liftIO (newIORef qinit)
  qinit <- pure ""
  newString <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  newBox <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef prog)
      liftIO (string_length arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef start)
        arg1 <- liftIO (readIORef len)
        liftIO (add arg0 arg1)
      liftIO (sub1 arg0)
    liftIO (greaterthan arg0 arg1)
  if hcond
    then do
      qset <- do
        arg0 <- do
          arg0 <- liftIO (readIORef prog)
          arg1 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef start)
              arg1 <- liftIO (readIORef len)
              liftIO (add arg0 arg1)
            liftIO (sub1 arg0)
          arg2 <- pure 1
          liftIO (sub_string arg0 arg1 arg2)
        liftIO (boxSymbol arg0)
      liftIO (writeIORef token qset)
      hobj <- liftIO (readIORef token)
      qset <- do
        arg0 <- do
          arg0 <- pure "totalCharPos"
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- liftIO (readIORef start)
          liftIO (boxInt arg0)
        arg2 <- pure Nothing
        liftIO (alistCons arg0 arg1 arg2)
      liftIO (writeIORef (getField @"qf_tag" (expect hobj)) qset)
      hcond <- do
        arg0 <- liftIO (readIORef token)
        liftIO (isOpenBrace arg0)
      if hcond
        then do
          hret <- do
            arg0 <- do
              arg0 <- liftIO (readIORef prog)
              arg1 <- liftIO (readIORef start)
              arg2 <- do
                arg0 <- liftIO (readIORef len)
                liftIO (sub1 arg0)
              arg3 <- liftIO (readIORef linecount)
              arg4 <- liftIO (readIORef column)
              arg5 <- liftIO (readIORef filename)
              liftIO (finish_token arg0 arg1 arg2 arg3 arg4 arg5)
            arg1 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef filename)
                arg1 <- liftIO (readIORef linecount)
                arg2 <- liftIO (readIORef column)
                arg3 <- liftIO (readIORef start)
                arg4 <- do
                  arg0 <- liftIO openBrace
                  liftIO (boxSymbol arg0)
                liftIO (annotateReadPosition arg0 arg1 arg2 arg3 arg4)
              arg1 <- do
                arg0 <- liftIO (readIORef prog)
                arg1 <- do
                  arg0 <- liftIO (readIORef start)
                  liftIO (add1 arg0)
                arg2 <- pure 1
                arg3 <- liftIO (readIORef linecount)
                arg4 <- do
                  arg0 <- liftIO (readIORef column)
                  liftIO (add1 arg0)
                arg5 <- liftIO (readIORef filename)
                liftIO (scan arg0 arg1 arg2 arg3 arg4 arg5)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          qreturn hret
          pure ()
        else do
          hcond <- do
            arg0 <- liftIO (readIORef token)
            liftIO (isCloseBrace arg0)
          if hcond
            then do
              hret <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef prog)
                  arg1 <- liftIO (readIORef start)
                  arg2 <- do
                    arg0 <- liftIO (readIORef len)
                    liftIO (sub1 arg0)
                  arg3 <- liftIO (readIORef linecount)
                  arg4 <- liftIO (readIORef column)
                  arg5 <- liftIO (readIORef filename)
                  liftIO (finish_token arg0 arg1 arg2 arg3 arg4 arg5)
                arg1 <- do
                  arg0 <- do
                    arg0 <- liftIO (readIORef filename)
                    arg1 <- liftIO (readIORef linecount)
                    arg2 <- liftIO (readIORef column)
                    arg3 <- liftIO (readIORef start)
                    arg4 <- do
                      arg0 <- liftIO closeBrace
                      liftIO (boxSymbol arg0)
                    liftIO (annotateReadPosition arg0 arg1 arg2 arg3 arg4)
                  arg1 <- do
                    arg0 <- liftIO (readIORef prog)
                    arg1 <- do
                      arg0 <- liftIO (readIORef start)
                      arg1 <- liftIO (readIORef len)
                      liftIO (add arg0 arg1)
                    arg2 <- pure 1
                    arg3 <- liftIO (readIORef linecount)
                    arg4 <- do
                      arg0 <- liftIO (readIORef column)
                      liftIO (add1 arg0)
                    arg5 <- liftIO (readIORef filename)
                    liftIO (scan arg0 arg1 arg2 arg3 arg4 arg5)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              qreturn hret
              pure ()
            else do
              hcond <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef token)
                  liftIO (stringify arg0)
                liftIO (isWhiteSpace arg0)
              if hcond
                then do
                  hret <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef prog)
                      arg1 <- liftIO (readIORef start)
                      arg2 <- do
                        arg0 <- liftIO (readIORef len)
                        liftIO (sub1 arg0)
                      arg3 <- liftIO (readIORef linecount)
                      arg4 <- liftIO (readIORef column)
                      arg5 <- liftIO (readIORef filename)
                      liftIO (finish_token arg0 arg1 arg2 arg3 arg4 arg5)
                    arg1 <- do
                      arg0 <- liftIO (readIORef prog)
                      arg1 <- do
                        arg0 <- liftIO (readIORef start)
                        arg1 <- liftIO (readIORef len)
                        liftIO (add arg0 arg1)
                      arg2 <- pure 1
                      arg3 <- do
                        arg0 <- liftIO (readIORef token)
                        arg1 <- liftIO (readIORef linecount)
                        liftIO (incForNewLine arg0 arg1)
                      arg4 <- pure 0
                      arg5 <- liftIO (readIORef filename)
                      liftIO (scan arg0 arg1 arg2 arg3 arg4 arg5)
                    liftIO (cons arg0 arg1)
                  qreturn hret
                  pure ()
                else do
                  hcond <- do
                    arg0 <- do
                      arg0 <- pure ";"
                      liftIO (boxSymbol arg0)
                    arg1 <- liftIO (readIORef token)
                    liftIO (equalBox arg0 arg1)
                  if hcond
                    then do
                      hret <- do
                        arg0 <- liftIO (readIORef prog)
                        arg1 <- do
                          arg0 <- liftIO (readIORef start)
                          arg1 <- do
                            arg0 <- do
                              arg0 <- do
                                arg0 <- do
                                  arg0 <- liftIO (readIORef prog)
                                  arg1 <- do
                                    arg0 <- liftIO (readIORef start)
                                    liftIO (add1 arg0)
                                  arg2 <- liftIO (readIORef len)
                                  liftIO (readComment arg0 arg1 arg2)
                                liftIO (string_length arg0)
                              liftIO (add1 arg0)
                            liftIO (add1 arg0)
                          liftIO (add arg0 arg1)
                        arg2 <- pure 1
                        arg3 <- do
                          arg0 <- liftIO (readIORef linecount)
                          liftIO (add1 arg0)
                        arg4 <- pure 0
                        arg5 <- liftIO (readIORef filename)
                        liftIO (scan arg0 arg1 arg2 arg3 arg4 arg5)
                      qreturn hret
                      pure ()
                    else do
                      hcond <- do
                        arg0 <- do
                          arg0 <- pure "\""
                          liftIO (boxSymbol arg0)
                        arg1 <- liftIO (readIORef token)
                        liftIO (equalBox arg0 arg1)
                      if hcond
                        then do
                          qset <- do
                            arg0 <- liftIO (readIORef prog)
                            arg1 <- do
                              arg0 <- liftIO (readIORef start)
                              liftIO (add1 arg0)
                            arg2 <- liftIO (readIORef len)
                            liftIO (readString arg0 arg1 arg2)
                          liftIO (writeIORef newString qset)
                          qset <- do
                            arg0 <- liftIO (readIORef filename)
                            arg1 <- liftIO (readIORef linecount)
                            arg2 <- liftIO (readIORef column)
                            arg3 <- liftIO (readIORef start)
                            arg4 <- do
                              arg0 <- liftIO (readIORef newString)
                              liftIO (boxString arg0)
                            liftIO (annotateReadPosition arg0 arg1 arg2 arg3 arg4)
                          liftIO (writeIORef newBox qset)
                          hret <- do
                            arg0 <- liftIO (readIORef newBox)
                            arg1 <- do
                              arg0 <- liftIO (readIORef prog)
                              arg1 <- do
                                arg0 <- liftIO (readIORef start)
                                arg1 <- do
                                  arg0 <- do
                                    arg0 <- do
                                      arg0 <- liftIO (readIORef newString)
                                      liftIO (string_length arg0)
                                    liftIO (add1 arg0)
                                  liftIO (add1 arg0)
                                liftIO (add arg0 arg1)
                              arg2 <- pure 1
                              arg3 <- liftIO (readIORef linecount)
                              arg4 <- do
                                arg0 <- liftIO (readIORef column)
                                liftIO (add1 arg0)
                              arg5 <- liftIO (readIORef filename)
                              liftIO (scan arg0 arg1 arg2 arg3 arg4 arg5)
                            liftIO (cons arg0 arg1)
                          qreturn hret
                          pure ()
                        else do
                          hret <- do
                            arg0 <- liftIO (readIORef prog)
                            arg1 <- liftIO (readIORef start)
                            arg2 <- do
                              arg0 <- liftIO (readIORef len)
                              arg1 <- pure (-1)
                              liftIO (sub arg0 arg1)
                            arg3 <- liftIO (readIORef linecount)
                            arg4 <- do
                              arg0 <- liftIO (readIORef column)
                              liftIO (add1 arg0)
                            arg5 <- liftIO (readIORef filename)
                            liftIO (scan arg0 arg1 arg2 arg3 arg4 arg5)
                          qreturn hret
                          pure ()
                      pure ()
                  pure ()
              pure ()
          pure ()
      pure ()
    else do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
  pure Nothing

isOpenBrace :: Maybe Box -> IO (Bool)
isOpenBrace b_arg = evalContT $ callCC $ \qreturn -> do
  b <- liftIO (newIORef b_arg)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO openBrace
      liftIO (boxSymbol arg0)
    arg1 <- liftIO (readIORef b)
    liftIO (equalBox arg0 arg1)
  if hcond
    then do
      hret <- pure True
      qreturn hret
      pure ()
    else do
      hret <- pure False
      qreturn hret
      pure ()
  pure False

isCloseBrace :: Maybe Box -> IO (Bool)
isCloseBrace b_arg = evalContT $ callCC $ \qreturn -> do
  b <- liftIO (newIORef b_arg)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO closeBrace
      liftIO (boxSymbol arg0)
    arg1 <- liftIO (readIORef b)
    liftIO (equalBox arg0 arg1)
  if hcond
    then do
      hret <- pure True
      qreturn hret
      pure ()
    else do
      hret <- pure False
      qreturn hret
      pure ()
  pure False

skipList :: Maybe Box -> IO (Maybe Box)
skipList l_arg = evalContT $ callCC $ \qreturn -> do
  l <- liftIO (newIORef l_arg)
  qinit <- pure Nothing
  b <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef l)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- liftIO emptyList
      qreturn hret
      pure ()
    else do
      qset <- do
        arg0 <- liftIO (readIORef l)
        liftIO (car arg0)
      liftIO (writeIORef b qset)
      hcond <- do
        arg0 <- liftIO (readIORef b)
        liftIO (isOpenBrace arg0)
      if hcond
        then do
          hret <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef l)
                liftIO (cdr arg0)
              liftIO (skipList arg0)
            liftIO (skipList arg0)
          qreturn hret
          pure ()
        else do
          hcond <- do
            arg0 <- liftIO (readIORef b)
            liftIO (isCloseBrace arg0)
          if hcond
            then do
              hret <- do
                arg0 <- liftIO (readIORef l)
                liftIO (cdr arg0)
              qreturn hret
              pure ()
            else do
              hret <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef l)
                  liftIO (cdr arg0)
                liftIO (skipList arg0)
              qreturn hret
              pure ()
          pure ()
      pure ()
  pure Nothing

add :: Int -> Int -> IO (Int)
add a_arg b_arg = evalContT $ callCC $ \qreturn -> do
  a <- liftIO (newIORef a_arg)
  b <- liftIO (newIORef b_arg)
  hret <- do
    arg0 <- liftIO (readIORef a)
    arg1 <- do
      arg0 <- pure 0
      arg1 <- liftIO (readIORef b)
      liftIO (sub arg0 arg1)
    liftIO (sub arg0 arg1)
  qreturn hret
  pure 0

addf :: Double -> Double -> IO (Double)
addf a_arg b_arg = evalContT $ callCC $ \qreturn -> do
  a <- liftIO (newIORef a_arg)
  b <- liftIO (newIORef b_arg)
  hret <- do
    arg0 <- liftIO (readIORef a)
    arg1 <- do
      arg0 <- pure 0
      arg1 <- liftIO (readIORef b)
      liftIO (subf arg0 arg1)
    liftIO (subf arg0 arg1)
  qreturn hret
  pure 0.0

sub1 :: Int -> IO (Int)
sub1 a_arg = evalContT $ callCC $ \qreturn -> do
  a <- liftIO (newIORef a_arg)
  hret <- do
    arg0 <- liftIO (readIORef a)
    arg1 <- pure 1
    liftIO (sub arg0 arg1)
  qreturn hret
  pure 0

add1 :: Int -> IO (Int)
add1 a_arg = evalContT $ callCC $ \qreturn -> do
  a <- liftIO (newIORef a_arg)
  hret <- do
    arg0 <- liftIO (readIORef a)
    arg1 <- pure 1
    liftIO (add arg0 arg1)
  qreturn hret
  pure 0

clone :: Maybe Box -> IO (Maybe Box)
clone b_arg = evalContT $ callCC $ \qreturn -> do
  b <- liftIO (newIORef b_arg)
  qinit <- pure Nothing
  newb <- liftIO (newIORef qinit)
  qset <- liftIO makeBox
  liftIO (writeIORef newb qset)
  hcond <- do
    arg0 <- liftIO (readIORef newb)
    liftIO (isNil arg0)
  if hcond
    then do
      _ <- do
        arg0 <- pure "clone: newb is nil\n"
        liftIO (printf arg0)
      _ <- do
        arg0 <- pure "clone: newb is nil"
        liftIO (panic arg0)
      hret <- liftIO (readIORef newb)
      qreturn hret
      pure ()
    else do
      hobj <- liftIO (readIORef newb)
      qset <- do
        hobj <- liftIO (readIORef b)
        liftIO (readIORef (getField @"qf_typ" (expect hobj)))
      liftIO (writeIORef (getField @"qf_typ" (expect hobj)) qset)
      hobj <- liftIO (readIORef newb)
      qset <- do
        hobj <- liftIO (readIORef b)
        liftIO (readIORef (getField @"qf_voi" (expect hobj)))
      liftIO (writeIORef (getField @"qf_voi" (expect hobj)) qset)
      hobj <- liftIO (readIORef newb)
      qset <- do
        hobj <- liftIO (readIORef b)
        liftIO (readIORef (getField @"qf_boo" (expect hobj)))
      liftIO (writeIORef (getField @"qf_boo" (expect hobj)) qset)
      hobj <- liftIO (readIORef newb)
      qset <- do
        hobj <- liftIO (readIORef b)
        liftIO (readIORef (getField @"qf_tag" (expect hobj)))
      liftIO (writeIORef (getField @"qf_tag" (expect hobj)) qset)
      hobj <- liftIO (readIORef newb)
      qset <- do
        hobj <- liftIO (readIORef b)
        liftIO (readIORef (getField @"qf_lis" (expect hobj)))
      liftIO (writeIORef (getField @"qf_lis" (expect hobj)) qset)
      hobj <- liftIO (readIORef newb)
      qset <- do
        hobj <- liftIO (readIORef b)
        liftIO (readIORef (getField @"qf_str" (expect hobj)))
      liftIO (writeIORef (getField @"qf_str" (expect hobj)) qset)
      hobj <- liftIO (readIORef newb)
      qset <- do
        hobj <- liftIO (readIORef b)
        liftIO (readIORef (getField @"qf_i" (expect hobj)))
      liftIO (writeIORef (getField @"qf_i" (expect hobj)) qset)
      hobj <- liftIO (readIORef newb)
      qset <- do
        hobj <- liftIO (readIORef b)
        liftIO (readIORef (getField @"qf_f" (expect hobj)))
      liftIO (writeIORef (getField @"qf_f" (expect hobj)) qset)
      hobj <- liftIO (readIORef newb)
      qset <- do
        hobj <- liftIO (readIORef b)
        liftIO (readIORef (getField @"qf_lengt" (expect hobj)))
      liftIO (writeIORef (getField @"qf_lengt" (expect hobj)) qset)
      hobj <- liftIO (readIORef newb)
      qset <- do
        hobj <- liftIO (readIORef b)
        liftIO (readIORef (getField @"qf_car" (expect hobj)))
      liftIO (writeIORef (getField @"qf_car" (expect hobj)) qset)
      hobj <- liftIO (readIORef newb)
      qset <- do
        hobj <- liftIO (readIORef b)
        liftIO (readIORef (getField @"qf_cdr" (expect hobj)))
      liftIO (writeIORef (getField @"qf_cdr" (expect hobj)) qset)
      hret <- liftIO (readIORef newb)
      qreturn hret
      pure ()
  pure Nothing

tern :: Bool -> Maybe Box -> Maybe Box -> IO (Maybe Box)
tern cond_arg tr_arg fal_arg = evalContT $ callCC $ \qreturn -> do
  cond <- liftIO (newIORef cond_arg)
  tr <- liftIO (newIORef tr_arg)
  fal <- liftIO (newIORef fal_arg)
  hcond <- liftIO (readIORef cond)
  if hcond
    then do
      hret <- liftIO (readIORef tr)
      qreturn hret
      pure ()
    else do
      hret <- liftIO (readIORef fal)
      qreturn hret
      pure ()
  pure Nothing

ternString :: Bool -> String -> String -> IO (String)
ternString cond_arg tr_arg fal_arg = evalContT $ callCC $ \qreturn -> do
  cond <- liftIO (newIORef cond_arg)
  tr <- liftIO (newIORef tr_arg)
  fal <- liftIO (newIORef fal_arg)
  hcond <- liftIO (readIORef cond)
  if hcond
    then do
      hret <- liftIO (readIORef tr)
      qreturn hret
      pure ()
    else do
      hret <- liftIO (readIORef fal)
      qreturn hret
      pure ()
  pure ""

ternList :: Bool -> Maybe Box -> Maybe Box -> IO (Maybe Box)
ternList cond_arg tr_arg fal_arg = evalContT $ callCC $ \qreturn -> do
  cond <- liftIO (newIORef cond_arg)
  tr <- liftIO (newIORef tr_arg)
  fal <- liftIO (newIORef fal_arg)
  hcond <- liftIO (readIORef cond)
  if hcond
    then do
      hret <- liftIO (readIORef tr)
      qreturn hret
      pure ()
    else do
      hret <- liftIO (readIORef fal)
      qreturn hret
      pure ()
  pure Nothing

newVoid :: IO (Maybe Box)
newVoid = evalContT $ callCC $ \qreturn -> do
  qinit <- pure Nothing
  newb <- liftIO (newIORef qinit)
  qset <- liftIO makeBox
  liftIO (writeIORef newb qset)
  hobj <- liftIO (readIORef newb)
  qset <- pure True
  liftIO (writeIORef (getField @"qf_voi" (expect hobj)) qset)
  hobj <- liftIO (readIORef newb)
  qset <- pure "void"
  liftIO (writeIORef (getField @"qf_typ" (expect hobj)) qset)
  hret <- liftIO (readIORef newb)
  qreturn hret
  pure Nothing

stackDump :: IO (())
stackDump = evalContT $ callCC $ \qreturn -> do
  _ <- do
    arg0 <- pure ""
    liftIO (printf arg0)
  pure ()

nop :: IO (())
nop = evalContT $ callCC $ \qreturn -> do
  _ <- do
    arg0 <- pure ""
    liftIO (printf arg0)
  pure ()

equalBox :: Maybe Box -> Maybe Box -> IO (Bool)
equalBox a_arg b_arg = evalContT $ callCC $ \qreturn -> do
  a <- liftIO (newIORef a_arg)
  b <- liftIO (newIORef b_arg)
  hcond <- do
    arg0 <- liftIO (readIORef b)
    liftIO (isList arg0)
  if hcond
    then do
      hret <- pure False
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- pure "string"
        arg1 <- do
          arg0 <- liftIO (readIORef a)
          liftIO (boxType arg0)
        liftIO (equalString arg0 arg1)
      if hcond
        then do
          hret <- do
            arg0 <- do
              arg0 <- liftIO (readIORef a)
              liftIO (unBoxString arg0)
            arg1 <- do
              arg0 <- liftIO (readIORef b)
              liftIO (stringify arg0)
            liftIO (equalString arg0 arg1)
          qreturn hret
          pure ()
        else do
          hcond <- do
            arg0 <- pure "bool"
            arg1 <- do
              arg0 <- liftIO (readIORef a)
              liftIO (boxType arg0)
            liftIO (equalString arg0 arg1)
          if hcond
            then do
              hret <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef a)
                  liftIO (unBoxBool arg0)
                arg1 <- do
                  arg0 <- liftIO (readIORef b)
                  liftIO (unBoxBool arg0)
                liftIO (andBool arg0 arg1)
              qreturn hret
              pure ()
            else do
              hcond <- do
                arg0 <- pure "symbol"
                arg1 <- do
                  arg0 <- liftIO (readIORef a)
                  liftIO (boxType arg0)
                liftIO (equalString arg0 arg1)
              if hcond
                then do
                  hcond <- do
                    arg0 <- pure "symbol"
                    arg1 <- do
                      arg0 <- liftIO (readIORef b)
                      liftIO (boxType arg0)
                    liftIO (equalString arg0 arg1)
                  if hcond
                    then do
                      hret <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef a)
                          liftIO (unBoxSymbol arg0)
                        arg1 <- do
                          arg0 <- liftIO (readIORef b)
                          liftIO (unBoxSymbol arg0)
                        liftIO (equalString arg0 arg1)
                      qreturn hret
                      pure ()
                    else do
                      hret <- pure False
                      qreturn hret
                      pure ()
                  pure ()
                else do
                  hcond <- do
                    arg0 <- pure "int"
                    arg1 <- do
                      arg0 <- liftIO (readIORef a)
                      liftIO (boxType arg0)
                    liftIO (equalString arg0 arg1)
                  if hcond
                    then do
                      hret <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef a)
                          liftIO (unBoxInt arg0)
                        arg1 <- do
                          arg0 <- liftIO (readIORef b)
                          liftIO (unBoxInt arg0)
                        liftIO (equal arg0 arg1)
                      qreturn hret
                      pure ()
                    else do
                      hcond <- do
                        arg0 <- pure "float"
                        arg1 <- do
                          arg0 <- liftIO (readIORef a)
                          liftIO (boxType arg0)
                        liftIO (equalString arg0 arg1)
                      if hcond
                        then do
                          hcond <- do
                            arg0 <- pure "float"
                            arg1 <- do
                              arg0 <- liftIO (readIORef b)
                              liftIO (boxType arg0)
                            liftIO (equalString arg0 arg1)
                          if hcond
                            then do
                              hret <- do
                                arg0 <- do
                                  arg0 <- liftIO (readIORef a)
                                  liftIO (unBoxFloat arg0)
                                arg1 <- do
                                  arg0 <- liftIO (readIORef b)
                                  liftIO (unBoxFloat arg0)
                                liftIO (equalf arg0 arg1)
                              qreturn hret
                              pure ()
                            else do
                              hret <- pure False
                              qreturn hret
                              pure ()
                          pure ()
                        else do
                          hret <- pure False
                          qreturn hret
                          pure ()
                      pure ()
                  pure ()
              pure ()
          pure ()
      pure ()
  pure False

openBrace :: IO (String)
openBrace = evalContT $ callCC $ \qreturn -> do
  hret <- pure "("
  qreturn hret
  pure ""

closeBrace :: IO (String)
closeBrace = evalContT $ callCC $ \qreturn -> do
  hret <- pure ")"
  qreturn hret
  pure ""

boxType :: Maybe Box -> IO (String)
boxType b_arg = evalContT $ callCC $ \qreturn -> do
  b <- liftIO (newIORef b_arg)
  hret <- do
    hobj <- liftIO (readIORef b)
    liftIO (readIORef (getField @"qf_typ" (expect hobj)))
  qreturn hret
  pure ""

makeBox :: IO (Maybe Box)
makeBox = evalContT $ callCC $ \qreturn -> do
  qinit <- pure Nothing
  b <- liftIO (newIORef qinit)
  qset <- liftIO (Just <$> newBox)
  liftIO (writeIORef b qset)
  hcond <- do
    arg0 <- liftIO (readIORef b)
    liftIO (isNil arg0)
  if hcond
    then do
      _ <- do
        arg0 <- pure "failed to create box!"
        liftIO (panic arg0)
      pure ()
    else do
      pure ()
  hobj <- liftIO (readIORef b)
  qset <- pure Nothing
  liftIO (writeIORef (getField @"qf_tag" (expect hobj)) qset)
  hobj <- liftIO (readIORef b)
  qset <- pure Nothing
  liftIO (writeIORef (getField @"qf_car" (expect hobj)) qset)
  hobj <- liftIO (readIORef b)
  qset <- pure Nothing
  liftIO (writeIORef (getField @"qf_cdr" (expect hobj)) qset)
  hobj <- liftIO (readIORef b)
  qset <- pure Nothing
  liftIO (writeIORef (getField @"qf_lis" (expect hobj)) qset)
  hobj <- liftIO (readIORef b)
  qset <- pure "None - error!"
  liftIO (writeIORef (getField @"qf_typ" (expect hobj)) qset)
  hret <- liftIO (readIORef b)
  qreturn hret
  pure Nothing

makePair :: IO (Maybe Box)
makePair = evalContT $ callCC $ \qreturn -> do
  hret <- liftIO makeBox
  qreturn hret
  pure Nothing

boxString :: String -> IO (Maybe Box)
boxString s_arg = evalContT $ callCC $ \qreturn -> do
  s <- liftIO (newIORef s_arg)
  qinit <- pure Nothing
  b <- liftIO (newIORef qinit)
  qset <- liftIO makeBox
  liftIO (writeIORef b qset)
  hobj <- liftIO (readIORef b)
  qset <- liftIO (readIORef s)
  liftIO (writeIORef (getField @"qf_str" (expect hobj)) qset)
  hobj <- liftIO (readIORef b)
  qset <- do
    arg0 <- liftIO (readIORef s)
    liftIO (string_length arg0)
  liftIO (writeIORef (getField @"qf_lengt" (expect hobj)) qset)
  hobj <- liftIO (readIORef b)
  qset <- pure "string"
  liftIO (writeIORef (getField @"qf_typ" (expect hobj)) qset)
  hret <- liftIO (readIORef b)
  qreturn hret
  pure Nothing

boxSymbol :: String -> IO (Maybe Box)
boxSymbol s_arg = evalContT $ callCC $ \qreturn -> do
  s <- liftIO (newIORef s_arg)
  qinit <- pure Nothing
  b <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef s)
    liftIO (boxString arg0)
  liftIO (writeIORef b qset)
  hobj <- liftIO (readIORef b)
  qset <- pure "symbol"
  liftIO (writeIORef (getField @"qf_typ" (expect hobj)) qset)
  hret <- liftIO (readIORef b)
  qreturn hret
  pure Nothing

boxBool :: Bool -> IO (Maybe Box)
boxBool boo_arg = evalContT $ callCC $ \qreturn -> do
  boo <- liftIO (newIORef boo_arg)
  qinit <- pure Nothing
  b <- liftIO (newIORef qinit)
  qset <- liftIO makeBox
  liftIO (writeIORef b qset)
  hobj <- liftIO (readIORef b)
  qset <- liftIO (readIORef boo)
  liftIO (writeIORef (getField @"qf_boo" (expect hobj)) qset)
  hobj <- liftIO (readIORef b)
  qset <- pure "bool"
  liftIO (writeIORef (getField @"qf_typ" (expect hobj)) qset)
  hret <- liftIO (readIORef b)
  qreturn hret
  pure Nothing

boxInt :: Int -> IO (Maybe Box)
boxInt val_arg = evalContT $ callCC $ \qreturn -> do
  val <- liftIO (newIORef val_arg)
  qinit <- pure Nothing
  b <- liftIO (newIORef qinit)
  qset <- liftIO makeBox
  liftIO (writeIORef b qset)
  hobj <- liftIO (readIORef b)
  qset <- liftIO (readIORef val)
  liftIO (writeIORef (getField @"qf_i" (expect hobj)) qset)
  hobj <- liftIO (readIORef b)
  qset <- pure "int"
  liftIO (writeIORef (getField @"qf_typ" (expect hobj)) qset)
  hret <- liftIO (readIORef b)
  qreturn hret
  pure Nothing

boxFloat :: Double -> IO (Maybe Box)
boxFloat val_arg = evalContT $ callCC $ \qreturn -> do
  val <- liftIO (newIORef val_arg)
  qinit <- pure Nothing
  b <- liftIO (newIORef qinit)
  qset <- liftIO makeBox
  liftIO (writeIORef b qset)
  hobj <- liftIO (readIORef b)
  qset <- liftIO (readIORef val)
  liftIO (writeIORef (getField @"qf_f" (expect hobj)) qset)
  hobj <- liftIO (readIORef b)
  qset <- pure "float"
  liftIO (writeIORef (getField @"qf_typ" (expect hobj)) qset)
  hret <- liftIO (readIORef b)
  qreturn hret
  pure Nothing

assertType :: String -> Maybe Box -> Int -> String -> IO (())
assertType atype_arg abox_arg line_arg file_arg = evalContT $ callCC $ \qreturn -> do
  atype <- liftIO (newIORef atype_arg)
  abox <- liftIO (newIORef abox_arg)
  line <- liftIO (newIORef line_arg)
  file <- liftIO (newIORef file_arg)
  hcond <- do
    arg0 <- liftIO (readIORef abox)
    liftIO (isNil arg0)
  if hcond
    then do
      hcond <- do
        arg0 <- liftIO (readIORef atype)
        arg1 <- pure "nil"
        liftIO (equalString arg0 arg1)
      if hcond
        then do
          qreturn ()
          pure ()
        else do
          qreturn ()
          pure ()
      pure ()
    else do
      hcond <- do
        arg0 <- liftIO (readIORef atype)
        arg1 <- do
          arg0 <- liftIO (readIORef abox)
          liftIO (boxType arg0)
        liftIO (equalString arg0 arg1)
      if hcond
        then do
          qreturn ()
          pure ()
        else do
          _ <- do
            arg0 <- pure "Assertion failure at line %d, in file %s: provided value is not a '%s'!  It was actually '%s'. Contents:"
            arg1 <- liftIO (readIORef line)
            arg2 <- liftIO (readIORef file)
            arg3 <- liftIO (readIORef atype)
            arg4 <- do
              arg0 <- liftIO (readIORef abox)
              liftIO (boxType arg0)
            liftIO (printf arg0 arg1 arg2 arg3 arg4)
          _ <- do
            arg0 <- liftIO (readIORef abox)
            liftIO (display arg0)
          _ <- do
            arg0 <- pure "\n"
            liftIO (printf arg0)
          _ <- do
            arg0 <- do
              arg0 <- do
                arg0 <- pure "Token may have been read from "
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef abox)
                      arg1 <- do
                        arg0 <- pure "filename"
                        liftIO (boxString arg0)
                      arg2 <- do
                        arg0 <- pure "source file not found"
                        liftIO (boxString arg0)
                      liftIO (getTagFail arg0 arg1 arg2)
                    liftIO (stringify arg0)
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure ":"
                    liftIO (boxString arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef abox)
                          arg1 <- do
                            arg0 <- pure "line"
                            liftIO (boxString arg0)
                          arg2 <- do
                            arg0 <- pure "source line not found"
                            liftIO (boxString arg0)
                          liftIO (getTagFail arg0 arg1 arg2)
                        liftIO (stringify arg0)
                      liftIO (boxString arg0)
                    arg1 <- pure Nothing
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (display arg0)
          _ <- liftIO stackTracePrint
          _ <- do
            arg0 <- pure "Invalid type!"
            liftIO (panic arg0)
          pure ()
      pure ()
  pure ()

unBoxString :: Maybe Box -> IO (String)
unBoxString b_arg = evalContT $ callCC $ \qreturn -> do
  b <- liftIO (newIORef b_arg)
  _ <- do
    arg0 <- pure "string"
    arg1 <- liftIO (readIORef b)
    arg2 <- pure 199
    arg3 <- pure "q/base.qon"
    liftIO (assertType arg0 arg1 arg2 arg3)
  hret <- do
    hobj <- liftIO (readIORef b)
    liftIO (readIORef (getField @"qf_str" (expect hobj)))
  qreturn hret
  pure ""

unBoxSymbol :: Maybe Box -> IO (String)
unBoxSymbol b_arg = evalContT $ callCC $ \qreturn -> do
  b <- liftIO (newIORef b_arg)
  hret <- do
    hobj <- liftIO (readIORef b)
    liftIO (readIORef (getField @"qf_str" (expect hobj)))
  qreturn hret
  pure ""

unBoxBool :: Maybe Box -> IO (Bool)
unBoxBool b_arg = evalContT $ callCC $ \qreturn -> do
  b <- liftIO (newIORef b_arg)
  hret <- do
    hobj <- liftIO (readIORef b)
    liftIO (readIORef (getField @"qf_boo" (expect hobj)))
  qreturn hret
  pure False

unBoxInt :: Maybe Box -> IO (Int)
unBoxInt b_arg = evalContT $ callCC $ \qreturn -> do
  b <- liftIO (newIORef b_arg)
  hret <- do
    hobj <- liftIO (readIORef b)
    liftIO (readIORef (getField @"qf_i" (expect hobj)))
  qreturn hret
  pure 0

unBoxFloat :: Maybe Box -> IO (Double)
unBoxFloat b_arg = evalContT $ callCC $ \qreturn -> do
  b <- liftIO (newIORef b_arg)
  hret <- do
    hobj <- liftIO (readIORef b)
    liftIO (readIORef (getField @"qf_f" (expect hobj)))
  qreturn hret
  pure 0.0

stringify_rec :: Maybe Box -> IO (String)
stringify_rec b_arg = evalContT $ callCC $ \qreturn -> do
  b <- liftIO (newIORef b_arg)
  hcond <- do
    arg0 <- liftIO (readIORef b)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- pure ""
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef b)
            liftIO (car arg0)
          liftIO (stringify arg0)
        arg1 <- do
          arg0 <- pure " "
          arg1 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef b)
              liftIO (cdr arg0)
            liftIO (stringify_rec arg0)
          liftIO (stringConcatenate arg0 arg1)
        liftIO (stringConcatenate arg0 arg1)
      qreturn hret
      pure ()
  pure ""

stringify :: Maybe Box -> IO (String)
stringify b_arg = evalContT $ callCC $ \qreturn -> do
  b <- liftIO (newIORef b_arg)
  hcond <- do
    arg0 <- liftIO (readIORef b)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- pure "()"
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- pure "string"
        arg1 <- do
          arg0 <- liftIO (readIORef b)
          liftIO (boxType arg0)
        liftIO (equalString arg0 arg1)
      if hcond
        then do
          hret <- do
            arg0 <- liftIO (readIORef b)
            liftIO (unBoxString arg0)
          qreturn hret
          pure ()
        else do
          hcond <- do
            arg0 <- pure "bool"
            arg1 <- do
              arg0 <- liftIO (readIORef b)
              liftIO (boxType arg0)
            liftIO (equalString arg0 arg1)
          if hcond
            then do
              hcond <- do
                arg0 <- liftIO (readIORef b)
                liftIO (unBoxBool arg0)
              if hcond
                then do
                  hret <- pure "true"
                  qreturn hret
                  pure ()
                else do
                  hret <- pure "false"
                  qreturn hret
                  pure ()
              pure ()
            else do
              hcond <- do
                arg0 <- pure "int"
                arg1 <- do
                  arg0 <- liftIO (readIORef b)
                  liftIO (boxType arg0)
                liftIO (equalString arg0 arg1)
              if hcond
                then do
                  hret <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef b)
                      liftIO (unBoxInt arg0)
                    liftIO (intToString arg0)
                  qreturn hret
                  pure ()
                else do
                  hcond <- do
                    arg0 <- pure "float"
                    arg1 <- do
                      arg0 <- liftIO (readIORef b)
                      liftIO (boxType arg0)
                    liftIO (equalString arg0 arg1)
                  if hcond
                    then do
                      hret <- do
                        arg0 <- do
                          arg0 <- liftIO (readIORef b)
                          liftIO (unBoxFloat arg0)
                        liftIO (floatToString arg0)
                      qreturn hret
                      pure ()
                    else do
                      hcond <- do
                        arg0 <- pure "symbol"
                        arg1 <- do
                          arg0 <- liftIO (readIORef b)
                          liftIO (boxType arg0)
                        liftIO (equalString arg0 arg1)
                      if hcond
                        then do
                          hret <- do
                            arg0 <- liftIO (readIORef b)
                            liftIO (unBoxSymbol arg0)
                          qreturn hret
                          pure ()
                        else do
                          hcond <- do
                            arg0 <- pure "list"
                            arg1 <- do
                              arg0 <- liftIO (readIORef b)
                              liftIO (boxType arg0)
                            liftIO (equalString arg0 arg1)
                          if hcond
                            then do
                              hret <- do
                                arg0 <- pure "("
                                arg1 <- do
                                  arg0 <- do
                                    arg0 <- do
                                      arg0 <- liftIO (readIORef b)
                                      liftIO (car arg0)
                                    liftIO (stringify arg0)
                                  arg1 <- do
                                    arg0 <- pure " "
                                    arg1 <- do
                                      arg0 <- do
                                        arg0 <- do
                                          arg0 <- liftIO (readIORef b)
                                          liftIO (cdr arg0)
                                        liftIO (stringify_rec arg0)
                                      arg1 <- pure ")"
                                      liftIO (stringConcatenate arg0 arg1)
                                    liftIO (stringConcatenate arg0 arg1)
                                  liftIO (stringConcatenate arg0 arg1)
                                liftIO (stringConcatenate arg0 arg1)
                              qreturn hret
                              pure ()
                            else do
                              hret <- do
                                arg0 <- pure "Unsupported type in stringify: "
                                arg1 <- do
                                  arg0 <- liftIO (readIORef b)
                                  liftIO (boxType arg0)
                                liftIO (stringConcatenate arg0 arg1)
                              qreturn hret
                              pure ()
                          pure ()
                      pure ()
                  pure ()
              pure ()
          pure ()
      pure ()
  pure ""

hasTag :: Maybe Box -> Maybe Box -> IO (Bool)
hasTag aBox_arg key_arg = evalContT $ callCC $ \qreturn -> do
  aBox <- liftIO (newIORef aBox_arg)
  key <- liftIO (newIORef key_arg)
  hcond <- do
    arg0 <- liftIO (readIORef aBox)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- pure False
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef key)
            liftIO (stringify arg0)
          arg1 <- do
            hobj <- liftIO (readIORef aBox)
            liftIO (readIORef (getField @"qf_tag" (expect hobj)))
          liftIO (assoc arg0 arg1)
        liftIO (isNotFalse arg0)
      qreturn hret
      pure ()
  pure False

getTag :: Maybe Box -> Maybe Box -> IO (Maybe Box)
getTag aBox_arg key_arg = evalContT $ callCC $ \qreturn -> do
  aBox <- liftIO (newIORef aBox_arg)
  key <- liftIO (newIORef key_arg)
  hcond <- pure False
  if hcond
    then do
      _ <- do
        arg0 <- pure "Getting %s from: "
        arg1 <- do
          arg0 <- liftIO (readIORef key)
          liftIO (stringify arg0)
        liftIO (printf arg0 arg1)
      _ <- do
        arg0 <- do
          arg0 <- do
            hobj <- liftIO (readIORef aBox)
            liftIO (readIORef (getField @"qf_tag" (expect hobj)))
          liftIO (alistKeys arg0)
        liftIO (display arg0)
      _ <- do
        arg0 <- pure "\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- pure ""
        liftIO (printf arg0)
      pure ()
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef key)
        liftIO (stringify arg0)
      arg1 <- do
        hobj <- liftIO (readIORef aBox)
        liftIO (readIORef (getField @"qf_tag" (expect hobj)))
      liftIO (assoc arg0 arg1)
    liftIO (cdr arg0)
  qreturn hret
  pure Nothing

getTagFail :: Maybe Box -> Maybe Box -> Maybe Box -> IO (Maybe Box)
getTagFail aBox_arg key_arg onFail_arg = evalContT $ callCC $ \qreturn -> do
  aBox <- liftIO (newIORef aBox_arg)
  key <- liftIO (newIORef key_arg)
  onFail <- liftIO (newIORef onFail_arg)
  hcond <- do
    arg0 <- liftIO (readIORef aBox)
    arg1 <- liftIO (readIORef key)
    liftIO (hasTag arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- liftIO (readIORef aBox)
        arg1 <- liftIO (readIORef key)
        liftIO (getTag arg0 arg1)
      qreturn hret
      pure ()
    else do
      hret <- liftIO (readIORef onFail)
      qreturn hret
      pure ()
  pure Nothing

assocExists :: String -> Maybe Box -> IO (Bool)
assocExists key_arg aBox_arg = evalContT $ callCC $ \qreturn -> do
  key <- liftIO (newIORef key_arg)
  aBox <- liftIO (newIORef aBox_arg)
  hcond <- do
    arg0 <- liftIO (readIORef aBox)
    liftIO (isNil arg0)
  if hcond
    then do
      hret <- pure False
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- liftIO (readIORef key)
          arg1 <- liftIO (readIORef aBox)
          liftIO (assoc arg0 arg1)
        liftIO (isNotFalse arg0)
      qreturn hret
      pure ()
  pure False

assocFail :: String -> Maybe Box -> Maybe Box -> IO (Maybe Box)
assocFail key_arg aBox_arg onFail_arg = evalContT $ callCC $ \qreturn -> do
  key <- liftIO (newIORef key_arg)
  aBox <- liftIO (newIORef aBox_arg)
  onFail <- liftIO (newIORef onFail_arg)
  hcond <- do
    arg0 <- liftIO (readIORef key)
    arg1 <- liftIO (readIORef aBox)
    liftIO (assocExists arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- liftIO (readIORef key)
        arg1 <- liftIO (readIORef aBox)
        liftIO (assoc arg0 arg1)
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- liftIO (readIORef key)
          liftIO (boxString arg0)
        arg1 <- liftIO (readIORef onFail)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

assocPanic :: String -> Maybe Box -> String -> IO (Maybe Box)
assocPanic key_arg aBox_arg onFail_arg = evalContT $ callCC $ \qreturn -> do
  key <- liftIO (newIORef key_arg)
  aBox <- liftIO (newIORef aBox_arg)
  onFail <- liftIO (newIORef onFail_arg)
  hcond <- do
    arg0 <- liftIO (readIORef key)
    arg1 <- liftIO (readIORef aBox)
    liftIO (assocExists arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- liftIO (readIORef key)
        arg1 <- liftIO (readIORef aBox)
        liftIO (assoc arg0 arg1)
      qreturn hret
      pure ()
    else do
      _ <- do
        arg0 <- liftIO (readIORef onFail)
        liftIO (panic arg0)
      pure ()
  _ <- do
    arg0 <- pure "Inconceivable"
    liftIO (panic arg0)
  hret <- pure Nothing
  qreturn hret
  pure Nothing

setTag :: Maybe Box -> Maybe Box -> Maybe Box -> IO (Maybe Box)
setTag key_arg val_arg aStruct_arg = evalContT $ callCC $ \qreturn -> do
  key <- liftIO (newIORef key_arg)
  val <- liftIO (newIORef val_arg)
  aStruct <- liftIO (newIORef aStruct_arg)
  hobj <- liftIO (readIORef aStruct)
  qset <- do
    arg0 <- liftIO (readIORef key)
    arg1 <- liftIO (readIORef val)
    arg2 <- do
      hobj <- liftIO (readIORef aStruct)
      liftIO (readIORef (getField @"qf_tag" (expect hobj)))
    liftIO (alistCons arg0 arg1 arg2)
  liftIO (writeIORef (getField @"qf_tag" (expect hobj)) qset)
  hret <- liftIO (readIORef aStruct)
  qreturn hret
  pure Nothing

locPanic :: String -> String -> String -> IO (())
locPanic file_arg line_arg message_arg = evalContT $ callCC $ \qreturn -> do
  file <- liftIO (newIORef file_arg)
  line <- liftIO (newIORef line_arg)
  message <- liftIO (newIORef message_arg)
  _ <- do
    arg0 <- pure "%s %s:%s\n"
    arg1 <- liftIO (readIORef file)
    arg2 <- liftIO (readIORef line)
    arg3 <- liftIO (readIORef message)
    liftIO (printf arg0 arg1 arg2 arg3)
  _ <- do
    arg0 <- liftIO (readIORef message)
    liftIO (panic arg0)
  pure ()

truthy :: Maybe Box -> IO (Bool)
truthy aVal_arg = evalContT $ callCC $ \qreturn -> do
  aVal <- liftIO (newIORef aVal_arg)
  hret <- do
    arg0 <- liftIO (readIORef aVal)
    liftIO (isNotFalse arg0)
  qreturn hret
  pure False

isNotFalse :: Maybe Box -> IO (Bool)
isNotFalse aVal_arg = evalContT $ callCC $ \qreturn -> do
  aVal <- liftIO (newIORef aVal_arg)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef aVal)
      liftIO (boxType arg0)
    arg1 <- pure "bool"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hcond <- do
        arg0 <- liftIO (readIORef aVal)
        liftIO (unBoxBool arg0)
      if hcond
        then do
          hret <- pure True
          qreturn hret
          pure ()
        else do
          hret <- pure False
          qreturn hret
          pure ()
      pure ()
    else do
      hret <- pure True
      qreturn hret
      pure ()
  pure False

toStr :: Maybe Box -> IO (Maybe Box)
toStr thing_arg = evalContT $ callCC $ \qreturn -> do
  thing <- liftIO (newIORef thing_arg)
  hret <- do
    arg0 <- do
      arg0 <- liftIO (readIORef thing)
      liftIO (stringify arg0)
    liftIO (boxString arg0)
  qreturn hret
  pure Nothing

listLast :: Maybe Box -> IO (Maybe Box)
listLast alist_arg = evalContT $ callCC $ \qreturn -> do
  alist <- liftIO (newIORef alist_arg)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef alist)
      liftIO (cdr arg0)
    liftIO (isEmpty arg0)
  if hcond
    then do
      hret <- do
        arg0 <- liftIO (readIORef alist)
        liftIO (car arg0)
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- liftIO (readIORef alist)
          liftIO (cdr arg0)
        liftIO (listLast arg0)
      qreturn hret
      pure ()
  pure Nothing

newLine :: Int -> IO (())
newLine indent_arg = evalContT $ callCC $ \qreturn -> do
  indent <- liftIO (newIORef indent_arg)
  _ <- do
    arg0 <- pure "\n"
    liftIO (printf arg0)
  _ <- do
    arg0 <- liftIO (readIORef indent)
    liftIO (printIndent arg0)
  pure ()

printIndent :: Int -> IO (())
printIndent ii_arg = evalContT $ callCC $ \qreturn -> do
  ii <- liftIO (newIORef ii_arg)
  hcond <- do
    arg0 <- liftIO (readIORef ii)
    arg1 <- pure 0
    liftIO (greaterthan arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "  "
        liftIO (printf arg0)
      _ <- do
        arg0 <- do
          arg0 <- liftIO (readIORef ii)
          liftIO (sub1 arg0)
        liftIO (printIndent arg0)
      pure ()
    else do
      qreturn ()
      pure ()
  pure ()

stringIndent :: Int -> IO (String)
stringIndent ii_arg = evalContT $ callCC $ \qreturn -> do
  ii <- liftIO (newIORef ii_arg)
  hcond <- do
    arg0 <- liftIO (readIORef ii)
    arg1 <- pure 0
    liftIO (greaterthan arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- pure "  "
        arg1 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef ii)
            liftIO (sub1 arg0)
          liftIO (stringIndent arg0)
        liftIO (stringConcatenate arg0 arg1)
      qreturn hret
      pure ()
    else do
      hret <- pure ""
      qreturn hret
      pure ()
  pure ""

listIndent :: Int -> IO (Maybe Box)
listIndent ii_arg = evalContT $ callCC $ \qreturn -> do
  ii <- liftIO (newIORef ii_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- liftIO (readIORef ii)
          liftIO (stringIndent arg0)
        liftIO (boxString arg0)
      liftIO (qid arg0)
    arg1 <- pure Nothing
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

listNewLine :: Int -> IO (Maybe Box)
listNewLine ii_arg = evalContT $ callCC $ \qreturn -> do
  ii <- liftIO (newIORef ii_arg)
  hret <- do
    arg0 <- do
      arg0 <- do
        arg0 <- do
          arg0 <- pure "\n"
          arg1 <- do
            arg0 <- liftIO (readIORef ii)
            liftIO (stringIndent arg0)
          liftIO (stringConcatenate arg0 arg1)
        liftIO (boxString arg0)
      liftIO (qid arg0)
    arg1 <- pure Nothing
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

argList :: Int -> Int -> [String] -> IO (Maybe Box)
argList count_arg pos_arg args_arg = evalContT $ callCC $ \qreturn -> do
  count <- liftIO (newIORef count_arg)
  pos <- liftIO (newIORef pos_arg)
  args <- liftIO (newIORef args_arg)
  hcond <- do
    arg0 <- liftIO (readIORef count)
    arg1 <- liftIO (readIORef pos)
    liftIO (greaterthan arg0 arg1)
  if hcond
    then do
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef pos)
            arg1 <- liftIO (readIORef args)
            liftIO (getStringArray arg0 arg1)
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- liftIO (readIORef count)
          arg1 <- do
            arg0 <- liftIO (readIORef pos)
            liftIO (add1 arg0)
          arg2 <- liftIO (readIORef args)
          liftIO (argList arg0 arg1 arg2)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
    else do
      hret <- pure Nothing
      qreturn hret
      pure ()
  pure Nothing

tron :: IO (())
tron = evalContT $ callCC $ \qreturn -> do
  qset <- pure True
  liftIO (writeIORef globalTrace qset)
  pure ()

troff :: IO (())
troff = evalContT $ callCC $ \qreturn -> do
  qset <- pure False
  liftIO (writeIORef globalTrace qset)
  pure ()

stron :: IO (())
stron = evalContT $ callCC $ \qreturn -> do
  qset <- pure True
  liftIO (writeIORef globalStepTrace qset)
  pure ()

stroff :: IO (())
stroff = evalContT $ callCC $ \qreturn -> do
  qset <- pure False
  liftIO (writeIORef globalStepTrace qset)
  pure ()

stackTraceMove :: String -> String -> String -> String -> IO (())
stackTraceMove direction_arg filename_arg fname_arg line_arg = evalContT $ callCC $ \qreturn -> do
  direction <- liftIO (newIORef direction_arg)
  filename <- liftIO (newIORef filename_arg)
  fname <- liftIO (newIORef fname_arg)
  line <- liftIO (newIORef line_arg)
  hcond <- do
    arg0 <- liftIO (readIORef direction)
    arg1 <- pure "in"
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      qset <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef filename)
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- liftIO (readIORef line)
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef fname)
                liftIO (boxString arg0)
              arg1 <- pure Nothing
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        arg1 <- liftIO (readIORef globalStackTrace)
        liftIO (cons arg0 arg1)
      liftIO (writeIORef globalStackTrace qset)
      pure ()
    else do
      qset <- do
        arg0 <- liftIO (readIORef globalStackTrace)
        liftIO (cdr arg0)
      liftIO (writeIORef globalStackTrace qset)
      pure ()
  pure ()

stackTracePrint :: IO (())
stackTracePrint = evalContT $ callCC $ \qreturn -> do
  _ <- do
    arg0 <- pure "Stack trace:\n"
    liftIO (printf arg0)
  hcond <- do
    arg0 <- liftIO (readIORef globalStackTrace)
    liftIO (isNil arg0)
  if hcond
    then do
      _ <- do
        arg0 <- pure "  <empty>\n"
        liftIO (printf arg0)
      pure ()
    else do
      _ <- do
        arg0 <- liftIO (readIORef globalStackTrace)
        liftIO (stackTracePrintHelper arg0)
      pure ()
  pure ()

stackTracePrintHelper :: Maybe Box -> IO (())
stackTracePrintHelper stack_arg = evalContT $ callCC $ \qreturn -> do
  stack <- liftIO (newIORef stack_arg)
  qinit <- do
    arg0 <- do
      arg0 <- do
        arg0 <- liftIO (readIORef stack)
        liftIO (car arg0)
      liftIO (first arg0)
    liftIO (stringify arg0)
  file <- liftIO (newIORef qinit)
  qinit <- pure ""
  line <- liftIO (newIORef qinit)
  qinit <- pure ""
  func <- liftIO (newIORef qinit)
  hcond <- do
    arg0 <- liftIO (readIORef stack)
    liftIO (isNil arg0)
  if hcond
    then do
      _ <- do
        arg0 <- pure "  <end>\n"
        liftIO (printf arg0)
      qreturn ()
      pure ()
    else do
      qset <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef stack)
            liftIO (car arg0)
          liftIO (first arg0)
        liftIO (stringify arg0)
      liftIO (writeIORef file qset)
      qset <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef stack)
            liftIO (car arg0)
          liftIO (second arg0)
        liftIO (stringify arg0)
      liftIO (writeIORef line qset)
      qset <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef stack)
            liftIO (first arg0)
          liftIO (third arg0)
        liftIO (stringify arg0)
      liftIO (writeIORef func qset)
      _ <- do
        arg0 <- pure "  %s:%s %s\n"
        arg1 <- liftIO (readIORef file)
        arg2 <- liftIO (readIORef line)
        arg3 <- liftIO (readIORef func)
        liftIO (printf arg0 arg1 arg2 arg3)
      _ <- do
        arg0 <- do
          arg0 <- liftIO (readIORef stack)
          liftIO (cdr arg0)
        liftIO (stackTracePrintHelper arg0)
      pure ()
  pure ()

noStackTrace_list :: IO (Maybe Box)
noStackTrace_list = evalContT $ callCC $ \qreturn -> do
  hret <- do
    arg0 <- do
      arg0 <- pure "StackTraceMove"
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "StackTracePrint"
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure "StackTracePrintHelper"
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "NoStackTrace_list"
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure "car"
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure "cdr"
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure "cons"
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure "set"
                    liftIO (boxString arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- pure "boxString"
                      liftIO (boxString arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- pure "makePair"
                        liftIO (boxString arg0)
                      arg1 <- do
                        arg0 <- do
                          arg0 <- pure "set-struct"
                          liftIO (boxString arg0)
                        arg1 <- do
                          arg0 <- do
                            arg0 <- pure "display"
                            liftIO (boxString arg0)
                          arg1 <- do
                            arg0 <- do
                              arg0 <- pure "list"
                              liftIO (boxString arg0)
                            arg1 <- do
                              arg0 <- do
                                arg0 <- pure "assertType"
                                liftIO (boxString arg0)
                              arg1 <- do
                                arg0 <- do
                                  arg0 <- pure "isEmpty"
                                  liftIO (boxString arg0)
                                arg1 <- do
                                  arg0 <- do
                                    arg0 <- pure "isNil"
                                    liftIO (boxString arg0)
                                  arg1 <- do
                                    arg0 <- do
                                      arg0 <- pure "get-struct"
                                      liftIO (boxString arg0)
                                    arg1 <- do
                                      arg0 <- do
                                        arg0 <- pure "equalString"
                                        liftIO (boxString arg0)
                                      arg1 <- do
                                        arg0 <- do
                                          arg0 <- pure "binop"
                                          liftIO (boxString arg0)
                                        arg1 <- do
                                          arg0 <- do
                                            arg0 <- pure "strcmp"
                                            liftIO (boxString arg0)
                                          arg1 <- do
                                            arg0 <- do
                                              arg0 <- pure "main"
                                              liftIO (boxString arg0)
                                            arg1 <- do
                                              arg0 <- do
                                                arg0 <- pure "makeBox"
                                                liftIO (boxString arg0)
                                              arg1 <- do
                                                arg0 <- do
                                                  arg0 <- pure "string_length"
                                                  liftIO (boxString arg0)
                                                arg1 <- do
                                                  arg0 <- do
                                                    arg0 <- pure "boxType"
                                                    liftIO (boxString arg0)
                                                  arg1 <- do
                                                    arg0 <- do
                                                      arg0 <- pure "displayList"
                                                      liftIO (boxString arg0)
                                                    arg1 <- do
                                                      arg0 <- do
                                                        arg0 <- pure "newLine"
                                                        liftIO (boxString arg0)
                                                      arg1 <- do
                                                        arg0 <- do
                                                          arg0 <- pure "panic"
                                                          liftIO (boxString arg0)
                                                        arg1 <- pure Nothing
                                                        liftIO (cons arg0 arg1)
                                                      liftIO (cons arg0 arg1)
                                                    liftIO (cons arg0 arg1)
                                                  liftIO (cons arg0 arg1)
                                                liftIO (cons arg0 arg1)
                                              liftIO (cons arg0 arg1)
                                            liftIO (cons arg0 arg1)
                                          liftIO (cons arg0 arg1)
                                        liftIO (cons arg0 arg1)
                                      liftIO (cons arg0 arg1)
                                    liftIO (cons arg0 arg1)
                                  liftIO (cons arg0 arg1)
                                liftIO (cons arg0 arg1)
                              liftIO (cons arg0 arg1)
                            liftIO (cons arg0 arg1)
                          liftIO (cons arg0 arg1)
                        liftIO (cons arg0 arg1)
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

noTrace_list :: IO (Maybe Box)
noTrace_list = evalContT $ callCC $ \qreturn -> do
  hret <- do
    arg0 <- do
      arg0 <- pure "StackTraceMove"
      liftIO (boxString arg0)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "StackTracePrint"
        liftIO (boxString arg0)
      arg1 <- do
        arg0 <- do
          arg0 <- pure "StackTracePrintHelper"
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- pure "NoStackTrace_list"
            liftIO (boxString arg0)
          arg1 <- do
            arg0 <- do
              arg0 <- pure "car"
              liftIO (boxString arg0)
            arg1 <- do
              arg0 <- do
                arg0 <- pure "cdr"
                liftIO (boxString arg0)
              arg1 <- do
                arg0 <- do
                  arg0 <- pure "cons"
                  liftIO (boxString arg0)
                arg1 <- do
                  arg0 <- do
                    arg0 <- pure "set"
                    liftIO (boxString arg0)
                  arg1 <- do
                    arg0 <- do
                      arg0 <- pure "boxString"
                      liftIO (boxString arg0)
                    arg1 <- do
                      arg0 <- do
                        arg0 <- pure "makePair"
                        liftIO (boxString arg0)
                      arg1 <- do
                        arg0 <- do
                          arg0 <- pure "set-struct"
                          liftIO (boxString arg0)
                        arg1 <- do
                          arg0 <- do
                            arg0 <- pure "display"
                            liftIO (boxString arg0)
                          arg1 <- do
                            arg0 <- do
                              arg0 <- pure "list"
                              liftIO (boxString arg0)
                            arg1 <- do
                              arg0 <- do
                                arg0 <- pure "assertType"
                                liftIO (boxString arg0)
                              arg1 <- do
                                arg0 <- do
                                  arg0 <- pure "isEmpty"
                                  liftIO (boxString arg0)
                                arg1 <- do
                                  arg0 <- do
                                    arg0 <- pure "isNil"
                                    liftIO (boxString arg0)
                                  arg1 <- do
                                    arg0 <- do
                                      arg0 <- pure "get-struct"
                                      liftIO (boxString arg0)
                                    arg1 <- do
                                      arg0 <- do
                                        arg0 <- pure "equalString"
                                        liftIO (boxString arg0)
                                      arg1 <- do
                                        arg0 <- do
                                          arg0 <- pure "binop"
                                          liftIO (boxString arg0)
                                        arg1 <- do
                                          arg0 <- do
                                            arg0 <- pure "strcmp"
                                            liftIO (boxString arg0)
                                          arg1 <- do
                                            arg0 <- do
                                              arg0 <- pure "main"
                                              liftIO (boxString arg0)
                                            arg1 <- do
                                              arg0 <- do
                                                arg0 <- pure "makeBox"
                                                liftIO (boxString arg0)
                                              arg1 <- do
                                                arg0 <- do
                                                  arg0 <- pure "string_length"
                                                  liftIO (boxString arg0)
                                                arg1 <- do
                                                  arg0 <- do
                                                    arg0 <- pure "boxType"
                                                    liftIO (boxString arg0)
                                                  arg1 <- do
                                                    arg0 <- do
                                                      arg0 <- pure "displayList"
                                                      liftIO (boxString arg0)
                                                    arg1 <- do
                                                      arg0 <- do
                                                        arg0 <- pure "newLine"
                                                        liftIO (boxString arg0)
                                                      arg1 <- do
                                                        arg0 <- do
                                                          arg0 <- pure "panic"
                                                          liftIO (boxString arg0)
                                                        arg1 <- do
                                                          arg0 <- do
                                                            arg0 <- pure "boxString"
                                                            liftIO (boxString arg0)
                                                          arg1 <- do
                                                            arg0 <- do
                                                              arg0 <- pure "boxSymbol"
                                                              liftIO (boxString arg0)
                                                            arg1 <- do
                                                              arg0 <- do
                                                                arg0 <- pure "boxType"
                                                                liftIO (boxString arg0)
                                                              arg1 <- do
                                                                arg0 <- do
                                                                  arg0 <- pure "equalString"
                                                                  liftIO (boxString arg0)
                                                                arg1 <- do
                                                                  arg0 <- do
                                                                    arg0 <- pure "unBoxSymbol"
                                                                    liftIO (boxString arg0)
                                                                  arg1 <- do
                                                                    arg0 <- do
                                                                      arg0 <- pure "isList"
                                                                      liftIO (boxString arg0)
                                                                    arg1 <- do
                                                                      arg0 <- do
                                                                        arg0 <- pure "makeBox"
                                                                        liftIO (boxString arg0)
                                                                      arg1 <- do
                                                                        arg0 <- do
                                                                          arg0 <- pure "equalBox"
                                                                          liftIO (boxString arg0)
                                                                        arg1 <- do
                                                                          arg0 <- do
                                                                            arg0 <- pure "sub"
                                                                            liftIO (boxString arg0)
                                                                          arg1 <- do
                                                                            arg0 <- do
                                                                              arg0 <- pure "sub1"
                                                                              liftIO (boxString arg0)
                                                                            arg1 <- do
                                                                              arg0 <- do
                                                                                arg0 <- pure "stringify"
                                                                                liftIO (boxString arg0)
                                                                              arg1 <- do
                                                                                arg0 <- do
                                                                                  arg0 <- pure "add"
                                                                                  liftIO (boxString arg0)
                                                                                arg1 <- do
                                                                                  arg0 <- do
                                                                                    arg0 <- pure "greaterthan"
                                                                                    liftIO (boxString arg0)
                                                                                  arg1 <- pure Nothing
                                                                                  liftIO (cons arg0 arg1)
                                                                                liftIO (cons arg0 arg1)
                                                                              liftIO (cons arg0 arg1)
                                                                            liftIO (cons arg0 arg1)
                                                                          liftIO (cons arg0 arg1)
                                                                        liftIO (cons arg0 arg1)
                                                                      liftIO (cons arg0 arg1)
                                                                    liftIO (cons arg0 arg1)
                                                                  liftIO (cons arg0 arg1)
                                                                liftIO (cons arg0 arg1)
                                                              liftIO (cons arg0 arg1)
                                                            liftIO (cons arg0 arg1)
                                                          liftIO (cons arg0 arg1)
                                                        liftIO (cons arg0 arg1)
                                                      liftIO (cons arg0 arg1)
                                                    liftIO (cons arg0 arg1)
                                                  liftIO (cons arg0 arg1)
                                                liftIO (cons arg0 arg1)
                                              liftIO (cons arg0 arg1)
                                            liftIO (cons arg0 arg1)
                                          liftIO (cons arg0 arg1)
                                        liftIO (cons arg0 arg1)
                                      liftIO (cons arg0 arg1)
                                    liftIO (cons arg0 arg1)
                                  liftIO (cons arg0 arg1)
                                liftIO (cons arg0 arg1)
                              liftIO (cons arg0 arg1)
                            liftIO (cons arg0 arg1)
                          liftIO (cons arg0 arg1)
                        liftIO (cons arg0 arg1)
                      liftIO (cons arg0 arg1)
                    liftIO (cons arg0 arg1)
                  liftIO (cons arg0 arg1)
                liftIO (cons arg0 arg1)
              liftIO (cons arg0 arg1)
            liftIO (cons arg0 arg1)
          liftIO (cons arg0 arg1)
        liftIO (cons arg0 arg1)
      liftIO (cons arg0 arg1)
    liftIO (cons arg0 arg1)
  qreturn hret
  pure Nothing

indexOfHelper :: String -> String -> Int -> Int -> IO (Int)
indexOfHelper haystack_arg needle_arg start_arg current_arg = evalContT $ callCC $ \qreturn -> do
  haystack <- liftIO (newIORef haystack_arg)
  needle <- liftIO (newIORef needle_arg)
  start <- liftIO (newIORef start_arg)
  current <- liftIO (newIORef current_arg)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef current)
      arg1 <- do
        arg0 <- liftIO (readIORef needle)
        liftIO (string_length arg0)
      liftIO (add arg0 arg1)
    arg1 <- do
      arg0 <- liftIO (readIORef haystack)
      liftIO (string_length arg0)
    liftIO (greaterthan arg0 arg1)
  if hcond
    then do
      hret <- pure (-1)
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- do
          arg0 <- liftIO (readIORef haystack)
          arg1 <- liftIO (readIORef current)
          arg2 <- do
            arg0 <- liftIO (readIORef needle)
            liftIO (string_length arg0)
          liftIO (sub_string arg0 arg1 arg2)
        arg1 <- liftIO (readIORef needle)
        liftIO (equalString arg0 arg1)
      if hcond
        then do
          hret <- liftIO (readIORef current)
          qreturn hret
          pure ()
        else do
          hret <- do
            arg0 <- liftIO (readIORef haystack)
            arg1 <- liftIO (readIORef needle)
            arg2 <- liftIO (readIORef start)
            arg3 <- do
              arg0 <- liftIO (readIORef current)
              liftIO (add1 arg0)
            liftIO (indexOfHelper arg0 arg1 arg2 arg3)
          qreturn hret
          pure ()
      pure ()
  pure 0

indexOf :: String -> String -> Int -> IO (Int)
indexOf haystack_arg needle_arg start_arg = evalContT $ callCC $ \qreturn -> do
  haystack <- liftIO (newIORef haystack_arg)
  needle <- liftIO (newIORef needle_arg)
  start <- liftIO (newIORef start_arg)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef needle)
      liftIO (string_length arg0)
    arg1 <- pure 0
    liftIO (equal arg0 arg1)
  if hcond
    then do
      hret <- liftIO (readIORef start)
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- liftIO (readIORef haystack)
        arg1 <- liftIO (readIORef needle)
        arg2 <- liftIO (readIORef start)
        arg3 <- liftIO (readIORef start)
        liftIO (indexOfHelper arg0 arg1 arg2 arg3)
      qreturn hret
      pure ()
  pure 0

stringReplace :: String -> String -> String -> IO (String)
stringReplace oldValue_arg newValue_arg s_arg = evalContT $ callCC $ \qreturn -> do
  oldValue <- liftIO (newIORef oldValue_arg)
  newValue <- liftIO (newIORef newValue_arg)
  s <- liftIO (newIORef s_arg)
  qinit <- pure 0
  pos <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef s)
    arg1 <- liftIO (readIORef oldValue)
    arg2 <- pure 0
    liftIO (indexOf arg0 arg1 arg2)
  liftIO (writeIORef pos qset)
  hcond <- do
    arg0 <- liftIO (readIORef pos)
    arg1 <- pure (-1)
    liftIO (equal arg0 arg1)
  if hcond
    then do
      hret <- liftIO (readIORef s)
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- do
          arg0 <- liftIO (readIORef s)
          arg1 <- pure 0
          arg2 <- liftIO (readIORef pos)
          liftIO (sub_string arg0 arg1 arg2)
        arg1 <- do
          arg0 <- liftIO (readIORef newValue)
          arg1 <- do
            arg0 <- liftIO (readIORef oldValue)
            arg1 <- liftIO (readIORef newValue)
            arg2 <- do
              arg0 <- liftIO (readIORef s)
              arg1 <- do
                arg0 <- liftIO (readIORef pos)
                arg1 <- do
                  arg0 <- liftIO (readIORef oldValue)
                  liftIO (string_length arg0)
                liftIO (add arg0 arg1)
              arg2 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef s)
                  liftIO (string_length arg0)
                arg1 <- do
                  arg0 <- liftIO (readIORef pos)
                  arg1 <- do
                    arg0 <- liftIO (readIORef oldValue)
                    liftIO (string_length arg0)
                  liftIO (add arg0 arg1)
                liftIO (sub arg0 arg1)
              liftIO (sub_string arg0 arg1 arg2)
            liftIO (stringReplace arg0 arg1 arg2)
          liftIO (stringConcatenate arg0 arg1)
        liftIO (stringConcatenate arg0 arg1)
      qreturn hret
      pure ()
  pure ""

stringContains :: String -> String -> IO (Bool)
stringContains haystack_arg needle_arg = evalContT $ callCC $ \qreturn -> do
  haystack <- liftIO (newIORef haystack_arg)
  needle <- liftIO (newIORef needle_arg)
  qinit <- pure 0
  haystackLength <- liftIO (newIORef qinit)
  qinit <- pure 0
  needleLength <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef haystack)
    liftIO (string_length arg0)
  liftIO (writeIORef haystackLength qset)
  qset <- do
    arg0 <- liftIO (readIORef needle)
    liftIO (string_length arg0)
  liftIO (writeIORef needleLength qset)
  hcond <- do
    arg0 <- liftIO (readIORef needleLength)
    arg1 <- liftIO (readIORef haystackLength)
    liftIO (greaterthan arg0 arg1)
  if hcond
    then do
      hret <- pure False
      qreturn hret
      pure ()
    else do
      hret <- do
        arg0 <- liftIO (readIORef haystack)
        arg1 <- liftIO (readIORef needle)
        arg2 <- pure 0
        liftIO (stringContainsHelper arg0 arg1 arg2)
      qreturn hret
      pure ()
  pure False

stringContainsHelper :: String -> String -> Int -> IO (Bool)
stringContainsHelper haystack_arg needle_arg startIndex_arg = evalContT $ callCC $ \qreturn -> do
  haystack <- liftIO (newIORef haystack_arg)
  needle <- liftIO (newIORef needle_arg)
  startIndex <- liftIO (newIORef startIndex_arg)
  qinit <- pure 0
  haystackLength <- liftIO (newIORef qinit)
  qinit <- pure 0
  needleLength <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- liftIO (readIORef haystack)
    liftIO (string_length arg0)
  liftIO (writeIORef haystackLength qset)
  qset <- do
    arg0 <- liftIO (readIORef needle)
    liftIO (string_length arg0)
  liftIO (writeIORef needleLength qset)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef startIndex)
      arg1 <- liftIO (readIORef needleLength)
      liftIO (add arg0 arg1)
    arg1 <- liftIO (readIORef haystackLength)
    liftIO (greaterthan arg0 arg1)
  if hcond
    then do
      hret <- pure False
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- do
          arg0 <- liftIO (readIORef haystack)
          arg1 <- liftIO (readIORef startIndex)
          arg2 <- liftIO (readIORef needleLength)
          liftIO (sub_string arg0 arg1 arg2)
        arg1 <- liftIO (readIORef needle)
        liftIO (equalString arg0 arg1)
      if hcond
        then do
          hret <- pure True
          qreturn hret
          pure ()
        else do
          hret <- do
            arg0 <- liftIO (readIORef haystack)
            arg1 <- liftIO (readIORef needle)
            arg2 <- do
              arg0 <- liftIO (readIORef startIndex)
              arg1 <- pure 1
              liftIO (add arg0 arg1)
            liftIO (stringContainsHelper arg0 arg1 arg2)
          qreturn hret
          pure ()
      pure ()
  pure False

isWhiteSpace :: String -> IO (Bool)
isWhiteSpace s_arg = evalContT $ callCC $ \qreturn -> do
  s <- liftIO (newIORef s_arg)
  hcond <- do
    arg0 <- pure " "
    arg1 <- liftIO (readIORef s)
    liftIO (equalString arg0 arg1)
  if hcond
    then do
      hret <- pure True
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- pure "\t"
        arg1 <- liftIO (readIORef s)
        liftIO (equalString arg0 arg1)
      if hcond
        then do
          hret <- pure True
          qreturn hret
          pure ()
        else do
          hcond <- do
            arg0 <- pure "\n"
            arg1 <- liftIO (readIORef s)
            liftIO (equalString arg0 arg1)
          if hcond
            then do
              hret <- pure True
              qreturn hret
              pure ()
            else do
              hcond <- do
                arg0 <- pure "\r"
                arg1 <- liftIO (readIORef s)
                liftIO (equalString arg0 arg1)
              if hcond
                then do
                  hret <- pure True
                  qreturn hret
                  pure ()
                else do
                  hret <- pure False
                  qreturn hret
                  pure ()
              pure ()
          pure ()
      pure ()
  pure False

stringTrim :: String -> IO (String)
stringTrim s_arg = evalContT $ callCC $ \qreturn -> do
  s <- liftIO (newIORef s_arg)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef s)
      liftIO (string_length arg0)
    arg1 <- pure 0
    liftIO (equal arg0 arg1)
  if hcond
    then do
      hret <- pure ""
      qreturn hret
      pure ()
    else do
      hcond <- do
        arg0 <- do
          arg0 <- liftIO (readIORef s)
          arg1 <- pure 0
          arg2 <- pure 1
          liftIO (sub_string arg0 arg1 arg2)
        liftIO (isWhiteSpace arg0)
      if hcond
        then do
          hret <- do
            arg0 <- do
              arg0 <- liftIO (readIORef s)
              arg1 <- pure 1
              arg2 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef s)
                  liftIO (string_length arg0)
                liftIO (sub1 arg0)
              liftIO (sub_string arg0 arg1 arg2)
            liftIO (stringTrim arg0)
          qreturn hret
          pure ()
        else do
          hcond <- do
            arg0 <- do
              arg0 <- liftIO (readIORef s)
              arg1 <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef s)
                  liftIO (string_length arg0)
                arg1 <- pure 1
                liftIO (sub arg0 arg1)
              arg2 <- pure 1
              liftIO (sub_string arg0 arg1 arg2)
            liftIO (isWhiteSpace arg0)
          if hcond
            then do
              hret <- do
                arg0 <- do
                  arg0 <- liftIO (readIORef s)
                  arg1 <- pure 0
                  arg2 <- do
                    arg0 <- do
                      arg0 <- liftIO (readIORef s)
                      liftIO (string_length arg0)
                    arg1 <- pure 1
                    liftIO (sub arg0 arg1)
                  liftIO (sub_string arg0 arg1 arg2)
                liftIO (stringTrim arg0)
              qreturn hret
              pure ()
            else do
              hret <- liftIO (readIORef s)
              qreturn hret
              pure ()
          pure ()
      pure ()
  pure ""

stringSplit :: String -> String -> IO (Maybe Box)
stringSplit s_arg delimiter_arg = evalContT $ callCC $ \qreturn -> do
  s <- liftIO (newIORef s_arg)
  delimiter <- liftIO (newIORef delimiter_arg)
  qinit <- pure 0
  end <- liftIO (newIORef qinit)
  qinit <- pure 0
  delimiterLength <- liftIO (newIORef qinit)
  _ <- do
    arg0 <- pure "Entering stringSplit with s: %.20s..., delimiter: %s\n"
    arg1 <- liftIO (readIORef s)
    arg2 <- liftIO (readIORef delimiter)
    liftIO (printf arg0 arg1 arg2)
  qset <- do
    arg0 <- liftIO (readIORef delimiter)
    liftIO (string_length arg0)
  liftIO (writeIORef delimiterLength qset)
  qset <- do
    arg0 <- liftIO (readIORef s)
    arg1 <- liftIO (readIORef delimiter)
    arg2 <- pure 0
    liftIO (indexOf arg0 arg1 arg2)
  liftIO (writeIORef end qset)
  hcond <- do
    arg0 <- liftIO (readIORef end)
    arg1 <- pure (-1)
    liftIO (equal arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "No delimiter found in stringSplit\n"
        liftIO (printf arg0)
      hret <- do
        arg0 <- do
          arg0 <- liftIO (readIORef s)
          liftIO (boxString arg0)
        arg1 <- pure Nothing
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
    else do
      _ <- do
        arg0 <- pure "Splitting string in stringSplit\n"
        liftIO (printf arg0)
      hret <- do
        arg0 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef s)
            arg1 <- pure 0
            arg2 <- liftIO (readIORef end)
            liftIO (sub_string arg0 arg1 arg2)
          liftIO (boxString arg0)
        arg1 <- do
          arg0 <- do
            arg0 <- liftIO (readIORef s)
            arg1 <- do
              arg0 <- liftIO (readIORef end)
              arg1 <- liftIO (readIORef delimiterLength)
              liftIO (add arg0 arg1)
            arg2 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef s)
                liftIO (string_length arg0)
              arg1 <- do
                arg0 <- liftIO (readIORef end)
                arg1 <- liftIO (readIORef delimiterLength)
                liftIO (add arg0 arg1)
              liftIO (sub arg0 arg1)
            liftIO (sub_string arg0 arg1 arg2)
          arg1 <- liftIO (readIORef delimiter)
          liftIO (stringSplit arg0 arg1)
        liftIO (cons arg0 arg1)
      qreturn hret
      pure ()
  pure Nothing

isNil :: Maybe Box -> IO (Bool)
isNil a_arg = evalContT $ callCC $ \qreturn -> do
  a <- liftIO (newIORef a_arg)
  hret <- do
    arg0 <- liftIO (readIORef a)
    liftIO (hsIsNil arg0)
  qreturn hret
  pure False

getEnv :: String -> IO (String)
getEnv key_arg = evalContT $ callCC $ \qreturn -> do
  key <- liftIO (newIORef key_arg)
  hret <- do
    arg0 <- liftIO (readIORef key)
    liftIO (hsGetEnv arg0)
  qreturn hret
  pure ""

panic :: String -> IO (())
panic s_arg = evalContT $ callCC $ \qreturn -> do
  s <- liftIO (newIORef s_arg)
  _ <- do
    arg0 <- liftIO (readIORef s)
    liftIO (hsPanic arg0)
  pure ()

exit :: Int -> IO (())
exit status_arg = evalContT $ callCC $ \qreturn -> do
  status <- liftIO (newIORef status_arg)
  _ <- do
    arg0 <- liftIO (readIORef status)
    liftIO (hsExit arg0)
  pure ()

sub :: Int -> Int -> IO (Int)
sub a_arg b_arg = evalContT $ callCC $ \qreturn -> do
  a <- liftIO (newIORef a_arg)
  b <- liftIO (newIORef b_arg)
  hret <- do
    arg0 <- liftIO (readIORef a)
    arg1 <- liftIO (readIORef b)
    pure (arg0 - arg1)
  qreturn hret
  pure 0

mult :: Int -> Int -> IO (Int)
mult a_arg b_arg = evalContT $ callCC $ \qreturn -> do
  a <- liftIO (newIORef a_arg)
  b <- liftIO (newIORef b_arg)
  hret <- do
    arg0 <- liftIO (readIORef a)
    arg1 <- liftIO (readIORef b)
    pure (arg0 * arg1)
  qreturn hret
  pure 0

greaterthan :: Int -> Int -> IO (Bool)
greaterthan a_arg b_arg = evalContT $ callCC $ \qreturn -> do
  a <- liftIO (newIORef a_arg)
  b <- liftIO (newIORef b_arg)
  hret <- do
    arg0 <- liftIO (readIORef a)
    arg1 <- liftIO (readIORef b)
    pure (arg0 > arg1)
  qreturn hret
  pure False

subf :: Double -> Double -> IO (Double)
subf a_arg b_arg = evalContT $ callCC $ \qreturn -> do
  a <- liftIO (newIORef a_arg)
  b <- liftIO (newIORef b_arg)
  hret <- do
    arg0 <- liftIO (readIORef a)
    arg1 <- liftIO (readIORef b)
    pure (arg0 - arg1)
  qreturn hret
  pure 0.0

multf :: Double -> Double -> IO (Double)
multf a_arg b_arg = evalContT $ callCC $ \qreturn -> do
  a <- liftIO (newIORef a_arg)
  b <- liftIO (newIORef b_arg)
  hret <- do
    arg0 <- liftIO (readIORef a)
    arg1 <- liftIO (readIORef b)
    pure (arg0 * arg1)
  qreturn hret
  pure 0.0

greaterthanf :: Double -> Double -> IO (Bool)
greaterthanf a_arg b_arg = evalContT $ callCC $ \qreturn -> do
  a <- liftIO (newIORef a_arg)
  b <- liftIO (newIORef b_arg)
  hret <- do
    arg0 <- liftIO (readIORef a)
    arg1 <- liftIO (readIORef b)
    pure (arg0 > arg1)
  qreturn hret
  pure False

equalf :: Double -> Double -> IO (Bool)
equalf a_arg b_arg = evalContT $ callCC $ \qreturn -> do
  a <- liftIO (newIORef a_arg)
  b <- liftIO (newIORef b_arg)
  hret <- do
    arg0 <- liftIO (readIORef a)
    arg1 <- liftIO (readIORef b)
    pure (arg0 == arg1)
  qreturn hret
  pure False

equal :: Int -> Int -> IO (Bool)
equal a_arg b_arg = evalContT $ callCC $ \qreturn -> do
  a <- liftIO (newIORef a_arg)
  b <- liftIO (newIORef b_arg)
  hret <- do
    arg0 <- liftIO (readIORef a)
    arg1 <- liftIO (readIORef b)
    pure (arg0 == arg1)
  qreturn hret
  pure False

equalString :: String -> String -> IO (Bool)
equalString a_arg b_arg = evalContT $ callCC $ \qreturn -> do
  a <- liftIO (newIORef a_arg)
  b <- liftIO (newIORef b_arg)
  hret <- do
    arg0 <- liftIO (readIORef a)
    arg1 <- liftIO (readIORef b)
    pure (arg0 == arg1)
  qreturn hret
  pure False

string_length :: String -> IO (Int)
string_length s_arg = evalContT $ callCC $ \qreturn -> do
  s <- liftIO (newIORef s_arg)
  hret <- do
    arg0 <- liftIO (readIORef s)
    liftIO (hsStringLength arg0)
  qreturn hret
  pure 0

setSubString :: String -> Int -> String -> IO (String)
setSubString target_arg start_arg source_arg = evalContT $ callCC $ \qreturn -> do
  target <- liftIO (newIORef target_arg)
  start <- liftIO (newIORef start_arg)
  source <- liftIO (newIORef source_arg)
  hret <- do
    arg0 <- liftIO (readIORef target)
    arg1 <- liftIO (readIORef start)
    arg2 <- liftIO (readIORef source)
    liftIO (hsSetSubString arg0 arg1 arg2)
  qreturn hret
  pure ""

sub_string :: String -> Int -> Int -> IO (String)
sub_string s_arg start_arg length_arg = evalContT $ callCC $ \qreturn -> do
  s <- liftIO (newIORef s_arg)
  start <- liftIO (newIORef start_arg)
  length <- liftIO (newIORef length_arg)
  hret <- do
    arg0 <- liftIO (readIORef s)
    arg1 <- liftIO (readIORef start)
    arg2 <- liftIO (readIORef length)
    liftIO (hsSubString arg0 arg1 arg2)
  qreturn hret
  pure ""

stringConcatenate :: String -> String -> IO (String)
stringConcatenate a_arg b_arg = evalContT $ callCC $ \qreturn -> do
  a <- liftIO (newIORef a_arg)
  b <- liftIO (newIORef b_arg)
  hret <- do
    arg0 <- liftIO (readIORef a)
    arg1 <- liftIO (readIORef b)
    pure (arg0 ++ arg1)
  qreturn hret
  pure ""

intToString :: Int -> IO (String)
intToString a_arg = evalContT $ callCC $ \qreturn -> do
  a <- liftIO (newIORef a_arg)
  hret <- do
    arg0 <- liftIO (readIORef a)
    liftIO (hsShowInt arg0)
  qreturn hret
  pure ""

floatToString :: Double -> IO (String)
floatToString a_arg = evalContT $ callCC $ \qreturn -> do
  a <- liftIO (newIORef a_arg)
  hret <- do
    arg0 <- liftIO (readIORef a)
    liftIO (hsShowFloat arg0)
  qreturn hret
  pure ""

read_file :: String -> IO (Maybe Box)
read_file filename_arg = evalContT $ callCC $ \qreturn -> do
  filename <- liftIO (newIORef filename_arg)
  hret <- do
    arg0 <- liftIO (readIORef filename)
    liftIO (hsReadFile arg0)
  qreturn hret
  pure Nothing

write_file :: String -> String -> IO (())
write_file filename_arg dataValue_arg = evalContT $ callCC $ \qreturn -> do
  filename <- liftIO (newIORef filename_arg)
  dataValue <- liftIO (newIORef dataValue_arg)
  _ <- do
    arg0 <- liftIO (readIORef filename)
    arg1 <- liftIO (readIORef dataValue)
    liftIO (hsWriteFile arg0 arg1)
  pure ()

getStringArray :: Int -> [String] -> IO (String)
getStringArray index_arg strs_arg = evalContT $ callCC $ \qreturn -> do
  index <- liftIO (newIORef index_arg)
  strs <- liftIO (newIORef strs_arg)
  hret <- do
    arg0 <- liftIO (readIORef index)
    arg1 <- liftIO (readIORef strs)
    liftIO (hsGetStringArray arg0 arg1)
  qreturn hret
  pure ""

programArgs :: IO ([String])
programArgs = evalContT $ callCC $ \qreturn -> do
  hret <- liftIO hsProgramArgs
  qreturn hret
  pure []

programArgsCount :: IO (Int)
programArgsCount = evalContT $ callCC $ \qreturn -> do
  hret <- liftIO hsProgramArgsCount
  qreturn hret
  pure 0

character :: Int -> IO (String)
character num_arg = evalContT $ callCC $ \qreturn -> do
  num <- liftIO (newIORef num_arg)
  hret <- do
    arg0 <- liftIO (readIORef num)
    liftIO (hsCharacter arg0)
  qreturn hret
  pure ""

displays :: String -> IO (())
displays s_arg = evalContT $ callCC $ \qreturn -> do
  s <- liftIO (newIORef s_arg)
  _ <- do
    arg0 <- pure "%s"
    arg1 <- liftIO (readIORef s)
    liftIO (printf arg0 arg1)
  pure ()

remainder :: Int -> Int -> IO (Int)
remainder a_arg b_arg = evalContT $ callCC $ \qreturn -> do
  a <- liftIO (newIORef a_arg)
  b <- liftIO (newIORef b_arg)
  hret <- do
    arg0 <- liftIO (readIORef a)
    arg1 <- liftIO (readIORef b)
    liftIO (hsRemainder arg0 arg1)
  qreturn hret
  pure 0

or :: Bool -> Bool -> IO (Bool)
or a_arg b_arg = evalContT $ callCC $ \qreturn -> do
  a <- liftIO (newIORef a_arg)
  b <- liftIO (newIORef b_arg)
  hret <- do
    arg0 <- liftIO (readIORef a)
    arg1 <- liftIO (readIORef b)
    pure (arg0 || arg1)
  qreturn hret
  pure False

max :: Int -> Int -> IO (Int)
max a_arg b_arg = evalContT $ callCC $ \qreturn -> do
  a <- liftIO (newIORef a_arg)
  b <- liftIO (newIORef b_arg)
  hcond <- do
    arg0 <- liftIO (readIORef a)
    arg1 <- liftIO (readIORef b)
    liftIO (greaterthan arg0 arg1)
  if hcond
    then do
      hret <- liftIO (readIORef a)
      qreturn hret
      pure ()
    else do
      hret <- liftIO (readIORef b)
      qreturn hret
      pure ()
  pure 0

min :: Int -> Int -> IO (Int)
min a_arg b_arg = evalContT $ callCC $ \qreturn -> do
  a <- liftIO (newIORef a_arg)
  b <- liftIO (newIORef b_arg)
  hcond <- do
    arg0 <- liftIO (readIORef a)
    arg1 <- liftIO (readIORef b)
    liftIO (greaterthan arg0 arg1)
  if hcond
    then do
      hret <- liftIO (readIORef b)
      qreturn hret
      pure ()
    else do
      hret <- liftIO (readIORef a)
      qreturn hret
      pure ()
  pure 0

makeHash :: IO (IORef [(String, String)])
makeHash = evalContT $ callCC $ \qreturn -> do
  hret <- liftIO hsMakeHash
  qreturn hret
  pure (error "no default value for IORef [(String, String)]")

setHash :: IORef [(String, String)] -> String -> String -> IO (())
setHash hash_arg key_arg value_arg = evalContT $ callCC $ \qreturn -> do
  hash <- liftIO (newIORef hash_arg)
  key <- liftIO (newIORef key_arg)
  value <- liftIO (newIORef value_arg)
  _ <- do
    arg0 <- liftIO (readIORef hash)
    arg1 <- liftIO (readIORef key)
    arg2 <- liftIO (readIORef value)
    liftIO (hsSetHash arg0 arg1 arg2)
  pure ()

getHash :: IORef [(String, String)] -> String -> IO (String)
getHash hash_arg key_arg = evalContT $ callCC $ \qreturn -> do
  hash <- liftIO (newIORef hash_arg)
  key <- liftIO (newIORef key_arg)
  hret <- do
    arg0 <- liftIO (readIORef hash)
    arg1 <- liftIO (readIORef key)
    liftIO (hsGetHash arg0 arg1)
  qreturn hret
  pure ""

inHash :: IORef [(String, String)] -> String -> IO (Bool)
inHash hash_arg key_arg = evalContT $ callCC $ \qreturn -> do
  hash <- liftIO (newIORef hash_arg)
  key <- liftIO (newIORef key_arg)
  hret <- do
    arg0 <- liftIO (readIORef hash)
    arg1 <- liftIO (readIORef key)
    liftIO (hsInHash arg0 arg1)
  qreturn hret
  pure False

makeArray :: Int -> IO ([String])
makeArray length_arg = evalContT $ callCC $ \qreturn -> do
  length <- liftIO (newIORef length_arg)
  hret <- do
    arg0 <- liftIO (readIORef length)
    liftIO (hsMakeArray arg0)
  qreturn hret
  pure []

setArray :: [String] -> Int -> String -> IO (())
setArray array_arg index_arg value_arg = evalContT $ callCC $ \qreturn -> do
  array <- liftIO (newIORef array_arg)
  index <- liftIO (newIORef index_arg)
  value <- liftIO (newIORef value_arg)
  _ <- do
    arg0 <- liftIO (readIORef array)
    arg1 <- liftIO (readIORef index)
    arg2 <- liftIO (readIORef value)
    liftIO (hsSetArray arg0 arg1 arg2)
  pure ()

getArray :: [String] -> Int -> IO (String)
getArray array_arg index_arg = evalContT $ callCC $ \qreturn -> do
  array <- liftIO (newIORef array_arg)
  index <- liftIO (newIORef index_arg)
  hret <- do
    arg0 <- liftIO (readIORef array)
    arg1 <- liftIO (readIORef index)
    liftIO (hsGetArray arg0 arg1)
  qreturn hret
  pure ""

start :: IO (Int)
start = evalContT $ callCC $ \qreturn -> do
  qinit <- pure False
  runTests <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  cmdLine <- liftIO (newIORef qinit)
  qinit <- pure Nothing
  filenameBox <- liftIO (newIORef qinit)
  qinit <- pure ""
  filename <- liftIO (newIORef qinit)
  qinit <- pure False
  runPerl <- liftIO (newIORef qinit)
  qinit <- pure False
  runJava <- liftIO (newIORef qinit)
  qinit <- pure False
  runNode <- liftIO (newIORef qinit)
  qinit <- pure False
  runNode2 <- liftIO (newIORef qinit)
  qinit <- pure False
  runHaskell <- liftIO (newIORef qinit)
  qinit <- pure False
  runAnsi3 <- liftIO (newIORef qinit)
  qinit <- pure False
  runTree <- liftIO (newIORef qinit)
  qset <- do
    arg0 <- do
      arg0 <- liftIO (readIORef globalArgsCount)
      arg1 <- pure 0
      arg2 <- liftIO (readIORef globalArgs)
      liftIO (argList arg0 arg1 arg2)
    liftIO (listReverse arg0)
  liftIO (writeIORef cmdLine qset)
  hcond <- do
    arg0 <- do
      arg0 <- liftIO (readIORef cmdLine)
      liftIO (listLength arg0)
    arg1 <- pure 1
    liftIO (greaterthan arg0 arg1)
  if hcond
    then do
      qset <- do
        arg0 <- liftIO (readIORef cmdLine)
        liftIO (second arg0)
      liftIO (writeIORef filenameBox qset)
      pure ()
    else do
      qset <- do
        arg0 <- pure "compiler.qon"
        liftIO (boxString arg0)
      liftIO (writeIORef filenameBox qset)
      pure ()
  qset <- do
    arg0 <- liftIO (readIORef filenameBox)
    liftIO (unBoxString arg0)
  liftIO (writeIORef filename qset)
  qset <- do
    arg0 <- do
      arg0 <- pure "--release"
      liftIO (boxString arg0)
    arg1 <- liftIO (readIORef cmdLine)
    liftIO (inList arg0 arg1)
  liftIO (writeIORef releaseMode qset)
  qset <- do
    arg0 <- do
      arg0 <- pure "--test"
      liftIO (boxString arg0)
    arg1 <- liftIO (readIORef cmdLine)
    liftIO (inList arg0 arg1)
  liftIO (writeIORef runTests qset)
  qset <- do
    arg0 <- do
      arg0 <- pure "--java"
      liftIO (boxString arg0)
    arg1 <- liftIO (readIORef cmdLine)
    liftIO (inList arg0 arg1)
  liftIO (writeIORef runJava qset)
  qset <- do
    arg0 <- do
      arg0 <- pure "--perl"
      liftIO (boxString arg0)
    arg1 <- liftIO (readIORef cmdLine)
    liftIO (inList arg0 arg1)
  liftIO (writeIORef runPerl qset)
  qset <- do
    arg0 <- do
      arg0 <- pure "--tree"
      liftIO (boxString arg0)
    arg1 <- liftIO (readIORef cmdLine)
    liftIO (inList arg0 arg1)
  liftIO (writeIORef runTree qset)
  qset <- do
    arg0 <- do
      arg0 <- pure "--node"
      liftIO (boxString arg0)
    arg1 <- liftIO (readIORef cmdLine)
    liftIO (inList arg0 arg1)
  liftIO (writeIORef runNode qset)
  qset <- do
    arg0 <- do
      arg0 <- pure "--node2"
      liftIO (boxString arg0)
    arg1 <- liftIO (readIORef cmdLine)
    liftIO (inList arg0 arg1)
  liftIO (writeIORef runNode2 qset)
  qset <- do
    arg0 <- do
      arg0 <- do
        arg0 <- pure "--haskell"
        liftIO (boxString arg0)
      arg1 <- liftIO (readIORef cmdLine)
      liftIO (inList arg0 arg1)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "--hs"
        liftIO (boxString arg0)
      arg1 <- liftIO (readIORef cmdLine)
      liftIO (inList arg0 arg1)
    liftIO (orBool arg0 arg1)
  liftIO (writeIORef runHaskell qset)
  qset <- do
    arg0 <- do
      arg0 <- pure "--ansi3"
      liftIO (boxString arg0)
    arg1 <- liftIO (readIORef cmdLine)
    liftIO (inList arg0 arg1)
  liftIO (writeIORef runAnsi3 qset)
  qset <- do
    arg0 <- do
      arg0 <- pure "--trace"
      liftIO (boxString arg0)
    arg1 <- liftIO (readIORef cmdLine)
    liftIO (inList arg0 arg1)
  liftIO (writeIORef globalTrace qset)
  qset <- do
    arg0 <- do
      arg0 <- pure "--steptrace"
      liftIO (boxString arg0)
    arg1 <- liftIO (readIORef cmdLine)
    liftIO (inList arg0 arg1)
  liftIO (writeIORef globalStepTrace qset)
  hcond <- do
    arg0 <- do
      arg0 <- do
        arg0 <- pure "--help"
        liftIO (boxString arg0)
      arg1 <- liftIO (readIORef cmdLine)
      liftIO (inList arg0 arg1)
    arg1 <- do
      arg0 <- do
        arg0 <- pure "-h"
        liftIO (boxString arg0)
      arg1 <- liftIO (readIORef cmdLine)
      liftIO (inList arg0 arg1)
    liftIO (orBool arg0 arg1)
  if hcond
    then do
      _ <- do
        arg0 <- pure "Usage: quon file [options]\n\nNote the options go after the file name\n"
        liftIO (printf arg0)
      _ <- do
        arg0 <- pure "Options:\n"
        liftIO (printf arg0)
      _ <- do
        arg0 <- pure "  -h, --help  Display this help\n"
        liftIO (printf arg0)
      _ <- do
        arg0 <- pure "  --release   Compile in release mode\n"
        liftIO (printf arg0)
      _ <- do
        arg0 <- pure "  --test      Run the test suite\n"
        liftIO (printf arg0)
      _ <- do
        arg0 <- pure "  --java      Compile to Java\n"
        liftIO (printf arg0)
      _ <- do
        arg0 <- pure "  --perl      Compile to Perl\n"
        liftIO (printf arg0)
      _ <- do
        arg0 <- pure "  --tree      Compile to an s-expression tree\n"
        liftIO (printf arg0)
      _ <- do
        arg0 <- pure "  --node      Compile to Node.js\n"
        liftIO (printf arg0)
      _ <- do
        arg0 <- pure "  --node2      Compile to Node.js, new outputter\n"
        liftIO (printf arg0)
      _ <- do
        arg0 <- pure "  --haskell, --hs Compile to Haskell\n"
        liftIO (printf arg0)
      _ <- do
        arg0 <- pure "  --ansi3     Compile to ANSI C (quon version 3)\n"
        liftIO (printf arg0)
      _ <- do
        arg0 <- pure "  --trace     Trace execution\n"
        liftIO (printf arg0)
      _ <- do
        arg0 <- pure "  --steptrace Step trace execution\n"
        liftIO (printf arg0)
      _ <- do
        arg0 <- pure 0
        liftIO (exit arg0)
      pure ()
    else do
      pure ()
  hcond <- liftIO (readIORef runTests)
  if hcond
    then do
      _ <- liftIO test0
      _ <- liftIO test1
      _ <- liftIO test2
      _ <- liftIO test3
      _ <- liftIO test4
      _ <- liftIO test5
      _ <- liftIO test6
      _ <- liftIO test7
      _ <- liftIO test8
      _ <- liftIO test9
      _ <- liftIO test10
      _ <- liftIO test12
      _ <- liftIO test13
      _ <- liftIO test14
      _ <- liftIO test15
      _ <- liftIO test16
      _ <- liftIO test17
      _ <- liftIO test18
      _ <- liftIO test19
      _ <- liftIO test20
      _ <- liftIO test21
      _ <- liftIO test22
      _ <- liftIO test23
      _ <- liftIO test24
      _ <- liftIO test25
      _ <- liftIO test27
      _ <- liftIO test28
      _ <- do
        arg0 <- pure "\n\nAfter all that hard work, I need a beer...\n"
        liftIO (printf arg0)
      _ <- do
        arg0 <- pure 9
        liftIO (beers arg0)
      pure ()
    else do
      hcond <- liftIO (readIORef runTree)
      if hcond
        then do
          _ <- do
            arg0 <- do
              arg0 <- do
                arg0 <- liftIO (readIORef filename)
                liftIO (loadQuon arg0)
              liftIO (macrowalk arg0)
            liftIO (display arg0)
          pure ()
        else do
          hcond <- do
            arg0 <- liftIO (readIORef runNode)
            arg1 <- liftIO (readIORef runNode2)
            liftIO (orBool arg0 arg1)
          if hcond
            then do
              _ <- do
                arg0 <- liftIO (readIORef filename)
                liftIO (node2Compile arg0)
              _ <- do
                arg0 <- pure "\n"
                liftIO (printf arg0)
              pure ()
            else do
              hcond <- liftIO (readIORef runHaskell)
              if hcond
                then do
                  _ <- do
                    arg0 <- liftIO (readIORef filename)
                    liftIO (haskellCompile arg0)
                  _ <- do
                    arg0 <- pure "\n"
                    liftIO (printf arg0)
                  pure ()
                else do
                  hcond <- liftIO (readIORef runPerl)
                  if hcond
                    then do
                      _ <- do
                        arg0 <- liftIO (readIORef filename)
                        liftIO (perlCompile arg0)
                      _ <- do
                        arg0 <- pure "\n"
                        liftIO (printf arg0)
                      pure ()
                    else do
                      hcond <- liftIO (readIORef runJava)
                      if hcond
                        then do
                          _ <- do
                            arg0 <- liftIO (readIORef filename)
                            liftIO (javaCompile arg0)
                          _ <- do
                            arg0 <- pure "\n"
                            liftIO (printf arg0)
                          pure ()
                        else do
                          hcond <- liftIO (readIORef runAnsi3)
                          if hcond
                            then do
                              _ <- do
                                arg0 <- liftIO (readIORef filename)
                                liftIO (ansi3Compile arg0)
                              _ <- do
                                arg0 <- pure "\n"
                                liftIO (printf arg0)
                              pure ()
                            else do
                              _ <- do
                                arg0 <- liftIO (readIORef filename)
                                liftIO (ansi3Compile arg0)
                              _ <- do
                                arg0 <- pure "\n"
                                liftIO (printf arg0)
                              pure ()
                          pure ()
                      pure ()
                  pure ()
              pure ()
          pure ()
      pure ()
  hret <- pure 0
  qreturn hret
  pure 0

main :: IO ()
main = do
  args <- getArgs
  let qargs = "fixmeprogname" : args
  writeIORef globalArgs qargs
  writeIORef globalArgsCount (length qargs)
  _ <- start
  pure ()


