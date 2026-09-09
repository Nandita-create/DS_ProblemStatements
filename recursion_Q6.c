//WAP To check number is prime or not using recursion
#include <stdio.h>

int prime(int, int);
int count=0;

int main()
{
    int num;
    printf("Enter a no. to check if it is prime or not: ");
    scanf("%d" ,&num);
    if (num<=1)
    {
        printf("%d is not Prime \n" ,num);
    }
    else if (prime(1, num)==2)  //if num has only 2 factors
    {
        printf("%d is Prime \n" ,num);
    }
    else
    {
        printf("%d is not Prime \n" ,num);
    }
    return 0;
}

int prime(int x, int y)
{
    if (x==y)
    {
        count++;
        return count;
    }
    else if (y%x==0)
    {
        count++;
        return (prime(x+1, y));
    }
    else
    {
        return (prime(x+1, y));
    }
}