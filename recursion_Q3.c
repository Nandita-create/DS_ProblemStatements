//WAP To find GCD of two numbers using recursion
#include <stdio.h>

int gcd(int, int);

int main()
{
    int a, b, result;
    printf("Enter 2 nos. to find their GCD: ");
    scanf("%d %d" ,&a, &b);
    result = gcd(a, b);
    printf("The GCD of %d and %d is: %d \n" ,a,b,result);
    return 0;
}

int gcd (int x, int y)  //finds gcd regardless of which no. is greater
{
    if (y==0)
    {
        return x;
    }
    else
    {
        return (gcd(y, x%y));
    }
}