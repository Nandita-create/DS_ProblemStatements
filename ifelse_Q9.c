//Calculator using switch 
//(1.Addation\n 2.Subtraction \n 3.Multiplication \n 4.Divide&quot;))
#include <stdio.h>

int main()
{
    int a, b, choice;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("\n");
    printf("Enter:\n 1.Addition\n 2.Subtraction \n 3.Multiplication \n 4.Divide&quot \n");
    scanf("%d" ,&choice);
    printf("\n");
    switch (choice)
    {
        case 1:
        printf("Addition of %d and %d is: %d\n" ,a, b, (a+b));
        break;

        case 2:
        if (a>b)
        {
            printf("Difference between %d and %d is: %d\n" ,a, b, (a-b));
        }
        else
        {
            printf("Difference between %d and %d is: %d\n" ,b, a, (b-a));
        }
        break;

        case 3:
        printf("Product of %d and %d is: %d\n" ,a ,b ,(a*b));
        break;

        case 4:
        if (b!=0)
        {
            printf("Quotient of %d divided by %d is: %.2f\n" ,a, b, ((float)a/(float)b));
        }
        else
        {
            printf("Number cannot be divided by zero \n");
        }
        break;

        default:
        printf("Invalid Input");
    }
    return 0;
}