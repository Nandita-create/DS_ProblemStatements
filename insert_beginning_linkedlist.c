//INserting Node at the beginning of a Linked List
#include <stdio.h>
#include <stdlib.h>

void Insert(int);
void Print();

struct Node
{
    int data;  //based on datatype of elements being entered, for eg. char data
    struct Node* link;
};  //always put semicolon after declaring structure

struct Node* head;  //global variable for head node

int main()
{
    int n, value;
    head = NULL;
    printf("Enter number of elements: ");
    scanf("%d" ,&n);

    for (int i=0 ; i<n ; i++)
    {
        printf("Enter Element %d: ",(i+1));
        scanf("%d" ,&value);
        Insert(value);
        Print();
    }
}

void Insert(int value)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));  //creating new node
    temp->data = value;
    if (head!=NULL)
    {
        temp->link = head;  //where head was initially pointing
    }
    else  //if it is the first element being inserted in the empty list
    {
        temp->link = NULL;
    }
    head = temp;  //now head points to address of new Node
}

void Print()
{
    struct Node* temp = head;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("\n");
}