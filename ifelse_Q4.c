//Second Largest no out of 3 (Nested If-else)
#include <stdio.h>

int main()
{
    int a, b, c;
    printf("Enter 3 numbers: \n");
    scanf("%d" ,&a);
    scanf("%d" ,&b);
    scanf("%d" ,&c);

    if (a==b && b==c)
    {
        printf("All numbers are equal \n");
    }

    else
    {
        printf("The Second Largest no. is: ");
        if (a==b)
        {
            if (a>c)
            {
                printf("%d",c,"\n");
            }
            else if (c>a)
            {
                printf("%d",a, "\n");
            }
        }

        else if (a==c)
        {
            if (a>b)
            {
                printf("%d",b, "\n");;
            }
            else if (b>a)
            {
                printf("%d",a, "\n");
            }
        }

        else if (b==c)
        {
            if (b>a)
            {
                printf("%d",a, "\n");
            }
            else if (a>b)
            {
                printf("%d",b, "\n");
            }
        }

        else if (a>b)
        {
            if (c>a)
            {
                printf("%d",a, "\n");
            }
            else if (c>b)
            {
                printf("%d",c, "\n");
            }
            else if (b>c)
            {
                printf("%d",b, "\n");
            }
        }

        else if (b>a)
        {
            if (c>b)
            {
                printf("%d",b, "\n");
            }
            else if (c>a)
            {
                printf("%d",c, "\n");
            }
            else if (a>c)
            {
                printf("%d",a, "\n");
            }
        }
    }
    printf("\n");
    return 0;
}