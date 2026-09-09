//WAP to find-out LCM of three numbers using recursion
#include <stdio.h>

int gcd(int, int);
int lcm(int, int);

int main()
{
    int a, b, c, result;
    printf("Enter 3 nos. to find their LCM: ");
    scanf("%d %d %d" ,&a, &b, &c);
    result = lcm(lcm(a, b), c);
    printf("The LCM of of %d, %d and %d is: %d \n" ,a, b, c, result);
    return 0;
}

int gcd(int m, int n)
{
    if (n==0)
    {
        return m;
    }
    else
    {
        return (gcd(n, m%n));
    }
}

int lcm(int x, int y)
{
    return ((x*y)/gcd(x, y));
    //dividing product of x and y by their gcd to get lcm
}