//Create 2 array. 
//Now create a function to create intersection of both of array. 
//(Pass both array to function)
#include <stdio.h>

void intersect_array(int[], int[]);
int len1, len2;  //global variables to store length of arrays

int main()
{
    int arr1[100];
    int arr2[100];
    printf("Enter length of 1st array: ");
    scanf("%d" ,&len1);
    printf("Enter 1st array: ");
    for (int i=0 ; i<len1 ; i++)
    {
        scanf("%d" ,&arr1[i]);
    }

    printf("Enter length of 2nd array: ");
    scanf("%d" ,&len2);
    printf("Emter 2nd array: ");
    for (int i=0 ; i<len2 ; i++)
    {
        scanf("%d" ,&arr2[i]);
    }

    intersect_array(arr1, arr2);
    return 0;
}

void intersect_array(int x[], int y[])
{
    int result[200];
    int k=0, count=0;
    for (int i=0 ; i<len1 ; i++)
    {
        for (int j=0 ; j<len2 ; j++)
        {
            if (x[i]==y[j])
            {
                count =0;
                for (int m=0 ; m<k ; m++)
                {
                    if (result[m]==x[i])
                    {
                        count=1;
                        break;
                    }
                }
                if (count==0)
                {
                    result[k++] = x[i];
                }
                break;
            }
        }
    }

    printf("Intersection of the arrays is: \n");

    for (int i=0 ; i<k ; i++)
    {
        printf("%d " ,result[i]);
    }
}