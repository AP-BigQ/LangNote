/* 
* Exercise 1.17
* print input lines longer than 80 chars
* 
*/

/*
* IN ORDER TO USE Local Functions here.
*/
#define _LIB
#define getline getline_lib

#include <stdio.h>

#undef getline
#undef _LIB


#define MAXLINE 1000 // max length of input line 
#define LONGLINE 80

int getline(char line[], int maxline);


int main() {
    int len;
    char line[MAXLINE];
    
    while((len = getline(line, MAXLINE)) > 0){
        if(len > LONGLINE)
            printf("%s", line);
    }
    return 0;
}

int getline(char s[], int lim){
    int c, i, j;
    
    j = 0;
    for(i=0; (c = getchar()) != EOF && c != '\n'; i++){
        if(i < lim - 2){
            s[j] = c;
            j++;
        }
    }
    if(c == '\n'){
        s[j] = c;
        j++;
        i++;
    }
    s[j] = '\0';
    return i;
}





















