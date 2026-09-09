//Create a function to Concatenate 2 strings
#include <stdio.h>
#include <string.h>

void concat(char [], char []);

int main()
{
    char str1[100];
    char str2[100];

    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    
    //removing newline character after each of the strings
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    concat(str1, str2);  //passing arguments to the user-defined function concat

    return 0;
}

void concat(char x[], char y[])
{
    char result[200];  //as str1[100] and str2[100] to avoid overflow
    int len1, len2, j=0;
    len1 = strlen(x);
    len2 = strlen(y);

    for (int i=0 ; i<len1 ; i++)
    {
        result[j] = x[i];
        j++;
    }

    for (int i=0 ; i<len2 ; i++)
    {
        result[j] = y[i];
        j++;
    }

    result[j]='\0';  //terminating resultant string

    printf("Concatenated string: %s \n" ,result);
}