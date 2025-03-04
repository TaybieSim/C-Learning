#include <stdio.h>

void ConcatenateString(char* str1, char* str2);
int CompareString(char* str1, char* str2);
void ReverseString(char* str, char* reversedStr);
void ToggleCharCase(char* str);
int main(){


    printf("\nConcatenate Strings using Pointer: \n");

    char string1[20];
    char string2[20];
    
    printf("Enter string 1: ");
    fgets(string1, sizeof(string1), stdin);
    string1[strcspn(string1, "\n")] = '\0';
    printf("Enter string 2: ");
    fgets(string2, sizeof(string2), stdin);
    string1[strcspn(string2, "\n")] = '\0';

    int len = strlen(string1);
    int i = 0;


    ConcatenateString(string1, string2);
    printf("Concatenate string = %s \n", string1);


    printf("\n\nCompare Strings using Pointer: \n");


    char string3[20];
    char string4[20];
    
    printf("Enter string 1: ");
    fgets(string3, sizeof(string3), stdin);
    string3[strcspn(string3, "\n")] = '\0';  

    printf("Enter string 2: ");
    fgets(string4, sizeof(string4), stdin);
    string4[strcspn(string4, "\n")] = '\0';
    int IsEqual = 0;

    IsEqual = CompareString(string3, string4);
    // set ptr to the end of string1
    
    
    if (IsEqual == 0){
        printf("string 1 and string 2 are equal.\n");
    }
    else{
        printf("string 1 and string 2 are not equal.\n");
    }
    


    printf("\n\nReverse Strings using Pointer: \n");
    char string5[20];
    char reversedString[20];
    printf("Enter string: ");
    scanf("%[^\n]*c", string5);

    ReverseString(string5, reversedString);
    
    printf("Reverse String = %s\n", reversedString);


    // Toggle case of each character 

    printf("\nToggle case of each character in string using pointer: \n");

    ToggleCharCase(string5);

    printf("After toggle case of each character in string = %s\n", string5);
    return 0;
}

void ConcatenateString(char *str1, char *str2)
{
    // set ptr to the end of string1
    while(*(++str1) != '\0');

    while(*(str1++) = *(str2++));
}

int CompareString(char *str1, char *str2)
{

    // (*str1 && *str2) Check both is null or not
    while ((*str1 && *str2) && (*str1 == *str2)){
        str1++;
        str2++;

    }
    return *str1 - *str2;
}

void ReverseString(char* str, char* reversedStr)
{
    int len = 0;
    // Get length
    while (*(str++)){
        len++;
    }

    str--;

    while(len >= 0){

        *(reversedStr++) = *(--str);
        len--;
    }

    *reversedStr = '\0';

}

void ToggleCharCase(char *str)
{
    char* ptr = str;
    
    while (*ptr){

        if (*ptr >= 'a' && *ptr <= 'z'){

            *ptr -= 32;
        }

        else if (*ptr >= 'A' && *ptr <= 'Z'){

            *ptr += 32;
        }
        *ptr++;

    }

}
