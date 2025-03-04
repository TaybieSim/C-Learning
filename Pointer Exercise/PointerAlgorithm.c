#include <stdio.h>

int main()
{
    int i = 10;
    int *ptr = &i; // Ptr stores the address of i
    int **dPtr = &ptr; // dPtr store the address of ptr

    printf("Value of i = %d\n", i); // i = 10
    printf("Address of i = %d\n", &i); 
    printf("Value of ptr = %d\n", ptr); // ptr = Address of ptr
    printf("Value of *ptr = %d\n", *ptr); // *ptr = value of i
    printf("Value of dPtr = %d\n", dPtr); // dPtr = Address of dPtr
    printf("Value of *dPtr = %d\n", *dPtr); // *dPtr = Address of ptr
    printf("Value of **dPtr = %d\n\n", **dPtr); // **dPtr = value of i


    int j;
    int *ptr2 = &j; // Need to point to a variable
    printf(" Input a number : ");
    scanf("%d", ptr2); 

    
    if (*ptr2 > *ptr){
        printf("\n%d is the maximum number.\n", *ptr2);
    }
    else{
        printf("%d is the maximum number.\n", *ptr);
    }


    return 0;
}