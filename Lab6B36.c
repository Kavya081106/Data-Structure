#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i = 0, countA = 0, countB = 0;
    
    printf("Enter the string: ");
    scanf("%s", str);

    while (str[i] == 'a') {
        countA++;
        i++;
    }

    while (str[i] == 'b') {
        countB++;
        i++;
    }

    if (str[i] == '\0' && countA >= 1 && countA == countB) {
        printf("VALID STRING: of the form a^i b^i\n");
    } else {
        printf("INVALID STRING\n");
    }

    return 0;
}
