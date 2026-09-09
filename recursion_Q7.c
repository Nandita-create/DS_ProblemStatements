//WAP to Reverse the number using recursion
#include <stdio.h>

int reverse(int);
int rev=0; 

int main()
{
    int num;
    printf("Enter a no. to find its reverse: ");
    scanf("%d" ,&num);
    printf("Reverse of %d is: %d \n" ,num, reverse(num));
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