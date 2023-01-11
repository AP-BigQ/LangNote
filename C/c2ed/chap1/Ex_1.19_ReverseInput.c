/* 
* Exercise 1.19
* Reverse string s
* Reverse input a line at a time
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

int getline(char line[], int maxline);
void reverse(char *s); // reverse chars in s

int main() {
    char line[MAXLINE];
    
    while(getline(line, MAXLINE) > 0){
        reverse(line);
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

void reverse(char *s){
    int i, j;
    char tmp;
    
    i = 0;
    while(s[i] != '\0')
        i++;
    --i;
    if(s[i] == '\n')
        --i;
    j = 0;
    while(j < i){
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        --i;
        ++j;
    }
}




















