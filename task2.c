#include <stdio.h>

int Input(int arr[], int n);
int FindMin(int arr[], int n);

int main()
{
    enum
    {
        BUFFER_SIZE = 5
    };
    int buffer[BUFFER_SIZE];

    printf("Enter 5 integers separated by a space: \n");
    Input(buffer, BUFFER_SIZE);
    int min = FindMin(buffer, BUFFER_SIZE);
    printf("Minimum: %d\n", min);

    return 0;
}

int Input(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++) // ввод массива
        scanf("%d", &arr[i]);
    return i;
}

int FindMin(int arr[], int n)
{
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    return min;
}
