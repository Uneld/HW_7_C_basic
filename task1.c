#include <stdio.h>

float calculateAverageInputArray (int arr[], int n);

int main()
{
	enum {BUFFER_SIZE = 5}; 
	int buffer [BUFFER_SIZE];

	printf("Enter 5 integers separated by a space: \n");
	float average = calculateAverageInputArray(buffer, BUFFER_SIZE);
	printf("Arithmetic mean: %.3f\n", average);

    return 0;
}

float calculateAverageInputArray (int arr[], int n){
	float sum = 0;
	
	for (int i = 0; i < n; i++){
		scanf ("%d", &arr[i]);
		sum += arr[i];
	
	} 
	
	return sum / 5;
}


