#include <stdio.h>
/*
* check a C program for syntax errors 
* like unbalanced parentheses, brackets, braces
* quotes(single and double)
* comments
*/

/*
* declaration
*/
int brace, brack, paren;
void in_quote(int c);
void in_comments(int c);
void search(int c); /*search unbalanced pairs of {}[]()*/

/*syntax checker for C program*/
int main() {
    int c;
    extern int brace, brack, paren;
    
    while((c = getchar()) != EOF){
        if(c == '/'){
            if((c = getchar()) == '*' || c == '/')
                in_comments(c); /* inside comment */
            else
                search(c);
        }else if(c == '\'' || c == '"')
                in_quote(c); /*inside quote*/
        else
            search(c);
            
        /*check scenarios like: ][ )( }{ 
        * to complement search function
        */
        if(brace < 0){
            printf("Unbalanced braces\n");
            brace = 0;
        }else if(brack < 0){
            printf("Unbalanced brackets\n");
            brack = 0;            
        }else if(paren < 0){
            printf("Unbalanced parentheses\n");
            paren = 0;
        }
        
    } // END while
    
    if(brace > 0)
        printf("Unbalanced braces\n");
    if(brack > 0)
        printf("Unbalanced brackets\n");
    if(paren > 0)
        printf("Unbalanced parenthesis\n");
    
    printf("Success on syntax checks.\n");
    return 0;
}
void in_comments(int c){
    if(c == '/'){
        int d;
        while((d = getchar()) != '\n')
            ;
    }else if(c == '*'){
        int p, n;
    
        p = getchar(); // prev char
        n = getchar(); // next char
        while(!(p == '*' && n == '/')){
            p = n;
            n = getchar();
        }
    }

}
void in_quote(int c){
    int d;
    while((d = getchar()) != c){
        if(d == '\\')
            getchar(); /* ignore escape sequence \ */
    }
}
void search(int c){
    extern int brace, brack, paren;
    
    if(c == '{')
        ++brace;
    else if(c == '}')
        --brace;
    else if(c == '[')
        ++brack;
    else if(c == ']')
        --brack;
    else if(c == '(')
        ++paren;
    else if(c == ')')
        --paren;
}

