//Program to Reverse a Linked List
#include <stdio.h>
#include <stdlib.h>

void Reverse();
void Insert(int);
void Print();

struct Node
{
    int data;
    struct Node *link;
};

struct Node *head;

void Reverse()  //as head is global. Otherwise void Reverse(head)
{
    struct Node *current, *prev, *next;
    current = head;
    prev = NULL;

    while (current!=NULL)
    {
        next = current->link;
        current->link=prev;
        prev = current;
        current = next;
    }
    head = prev;  //head points to original last node
}

int main()
{
    head=NULL;
    int len, value, position;
    printf("Enter number of elements: ");
    scanf("%d" ,&len);

    for (int i=0 ; i<len ; i++)
    {
        printf("Enter element %d: ",(i+1));
        scanf("%d" ,&value);

        Insert(value);
    }
    Print();

    Reverse();

    Print();
    return 0;
}

void Insert(int n)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = n;

    if (head==NULL)
    {
        head = temp;
    }

    else
    {
        struct Node *current = head;

        while(current->link!=NULL)
            {
                current = current->link;
            }
            current->link = temp;
        }

    temp->link = NULL;
}

void Print()
{
    struct Node *current = head;
    while(current!=NULL)
    {
        printf("%d " ,current->data);
        current = current->link;
    }
    printf("\n");
}