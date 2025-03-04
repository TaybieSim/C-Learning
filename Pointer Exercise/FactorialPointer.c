#include <stdio.h>
void Factorial(int factor, int* result){

    *result = 1;

    for (int i = 1; i <= factor; i++){
        *result *= i;

    }

}

int main(){
    printf("Pointer : Find the factorial of a number :\n\n"); 
    int facNum;
    int Result;
    printf("Enter a number: ");
    scanf("%d", &facNum);

    Factorial(facNum, &Result);

    printf("The factorial of %d = %d\n", facNum,Result);

    return 0;
}
