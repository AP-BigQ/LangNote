/* 
* Exercise 1-23
* Remove comments of a C program
* 
*/
#include <stdio.h>

void rcomment(int c);
void in_comment(int c);
void echo_quote(int c);

int main() {
    int c;
    while((c = getchar()) != EOF)
        rcomment(c);
    
    return 0;
}

void rcomment(int c){
    int d;
    
    if(c == '/'){
        if((d = getchar()) == '*' || d == '/')
            in_comment(d);
        else{
            putchar(c);
            putchar(d);
        }
    } else if(c == '\'' || c == '"')
        echo_quote(c);
    else
        putchar(c);
}

void in_comment(int c){
    if(c == '*'){
        int d1, d2;
        
        d1 = getchar();
        d2 = getchar();
        while(!(d1 == '*' && d2 == '/')){
            d1 = d2;
            d2 = getchar();
        }
    }else if(c == '/'){
        while((c = getchar()) != '\n')
            ;
        putchar(c);
    }

}

void echo_quote(int c){
    int d;
    
    putchar(c);
    while((d = getchar()) != c){
        putchar(d);
        if(d == '\\')
            putchar(getchar());
    }
    putchar(d);
}
























