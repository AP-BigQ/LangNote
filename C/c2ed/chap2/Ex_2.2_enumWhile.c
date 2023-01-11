/* 
* Exercise 2-2
* Using enum and while to replace for loop
* 
*/
#include <stdio.h>
/*
for(i = 0; i < lim -1 &&(c = getchar()) != '\n' && c != EOF; ++i)
    s[i] = c;
*/
#define LIM  1000
int main() {
    int i, c;
    char s[LIM];
    enum loop {NO, YES} okloop;
    okloop = YES;
    i = 0;
    
    while(okloop == YES){
        if(i >= LIM - 1)
            okloop = NO;
        else if((c = getchar()) == '\n')
            okloop = NO;
        else if(c == EOF)
            okloop = NO;
        else{
            s[i] = c;
            ++i;
        }
    }
    
    printf("%s", s);

    return 0;
}
