/*Write A Menu Driven Program which has following operations:
a)	Factorial of a number
b)	Prime or not
c)	Odd or Even
d)	Exit.*/
#include <stdio.h>
#include <ctype.h>

int main()
{
    int num, x=0, fact=1, count;
    char choice;
    printf("Enter a number: ");
    scanf("%d" ,&num);
    printf("\n");

    while (x==0)
    {
        printf("Enter: \n a) Factorial of a number \n b) Prime or not \n c) Odd or Even \n d) Exit. \n");
        scanf(" %c" ,&choice);  
        //space before %c tells it to ignore newline character coming after %d, &num
        choice = tolower(choice);

        switch (choice)
        {
            case 'a':
            for (int i=1 ; i<=num ; i++)
            {
                fact = fact*i;
            }
            printf("Factorial of %d is: %d \n" ,num, fact);
            fact=1;  //for next iteration
            break;

            case 'b':
            count = 0;
            for (int i=1 ; i<=num ; i++)
            {
                if (num%i==0)
                {
                    count++;
                }
            }
            if (count==2)
            {
                printf("%d is a Prime Number \n" ,num);
            }
            else
            {
                printf("%d is not a Prime Number \n" ,num);
            }
            break;

            case 'c':
            if (num%2==0)
            {
                printf("%d is Even \n" ,num);
            }
            else
            {
                printf("%d is Odd \n" ,num);
            }
            break;

            case 'd':
            printf("Exiting Program... \n");
            x = 1;
            break;

            default:
            printf("Invalid Input \n");
        }
        printf("\n");
    }
    return 0;
}