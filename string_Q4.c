//Create a function to reverse string.
#include <stdio.h>
#include <string.h>

void rev(char []);

int main()
{
    char str[100];
    printf("Enter a string to be reversed: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';
    //strcspn is string complementary span which finds where "\n" is located

    rev(str);
    return 0;
}

void rev(char x[])
{
    char result[100];
    int j=0;
    int len = strlen(x);

    for (int i=len-1 ; i>=0 ; i--)
    {
        result[j] = x[i];
        j++;
    }

    result[j] = '\0';  //terminating string with '\0' character
    printf("The reversed string is: %s \n" ,result);
}