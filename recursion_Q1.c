//WAP To find factorial of a number using recursion
#include <stdio.h>

int fact(int);

int main()
{
    int num, factorial;
    printf("Enter a no. to find the factorial: ");
    scanf("%d" ,&num);
    if (num<0)
    {
        printf("Factorial of only 0 or positive nos. can be found \n");
    }
    else
    {
        factorial = fact(num);
        printf("Factorial of %d is: %d \n" ,num, factorial);
    }
    return 0;
}

int fact (int x)  //recursive function
{
    if (x==0)
    {
        return 1;
    }
    else
    {
        return (x * fact(x-1));
    }
}