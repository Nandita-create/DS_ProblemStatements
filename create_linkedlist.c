//Program to create a linked list
//Use a new Node for each element
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* link;
};

int main()
{
    struct Node* A;
    A = NULL;
    //need to mention'struct' Node* A in C, not just Node* A

    struct Node* first = (struct Node *)malloc(sizeof(struct Node));

    first->data = 2;
    first->link = NULL;
    A = first;  //address of added node

    //Traverse List - Visit each item of the list one by one
    struct Node* temp1 = A;
    printf("Adding 1st element to the linked list: \n");
    while (temp1!=NULL)
    {
        printf("%d ",temp1->data);
        temp1 = temp1->link;
    }

    //Adding 2 more elements to the list. Use new pointer variable for this.
    //Do not reuse previous pointers
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    second->data = 4;
    second->link = NULL;
    first->link = second;  //linking to 1st element

    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    third->data = 6;
    third->link = NULL;
    second->link = third;  //linking to 2nd element

    printf("\nAdded 2 more elements to the linked list: \n");
    struct Node* temp2 = A;
    while(temp2!=NULL)
    {
        printf("%d " ,temp2->data);
        temp2 = temp2->link;
    }
    return 0;
}

//In linked list,
//Entire node is of type Node datatype
//'Value' part of node is int datatype
//'Address of next node' part of node is Node* datatype