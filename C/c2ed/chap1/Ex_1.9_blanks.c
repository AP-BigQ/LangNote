/* Exercise 1-9
* copy input to output
* replace 1 or more blanks by a single blank
*/
#include <stdio.h>

/*
* 
*/
int main() {
    int c, lastc = -1;
    while((c = getchar()) != EOF){
        if(c != ' ')
            putchar(c);
        if(c == ' '){
            if(lastc != ' ')
                putchar(c);
        }
        lastc = c;
    }
    return 0;
}
