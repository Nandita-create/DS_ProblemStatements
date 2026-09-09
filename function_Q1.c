/*Write A Menu Driven Program using function which has following function:
a) Factorial of a number
b) Prime or not
c) Odd or Even
d) Exit*/
#include <stdio.h>
#include <ctype.h>

int fact(int);
void prime(int);
void oddeven(int);

int main()
{
    int num, x=0;
    char choice;
    printf("Enter a number: ");
    scanf("%d" ,&num);
    printf("\n");
    while (x==0)
    {
        printf("Enter: \n a) Factorial of a number \n b) Prime or not \n c) Odd or Even \n d) Exit \n");
        scanf(" %c" ,&choice);
        choice = tolower(choice);

        switch (choice)
        {
            case 'a':
            if (num<0)
            {
                printf("Factorial of only zero or a positive number can be found \n");
            }
            else
            {
                printf("The factorial of %d is: %d \n" ,num, fact(num));
            }
            break;

            case 'b':
            if (num<0)
            {
                printf("Prime or not can only be checked for zero or a positive number \n");
            }
            else
            {
                prime(num);
            }
            break;

            case 'c':
            oddeven(num);
            break;

            case 'd':
            printf("Exiting Prgram... \n");
            x=1;
            break;

            default:
            printf("Invalid Input \n");
        }
    }
    return 0;
}

int fact (int x)
{
    int result=1;
    for (int i=1 ; i<=x ; i++)
    {
        result = result*i;
    }
    return result;
}

void prime (int y)
{
    int count=0;
    for (int i=1 ; i<=y ; i++)
    {
        if (y%i==0)
        {
            count++;
        }
    }
    if (count==2)
    {
        printf("%d is Prime \n" ,y);
    }
    else
    {
        printf("%d is not Prime \n" ,y);
    }
}

void oddeven (int z)
{
    if (z%2==0)
    {
        printf("%d is Even \n" ,z);
    }
    else
    {
        printf("%d is Odd \n" ,z);
    }
}