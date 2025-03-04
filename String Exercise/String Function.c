#include <stdio.h>
#define MAX_SIZE 100

void getStringLength(char* str);
void getStringWordNum(char* str);
void getCharTypeNum(char* str);
void getFreqChar(char* str);
void reverseChar(char* str);
void reverseWordOrder(char* str);
void searchWord(char* str);
void removeDuplicateChar(char* str);
void removeDuplicateWord(char* str);
void concatenateString(char* str);
void compareString(char* str);

unsigned int hash(char* word) {
    unsigned int hashVal = 0;
    while (*word) {
        hashVal = (hashVal * 31) + *word;
        word++;
    }
    return hashVal;
}

int main(){
    
    // Get string from user 
    char string[MAX_SIZE];
    printf("Enter string: ");
    scanf("%[^\n]s",string);

    // 0: Get String Length
    // 1: Get Number of Word 
    // 2: Get Number of Different Chracter Type
    // 3: Find frequency of character in string
    // 4: Reverse char of String
    // 5: Reverse order of word in String
    // 6: Find word in string
    // 7: Remove duplicate character
    // 8: Concatenate strings
    // 9: Compare two strings
    // 10: Toggle alphabet of the string
    




    int operation;
    printf("Enter the operation: ");
    scanf("%d", &operation);

    switch (operation)
    {
    case 0:
        getStringLength(string);
        break;

    case 1:
        getStringWordNum(string);
        break;

    case 2:
        getCharTypeNum(string);
        break;
    case 3:
        getFreqChar(string);
        break;
    case 4:
        reverseChar(string);
        break;
    case 5:
        reverseWordOrder(string);
        break;
    case 6:
        searchWord(string);
        break;
    case 7:
        removeDuplicateChar(string);
        break;
    case 8:
        removeDuplicateWord(string);
        break;
    case 9:
        concatenateString(string);
        break;
    case 10:
        compareString(string);
        break;
    
    default:
        break;
    }




    


    


    return 0;
}

//
// Get length of string
//
void getStringLength(char* str){

    int count = 0;
    for (int i = 0; str[i] != '\0' ; i++){
        count++;
    }
    // Alternative: strlen() 
    printf("The length of string is %d.\n", count);

}

//
// Get number of word
//
void getStringWordNum(char* str){

    int i=0,wordNum = 0;
    char prevChar = '\0';
    while (1){

        if (str[i] == ' ' || str[i] == '\t' || str[i]=='\n'){
            
            if (prevChar != ' '|| str[i] != '\t' || str[i]!='\n' || str[i] != '\0'){
                wordNum++;
            }

        }

        if (str[i] == '\0'){
            wordNum++;
            break;
        }

        i++;
    }
    printf("The number of word in string is %d.\n", wordNum);
}

//
// Get number of alphaber letter, digit and special character
//

void getCharTypeNum(char* str){

    // Get number of digit, alphabet and special charater
    int i = 0;
    int digitNum = 0, alphabetNum = 0, speCharNum = 0, vowelNum = 0, consonantNum = 0;
    while (str[i] != '\0'){

        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){

            if (str[i] == 'a' ||str[i] == 'e' || str[i] == 'i' ||str[i] == 'o' ||str[i] == 'u' )
                vowelNum++;
            else
                consonantNum++;

            alphabetNum++;
        }
        else if (str[i] >= '0' && str[i] <= '9' ){

            digitNum++;
        }
        else{
            speCharNum++;
        }


        if (str[i] == '\0'){
            break;
        }

        i++;
    }

    printf("The number of alphabet = %d (Vowels = %d, Consonants = %d)\n", alphabetNum, vowelNum, consonantNum);
    printf("The number of digit = %d \n", digitNum);
    printf("The number of special character = %d \n", speCharNum);




}

//
// Get each char's occurrence number
//
void getFreqChar(char* str){
    int i = 0;
    char storeChar[MAX_SIZE];
    int freqChar[MAX_SIZE];
    int storeCharSize = 0;
    // Flag
    int charExist = 0;

    while (str[i] != '\0'){

        for(int j = 0; j <= storeCharSize ; j++ ){
            charExist = 0;
            if (str[i] == storeChar[j]){
                freqChar[j]++;
                charExist = 1;
                break;
            }
        }
        
        if (charExist == 0){
            // Store char to storeChar
            storeChar[storeCharSize] = str[i];

            freqChar[storeCharSize] = 1;

            storeCharSize++;
            
        }
    

        i++;
    }

    for (int k = 0 ; k < storeCharSize; k++ ){
        printf("%c : %d \n", storeChar[k], freqChar[k]);
    }


}

//
// Reverse the string
//
void reverseChar(char* str){

    int len = strlen(str);
    char reverseChar[MAX_SIZE];
    int index = 0;
    for (int i = len-1 ; i >= 0; i--){

        reverseChar[index] = str[i];

        index++;
    }

    reverseChar[index] = '\0';

    printf("The reverse string = %s \n", reverseChar);


}

