/*
* Exercise 1-22
* similar to word wrap with limited columns
* Fold long input lines into 2 or more shorter lines
* line limit is n columns
* the break/folding point is after the last nonblank char before line limit n
*/
#include <stdio.h>

/*
* declaration
*/
#define MAXCOL 10 // maximum columns of line input
#define TAB    8  // tab is 8 spaces
char line[MAXCOL]; // store input into line
int exptab(int pos); // expand tab into spaces
int findblank(int pos); // find the blank position before line limit
int newpos(int pos); // update new position
void printl(int pos); // print line until pos column

int main() {
    int c, pos;
    
    pos = 0;// position in the line
    while((c = getchar()) != EOF){
        line[pos] = c;
        if(c == '\t')
            pos = exptab(pos); 
        else if(c == '\n'){
            printl(pos); // print this current line
            pos = 0;
        }else if(++pos >= MAXCOL){
            pos = findblank(pos);
            printl(pos);
            pos = newpos(pos);
        }
    }// END while

    return 0;
}

void printl(int pos){
    if(pos == 0) return;
    
    for(int i=0; i < pos; i++){
        putchar(line[i]);
    }
    putchar('\n');
}

int exptab(int pos){
    line[pos] = ' '; // update TAB to space
    for(++pos; pos < MAXCOL && pos % TAB != 0; ++pos){
        line[pos] = ' ';
    }
    if(pos == MAXCOL){
        printl(pos);
        pos = 0;
    }
    return pos;
}

int findblank(int pos){
    while(pos > 0 && line[pos] != ' ')
        --pos;
    if(pos == 0)
        return MAXCOL;
    else
        return pos+1;
}

int newpos(int pos){
    int i, j;
    if(pos <= 0 || pos >= MAXCOL)
        return 0; // start from beginning
    else{
        i = 0;
        for(j=pos; j < MAXCOL; j++){
            line[i] = line[j]; // copy rest of the input to line array
            i++;
        }
        return i; // new position in line
    }
    
}


















