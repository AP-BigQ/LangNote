/* 
* Exercise 1.16
* print longest line as much as possible of the text
* 
*/
#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000 // max length of input line 

int getlin(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];
    
    max = 0;
    while((len = getlin(line, MAXLINE)) > 0){
        printf("%d, %s", len, line);
        if(len > max){
            max = len;
            copy(longest, line);
        }
    }
    if(max > 0)
        printf("%s", longest);
        
    return 0;
}

int getlin(char s[], int lim){
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

void copy(char *to, char *from){
    int i;
    
    i = 0;
    while((to[i] = from[i]) != '\0')
        i++;
}




















