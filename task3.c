#include <stdio.h>

int Input(int arr[], int n);
void ShiftRightByOffset(int input[], int output[], int n, int offset);
void PrintArray(int arr[], int n);

int main()
{
    enum
    {
        BUFFER_SIZE = 12,
        OFFSET = 4
    };
    int input[BUFFER_SIZE];
    int output[BUFFER_SIZE];

    printf("Enter 12 integers separated by a space: \n");
    Input(input, BUFFER_SIZE);
    ShiftRightByOffset(input, output, BUFFER_SIZE, OFFSET);

    printf("Cyclic shift by 4 elements: \n");
    PrintArray(output, BUFFER_SIZE);

    return 0;
}

int Input(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    return i;
}

void PrintArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void ShiftRightByOffset(int input[], int output[], int n, int offset)
{
    int nOut = 0;

    for (int i = 0; i < n; i++)
    {
        nOut = i + offset;
        if (nOut >= n)
        {
            nOut = nOut - n;
        }

        output[nOut] = input[i];
    }
}
