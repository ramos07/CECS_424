import sys

args  = str(sys.argv[1])

args_split = args.split()

int1 = int(args_split[0])
int2 = int(args_split[2])
operand = args_split[1]

if operand == "+":
    out = int1 + int2
elif operand == "-":
    out = int1 - int2
elif operand == "*":
    out = int1 * int2
elif operand == "/":
    out = int1 / int2

print(args + " = " + str(out))
