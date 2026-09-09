//Printing Patterns
#include <stdio.h>

int main()
{
    printf("Pattern 1 \n");
    for (int i=1 ; i<=4 ; i++)
    {
        for (int j=1 ; j<=i ; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    printf("Pattern 2 \n");
    for (int i=1 ; i<=5 ; i++)
    {
        for (int j=i ; j<=5 ; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    printf("Pattern 3 \n");
    for (int i=1 ; i<=7 ; i+=2)
    {
        for (int j=i ; j<=5 ; j++)
        {
            printf(" ");
        }
        for (int j=1 ; j<=i ; j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    printf("Pattern 4 \n");
    for (int i=1 ; i<=7 ; i+=2)
    {
        for (int j=i ; j<=5 ; j++)
        {
            printf(" ");
        }
        for (int j=1 ; j<=i ; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    for (int i=1 ; i<=5 ; i+=2)
    {
        for (int j=1 ; j<=i ; j++)
        {
            printf(" ");
        }
        for (int j=i ; j<=5 ; j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}