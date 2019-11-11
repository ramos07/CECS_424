#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

int main(int argc , char** argv){

    string input = ""; //String to hold our CL arguments

    //Set our CL arguments inside the input String variable
    for(int i=1; i < argc; i++)
    {
        input =  input + argv[i];
    }

    //Get the rows and columns as chars then set as string 
    string row1(1, input[0]); 
    string col1(1, input[1]);
    string row2(1, input[2]);
    string col2(1, input[3]);

    //Convert each row and column from string to int
    int r1 = stoi(row1);
    int c1 = stoi(col1);
    int r2 = stoi(row2);
    int c2 = stoi(col2);

    //Creating matrix1 using pointers
    int** matrix1;

    matrix1 = new int*[r1];

    for(int i=0; i < r1; i++)
    {
        matrix1[i] = new int[c1]; 
    }

    for(int i=0; i < r1; i++)
    {
        for(int j=0; j < c1; j++)
        {
            matrix1[i][j] = (i * c1 + j) + 1;
        }
    }

    cout<<"Matrix 1"<<endl;
    for(int i=0; i < r1; i++)
    {
        for(int j=0; j < c1; j++)
        {
            cout<< *(*(matrix1 + i) + j)<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    //Creating matrix2
    int** matrix2;

    matrix2 = new int*[r2];

    for(int i = 0; i < r2; i++)
    {
        matrix2[i] = new int[c2];
    }

     for(int i=0; i < r2; i++)
    {
        for(int j=0; j < c2; j++)
        {
             matrix2[i][j] =  ((r2 - i)  * c2) - j;
        }
    }

    cout<<"Matrix 2"<<endl;
    for(int i=0; i < r2; i++)
    {
        for(int j=0; j < c2; j++)
        {
            cout<< *(*(matrix2 + i) + j)<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    //Product matrix
    int** matrix3;

    matrix3 = new int*[r1];

    for(int i = 0; i < r1; i++)
    {
        matrix3[i] = new int[c2];
    }

    for(int i=0; i < r1; i++)
    {
        for(int j=0; j < c2; j++)
        {
             matrix3[i][j] = 0;
            for(int k=0; k < c1; k++)
            {
                 matrix3[i][j] += (matrix2[k][j] * matrix1[i][k]);
            }
        }
    }

    cout<<"Matrix 1  * Matrix 2"<<endl;
    for(int i=0; i < r1; i++)
    {
        for(int j=0; j < c2; j++)
        {
            cout<< *(*(matrix3 + i) + j)<<" ";
        }
        cout<<endl;
    }






    return 0;
}