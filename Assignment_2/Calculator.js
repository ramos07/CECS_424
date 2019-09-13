var input = process.argv.slice(2).join(' ');

var expr = input.split(' ', 5);
var int1 = parseInt(expr[0], 10);
var operand = expr[1];
var int2 = parseInt(expr[2], 10);
var out;

if(operand == "+") {
  out = int1 + int2;
}else if(operand == "-") {
  out = int1 - int2;
}else if(operand == "*") {
  out = int1 * int2;
}else {
  out = int1 / int2;
}

console.log(input + " = " + out.toString(10));
