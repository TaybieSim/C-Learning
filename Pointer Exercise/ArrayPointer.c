#include <stdio.h>

int main(){

    //
    // Array store pointer to the value
    //

    int num;
    // Store Array using pointer
    int arr[20];
    

    printf("Enter the size of array (<=20): ");
    scanf("%d", &num);

    
    for (int i = 0; i < num ; i++){
        printf("Array[%d] = ", i);
        scanf("%d", arr + i);
        
    }

    printf("\nThe array entered:\n");
    for (int i = 0; i < num ; i++){
        printf("Array[%d] = %d\n", i, *(arr + i));
    }


    //
    // Reverse the array
    //
    int *start = &arr[0];
    int *end = &arr[num-1];
    while(start < end){
        
        // Swap variable using XOR Operator
        *start ^= *end;
        *end ^= *start;
        *start ^= *end;

        start++;
        end--;
    }


    printf("\nThe Array in reverse order: \n");
    for (int i = 0; i < num ; i++){
        printf("Array[%d] = %d\n", i, *(arr + i));
    }


    int LargestValue = 0;
    int *Ptr = &LargestValue;
    // Find largest value in array
    for (int i = 0 ; i < num; i++){

        if (*Ptr < *(arr+i)){
            *Ptr = *(arr+i);
        }
    }

    printf("\nThe largest value in array: %d\n", *Ptr);

    return 0;
}