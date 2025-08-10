#include <stdio.h>

int main() {
    char str[1000];
    int i = 0;
    int has_a = 0, has_b = 0;

    printf("Enter a string to check: ");
    scanf("%s", str);

    // Check characters and presence of a and b
    while (str[i] != '\0') {
        if (str[i] != 'a' && str[i] != 'b') {
            printf("'%s' DOES NOT MATCH the regular expression.\n", str);
            return 0;
        }
        if (str[i] == 'a') has_a = 1;
        if (str[i] == 'b') has_b = 1;
        i++;
    }

    if (has_a && has_b) {
        printf("'%s' MATCHES the regular expression.\n", str);
    } else {
        printf("'%s' DOES NOT MATCH the regular expression.\n", str);
    }

    return 0;
}

