//Prgram to sort 2D array as a whole (not row or colummn specific)
#include <stdio.h>

int main()
{
    int arr[100][100], sort[10000];  //as arr[100][100] ca store upto 10000 elements
    int m, n, k=0, temp;
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

    printf("Array before sorting: \n");
    for (int i=0 ; i<m ; i++)
    {
        for (int j=0 ; j<n ; j++)
        {
            printf("%d " ,arr[i][j]);
        }
        printf("\n");
    }

    //storing 2D array elements in 1D array
    for (int i=0 ; i<m ; i++)
    {
        for (int j=0 ; j<n ; j++)
        {
            sort[k] = arr[i][j];
            k++;
        }
    }

    //sorting 1D array by bubble sort
    for (k=0 ; k<(m*n) ; k++)
    {
        for (int j=0 ; j<((m*n)-1) ; j++)
        {
            if (sort[j] > sort[j+1])
            {
                temp = sort[j];
                sort[j] = sort[j+1];
                sort[j+1] = temp;
            }
        }
    }

    k=0;  //reset k to 0 index

    //putting 1D array into 2D array form
    for (int i=0 ; i<m ; i++)
    {
        for (int j=0 ; j<n ; j++)
        {
            arr[i][j] = sort[k] ;
            k++;
        }
    }

    //printing sorted array
    printf("Sorted Array: \n");
    for (int i=0 ; i<m ; i++)
    {
        for (int j=0 ; j<n ; j++)
        {
            printf("%d " ,arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}