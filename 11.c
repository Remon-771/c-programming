#include <stdio.h>

char keywords[][10] = {"int", "if", "while", "return", "for", "else"};
int keywordcount = 6;

int isletter(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int isdigit(char c) {
    return (c >= '0' && c <= '9');
}

int isunderscore(char c) {
    return (c == '_');
}

int stringequal(char a[], char b[]) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i])
            return 0;
        i++;
    }
    return (a[i] == '\0' && b[i] == '\0');
}

int iskeyword(char str[]) {
    int i;
    for (i = 0; i < keywordcount; i++) {
        if (stringequal(str, keywords[i]))
            return 1;
    }
    return 0;
}

int isvalid(char str[]) {
    int i = 0;

    if (str[0] == '\0') // empty string
        return 0;

    // first character must be letter or underscore
    if (!(isletter(str[0]) || isunderscore(str[0])))
        return 0;

    // check rest characters
    for (i = 1; str[i] != '\0'; i++) {
        if (!(isletter(str[i]) || isdigit(str[i]) || isunderscore(str[i])))
            return 0;
    }

    // not a keyword
    if (iskeyword(str))
        return 0;

    return 1;
}

int main() {
    char input[1000];

    while (1) {
        printf("Enter string = ");
        gets(input); // unsafe, but used as per your request

        if (input[0] == '\0') // stop if empty
            break;

        if (isvalid(input)) {
            printf("%s is a valid identifier\n", input);
        } else {
            printf("%s is NOT a valid identifier\n", input);
        }
    }
    return 0;
}
