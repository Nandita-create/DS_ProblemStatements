//Program to Find Sum and Average of Three Real Numbers
#include <stdio.h>

int main()
{
    float a, b, c, sum, average;
    printf("Enter the first no.: ");
    scanf("%f" ,&a);
    printf("Enter the second no.: ");
    scanf("%f" ,&b);
    printf("Enter the third no.: ");
    scanf("%f" ,&c);
    sum = a+b+c;
    average = sum/3;
    printf("The sum is: %.2f \n" ,sum);
    printf("The average is: %.2f \n" ,average);
    return 0;
}