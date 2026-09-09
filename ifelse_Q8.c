//Provide Remarks according to grade using Switch case 
//(take the grade from user like A, B , C,D,F and remarks for 
//A is Outstanding, B excellent , C Good, D- Average need to work hard, F – fail) 
#include <stdio.h>
#include <ctype.h>

int main()
{
    char grade;
    printf("Enter the grade: ");
    scanf("%c" ,&grade);
    grade = toupper(grade);
    switch (grade)
    {
        case 'A':
        printf("Outstanding \n");
        break;

        case 'B':
        printf("Excellent \n");
        break;

        case 'C':
        printf("Good \n");
        break;

        case 'D':
        printf("Average need to work hard \n");
        break;

        case 'F':
        printf("Fail \n");
        break;

        default:
        printf("Invalid Grade Entered \n");
    }
    return 0;
}