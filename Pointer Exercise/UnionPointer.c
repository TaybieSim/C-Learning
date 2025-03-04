#include <stdio.h>


// In Union, all member share same memory location
// while struct each member gets its own memory location

union Data{
    int i;
    float f;
    char str[20];
};

int main(){

    union Data *DataPtr = (union Data*) malloc(sizeof(union Data));

    DataPtr->i = 10;
    printf("DataPtr->i = %d\n", DataPtr->i);
    printf("Address of DataPtr->i: %p\n", (void*)&DataPtr->i);  // Address of the 'i' member

    // Assign a value to the float member
    DataPtr->f = 3.14;
    printf("DataPtr->f = %.2f\n", DataPtr->f);
    printf("Address of DataPtr->f: %p\n", (void*)&DataPtr->f);  // Address of the 'f' member

    // Assign a value to the string member
    strcpy(DataPtr->str, "Hello, Union!");
    printf("DataPtr->str = %s\n", DataPtr->str);
    printf("Address of DataPtr->str: %p\n", (void*)&DataPtr->str);  // Address of the 'str' member

    // Free allocated memory
    free(DataPtr);

    return 0;
}
