//To check whether Number is even or Odd
#include <stdio.h>

int main()
{
    int num;
    printf("Enter a number: \n");
    scanf("%d",&num);
    if (num%2==0)
    {
        printf("%d is an Even Number \n",num);
    }
    else
    {
        printf("%d is an Odd Number \n",num);
    }
    return 0;
}