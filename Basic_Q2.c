//Program to Find Area of a Triangle using Heron's Formula
#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, s, area;
    printf("Enter the first side of the trianlge: ");
    scanf("%f" ,&a);
    printf("Enter the second side of the triangle: ");
    scanf("%f" ,&b);
    printf("Enter the third side of the triangle: ");
    scanf("%f" ,&c);
    printf("\n");
    if (a>=0 && b>=0 && c>=0)
    {
    s = (a+b+c)/2;
    area = sqrt(s*(s-a)*(s-b)*(s-c));
    printf("Area of the triangle is: %.2f unit sq. \n" ,area);
    }
    else
    {
        printf("Length of all sides of the triangle should be greater than or equal to 0 \n");
    }
    return 0;
}