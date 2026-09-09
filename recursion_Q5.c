//WAP to find given number is a palindrome or not using recursion
#include <stdio.h>

int reverse(int);
int rev=0; 

int main()
{
    int num;
    printf("Enter a no. to check if palindrome or not: ");
    scanf("%d" ,&num);
    if (reverse(num)==num)
    {
        printf("%d is a Palindrome \n" ,num);
    }
    else
    {
        printf("%d is not a Palindrome \n" ,num);
    }
    return 0;
}

int reverse(int x)
{
    if (x==0)
    {
        return rev;
    }
    else
    {
        rev = (rev*10) + (x%10);
        return (reverse(x/10));
    }
}