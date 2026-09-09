/*Short the array by
a.	Insertion sort*/

#include <stdio.h>

int main()
{
    int arr[100];
    int n, key, j;
    printf("Enter no. of elements in the array: ");
    scanf("%d" ,&n);
    printf("Enter the %d elements of the array: " ,n);
    for (int i=0 ; i<n ; i++)
    {
        scanf("%d" ,&arr[i]);
    }

    //Insertion Sort
    for(int i=1 ; i<n ; i++)
    {
        key = arr[i];
        j = i-1;

        // Shift elements of arr[0..i-1] that are greater than key
        while ( j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;;
        }
        arr[j+1] = key;
    }

    printf("Sorted array by insertion sort: \n");

    for (int i=0 ; i<n ; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}
//insertion --> uses key