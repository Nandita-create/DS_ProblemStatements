//Compound Interest 
#include <stdio.h>
#include <math.h>

int main()
{
    float p, r, t, amount, interest;
    int n;
    printf("Enter the principal amount: ");
    scanf("%f" ,&p);
    printf("Enter the rate of interest (in %% per annum): ");
    scanf("%f" ,&r);
    printf("Enter the time (in years): ");
    scanf("%f" ,&t);
    printf("Enter the no. of times interest is compounded per year: ");
    scanf("%d" ,&n);
    printf("\n");
    if (p>=0 && r>=0 && t>=0 && n>0)
    {
        amount = (p*pow(1+ (r/(100*n)),(n*t)));
        interest = amount - p;
        printf("Compound Interest is: Rs. %.2f \n" ,interest);
        printf("Final Amount is: Rs. %.2f \n" ,amount);
    }
    else
    {
        printf("Principal amount, rate of interest and time should be greater than or equal to 0 \n");
        printf("No. of times interest is compounded per year should be greater than 0 \n");
    }
    return 0;
}