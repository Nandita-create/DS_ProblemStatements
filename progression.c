#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool canMakeArithmeticProgression(int* arr, int arrSize) {
    int i;
    int diff = arr[1] - arr[0];
    for (i=1 ; i<arrSize-1 ; i++)
    {
        if (diff != (arr[i+1]-arr[i]))
        {
            return false;
            break;
        }
    }
        return true;
}

int main()
{
    int *arr;
    int n, key, j;
    printf("Enter length of arrray: ");
    scanf("%d" ,&n);

    arr = (int *)malloc(n*sizeof(int));

    printf("Enter %d elements of the array: \n" ,n);
    for (int i=0 ; i<n ; i++)
    {
        scanf("%d" ,&arr[i]);
    }
    
    //insertion sort
    for (int i=1 ; i<n ; i++)
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

    if (canMakeArithmeticProgression(arr, n))
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
    free(arr);
    return 0;
}