/* 
* 1.9 Print the longest line
* read a set of text lines
* and print the longest line
*/
#include <stdio.h>

#define MAXLINE 1000  //maximum input line size

// getline function conflicts with getline in stdio.h header file
// so rename to getlin
int getlin(char* s, int lim);//read a line into s, return length
void copy(char* to, char* from); // copy array

int main() {
    int len; // current line length
    int max; // max len
    char line[MAXLINE];
    char longest[MAXLINE];//longest line saved
    
    max = 0;
    while((len = getlin(line, MAXLINE)) > 0){
        if(len > max){
            max = len;
            copy(longest, line);
        }
    }//END while
    if(max > 0)
        printf("%s", longest);
    return 0;
}

int getlin(char* s, int lim){
    int c, i;
    for(i=0; i < lim -1 &&(c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if(c == '\n'){
        s[i] = '\n';
        i++;
    }
    s[i] = '\0';
    return i;
}

void copy(char* to, char* from){
    int i = 0;
    while((to[i] = from[i]) != '\0')
        i++;
}

