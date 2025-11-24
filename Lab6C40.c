#include <stdio.h>
#include <string.h>

void reverseString(char str[], int n) {
    int i = 0, j = n - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int main() {
    int T, len_str;
    printf("Enter number of test cases: ");
    scanf("%d", &T);
    for (int t = 1; t <= T; t++){
        char str[100];
        printf("Enter the length of the string : ");
        scanf("%d", &len_str);
        printf("Enter string %d: ", t);
        scanf("%s", str);
        printf("Original: %s\n", str);
        for (int i = 0; i < strlen(str); i++){
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
                reverseString(str, i);
            }
        }
        printf("After conversion: %s\n\n", str);
    }

    return 0;
}
