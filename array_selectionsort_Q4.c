/*Short the array by
b.	Selection sort*/

#include <stdio.h>

int main()
{
    int arr[100];
    int n, min_index, temp;
    printf("Enter no. of elements in the array: ");
    scanf("%d" ,&n);
    printf("Enter the %d elements of the array: " ,n);
    for (int i=0 ; i<n ; i++)
    {
        scanf("%d" ,&arr[i]);
    }

    //Selection Sort
    for(int i=0 ; i<n-1 ; i++)
    {
        min_index = i;

        for (int j=i+1 ; j<n ; j++)
        {
            if (arr[j]<arr[min_index])
            {
                min_index = j;
            }
        }
            //swapping arr[i] element with minimum element found in the array
            temp = arr[min_index];
            arr[min_index] = arr[i];
            arr[i] = temp;
    }

    printf("Sorted array by selection sort: \n");

    for (int i=0 ; i<n ; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}
//selection --> using index and storing in min