//Create a function to convert binary number into decimal
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int bin_to_dec(int);

int main()
{
    int num, k, x=0, result;
    char str[100];
    printf("Enter a binary number: \n");
    scanf("%d" ,&num);
    int n = num;

    while (num>0)
    {
        k = num%10;
        if (k!=0 && k!=1)
        {
            printf("Number entered is not Binary \n");
            x=1;
            break;
        }
        num = num/10;
    }

    if (x==0)
    {
        result = bin_to_dec(n);
        printf("The decimal equivalent of %d is: %d \n" ,n, result);
    }
    return 0;
}

int bin_to_dec(int x)
{
    int rem, b=0, power=0;
    while (x>0)
    {
        rem = x%10;
        b = b + rem*(pow(2, power));
        x = x/10;
        power++;
    }
    return b;
}