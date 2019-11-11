import sys
import re

#Take the arguments from the command line
args = str(sys.argv[1])

#Split the string arguments into a list called args_split
args_split = args.split()

#Create a stack and iniitate with a placeholder
#value to not get the IndexOut of error 
stack = ['0'] 

#Boolean function where a value is passed in
#returns true if the value is an operator 
#returns false if the value is a digit
def isOperator(value):
    if value == "+" or value == "-":
        return True
    if value == "*" or value == "/":
        return True
    
    return False 

#Iterate throught the prefixed expression in the args_split list
for i in reversed(args_split):

    #If the value is NOT an operator then it is a digit therfore append to stack
    if isOperator(i) == False:
        stack.append(i)
    
    #If the value IS an operator then pop() two digits 
    #from the stack and create expression along with the 
    #detected operator symbol
    if isOperator(i) == True: 
        digit1 = stack.pop()
        digit2 = stack.pop()

        expr = "(" + digit1 + " " + i + " " + digit2 + ")"

        stack.append(expr) #Append the expression into the stack

expression = stack[1]
result = eval(stack[1])

print(expression + " = " + str(result))