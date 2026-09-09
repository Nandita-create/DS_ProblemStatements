//Program for bubble sort
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int n, temp;
    printf("Enter length of array: ");
    scanf("%d" ,&n);

    arr = (int*)malloc(n*sizeof(int));
    printf("Enter %d elements of the array: \n" ,n);
    for (int i=0 ; i<n ; i++)
    {
        scanf("%d" ,&arr[i]);
    }

    printf("Before Sorting: \n");
    for (int i=0 ; i<n ; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    //Bubble sort
    for (int i=0 ; i<n-1 ; i++)
    {
        for (int j=0 ; j<n-1-i ; j++)
        {
            if (arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("After Sorting: \n");
    for (int i=0 ; i<n ; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}