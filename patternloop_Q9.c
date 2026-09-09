//Pattern Programs with Increasing Numbers
#include <stdio.h>

int main()
{
    printf("Pattern 1 \n");
    int k = 1;
    for (int i=1 ; i<=4 ; i++)
    {
        for (int j=1 ; j<=i ; j++)
        {
            printf("%d " ,k);
            k++;
        }
        printf("\n");
    }
    printf("\n");

    printf("Pattern 2 \n");
    for (int i=1 ; i<=5 ; i+=2)
    {
        for (int j=i ; j<=5 ; j++)
        {
            printf(" ");
        }
        for (int j=1 ; j<=i ; j++)
        {
            if (j==1 || j==i)
            {
                printf("1 ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");

    printf("Pattern 3 \n");
    int p, mid, count, p_count=1;
    for (int i=1 ; i<=9 ; i+=2)
    {
        p = p_count;
        mid = (i+1)/2;
            for (int count=1 ; count<=mid ; count++)
            {
                printf("%d " ,p);
                p++;
            }
            p--;
            if (mid<i)
            {
                for (int count=mid ; count>1 ; count--)
                {
                    p--;
                    printf("%d " ,p);
                }
            }

        p_count++;
        printf("\n");
    }

    return 0;
}