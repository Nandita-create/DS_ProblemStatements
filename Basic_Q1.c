//Program to Find Area of Square and Circumference of a Circle
#include <stdio.h>
#define PI 3.14

int main()
{
    float side, radius;
    printf("Enter the side of a square: ");
    scanf("%f" ,&side);
    printf("Enter the radius of a circle: ");
    scanf("%f" ,&radius);
    printf("\n");
    if (side>=0)
    {
    printf("Area of the square is: %.2f unit sq.\n",(side*side));
    }
    else
    {
        printf("Length of the side should be greater than or equal to 0\n");
    }
    if (radius>=0)
    {
    printf("Circumference of the circle is: %.2f unit \n",(2*PI*radius));
    }
    else
    {
        printf("Length of the radius should be greater than or equal to 0\n");
    }
    return 0;
}