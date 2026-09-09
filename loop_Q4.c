//to find sum of the digits of the no.
#include <stdio.h>

int main()
{
    int num, rem, sum=0;
    printf("Enter a number: ");
    scanf("%d" ,&num);
    int n=num;

    while (num>0)
    {
        rem = num%10;
        sum = sum + rem;
        num = num/10;
    }
    
    printf("The sum of digits of %d is: %d \n" ,n, sum);
    return 0;
}