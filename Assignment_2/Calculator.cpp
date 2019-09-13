#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char** argv)
{
  string input = "";
  for(int i=1; i < argc; i++){
    input = input + argv[i];
  }
  cout<< input; //This is my CL input as a string
  string strArr[2];
  int i=0;
  stringstream ssin(input);
  while(ssin.good() && i < 3){
    ssin >> strArr[i];
    i++;
  }
  int int1;
  int int2;
  string operand;
  int out;
  for(i = 0; i < 3; i++){
    int1 = stoi(strArr[0]);
    operand = strArr[1];
    int2 = stoi(strArr[2]);
  }
  if(operand == "+"){
    out = int1 + int2;
    cout<<" = " << out << endl;
  }
  else if(operand == "-"){
    out = int1 - int2;
    cout<<" = " << out << endl;
  }
  else if(operand == "*"){
    out = int1 * int2;
    cout<<" = " << out << endl;
  }
  else if(operand == "/"){
    out = int1 / int2;
    cout<<" = " << out << endl;
  }
  return 0;
}
