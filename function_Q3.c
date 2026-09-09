//Create a function to print all prime numbers between two numbers 
//(For eg print all prime numbers between 10 to 80 )
#include <stdio.h>
#include <stdbool.h>  //for using Boolean values

bool prime(int);

int main()
{
    int m, n;
    printf("Enter the start of the range: ");
    scanf("%d" ,&m);
    printf("Enter the end of the range: ");
    scanf("%d" ,&n);
    printf("Prime nos. between %d and %d are: \n" ,m, n);
    for (int i=m ; i<=n ; i++)
    {
        if (prime(i) == true)
        {
            printf("%d " ,i);
        }
    }
    printf("\n");
    return 0;
}

bool prime (int num)
{
    int count = 0;
    for (int i=1 ; i<=num ; i++)
    {
        if (num%i==0)
        {
            count++;
        }
    }

    if (count==2)
    {
        return true;  //number is prime
    }
    else
    {
        return false;  //number is not prime
    }
}