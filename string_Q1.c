//WAP to Remove all characters that are not alphabets in String.
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char str[100];
    char result[100];
    int len, value, j=0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    len = strlen(str);  //counts '\0' character too

    for (int i=0 ; i<len ; i++)
    {
        value = str[i];
        if ((value>=65 && value<=90) || (value>=97 && value<=122))
        {
            result[j] = str[i];
            j++;
        }
    }

    printf("String with only alphabet characters: %s \n" ,result);
    return 0;
}