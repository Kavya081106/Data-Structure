#include <stdio.h>

void main(){
    char c;
    printf("Enter character \n");
    scanf("%c", &c);
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
        printf("Character is a vowel");
    }else{
        printf("Character is a consonant");
    }
}