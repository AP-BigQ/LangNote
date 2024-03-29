#include <stdio.h>
/* 
* power: raise base to n-th power;
* constraint: n >= 0
* similar to : pow(base, n)
*/
int power(int base, int n){
    int p = 1;
    for(int i=1; i <= n; ++i){
        p = p * base;
    }
    return p;
}
/*
* test power function
*/
int main() {
    for(int i=0; i < 10; ++i){
        printf("%2d %6d %6d \n", i, power(2,i), power(-3, i));
    }
    return 0;
}
