/* 
* Exercise 1.13
* histogram of lengths of words in input
* Vertical bar chart
*/
#include <stdio.h>

#define IN 1  //inside a word
#define OUT 0 // outside a word
#define MAXHIST 15 // max length of histogram
#define MAXWORD 11  // max length of a word

int main() {
    int c, i, j, nc, state;

    int maxvalue; // max value for wl[]
    int ovflow; // number of overflow words
    int wl[MAXWORD]; // word length counters
    
    state = OUT;
    nc = 0;
    ovflow = 0;
    for(i=0; i < MAXWORD; i++)
        wl[i] = 0;
    
    while((c = getchar()) != EOF){
        if(c ==' ' || c == '\n' || c == '\t'){
            if(nc > 0){
                if(nc < MAXWORD)
                    ++wl[nc];
                else
                    ++ovflow;
                
            }
            nc = 0;
            state = OUT;
        }else{
            if(state == OUT){
                nc = 1;
                state = IN;
            }else{
                ++nc;
            }
        }
    }//END while

    maxvalue = 0;
    for(i=1; i < MAXWORD; i++){
        if(wl[i] > maxvalue)
            maxvalue = wl[i];
    }
    
    for(i=MAXHIST; i > 0; i--){
        for(j=1; j < MAXWORD; j++){
            if(wl[j]*MAXHIST / maxvalue >= i)
                printf("  *  ");
            else
                printf("     ");
        }
        putchar('\n');
    }//END for
    
    for(i=1; i < MAXWORD; i++)
        printf("%4d ", i);
    putchar('\n');
    for(i=1; i < MAXWORD; i++)
        printf("%4d ", wl[i]);
    putchar('\n');
    
    if(ovflow > 0)
        printf("%d words' length >= %d\n", ovflow, MAXWORD);
    return 0;
}

























