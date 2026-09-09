//Assignment 2: Part A
#include <stdio.h>
#include <stdlib.h>

struct Node* Insert_beginning(int);
struct Node* Insert_end(int);
struct Node* Insert_position(int, int);
struct Node* Delete_beginning(struct Node*);
struct Node* Delete_end(struct Node*);
struct Node* Delete_position(struct Node*, int);
void Print(struct Node*);

struct Node{
    int val;
    struct Node* next;
};

struct Node*head;

struct Node* Insert_beginning(int value)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->val = value;
    temp->next = head;
    head = temp;
    return head;
}

struct Node* Insert_end(int value)
{
    struct Node* current = head;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->val = value;
    if(head==NULL)
    {
        head = temp;
        temp->next = NULL;
        return head;
    }

    else
    {
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp;
        temp->next = NULL;
        return head;
    }
}

struct Node* Insert_position(int value, int position)
{
    struct Node* current = head;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    int pos = 0;
    if (temp==NULL)
    {
        return head;
    }

    temp->val = value;

    for (int i = 0; i < position - 1 && current != NULL; i++)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        free(temp);
        return head;
    }

    temp->next = current->next;
    current->next = temp;
    return head;
}

struct Node* Delete_beginning(struct Node* head)
{
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node* Delete_end(struct Node* head)
{
    struct Node* current = head;
    if (head==NULL)
    {
        return NULL;
    }

    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    while(current->next->next != NULL)
    {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return head;
}

struct Node* Delete_position(struct Node* head, int position)
{
    struct Node* current = head;
    int pos = 0;
    if (head==NULL)
    {
        return NULL;
    }

    if (position==0)
    {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    for (int i = 1; i < position-1 && current->next != NULL; i++)
    {
        current = current->next;
    }

    if (current->next==NULL)
    {
        return head;
    }

    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}

void Print(struct Node* head)
{
    struct Node* current = head;
    while(current!=NULL)
    {
        if (current->next==NULL)
        {
            printf("%d " ,current->val);
        }
        else
        {
            printf("%d -> " ,current->val);
        }
        current = current->next;
    }
    printf("\n");
}

int main()
{
    int size, choice, data;
    printf("Enter length of linkedlist: ");
    scanf("%d" ,&size);

    int x=0;

    while(x==0)
    {
    printf("Enter: \n1. Insert at Beginning \n2. Insert at End \n3. Insert at Given Position \n4. Delete from Beginning \n5. Delete from End \n6. Delete from Given Position \n7. Display List \n0. Exit \n");
    scanf("%d" ,&choice);

    switch(choice)
    {
        case 1:
        printf("Enter %d elements: " ,size);
        for (int i=0 ; i<size ; i++)
        {
            scanf("%d" ,&data);
            head = Insert_beginning(data);
        }
        Print(head);
        break;

        case 2:
        printf("Enter %d elements: " ,size);
        for (int i=0 ; i<size ; i++)
        {
            scanf("%d" ,&data);
            head = Insert_end(data);
        }
        Print(head);
        break;

        case 3:
        printf("Enter %d elements: " ,size);
        int position;
        for (int i=0 ; i<size ; i++)
        {
            printf("Enter value of element %d: " ,(i+1));
            scanf("%d" ,&data);
            printf("Enter position of element %d: " ,(i+1));
            scanf("%d" ,&position);
            head = Insert_position(data, position);
        }
        Print(head);
        break;

        case 4:
        printf("Deleting a node from the beginning \n");
        head = Delete_beginning(head);
        Print(head);
        break;

        case 5:
        printf("Deleting a node from the end \n");
        head = Delete_end(head);
        Print(head);
        break;

        case 6:
        printf("Enter position from which node should be deleted: \n");
        int position_del;
        scanf("%d" ,&position_del);
        head = Delete_position(head, position_del);
        Print(head);
        break;

        case 7:
        printf("Displaying Linked List: \n");
        Print(head);
        break;

        case 0:
        printf("Exiting... \n");
        x=1;
        break;

        default:
        printf("Invalid Input \n");
    }
}
return 0;
}