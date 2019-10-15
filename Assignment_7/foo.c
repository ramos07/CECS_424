#include <stdio.h>

void foo(int x){
    int i = x;
    printf("%d", i++);
}

int main(){

    int j;
    
    for(j=1; j <= 10; j++){
        foo(j);    }

    return 0;
}