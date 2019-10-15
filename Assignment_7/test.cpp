#include <iostream>

using namespace std;

void f(int x, int y, int z){
    cout<<"IN FUNCTION..."<<endl;
    cout<<"Values before procedures"<<endl;
    cout<<"x = "<< x <<endl;
    cout<<"y = "<< y <<endl;
    cout<<"z = "<< z <<endl;

    x++;
    y = z;
    z++;

    cout<<"Values after procedure"<<endl;
    cout<<"x = "<< x <<endl;
    cout<<"y = "<< y <<endl;
    cout<<"z = "<< z <<endl;
    cout<<"BACK TO MAIN...."<<endl;
}

int main(){

    int i = 1;
    int a[3] = {0, 10, 11};


    cout<<"i = "<< i <<endl;
    cout<<"a[1] = "<< a[1] <<endl;
    cout<<"a[2] = "<< a[2] <<endl;

    f(i, a[i], i);

    cout<<"i = "<< i <<endl;
    cout<<"a[1] = "<< a[1] <<endl;
    cout<<"a[2] = "<< a[2] <<endl;

    return 0;
}

