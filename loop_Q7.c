//Distribute grades to the students (Use of Loop &amp; IF-Else) 
//(Enter 5 subjects number using loop then provide the grade based on total of those numbers)

#include <stdio.h>

int main()
{
    int marks, total=0;
    char grade;
    printf("Enter marks of 5 subjects: \n");
    
    for (int i=1 ; i<=5 ; i++)
    {
        printf("Marks of Subject %d: " ,i);
        scanf("%d" ,&marks);
        if (marks<0 || marks>100)
        {
            printf("Invalid Marks \n");
            i--;
        }
        else
        {
            total = total + marks;
        }
    }

    if (total>=400)
    {
        grade = 'A';
    }
    else if (total>=300)
    {
        grade = 'B';
    }
    else if (total>=200)
    {
        grade = 'C';
    }
    else if (total>=100)
    {
        grade = 'D';
    }
    else
    {
        grade = 'F';
    }

    printf("Total Marks: %d \n" ,total);
    printf("Grade: %c \n" ,grade);
    return 0;
}