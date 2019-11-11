#include <iostream>
#include <iomanip>
#include <string>
#include <cfloat>
#include <fstream>
#include <string>
#include <bitset>
#include <limits.h>
#include <sstream>
#include <math.h>

using namespace std;

string convertFloat(float number);
/**
return the sign, exponent, and matissa of the number in '(sign,exponent,mantissa)' format.
**/

float nextFloat(float number);
/**
return the next greater number of the 'number' in the series of 32-bit floating point numbers
**/

unsigned int countBetween(float lower, float upper);
/**
return the number of 32-bit floating point numbers between lower and upper
**/

/**
 * Extra functions we added to get certain data 
 **/
int getMan(float number);
int getExp(float number);
int binaryToDecimal(string binary);

int main(int argc, char* argv[]) {
	cout << "i. Floating point number converter.\n";
	float pi = 3.14159265358979;
	cout << pi << " -> " << convertFloat(pi) << endl;

	cout << "\nii. Floating point number enumeration.\n";
	float fp = 0.0;
	unsigned int i = 0;
	while (fp < 1.4E-44) {
		cout << ++i << "th number: " << (fp = nextFloat(fp)) << endl;
	}

	cout << "\niii. Floating point number counting\n";
	unsigned int posFPs = countBetween(0.0, FLT_MAX);
	unsigned int zeroOneFPs = countBetween(0.0, 1.0);
	cout << "Number of positive floating point numbers: " << posFPs << endl;
	cout << "Number of floating point numbers between 0 and 1: " << zeroOneFPs << endl;
	cout << "Proportion (# of 0~1) / (# of positive): " << (double) zeroOneFPs / (double) posFPs * 100.0 << "%\n";

	if (argc != 2) {
		cerr << "\niv. Pass the data file name\n";
		return 0;
	}
	cout << "\niv. Floating point number distribution\n";
	ofstream datafile;
	datafile.open(argv[1]);
	float lower = 0.0, upper, interval = 100.0;
	for (int i = 0; i < 100; i++) {
		upper = lower + interval;
		datafile << countBetween(lower, upper) << endl;
		lower = upper;
	}
	datafile.close();
	cout << "The output file is ready. Execute \"Python3 Histogram.py " << argv[1] << "\"\n";
}

string convertFloat(float number) {
	union
	{
		float input;
		int output;
	}binaryData;

	binaryData.input = number; //setting out binaryData bit variable equal to our float value being passed in

	bitset<sizeof(float) * CHAR_BIT> bits(binaryData.output); //using the bitset library to get the 32 bit IEEE binary of the float value

	string numberAsBit = bits.to_string<char, char_traits<char>, allocator<char>>(); //converting the binary data as a string called numberAsBit

	string exponent = numberAsBit.substr(1, 8); //taking the exponent out of the whole binary string
	string mantissa = numberAsBit.substr(9, 31); //taking the mantissa out of the whole binary string
	char s = numberAsBit[0]; //taking the sign as a char variable out of the wole binary string
	string sign(1, s); //converting the sign char to string

	ostringstream expStr; //output string stream for the exponent
	expStr << binaryToDecimal(exponent); //sending the exponent decimal value to the out expStr output string
	string exponentString = expStr.str(); //converting the decimal value to string

	ostringstream manStr; //output string stream for the mantissa
	manStr << binaryToDecimal(mantissa); //sending the mantissa decimal value to the out manStr output string
	string mantissaString = manStr.str(); //converting the decimal value to string 

	string dataToSendOut = "(" + sign + "," + exponentString + "," + mantissaString + ")"; //concatenating all the data we need to send out 

	return dataToSendOut;
}

float nextFloat(float number)
{
	float nextNumber= number;
	nextNumber += 1.4013E-045;

	return nextNumber;
}

unsigned int countBetween(float lower, float upper)
{
	unsigned int floatCount;

	
	floatCount = (pow(2, 23) * getExp(upper)) + getMan(upper);
	cout << floatCount;
	
	return floatCount;

}

int binaryToDecimal(string binary)
{
	string num = binary; //setting the num string variable equal to the binary data string data 
	int decimalValue = 0; //decimal value being declared
	int base = 1; //initializing base value to 1 

	int len = num.length();//lenght of the binary number 

	for(int i = len - 1; i >= 0; i--)
	{
		if(num[i] == '1'){
			decimalValue += base;
		}
		base = base * 2;
	}
	
	return decimalValue;
}

int getMan(float number)
{
	union
	{
		float input;
		int output;
	}binaryData;

	binaryData.input = number; //setting out binaryData bit variable equal to our float value being passed in

	bitset<sizeof(float) * CHAR_BIT> bits(binaryData.output); //using the bitset library to get the 32 bit IEEE binary of the float value

	string numberAsBit = bits.to_string<char, char_traits<char>, allocator<char>>(); //converting the binary data as a string called numberAsBit

	string exponent = numberAsBit.substr(1, 8); //taking the exponent out of the whole binary string
	string mantissa = numberAsBit.substr(9, 31); //taking the mantissa out of the whole binary string

	return binaryToDecimal(mantissa);
}

int getExp(float number)
{
	union
	{
		float input;
		int output;
	}binaryData;

	binaryData.input = number; //setting out binaryData bit variable equal to our float value being passed in

	bitset<sizeof(float) * CHAR_BIT> bits(binaryData.output); //using the bitset library to get the 32 bit IEEE binary of the float value

	string numberAsBit = bits.to_string<char, char_traits<char>, allocator<char>>(); //converting the binary data as a string called numberAsBit

	string exponent = numberAsBit.substr(1, 8); //taking the exponent out of the whole binary string
	string mantissa = numberAsBit.substr(9, 31); //taking the mantissa out of the whole binary string

	return binaryToDecimal(exponent);
}