//Crate an array of integer and find out maximum and minimum in that array.
#include <stdio.h>

int main()
{
    int arr[100];
    int n, min, max;
    printf("Enter no. of elements in the array: ");
    scanf("%d" ,&n);
    printf("Enter %d elements of the array: \n" ,n);

    for (int i=0 ; i<n ; i++)
    {
        scanf("%d" ,&arr[i]);
    }
    
    max = arr[0];
    min = arr[0];

    for (int i=1 ; i<n ; i++)  //comparing from index 1 of array
    {
        if (arr[i]>max)
        {
            max = arr[i];
        }
    }

    for (int i=1 ; i<n ; i++)
    {
        if (arr[i]<min)
        {
            min = arr[i];
        }
    }

    printf("Maximum value in array: %d \n" ,max);
    printf("Minimum value in array: %d \n" ,min);
    return 0;
}