//Create a function to convert  decimal number into binary
#include <stdio.h>

void dec_to_bin(int);

int main()
{
    int num;
    printf("Enter a decimal number: ");
    scanf("%d" ,&num);
    printf("The binary equivalent of %d is: " ,num);
    dec_to_bin(num);
    return 0;
}

void dec_to_bin(int x)
{
    int bin[32];  //array of integers
    int rem, i=0;
    while (x>0)
    {
        rem = x%2;
        bin[i] = rem;
        x = x/2;
        i++;
    }

    for (int j=i-1 ; j>=0 ; j--)
    {
        printf("%d" ,bin[j]);
    }
}