#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// Function to sort characters of a string
void sortString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

// Function to check if two strings are anagrams
int isAnagram(char* str1, char* str2) {
    // Check if lengths are the same
    if (strlen(str1) != strlen(str2))
        return 0;

    char temp1[50], temp2[50];
    strcpy(temp1, str1);
    strcpy(temp2, str2);

    // Convert to uppercase or lowercase to make comparison case-insensitive
    for (int i = 0; temp1[i]; i++) temp1[i] = tolower(temp1[i]);
    for (int i = 0; temp2[i]; i++) temp2[i] = tolower(temp2[i]);

    sortString(temp1);
    sortString(temp2);

    return strcmp(temp1, temp2) == 0;
}

int main() {
    int n;
    char words[50][50];

    printf("Enter number of words: ");
    scanf("%d", &n);

    // Input words
    printf("Enter %d words:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    // Seed the random number generator
    srand(time(NULL));
    int randomIndex = rand() % n;

    // Display the selected word
    printf("\nYour word is: %s\n", words[randomIndex]);

    // Input from user
    char userWord[50];
    printf("Enter an anagram of the word above: ");
    scanf("%s", userWord);

    // Check and display result
    if (isAnagram(words[randomIndex], userWord)) {
        printf("Correct! It is an anagram.\n");
    } else {
        printf("Incorrect. That is not an anagram.\n");
    }

    return 0;
}
