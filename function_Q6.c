//Create a function to convert decimal number to hexadecimal number. 
#include <stdio.h>

void dec_to_hex(int);

int main()
{
    int num;
    printf("Enter a decimal number: ");
    scanf("%d" ,&num);

    if (num==0)
    {
        printf("The hexadecimal equivalent of %d is: 0 \n" ,num);
    }

    printf("The hexadecimal equivalent of %d is: \n" ,num);
    dec_to_hex(num);
    return 0;
}

void dec_to_hex(int x)
{
    char hexa[32];  //array of integers
    char result[32];
    char c;
    int rem, i=0, p=0;
    while (x>0)
    {
        rem = x%16;
        if (rem>9)
        {
            c = rem + 55;
        }
        else
        {
        c = rem + '0';
        }
        hexa[i] = c;
        x = x/16;
        i++;
    }

    for (int j=i-1 ; j>=0 ; j--)
    {
        printf("%c" ,hexa[j]);
    }
}