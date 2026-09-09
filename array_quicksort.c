//Sorting an array using Quick Sort
#include <stdio.h>
#include <stdlib.h>

void quicksort(int [], int, int);

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i=low;
    int j=low;
    int temp;
    for (int j=low ; j<high ; j++)
    {
        if (arr[j]<pivot)
        {
            temp=arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }  
    temp = arr[high];
    arr[high] = arr[i];
    arr[i] = temp;

    return i;
}

void quicksort(int arr[], int low, int high)
{
    if (low<high)
    {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot-1);
        quicksort(arr, pivot+1, high);
    }
}

int main()
{
    int *arr, n;
    printf("Enter length of array: ");
    scanf("%d" ,&n);

    arr=(int *)malloc(n*sizeof(int));

    printf("Enter %d elements of the array: \n" ,n);
    for (int i=0 ; i<n ; i++)
    {
        scanf("%d" ,&arr[i]);
    }

    quicksort(arr, 0, n-1);

    printf("Sorted array: \n");
    for (int i=0 ; i<n ; i++)
    {
        printf("%d " ,arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}