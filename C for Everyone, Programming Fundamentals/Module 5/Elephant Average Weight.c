#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int size = 0;
	int weight;
	
	FILE* ifile;
	char filename[] = "elephant.txt";
	
	// Open the file as read 
	ifile = fopen(filename, "r");
	
	// Read until the end of file
	while (fscanf(ifile, "%d", &weight) != EOF) {
		size++; //Count the amount of data
	}
	
	
	// Back to beginning of file
	rewind(ifile);
	
	// declare the array
	int elep_data[size];
	int sum = 0;
	double average;
	for (int i = 0; i < size; i++) {
		
		fscanf(ifile, "%d", &weight);
		elep_data[i] =weight;
		printf("elep = %d\n",elep_data[i]);
		sum += elep_data[i];
	}
	// Close the file
	fclose(ifile); 
	
	// Calculate the average and cast to double
	average = (double)sum / size;
	
	printf("The average weight for a population of elephant seals = %.2lf\n", average);
	
	
	return 0;
}