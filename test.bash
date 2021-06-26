#!/bin/bash

my_function () {
  local func_result="some result in f1: $1 <<< f1"
  echo "$func_result"
}

my_function2 () {
  local func_result="some result 2 $1"
  echo "$func_result"
}
func_result="$(my_function2 $(my_function lalala))"
echo $func_result
