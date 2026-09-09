//Changer Lowercase to Upper Case and vice-versa
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[100];
    int i;

    printf("Enter a string: \n");
    fgets(str, sizeof(str), stdin);
    printf("Original string: %s \n" ,str);

    for (i=0 ; str[i]!='\0' ; i++)
    {
        if(isupper(str[i]))
        {
            str[i] = tolower(str[i]);
        }
        else if(islower(str[i]))
        {
            str[i] = toupper(str[i]);
        }
    }
    printf("Modified string: %s \n" ,str);
    return 0;
}