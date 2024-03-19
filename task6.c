#include <stdio.h>

int Input(int arr[], int n);
void FindUniqueNumbers(int input[], int uniqueNumbers[], int n);
int FindPosInUniqueArray(int number, int uniqueNumbers[], int n);
int FindMostFrequentNumber(int input[], int uniqueNumbers[], int countNumbers[], const int n);
int FindMaxPos(int arr[], int len);

enum
{
	BUFFER_SIZE = 10,
	UNIQUE_SIZE_OFFSET = 1
};

int main()
{

	int input[BUFFER_SIZE];
	int uniqueNumbers[BUFFER_SIZE + UNIQUE_SIZE_OFFSET] = {0};
	int countNumbers[BUFFER_SIZE] = {0};

	printf("Enter 10 integers separated by a space: \n");
	Input(input, BUFFER_SIZE);
	FindUniqueNumbers(input, uniqueNumbers, BUFFER_SIZE);

	int mostFrequentNum = FindMostFrequentNumber(input, uniqueNumbers, countNumbers, BUFFER_SIZE);
	printf("The number that occurs more often than others:  %d", mostFrequentNum);

	return 0;
}

int Input(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	return i;
}

int FindMaxPos(int arr[], int len)
{
	int posMax = 0;
	int max = arr[0], i;
	for (i = 1; i < len; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			posMax = i;
		}
	}

	return posMax;
}

void FindUniqueNumbers(int input[], int uniqueNumbers[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (input[i] == 0)
		{
			uniqueNumbers[0] = input[i];
			continue;
		}

		for (int j = 1; j < n + UNIQUE_SIZE_OFFSET; j++)
		{
			if (input[i] == uniqueNumbers[j])
			{
				break;
			}
			else if (uniqueNumbers[j] == 0)
			{
				uniqueNumbers[j] = input[i];
				break;
			}
		}
	}
}

int FindPosInUniqueArray(int number, int uniqueNumbers[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (number == uniqueNumbers[i])
		{
			return i;
		}
	}
	return -1;
}

int FindMostFrequentNumber(int input[], int uniqueNumbers[], int countNumbers[], const int n)
{
	int pos = 0;

	for (int i = 0; i < n; i++)
	{
		pos = FindPosInUniqueArray(input[i], uniqueNumbers, n);
		countNumbers[pos]++;
	}

	int posMax = FindMaxPos(countNumbers, n);

	return uniqueNumbers[posMax];
}
