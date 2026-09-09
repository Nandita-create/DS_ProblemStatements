//Program to insert Node at nth position of Linked List
#include <stdio.h>
#include <stdlib.h>

void Insert_end(int);
void Insert_between(int, int);
void Print();

struct Node
{
    int data;
    struct Node* link;
};

struct Node* head;  //head node as a global variable

int main()
{
    head = NULL;
    int n, value, position;
    printf("Enter number of elements: ");
    scanf("%d" ,&n);

    for (int i=0 ; i<n ; i++)
    {
        printf("Enter Element %d: " ,(i+1));
        scanf("%d" ,&value);
        Insert_end(value);
        Print();
    }

    printf("Enter new value: ");
    scanf("%d" ,&value);

    printf("Enter posiion (index) it should be entered at: ");
    scanf("%d" ,&position);

    Insert_between(value, position);
    Print();
    return 0;
}

void Insert_end(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = x;
    struct Node* current = head;
    if (head==NULL)
    {
        head = temp;
    }
    else
    {
    while(current->link!=NULL)
    {
        current = current->link;
    }
    current->link = temp;
}
    temp->link = NULL;
}

void Insert_between(int x, int n)
{
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node*));
    temp1->data = x;
    temp1->link = NULL;
    if (n==1)
    {
        temp1->link = head;  //to wherever head is pointing
        head = temp1;  //head points to temp1
        return;
    }

    struct Node* temp2 = head;
    for (int i=0 ; i<n-2 ; i++)
    {
        temp2 = temp2->link;
    }

    temp1->link = temp2->link;  //temp1 points to where temp2 was pointing initially
    temp2->link = temp1;  //temp2 now points to new Node temp1
}

void Print()
{
    struct Node* current = head;
    while(current!=NULL)
    {
        printf("%d " ,current->data);
        current = current->link;
    }
    printf("\n");
}