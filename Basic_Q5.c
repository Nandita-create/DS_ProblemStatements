//Program to Convert Temperature from Degree Centigrade to Fahrenheit 
#include <stdio.h>

int main()
{
    float ctemp, ftemp;
    printf("Enter the temperature in degree Centigrade: ");
    scanf("%f" ,&ctemp);
    if (ctemp>=-273.15)
    {
    ftemp = ((9*ctemp)/5)+32;
    printf("Temperature in degree Fahrenheit is: %.2f degree Fahrenheit \n" ,ftemp);
    }
    else
    {
        printf("Temperature entered should be greater than or equal to -273.15 degree Centigrade \n");
    }
    return 0;
}