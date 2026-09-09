//WAP To print Fibonacci series with recursion
#include <stdio.h>

int fib(int);;

int main()
{
    int num, result;
    printf("Enter no. of terms in the fibonacci series: ");
    scanf("%d" ,&num);  //alway put & before input variable 
    printf("Fibonaaci Series till %d elements is: \n" ,num);
    for (int i=1 ; i<=num ; i++)
    {
        result = fib(i);
        if (i==num)
        {
            printf("%d \n" ,result);
        }
        else
        {
            printf("%d, ",result);
        }
    }
    return 0;
}

int fib (int x)
{
    if (x==1)
    {
        return 0;
    }
    else if (x==2)
    {
        return 1;
    }
    else
    {
        return (fib(x-1) + fib(x-2));
    }
}