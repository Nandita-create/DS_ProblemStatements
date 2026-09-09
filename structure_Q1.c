//Create a structure name book contains Title, author, price and pages. 
//Now enter 3 books entry. And find books which has maximum number of pages. 
//Also find the book with lowest price.
#include <stdio.h>
#include <string.h>

struct Book{
    char title[100];
    char author[100];
    float price;
    int pages;
};  //semicolon after declaring structure

int main()
{
    struct Book books[3];
    int max, max_index, low_index;
    float low;

    printf("Enter the Title, author, price and pages, of 3 books: ");
    printf("\n");

    for (int i=0 ; i<3 ; i++)
    {
        printf("Title of Book %d: " ,(i+1));
        fgets(books[i].title, sizeof(books[i].title), stdin);
        printf("Author of Book %d: " ,(i+1));
        fgets(books[i].author, sizeof(books[i].author), stdin);

        books[i].title[strcspn(books[i].title, "\n")] = '\0';
        books[i].author[strcspn(books[i].author, "\n")] = '\0';
        //to elminate newline character from the end of the string

        printf("Price of Book %d: " ,(i+1));
        scanf("%f" ,&books[i].price);
        printf("Pages of Book %d: " ,(i+1));
        scanf("%d" ,&books[i].pages);

        getchar();  //to eliminate '\n' left in input buffer
    }

    max = books[0].pages;
    low = books[0].price;
    max_index = 0;
    low_index = 0;

    for (int i=1 ; i<3 ; i++)
    {
        if (books[i].pages>max)
        {
            max_index = i;
            max = books[i].pages;
        }
        if (books[i].price<low)
        {
            low_index = i;
            low = books[i].price;
        }
    }

    printf("The book with maximum no. of pages is: %s \n" ,books[max_index].title);
    printf("Pages: %d \n" ,books[max_index].pages);
    printf("The book with lowest price is: %s \n" ,books[low_index].title);
    printf("Price: %.2f \n" ,books[low_index].price);
    return 0;
}