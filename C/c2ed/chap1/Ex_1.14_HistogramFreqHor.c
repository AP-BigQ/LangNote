/* 
* Exercise 1.14
* histogram of freq. of diff. chars in input
* horizontal bar chart
*/
#include <stdio.h>
#include <ctype.h>

#define MAXHIST 15 // max length of histogram
#define MAXCHAR 128  // max diff. chars

int main() {
    int c, i;
    int len; // lenght of each bar
    int maxvalue;
    int cc[MAXCHAR]; // char counters
    
    for(i=0; i < MAXCHAR; i++)
        cc[i] = 0;
    
    while((c = getchar()) != EOF){
        if(c < MAXCHAR)
            cc[c]++;
    }//END while
    
    maxvalue = 0;
    for(i=1; i < MAXCHAR; i++){
        if(cc[i] > maxvalue)
            maxvalue = cc[i];
    }
    
    for(i=1; i < MAXCHAR; i++){
        if(isprint(i))
            printf("%5d - %c - %5d : ", i, i, cc[i]);
        else
            printf("%5d -    - %5d : ", i, cc[i]);
        if(cc[i] > 0){
            if((len = cc[i]*MAXHIST / maxvalue) <= 0)
                len = 1;
        }else
            len = 0;
        while(len > 0){
            putchar('*');
            --len;
        }
        putchar('\n');
    }
}

