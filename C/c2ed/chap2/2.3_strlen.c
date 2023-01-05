int strlen(char* s); // return length of string

int main() {
    char s[] = "123458";

    int ans = strlen(s);
    printf("%s %d", s, ans);

    return 0;
}

int strlen(char *s){
    int i = 0;
    while(s[i] != '\0'){
        i++;
    }
    return i;
}

