//Program to sort array using Merge Sort
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int low, int mid, int high)
{
    int i=low;
    int j=mid+1;
    int k=0;
    int temp[high-low + 1];

    while(i<=mid && j<=high)
    {
        if (arr[i]<=arr[j])
        {
            temp[k]=arr[i];
            i++;
        }

        else
        {
            temp[k]=arr[j];
            j++;
        }
        k++;
    }

    while(i<=mid)
    {
        temp[k]=arr[i];
        k++;
        i++;
    }

    while(j<=high)
    {
        temp[k]=arr[j];
        k++;
        j++;
    }

    //copying array back to original array
    for (i=low, k=0 ; i<=high ; i++, k++)  //as size of array remains value of arrSize
    {
        arr[i] = temp[k];
    }
}

void mergeSort(int arr[], int low, int high)
{
    int mid;
    if(low<high)
    {
        mid = (low+high)/2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);

        merge(arr, low, mid, high);
    }
}

int main()
{
    int *arr, arrSize;
    printf("Enter length of array: ");
    scanf("%d" ,&arrSize);

    arr = (int *)malloc(arrSize*sizeof(int));

    printf("Enter %d elements: \n" ,arrSize);
    for (int i=0 ; i<arrSize ; i++)
    {
        scanf("%d" ,&arr[i]);
    }

    printf("Before Sorting: \n");
    for (int i=0 ; i<arrSize ; i++)
    {
        printf("%d " ,arr[i]);
    }
    printf("\n");

    mergeSort(arr, 0, arrSize-1);

    printf("After Sorting: \n");
    for (int i=0 ; i<arrSize ; i++)
    {
        printf("%d " ,arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}