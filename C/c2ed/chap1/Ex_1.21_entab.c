/*
* Exercise 1-21 entab
* replace strings of blanks by min number of tabs and blanks
* to achieve the same spacing
*/
#include <stdio.h>

#define TAB  8 

// ' ' '\t' '\n' 'char'
// space, tab, newline, char
// 4 types
int main() {
    int c, nb, nt, pos;
    
    nb = 0;
    nt = 0;
    for(pos = 1; (c = getchar()) != EOF; ++pos){
        if(c == ' '){
            if(pos % TAB != 0)
                ++nb;
            else{
                nb = 0;
                ++nt;
            }
        }else{
            for(; nt > 0; --nt)
                putchar('\t');
            if(c == '\t')
                nb = 0;
            else
                for(; nb > 0; --nb)
                    putchar(' ');
            putchar(c);
            if(c == '\n')
                pos = 0;
            else if(c == '\t')
                pos += TAB - (pos - 1) % TAB;
                pos -= 1; //cancel/offset for loop ++pos
        }
    }

    return 0;
}
