//Fibonnaci series
#include <stdio.h>

int main()
{
    int n, count=0, t1=0, t2=1, nextTerm;
    printf("Enter number of terms in Fibonacci Series: ");
    scanf("%d" ,&n);
    for (int i=0 ; i<n ; i++)
    {
        printf("%d" ,t1);

        if (i<n-1)
        {
            printf(", ");
        }

        nextTerm = t1+t2;
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");
    return 0;
}