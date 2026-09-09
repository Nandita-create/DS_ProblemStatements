//Program to insert node at end and at beginning of linked list
#include <stdio.h>
#include <stdlib.h>

void Insert_start(int);
void Insert_end(int);
void Print();

struct Node
{
    int data;
    struct Node* link;
};

struct Node* head;

int main()
{
    head = NULL;
    int n, choice, value;
    printf("Enter number of elements: ");
    scanf("%d" ,&n);

    for (int i=0 ; i<n ; i++)
    {
        printf("Enter 1 to insert at start and 2 to insert at end: ");
        scanf("%d" ,&choice);

        if (choice==1)
        {
            printf("Enter element %d: " ,(i+1));
            scanf("%d" ,&value);
            Insert_start(value);
            Print();
        }
        else if (choice==2)
        {
            printf("Enter element %d: " ,(i+1));
            scanf("%d" ,&value);
            Insert_end(value);
            Print();
        }
        else
        {
            printf("Invalid Choice\n");
            i--;
        }
    }
}

void Insert_start(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = x;
    if (head!=NULL)  //if list is not empty
    {
        temp->link = head;
    }
    else
    {
        temp->link = NULL;
    }
    head = temp;
}

void Insert_end(int y)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = y;
    if(head==NULL)  //if list is empty
    {
        head = temp;
    }
    else
    {
        struct Node* current = head;
        //traverse list until last Node is reached. Then add new Node to link of last Node
        while(current->link!=NULL)  //so that it does not stop at NULL
        {
            current = current->link;
        }
        current->link = temp;  //link of last Node points to new Node
    }
    temp->link = NULL;  //new Node points to NULL as it is now the last Node in the list
}

void Print()
{
    struct Node* temp = head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("\n");
}