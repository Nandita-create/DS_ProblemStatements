//Apply binary search to find an element in sorted array
#include <stdio.h>

int main()
{
    int arr[100], n, min_index, temp, key, mid, found_index=0;
    printf("Enter the length of the array: ");
    scanf("%d" ,&n);
    printf("Enter the %d elements of the array: \n" ,n);
    
    for (int i=0 ; i<n ; i++)
    {
        scanf("%d" ,&arr[i]);
    }

    //Sorting the array using selection sort
    for (int i=0 ; i<n-1 ; i++)
    {
        min_index = i;
        for (int j=i+1 ; j<n ; j++)
        {
            if (arr[j]<arr[min_index])
            {
                min_index = j;
            }
        }
        temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }

    printf("Enter the no. to be searched: \n");
    scanf("%d" ,&key);

    int lb = 0;
    int ub = n-1;
    for (int i=0 ; i<n ; i++)
    {
        mid = ((lb+ub)/2);
        if (key==arr[mid])
        {
            found_index++;
        }
        else if(key<arr[mid])
        {
            ub = mid-1;
        }
        else if (key>arr[mid])
        {
            lb = mid+1;
        }
    }

    //binary search only checks if value to be searched in present or not
    if (found_index!=0)
    {
        printf("The value %d is found in the array \n" ,key);
        return 0;
    }
    else
    {
        printf("The value %d is not found in the array \n" ,key);
    }
}