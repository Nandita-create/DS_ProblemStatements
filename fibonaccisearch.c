//Searching for element using Fibonacci Search
//Time Complexity = O(log n)

#include <stdio.h>
#include <stdlib.h>

int FibonacciSearch(int *, int, int);
void QuickSort(int *, int, int);
int partition(int *, int, int);

int main()
{
    int *arr, arrSize, key;
    printf("Enter length of array: ");
    scanf("%d" ,&arrSize);

    arr = (int *)malloc(arrSize*sizeof(int));

    printf("Enter %d elements: " ,arrSize);
    for (int i=0 ; i<arrSize ; i++)
    {
        scanf("%d" ,&arr[i]);
    }

    printf("Enter value to be found: ");
    scanf("%d" ,&key);

    int position = FibonacciSearch(arr, arrSize, key);

    if (position!=-1)
    printf("Value found at index %d \n" ,(position-1));

    else
    printf("Value not found \n");

    return 0;
}

int FibonacciSearch(int *arr, int arrSize, int key)
{
    int n = arrSize;
    int fib1=0, fib2=1;
    int fib3 = fib1+fib2;

    QuickSort(arr, 0, arrSize-1);

    //for getting smallest fibonacci number greater than or equal to size of array
    while(fib3<n)  
    {
        fib1 = fib2;
        fib2 = fib3;
        fib3 = fib1 + fib2;
    }

    int offset = -1;  //value of offset tells what part of array has been eliminated
    //initially it is -1 as nothing is eliminated

    int index;

    while (fib3>1)  //main search loop
    {
        if (offset + fib1 < n)
        index = offset + fib1;

        else
        index = n-1;

        if (arr[index]<key)
        {
            fib3 = fib2;
            fib2 = fib1;
            fib1 = fib3 - fib2;

            offset = index;  //so that elements lesser than key are eliminated
        }

        else if (arr[index]>key)
        {
            fib3 = fib1;  //eliminating upper half of key value
            fib2 = fib2 - fib1;
            fib1 = fib3 - fib2;
        }

        else
        return index;
    }

    //sometimes one last element is not check, this checks if it is equal to key entered
    if (fib2 && offset+1<n && arr[offset+1]==key)
    return offset+1;

    return -1;  //if value is not found
}

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
    int i=low;
    int j=low;
    int temp;

    for(j=low ; j<high ; j++)
    {
        if (arr[j]<pivot)
        {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;

            i++;
        }
    }
    temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;

    return i;
}