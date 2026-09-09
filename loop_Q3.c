//Factorial of a number
#include <stdio.h>

int main()
{
    int num, fact=1;
    printf("Enter a no. to find Factorial: ");
    scanf("%d" ,&num);

    for (int i=1 ; i<=num ; i++)
    {
        fact = fact*i;
    }
    printf("he factorial of %d is: %d \n" ,num, fact);
    return 0;
}