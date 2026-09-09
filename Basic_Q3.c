//Simple Interest
#include <stdio.h>

int main()
{
    float p, r, t, interest;
    printf("Enter the principal amount (in Rs.): ");
    scanf("%f" ,&p);
    printf("Enter the rate of interest (in %% per annum): ");  //%% to print percentage sign
    scanf("%f" ,&r);
    printf("Enter the time (in years): ");
    scanf("%f", &t);
    if (p>=0 && r>=0 && t>=0)
    {
    interest = (p*r*t)/100;
    printf("Simple Interest is: Rs. %.2f \n " ,interest);
    printf("Final Amount is: Rs. %.2f \n" ,(p+interest));
    }
    else
    {
        printf("Principal amount, rate of interest and time should be greater than or equal to 0");
    }
    return 0;
}