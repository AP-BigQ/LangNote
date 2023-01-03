/* 
* 1.5.4 Word Counting
* bare-bones version of UNIX program wc
* count lines, words, and chars in input
*/
#include <stdio.h>

#define IN  1 //inside a word
#define OUT 0 // outside a word

int main() {
    int c;
    int nl, nw, nc;
    int state = OUT;
    
    nl = nw = nc = 0;
    while((c = getchar()) != EOF){
        ++nc;
        if(c == '\n')
            ++nl;
        if(c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if(state == OUT){
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
    

    return 0;
}
