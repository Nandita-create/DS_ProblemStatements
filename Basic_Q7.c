//Program to Calculate the Net Salary (Enter the basic salary. DA is 10% of basic Salary, 
//HRA is 30% of Basic salary, Medical is 20% of Basic Salary and 
//Travel allowance is 15% of basic salary so calculate Net salary)
#include <stdio.h>

int main()
{
    float basic_salary, da, hra, medical, travel, net_salary;
    printf("Enter the basic salary: ");
    scanf("%f" ,&basic_salary);
    if (basic_salary>=0)
    {
    da = (10*basic_salary)/100;  
    //do not write as (10/100)*basic_salary as it takes integer division to be 0, in this case
    hra = (30*basic_salary)/100;
    medical = (20*basic_salary)/100;
    travel = (15*basic_salary)/100;
    net_salary = basic_salary + da + hra + medical + travel;
    printf("The Net Salary is: Rs. %.2f \n" ,net_salary);
    }
    else
    {
        printf("Basic salary should be greater than or equal to 0");
    }
    return 0;
}