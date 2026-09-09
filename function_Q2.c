//Write a function to swap 2 variables using call by value and call by reference
#include <stdio.h>

void swap1(int, int);  //for pass by value
void swap2(int *, int *);  //for pass by reference

int main()
{
    int a, b;
    printf("Enter 2 numbers: ");
    scanf("%d %d" ,&a, &b);

    printf("Before swapping: \n");
    printf("a = %d and b = %d \n " ,a,b);

    swap1 (a, b);  //pass by value

    printf("Using pass by reference: \n");
    swap2 (&a, &b);  //pass by reference
    printf("a = %d and b = %d \n" ,a,b);
    return 0;
}

void swap1 (int m, int n)
{
    int temp;
    temp = m;
    m = n;
    n = temp;
    printf("Using pass by value: \n");
    printf("a = %d and b = %d \n" ,m,n);
}

void swap2 (int *x, int *y)
{
    int var;
    var = *x;
    *x = *y;
    *y = var;
}