//
// Reverse the order of word
//
void reverseWordOrder(char* str){
    
    
    char reverseString[MAX_SIZE];

    char tempStr = '\0';

    int len = strlen(str);
    int wordIndex = 0, startIndex = len - 1, endIndex = len - 1;
    

    
    while(len >= 0){
        
        if (startIndex == 0){
            for (int j = startIndex; j <= endIndex; j++){
                // Add to reverseChar
                reverseString[wordIndex++] = str[j];
            }

        }
        else if (str[startIndex] == ' ' || str[startIndex] == '\t' || str[startIndex] == '\n'){
            if (tempStr != ' '|| tempStr != '\t'|| tempStr != '\n'||tempStr != '\0'){
                
                for (int j = startIndex + 1; j <= endIndex; j++){
                    // Add to reverseChar
                    reverseString[wordIndex++] = str[j];
                }
                reverseString[wordIndex++] = str[startIndex];

                endIndex = startIndex - 1;

            }
        }
    
        tempStr = str[startIndex];



        startIndex--;
        len--;
    }

    reverseString[wordIndex] = '\0';

    printf("The word in reverse order = %s \n", reverseString);

}

//
// Search word
//
void searchWord(char *str)
{
    char searchText[MAX_SIZE];
    printf("Enter the word to be searched (do not include space): \n");
    scanf("%s ", searchText);  // Stops at the first space
    int len = strlen(searchText);
    int position[30];
    int numFound = 0;
    int startIndex = 0;
    int i = 0;
    while(str[i] != '\0'){

        int tempPos = i;
        while (str[i] == searchText[startIndex]){
            startIndex++;

            if (startIndex == len && (str[i+1]== ' ' ||str[i+1]== '\t' || str[i+1]== '\n' || str[i+1] == '\0')){
                position[numFound++] = tempPos;
                break;
            }
            
            i++;
        }

        startIndex = 0;
        i++;
    }

    printf("Search \"%s\" in string:\n", searchText);
    printf("The number of word \"%s\" found in string = %d :\n", searchText, numFound);
    printf("The word \"%s\" found at index ", searchText);
    for (int j = 0; j < numFound; j++){
        printf("%d ", position[j]);
    }
    

}

void removeDuplicateChar(char *str)
{
    //
    // Remove duplicated character in string
    //
    int i = 0, j = 0;

    // There is 256 of character
    int hash[256] = {0};


    while (str[i]!= '\0'){

        // Check the number of character in hash 
        if (hash[(unsigned char)str[i]] == 0){
            str[j++] = str[i];

            hash[(unsigned char)str[i]] = 1;
        }
        
        i++;
    }

    str[j] = '\0';

    printf("The string after removing duplicate character = %s", str);


}




void removeDuplicateWord(char *str)
{
    int i = 0;
    // Boolean var
    int seen[10000] = {0};

    char Words[MAX_SIZE][20];
    int currentIndex = 0, endIndex = 0;
    int len = strlen(str);
    while (i <= len){
        
        if (str[i] == ' ' || str[i]== '\0'){
            
            if (i > currentIndex){
                char temp = str[i];
                str[i] = '\0';

                char* word = &str[currentIndex];
                
                if (seen[hash(word) % 10000] == 0){
                    seen[hash(word) % 10000] = 1;

                         
                    // Change the word
                    int j = currentIndex;
                    
                    while (str[j]!= '\0'){

                        str[endIndex++] = str[j++];
                    }
                    str[endIndex++] = temp;


                } 
                
            }

            currentIndex = i+1;

        }


        i++;
    }
    str[endIndex-1] = '\0';
    printf("The string after removing duplicate word = %s", str);

   

}

void concatenateString(char *str)
{
    char secondString[MAX_SIZE];
    // Clear the \n stored 
    getchar();

    printf("Enter the string to be concatenated: ");
    
    fgets(secondString, sizeof(secondString), stdin);

    // Remove the newline character if it exists at the end of the string
    secondString[strcspn(secondString, "\n")] = '\0';

    int len = strlen(str);
    int i = 0;
    while (secondString[i] != '\0'){
        str[len + i] = secondString[i];

        i++;


    }
    str[len + i] = '\0';

    printf("The concatenated string = %s", str);


}

void compareString(char *str)
{
    char secondString[MAX_SIZE];
    // Clear the \n stored 
    getchar();
    printf("Enter the string to be compared: ");
    fgets(secondString, sizeof(secondString), stdin);

    // Remove the newline character if it exists at the end of the string
    secondString[strcspn(secondString, "\n")] = '\0';

    
    int IsNotEqual = 0;
    int len1 = strlen(str);
    int len2 = strlen(secondString);
    int i = 0;
    if (len1 == len2){
        while (secondString[i] != '\0'){
        
            if (str[i] != secondString[i]){
                IsNotEqual = 1;
                break;
            }

            i++;

        }
    }else{
        IsNotEqual = 1;
    }
    

    if (IsNotEqual == 0 ){
        printf("The strings are the same.");

    }else{
        printf("The strings are different.");
    }
    


}
