#include <stdio.h>

int main() {
    char input[1024];
    char result[4096];
    int i, j, k;
    int in_single_line = 0, in_multi_line = 0;

    printf("Enter text. Press enter on blank line to exit.\n");

    j = 0;

    while (1) {
        // First read a line
        if (scanf("%[^\n]", input) != 1) {
            // If no input read (empty line), break
            break;
        }

        getchar(); // consume the newline character after input

        // Append newline manually since scanf doesn't include it
        int len = 0;
        while (input[len] != '\0') len++;
        input[len] = '\n';
        input[len + 1] = '\0';

        // Process this line character by character
        i = 0;
        while (input[i] != '\0') {
            if (input[i] == '/' && input[i + 1] == '/' && !in_multi_line) {
                in_single_line = 1;
                i += 2;
                continue;
            }
            if (input[i] == '/' && input[i + 1] == '*' && !in_single_line) {
                in_multi_line = 1;
                i += 2;
                continue;
            }
            if (in_single_line && input[i] == '\n') {
                in_single_line = 0;
                result[j++] = '\n';
                i++;
                continue;
            }
            if (in_multi_line && input[i] == '*' && input[i + 1] == '/') {
                in_multi_line = 0;
                i += 2;
                continue;
            }
            if (!in_single_line && !in_multi_line) {
                result[j++] = input[i++];
            } else {
                i++;
            }
        }
    }

    result[j] = '\0';

    printf("\nCleaned code:\n%s", result);

    return 0;
}

