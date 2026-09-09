//Using Insertion Sort
#include <stdio.h>

int main()
{
    int arr[100];
    int n, key, j;
    printf("Enter length of array: ");
    scanf("%d" ,&n);

    printf("Enter elements of array: \n");
    for (int i=0 ; i<n ; i++)
    {
        scanf("%d" ,&arr[i]);
    }

    printf("Array before sorting: \n");
    for (int i=0 ; i<n ; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    //sorting using insertion sort
    for (int i=0 ; i<n ; i++)
    {
        key = arr[i];
        j = i-1;
        while (j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    //printing sorted array
    printf("Array after sorting: \n");
    for (int i=0 ; i<n ; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}