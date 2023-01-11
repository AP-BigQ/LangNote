/* 
* Exercise 2-3 htoi()
* convert a string of hex digits into equivalent integer value
* 
*/
#include <stdio.h>
#define YES 1
#define NO 0

int htoi(char s[]);

int main() {
    char *s = "0x1aF";
    printf("%s value is %d", s, htoi(s));

    return 0;
}

int htoi(char *s){
    int hexdigit, i, inhex, val;
    
    i = 0;
    if(s[i] == '0'){
        ++i;
        if(s[i] == 'x' || s[i] == 'X')
            ++i;
    }
    
    val = 0;
    inhex = YES;
    for(; inhex == YES; ++i){
        if(s[i] >= '0' && s[i] <= '9')
            hexdigit = s[i] - '0';
        else if(s[i] >= 'a' && s[i] <= 'f')
            hexdigit = s[i] - 'a' + 10;
        else if(s[i] >= 'A' && s[i] <= 'F')
            hexdigit = s[i] - 'A' + 10;
        else
            inhex = NO;
        if(inhex == YES)
            val = 16*val + hexdigit;
    }
    
    return val;
}
