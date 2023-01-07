/* 
* Exercise 1.13
* histogram of lengths of words in input
* horizontal bar chart
*/
#include <stdio.h>

#define IN 1  //inside a word
#define OUT 0 // outside a word
#define MAXHIST 15 // max length of histogram
#define MAXWORD 11  // max length of a word

int main() {
    int c, i, nc, state;
    int len; //length of each bar
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
    
    for(i=1; i < MAXWORD; i++){
        printf("%5d - %5d : ", i, wl[i]);
        if(wl[i] > 0){
            if((len = wl[i]*MAXHIST/maxvalue) <= 0)
                len = 1;
        }else
            len = 0;
        while(len > 0){
            putchar('*');
            --len;
        }
        putchar('\n');
    }//END for
    
    if(ovflow > 0)
        printf("%d words' length >= %d\n", ovflow, MAXWORD);
    return 0;
}






















