/* Write a program that prints the sine function for an input x between (0, 1) */

#include <stdio.h>
#include <math.h>

int main(void){

    // variable declaration
    double num;

    // User Input (0-1)
    printf("Enter a number (0-1):");
    scanf("%lf",&num);

    // Print the sine function of input x
    printf("%lf",sin(num));

    return 0;
}