//Switch to tell days of the week(mean 1 for Monday, 2 for Tuesday ……. 7 for sunday)
#include <stdio.h>

int main()
{
    int n;
    printf("Enter a number from 1 to 7: \n");
    scanf("%d" ,&n);
    switch (n)
    {
        case 1:
        printf("The day of the week is: Monday \n");
        break;
        //always put break at the end of each case to prevent fall through

        case 2:
        printf("The day of the week is: Tuesday \n");
        break;

        case 3:
        printf("The day of the week is: Wednesday \n");
        break;

        case 4:
        printf("The day of the week is: Thursday \n");
        break;

        case 5:
        printf("The day of the week is: Friday \n");
        break;

        case 6:
        printf("The day of the week is: Saturday \n");
        break;

        case 7:
        printf("The day of the week is: Sunday \n");
        break;

        default:
        printf("Number entered should be from 1 to 7 only!! \n");
    }
    return 0;
}