#include <stdio.h>

int main() {
    char str[100];
    char ch;
    int i = 0;

    printf("Enter a string (press Enter to finish):\n");

    // Read characters until newline is pressed
    while(1) {
        scanf("%c", &ch);

        if(ch == '\n') {
            break;
        }

        // Convert lowercase to uppercase
        if(ch >= 'a' && ch <= 'z') {
            str[i] = ch - 32;
        }
        // Convert uppercase to lowercase
        else if(ch >= 'A' && ch <= 'Z') {
            str[i] = ch + 32;
        }
        // Leave other characters unchanged
        else {
            str[i] = ch;
        }

        i++;
    }

    str[i] = '\0';  // Null-terminate the string

    printf("Modified string: %s\n", str);

    return 0;
}
