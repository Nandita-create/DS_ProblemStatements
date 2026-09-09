//Program for selection sort
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int n, max, temp;
    printf("Enter length of the array: ");
    scanf("%d" ,&n);

    arr = (int *)malloc(n*sizeof(int));
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

    //Selection Sort
    for (int i=0 ; i<n-1 ; i++)
    {
        max = 0;
        for (int j=0 ; j<n-i ; j++)
        {
            if (arr[max]<arr[j])
            {
                max = j;
            }
        }
        temp = arr[max];
        arr[max] = arr[n-1-i];
        arr[n-1-i] = temp;
    }

    printf("After Sorting: \n");
    for (int i=0 ; i<n ; i++)
    {
        printf("%d ",arr[i]);
    }
    free(arr);
    return 0;
}