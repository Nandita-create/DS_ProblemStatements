//Write A Menu Driven Program To Convert 
//Fahrenheit Temperature to Centigrade Or Centigrade To Fahrenheit Temperature. 
//(1.Convert C to F  \n 2.Convert F to C  )
#include <stdio.h>

int main()
{
    int choice;
    float ctemp, ftemp;
    printf("Press 1. Convert C to F \nPress 2. Convert F to C \n");
    scanf("%d" ,&choice);
    
    switch (choice)
    {
        case 1:
        printf("Enter the temperature in degree Centigrade: ");
        scanf("%f" ,&ctemp);
        if (ctemp>=-273.15)
        {
            ftemp = ((ctemp*9)/5) + 32;
            printf("Temperature in degree Fahrenheit is: %.2f \n" ,ftemp, " degree Fahrenheit");
        }
        else{
            printf("Temperature in degree Centigrade should be greater than or equal to -273.15 degree Centigrade \n");
        }
        break;

        case 2:
        printf("Enter the temperature in degree Fahrenheit: ");
        scanf("%f" ,&ftemp);
        if (ftemp>=-459.67)
        {
            ctemp = ((ftemp-32)*5)/9;
            printf("Temperature in degree Centigrade is: %.2f \n" ,ctemp, " degree Centigrade");
        }
        else{
            printf("Temperature in degree Fahrenheit should be greater than or equal to -459.67 degree Centigrade \n");
        }
        break;

        default:
        printf("Invalid Input \n");
    }
    return 0;
}