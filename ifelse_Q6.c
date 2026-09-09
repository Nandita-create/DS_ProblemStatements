//Check whether character is vowel or not
#include <stdio.h>
#include <ctype.h>

int main()
{
    char c, letter;
    printf("Enter a character: ");
    scanf(" %c" ,&c);
    letter = c;
        c = tolower(c);
        if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        {
            printf("%c is a vowel \n" ,letter);
        }
        else
        {
            printf("%c is a not vowel \n" ,letter);
        }
        return 0;
    }