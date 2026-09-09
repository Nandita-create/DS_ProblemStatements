//Program to find A-B or B-A
#include <stdio.h>

void diff(int[], int[]);
int len_a, len_b;

int main()
{
    int a[100], b[100];
    int choice, temp;
    printf("Enter the length of first array (A): ");
    scanf("%d" ,&len_a);
    printf("Enter the %d elements for array A: " ,len_a);
    for (int i=0 ; i<len_a ; i++)
    {
        scanf("%d" ,&a[i]);
    }

    printf("Enter the length of second array (B): ");
    scanf("%d" ,&len_b);
    printf("Enter the %d elements for array B: " ,len_b);
    for (int i=0 ; i<len_b ; i++)
    {
        scanf("%d" ,&b[i]);
    }

    printf("\n");

    printf("Enter:\n 1 for (A-B)\n 2 for (B-A)\n");
    scanf("%d" ,&choice);

    switch (choice)
    {
        case 1:
        printf("Array representing (A-B) is: \n");
        diff(a, b);
        break;

        case 2:
        printf("Array representing (B-A) is: \n");
        //interchanging value of lengths for B-A
        temp = len_a;
        len_a = len_b;
        len_b = temp;
        diff(b, a);
        break;

        default:
        printf("Invalid choice entered \n");
    }
    return 0;
}

void diff(int x[], int y[])
{
    int result[100];
    int count=0, k=0;

    for (int i=0 ; i<len_a ; i++)
    {
        for (int j=0 ; j<len_b ; j++)
        {
            if (x[i]==y[j])
            {
                count++;
            }
        }

        for (int j=0 ; j<k ; j++)
            {
                if (result[j] == x[i])
                {
                    count++;
                }
            }

        if (count==0)
        {
            result[k] = x[i];
            k++;
        }
        count=0;
    }

    for (int i=0 ; i<k ; i++)
    {
        printf("%d " ,result[i]);
    }
}