//Assignment 2: Part B
#include <stdio.h>
#include <stdlib.h>

struct Node* Insert(int);
void Print(struct Node*);
void Even_num(struct Node*);
struct Node* swap(struct Node*);

//Doubly Linked List
struct Node{
    int val;
    struct Node* prev;
    struct Node* next;
};

struct Node* head;

struct Node* Insert(int value)
{
    struct Node* current = head;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->val = value;
    if (head==NULL)
    {
    temp->next = head;
    temp->prev = NULL;
    head = temp;
    return head;
    }

    while(current->next!=NULL)
    {
        current = current->next;
    }
    current->next = temp;
    temp->next = NULL;
    temp->prev = current;

    return head;
}

void Print(struct Node* head)
{
    struct Node* current = head;
    while(current!= NULL)
    {
        if (current->next == NULL)
        printf("%d " ,current->val);

        else
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("\n");
}

void Even_num(struct Node* head)
{
    struct Node* current = head;
    printf("Nodes containing Even Numbers: \n");
    while(current!=NULL)
    {
        if (current->val%2==0)
        {
            printf("%d " ,current->val);
        }
        current = current->next;
    }
    printf("\n");
}

struct Node* swap(struct Node* head)
{
    // Empty list or single-node list
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    struct Node* first = head;
    struct Node* last = head;

    // Find last node
    while (last->next != NULL)
    {
        last = last->next;
    }

    // Two-node list
    if (first->next == last)
    {
        last->next = first;
        last->prev = NULL;

        first->prev = last;
        first->next = NULL;

        return last;
    }

    struct Node* second = first->next;
    struct Node* secondLast = last->prev;

    // Make last the new head
    last->prev = NULL;
    last->next = second;

    second->prev = last;

    // Make first the new last
    first->next = NULL;
    first->prev = secondLast;

    secondLast->next = first;

    return last;
}

int main()
{
    head = NULL;
    int size, data, choice, x=0;
    printf("Enter size of Doubly Linked List: ");
    scanf("%d" ,&size);

    while(x==0)
    {
        printf("Enter: \n1. Insert Node \n2. Display List \n3. Find Nodes Containing Even Numbers \n4. Swap First and Last Nodes \n0. Exit \n");
        scanf("%d" ,&choice);

        switch(choice)
        {
            case 1:
            printf("Enter %d elements: " ,size);
            for (int i=0 ; i<size ; i++)
            {
                scanf("%d" ,&data);
                head = Insert(data);
            }
            Print(head);
            break;

            case 2:
            printf("Displaying Doubly Linked List: \n");
            Print(head);
            break;

            case 3:
            Even_num(head);
            break;

            case 4:
            printf("Linked List after Swapping First and Last Node: \n");
            head = swap(head);
            Print(head);
            break;

            case 0:
            printf("Exiting...\n");
            x=1;
            break;

            default:
            printf("Invalid Input \n");
            break;
        }
    }
    return 0;
}