int atoi(char * s); // convert s to integer

int main() {
    char s[] = "123458";

    int ans = atoi(s);
    printf("%s %d", s, ans);

    return 0;
}

int atoi(char* s){
    int n = 0;
    for(int i=0; s[i] >= '0' && s[i] <= '9'; i++){
        n =  10*n + (s[i] - '0');
    }
    return n;
}
