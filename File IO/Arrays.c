#include <stdio.h>
#include <stdlib.h>

typedef struct rational{
	int numerator;
	int denominator;
}rational;

double AverageRational(double sum, int size);
int main(void)
{
	// Open file
	FILE *ifile;
	ifile = fopen("Input.txt", "r");
	// Get first digit from file
	int num;
	fscanf(ifile, "%d", &num);
	// Create array r with size num;
	rational r[num];
	int i=0;
	// Read pair of number from file
	while (fscanf(ifile, "%d %d", &r[i].numerator, &r[i].denominator)== 2){
		i++;
	}
	fclose(ifile);
	// Validate the number of pairs
	if (i != num){
		printf("The pair of numbers taken from file is not same as the array size!\n");
		return 0;
	}
	// Check denominator of the rational
	for (int j =0; j < num; j++){
		if (r[j].denominator == 0){
			printf("One of the denominator is equal to zero!");
			return 0;
		}
	}
	// Add, Substract, Multiply, Divide
	
	double totalAdd, totalSub, totalMul, totalDiv;
	for (int j =0; j < num ; j++){
		if (j == 0){
			totalAdd = (double) r[j].numerator/ r[j].denominator;
			totalSub = (double)r[j].numerator/ r[j].denominator;
			totalMul = (double)r[j].numerator/ r[j].denominator;
			totalDiv = (double) r[j].numerator/ r[j].denominator;
		}
		else{
			totalAdd += (double)r[j].numerator/ r[j].denominator;
			totalSub -= (double)r[j].numerator/ r[j].denominator;
			totalMul *= (double)r[j].numerator/ r[j].denominator;
			totalDiv /= (double)r[j].numerator/ r[j].denominator;
		}
	}
	
	printf("Addition of rationals = %.2lf\n", totalAdd);
	printf("Substraction of rationals = %.2lf\n", totalSub);
	printf("Multiplication of rationals = %.2lf\n",totalMul);
	printf("Division of rationals = %.2lf\n", totalDiv);
	
	
	
	// Average of rationals
	double average =  AverageRational(totalAdd,num);
	
	printf("Average of rationals = %.2lf\n", average);
	return 0;
}

double AverageRational(double sum, int size){
	
	
	return sum / size;
}