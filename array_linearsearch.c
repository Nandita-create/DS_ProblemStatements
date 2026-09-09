//Using Linear Search
#include <stdio.h>

int main()
{
    int arr[100];
    int n, key, i;
    printf("Enter length of array: ");
    scanf("%d" ,&n);

    printf("Enter elements of array: \n");
    for (i=0 ; i<n ; i++)
    {
        scanf("%d" ,&arr[i]);
    }

    printf("Enter element to be searched: \n");
    scanf("%d" ,&key);

    for (i=0 ; i<n ; i++)
    {
        if (arr[i] == key)
        {
            printf("%d found at index %d \n" ,key, i);
            break;
        }
    }

    //if entire loop runs, i becomes 8. 
    //If element is found, it breaks out of loop at that index
    if (i==n)  
    {
        printf("%d Not Found in the Array \n" ,key);
    }

    return 0;
}