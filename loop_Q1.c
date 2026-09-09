//Sum of first 10 numbers.
#include <stdio.h>

int main()
{
    int sum = 0;
    for (int i=1 ; i<=10 ; i++)
    {
        sum = sum + i;
    }
    printf("Sum of first 10 numbers is: %d \n" ,sum);
    return 0;
}