/*
* 1.6 Arrays
* count digits, white space, others
*/
#include <stdio.h>

int main() {
    int c, i, nwhite, nothers;
    int ndigits[10];
    nwhite = nothers = 0;
    for(i=0; i < sizeof(ndigits)/sizeof(int); i++){
        ndigits[i] = 0;
    }
    
    while((c = getchar()) != EOF){
        if(c >= '0' && c <= '9'){
            ndigits[c - '0']++;
        }else if(c == ' ' || c == '\t' || c == '\n')
            nwhite++;
        else
            nothers++;
    } // END while
    
    printf("digits = ");
    for(i=0; i < sizeof(ndigits)/sizeof(int); i++){
        printf(" %d", ndigits[i]);
    }
    printf(", white space = %d, others = %d\n", nwhite, nothers);
    

    return 0;
}
