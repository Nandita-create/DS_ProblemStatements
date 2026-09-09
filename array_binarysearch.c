//Using Binary Search
#include <stdio.h>

int main()
{
    int arr[100];
    int n, key, j;
    int lb, ub, mid;
    printf("Enter length of array: ");
    scanf("%d" ,&n);

    printf("Enter elements of array: \n");
    for (int i=0 ; i<n ; i++)
    {
        scanf("%d" ,&arr[i]);
    }

    lb = 0;
    ub = n-1;

    //sorting entered array using insertion sort
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

    printf("Enter the element to be searched: ");
    scanf("%d" ,&key);

    while (lb<=ub)
    {
        mid = (ub + lb)/2;
        if (arr[mid]==key)
        {
            printf("Element %d Found \n" ,key);
            break;
        }
        else if (arr[mid]>key)
        {
            ub = mid-1;
        }
        else
        {
            lb = mid+1;
        }
    }

    if (ub<lb)
    {
        printf("Element %d Not Found \n" ,key);
    }
    return 0;
}