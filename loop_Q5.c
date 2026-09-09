//To reverse the Number (1234  4321)
#include <stdio.h>

int main()
{
    int num, rem, rev=0;
    printf("Enter a number to be reversed: ");
    scanf("%d" ,&num);

    while (num>0)
    {
        rem = num%10;
        rev = (rev*10) + rem;
        num = num/10;
    }

    printf("Reversed No.: %d \n" ,rev);
    return 0;
}