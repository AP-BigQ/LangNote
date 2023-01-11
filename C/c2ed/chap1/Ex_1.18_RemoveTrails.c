/* 
* Exercise 1.18
* Remove trailing blanks, tabs in each line
* delete entirely blank lines
*/

/*
* IN ORDER TO USE Local Functions here.
*/
#define _LIB
#define getline getline_lib
#define remove remove_lib
#include <stdio.h>
#undef remove
#undef getline
#undef _LIB


#define MAXLINE 1000 // max length of input line 

int getline(char line[], int maxline);
int remove(char *s);//remove trailing blanks,tabs

int main() {
    char line[MAXLINE];
    
    while(getline(line, MAXLINE) > 0){
        if(remove(line) > 0)
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

int remove(char *s){
    int i;
    
    i = 0;
    while(s[i] != '\n')
        i++;
    --i; // back off from \n
    while(i >= 0 && (s[i] == ' ' || s[i] == '\t'))
        --i;
    if(i >= 0){
        ++i;
        s[i] = '\n';
        ++i;
        s[i] = '\0';
    }
    return i;
}



















