package main

import (
  "fmt"
  "os"
  "strconv"
  "log"
  "strings"
)

func main() {

  input := strings.Split(os.Args[1], " ")


  int1 := input[0]
  operand := input[1]
  int2 := input[2]

  integer1, err := strconv.Atoi(int1)
  if(err != nil) {
    log.Fatal(err)
  }
  integer2, err := strconv.Atoi(int2)
  if(err != nil) {
    log.Fatal(err)
  }

  var result int
  if(operand == "+"){
    result = integer1 + integer2
  }else if (operand == "-"){
    result = integer1 - integer2
  }else if(operand == "*"){
    result = integer1*integer2
  }else{
    result = integer1/integer2
  }

  fmt.Print(os.Args[1])
  fmt.Print(" = ")
  fmt.Print(result)

}
