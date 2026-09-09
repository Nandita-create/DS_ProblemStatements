//WAP to Count Vowels in given string.
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char str[100], c;
    int len, vowel=0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    len = strlen(str);

    for (int i=0 ; i<len ; i++)
    {
        c = tolower(str[i]);
        if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        {
            vowel++;
        }
    }

    printf("No. of vowels in the string are: %d \n" ,vowel);
    return 0;
}