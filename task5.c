#include <stdio.h>

int Input(int arr[], int n);
void FindNumbersWithZeroSecPlace(int arr[], int n);

int main()
{
	enum
	{
		BUFFER_SIZE = 10,
		OFFSET = 4
	};
	int buffer[BUFFER_SIZE];

	printf("Enter 10 integers separated by a space: \n");
	Input(buffer, BUFFER_SIZE);

	printf("Numbers with the second digit from the end being zero: \n");
	FindNumbersWithZeroSecPlace(buffer, BUFFER_SIZE);

	return 0;
}

int Input(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	return i;
}

void FindNumbersWithZeroSecPlace(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int num = arr[i] / 10 % 10;
		if (num == 0)
		{
			printf("%d ", arr[i]);
		}
	}
}
