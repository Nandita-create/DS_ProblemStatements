//Program to search a value in a 3D array
#include <stdio.h>

int main()
{
    int arr[50][50][50]; 
    //different size restrictions for different platforms

    int k, m, n, key, count=0;
    //k=no. of layers, m=no.of rows, n=no. of columns

    printf("Enter the no. of layers in the array: ");
    scanf("%d" ,&k);
    printf("Enter the no. of rows in the array: ");
    scanf("%d" ,&m);
    printf("Enter the no. of columns in the array: ");
    scanf("%d" ,&n);

    printf("Enter the %d elements of the array: \n" ,(k*m*n));
    for (int i=0 ; i<k ; i++)
    {
        for (int j=0 ; j<m ; j++)
        {
            for (int p=0 ; p<n ; p++)
            {
                scanf("%d", &arr[i][j][p]);
            }
        }
    }

    printf("Array entered: \n");
    for (int i=0 ; i<k ; i++)
    {
        printf("Layer %d \n" ,(i+1));
        for (int j=0 ; j<m ; j++)
        {
            for (int p=0 ; p<n ; p++)
            {
                printf("%d " ,arr[i][j][p]);
            }
            printf("\n");
        }
    }
    printf("\n");

    printf("Enter the value to be searched: \n");
    scanf("%d" ,&key);
    
    for (int i=0 ; i<k ; i++)
    {
        for (int j=0 ; j<m ; j++)
        {
            for (int p=0 ; p<n ; p++)
            {
                if (arr[i][j][p]==key)
                {
                    printf("The value %d is found at\n Layer No.: %d\n Row No.: %d\n Column No.: %d \n" ,key, (i+1), (j+1), (p+1));
                    count++;
                    break;
                }
            }
            if (count!=0)
            {
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