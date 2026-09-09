//Program to find an value in a 2D array
#include <stdio.h>

int main()
{
    int arr[100][100];
    int m, n, key, count=0;
    printf("Enter no. of rows: ");
    scanf("%d" ,&m);
    printf("Enter no. of columns: ");
    scanf("%d" ,&n);

    printf("Enter the %d elements of the array: \n" ,(m*n));
    for (int i=0 ; i<m ; i++)
    {
        for (int j=0 ; j<n ; j++)
        {
            scanf("%d" ,&arr[i][j]);
        }
    }

    printf("The entered array: \n");
    for (int i=0 ; i<m ; i++)
    {
        for (int j=0 ; j<n ; j++)
        {
            printf("%d " ,arr[i][j]);
        }
        printf("\n");
    }

    printf("Enter the value to be searched: ");
    scanf("%d" ,&key);

    for (int i=0 ; i<m ; i++)
    {
        for (int j=0 ; j<n ; j++)
        {
            if (arr[i][j] == key)
            {
                printf("The value %d is found at \nRow No.: %d \nColumn No.: %d \n" ,key, (i+1), (j+1));
                count++;
                break;
            }
        }
        if (count!=0)
        {
            break;
        }
    }

    if (count==0)
    {
        printf("Value %d is not found in the array \n" ,key);
    }
    return 0;
}