#include <stdio.h>

int Input(int arr[], int n);
void BubbleSortByLastDigit(int a[], int n);
void PrintArray(int arr[], int n);

int main()
{
    enum
    {
        BUFFER_SIZE = 10
    };
    int buffer[BUFFER_SIZE];

    printf("Enter 10 integers separated by a space: \n");
    Input(buffer, BUFFER_SIZE);
    BubbleSortByLastDigit(buffer, BUFFER_SIZE);

    printf("Sorted numbers by the last digit: \n");
    PrintArray(buffer, BUFFER_SIZE);

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

void BubbleSortByLastDigit(int a[], int n)
{
    int i;
    int tmp;
    int flag;

    do
    {
        flag = 0;
        for (i = 1; i < n; i++)
        {
            if (a[i] % 10 < a[i - 1] % 10)
            {
                tmp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = tmp;
                flag = 1;
            }
        }
    } while (flag);
}
