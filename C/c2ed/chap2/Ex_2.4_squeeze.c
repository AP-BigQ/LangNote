/* 
* Exercise 2-4 squeeze(char *, char *)
* delete chars in s1 that matches any char in s2
* s2 can be a string constant, so a char array pointer is correct
* s1 needs to be a char array! otherwise, segmentation fault
* s1 is modified
*/

#include <stdio.h>

void squeeze(char [], char []);

int main() {
    char s1[] = "abcdefgccddee";
    char *s2 = "cde";
    squeeze(s1, s2);
    printf("%s\n", s1);
    return 0;
}

void squeeze(char *s1, char *s2){
    int i, j, k;
    
    i = k = 0;
    while(s1[i] != '\0'){
        for(j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
            ;
        if(s2[j] == '\0')
            s1[k++] = s1[i];
        ++i;
    }
    s1[k] = '\0';
}























