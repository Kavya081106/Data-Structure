#include <stdio.h>
#include <string.h>

char String[100];



void VowelAnxiety(char String[]){
    char temp[100];
    char stringReverse[100];
    strcpy(temp,String);
    
    int i = 0;
    while(String[i]!='\0'){
        if((String[i])=='a'||(String[i])=='e'||(String[i])=='o'||(String[i])=='i'||(String[i])=='u'){
            char temp2[i+1];
            strncpy(temp2,String,i);
            strrev(temp2);
            strncpy(String,temp2,i);
        }
        i++;
    }

    printf("%s",String);
    
}





int main(){
    int input,length;
    printf("Enter number of inputs: ");
    scanf("%d", &input);

    for(int i = 1; i <= input; i++){

        printf("Enter length of string:");
        scanf("%d", &length);
        printf("Enter string: ");
        scanf("%s", String);
        
        VowelAnxiety(String);
    }

    return 0;
}
