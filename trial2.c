#include <stdio.h>
#include <stdlib.h>

void FibonacciSearch(int *, int);
int partition(int *, int, int);

void QuickSort(int *arr, int low, int high)
{
    if (low<high)
    {
        int pivot = partition(arr, low, high);

        QuickSort(arr, low, pivot-1);
        QuickSort(arr, pivot+1, high);
    }
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low;
    int j = low;
    int temp;
    for (j=low ; j<high ; j++)
    {
        if (arr[j]<pivot)
        {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;
        }
    }
    temp = arr[high];
    arr[high] = arr[i];
    arr[i] = temp;

    return i;
}

void FibonacciSearch(int arr[], int arrSize)
{
    int n = arrSize;

    QuickSort(arr, 0, arrSize-1);
    int key;
    printf("Enter value to be serached: ");
    scanf("%d" ,&key);

    int fib1 = 0;       
    int fib2 = 1;       
    int fib3 = fib1 + fib2;

    while (fib3 < n)
    {
        fib1 = fib2;
        fib2 = fib3;
        fib3 = fib1 + fib2;
    }

    int offset = -1;

    while (fib3 > 1)
    {
        int index;

        if (offset + fib1 < n)
            index = offset + fib1;
        else
            index = n - 1;
        
        if (arr[index] < key)
        {
            fib3 = fib2;
            fib2 = fib1;
            fib1 = fib3 - fib2;
            offset = index;
        }
        else if (arr[index] > key)
        {
            fib3 = fib1;
            fib2 = fib2 - fib1;
            fib1 = fib3 - fib2;
        }
        else
        {
            printf("Value found at index %d \n" ,index);
            return;
        }
    }

    if (fib2 && offset + 1 < n && arr[offset + 1] == key)
    {
        printf("Value found at index %d \n" ,offset + 1);
        return;
    }

    printf("Value Not Found \n");
}

int main()
{
    int *arr, arrSize;
    printf("Enter length of array: ");
    scanf("%d" ,&arrSize);

    arr=(int *)malloc(arrSize*sizeof(int));

    printf("Enter %d elements of the array: \n" ,arrSize);
    for (int i=0 ; i<arrSize ; i++)
    {
        scanf("%d" ,&arr[i]);
    }

    FibonacciSearch(arr, arrSize);

    printf("Sorted array: \n");
    for (int i=0 ; i<arrSize ; i++)
    {
        printf("%d " ,arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}