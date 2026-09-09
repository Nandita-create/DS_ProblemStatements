//check weather no is positive, negative or zero 
#include <stdio.h>

int main()
{
    int num;
    printf("Enter a number: \n");
    scanf("%d" ,&num);
    if (num>0)
    {
        printf("%d is Positive \n",num);
    }
    else if (num<0)
    {
        printf("%d is Negative \n",num);
    }
    else
    {
        printf("%d is Zero \n",num);
    }
    return 0;
}