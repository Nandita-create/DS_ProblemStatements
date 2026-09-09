//Program to delete element at nth position in a Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* link;
};

void Insert(int, int);
void Print();
void Delete(int);

struct Node* head;

int main()
{
    head = NULL;
    int num, value, position;
    int n;  //position of element to be deleted
    printf("Enter no. of elements: ");
    scanf("%d" ,&num);

    for (int i=0 ; i<num ; i++)
    {
        printf("Enter element %d: ",(i+1));
        scanf("%d" ,&value);

        printf("Enter position: ");
        scanf("%d" ,&position);

        if(position>num)
        {
            printf("Invalid Position \n");
            i--;
            continue;
        }

        Insert(value, position);
    }
    Print();

    printf("Enter position of element to be deleted: ");
    scanf("%d" ,&n);
    if (n>num)
    {
        printf("Invalid Position \n");
        return 1;
    }

    Delete(n);
    Print();

    return 0;
}

void Insert(int value, int position)
{
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node*));
    temp1->data = value;
    temp1->link = NULL;
    if (position==1)
    {
        temp1->link = head;
        head = temp1;
        return;
    }

        struct Node* temp2 = head;
        for (int i=0 ; i<position-2 ; i++)
        {
            temp2 = temp2->link;
        }

        temp1->link = temp2->link;
        temp2->link = temp1;
}

void Delete(int n)
{
    struct Node* temp1 = head;
    if(n==1)
    {
        head = temp1->link;
        free(temp1);
        return;
    }

    for (int i=0 ; i<n-2 ; i++)
    {
        temp1 = temp1->link;
    }
    
    struct Node* temp2 = temp1->link;
    temp1->link = temp2->link;  //ignoring nth node from linked list
    free(temp2);
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