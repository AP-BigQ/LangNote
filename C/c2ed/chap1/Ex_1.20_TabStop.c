/* 
* Exercise 1.20 detab
* replace tabs with blanks to space to next tab stop
* 
*/

#include <stdio.h>

#define TAB   8

int main() {
    int c, nb, pos;
    
    nb = 0;
    pos = 1;
    while((c = getchar()) != EOF){
        if(c == '\t'){
            nb = TAB - (pos - 1) % TAB;
            while(nb > 0){
                putchar(' ');
                ++pos;
                --nb;
            }
        }else {
            if(c == '\n'){
                putchar(c);
                pos = 1;
            }else{
                putchar(c);
                ++pos;
            }
        }
    }//END while
    
    return 0;
}























