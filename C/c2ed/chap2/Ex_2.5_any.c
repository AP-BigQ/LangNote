
/* 
* Exercise 2-5 any(s1, s2)
* return 1st location of s1 where any char in s2 occurs, otherwise -1
* 
*/

#include <stdio.h>

int any(char * s1, char *s2);

int main() {
    char *p = "worldbeautiful";
    char *q = "abcdefg";
    printf("%s has a char of %s in location %d", p, q, any(p, q));

    return 0;
}

int any(char *s1, char *s2){
    int i, j;
    
    for(i = 0; s1[i] != '\0'; i++){
        for(j = 0; s2[j] != '\0'; j++){
            if(s1[i] == s2[j])
                return i;
        }
    }
    
    return -1;
}
