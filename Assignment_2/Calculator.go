package main

import (
  "fmt"
  "strconv" //used to convert string into integer
  "log" //used for conversion
)

func main() {

  fmt.Println("Enter an expression: ")
  var input string
  fmt.Scan(&input)

  inputSlice := []rune(input) //Converting the given string into a slice

  int1 := string(inputSlice[0]) //Taking the first element in the slice
  operand := string(inputSlice[1]) //Taking the second element in the slice
  int2 := string(inputSlice[2]) //Taking the third element in the slice

  //Converting the strings to integrs
  integer1, err := strconv.Atoi(int1)
  if(err != nil) {
    log.Fatal(err)
  }
  integer2, err := strconv.Atoi(int2)
  if(err != nil) {
    log.Fatal(err)
  }

  /*If and else statements to determine what operand to
  perform on the given intergers and then perform that operation*/
  var result int
  if(operand == "+"){
    result = integer1 + integer2
    fmt.Println(result)
  }else if (operand == "-"){
    result = integer1 - integer2
    fmt.Println(result)
  }else if(operand == "*"){
    result = integer1*integer2
    fmt.Println(result)
  }else{
    result = integer1/integer2
    fmt.Println(result)
  }

}
