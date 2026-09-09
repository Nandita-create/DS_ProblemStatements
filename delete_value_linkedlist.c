/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


//Optimised Solution

/*#include <stdlib.h>

struct ListNode* removeElements(struct ListNode* head, int val) {
    // Dummy node on the stack simplifies removing the head node
    struct ListNode dummy;
    dummy.next = head;
    
    struct ListNode* current = &dummy;
    
    while (current->next != NULL) {
        if (current->next->val == val) {
            // Node to remove found
            struct ListNode* temp = current->next;
            current->next = current->next->next;
            free(temp); // Free allocated memory
        } else {
            // Move forward only if no node was deleted
            current = current->next;
        }
    }
    
    return dummy.next;
}*/


#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void printList(struct ListNode *);
void freeList(struct ListNode *);

struct ListNode* removeElements(struct ListNode* head, int val) {
    //struct ListNode* list = (struct ListNode*)malloc(sizeof(struct ListNode*));
    
    struct ListNode* temp1 = (struct ListNode*)malloc(sizeof(struct ListNode*));
    struct ListNode* temp2 = (struct ListNode*)malloc(sizeof(struct ListNode*));
    if(head==NULL)
    {
        return NULL;
    }

    struct ListNode* current = head;
    int n=1;

    while(current->next!=NULL)
    {
        if (current->val==val)
        {
            temp1->next = head;
            
            if(n==1)
            {
                head = temp1;
                free(temp1);
                n++;
                continue;
            }
            for(int i=0 ; i<n-2 ; i++)
            {
                temp1 = temp1->next;
            }
            temp2 = temp1->next;
            temp1->next = temp2->next;
            free(temp2);
            n++;
            continue;
            }
            n++;
            }
            return head;
            }

void printList(struct ListNode *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(struct ListNode *head)
{
    while (head != NULL)
    {
        struct ListNode *temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    // Create list: 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6

    struct ListNode *head = malloc(sizeof(struct ListNode));
    head->val = 1;

    head->next = malloc(sizeof(struct ListNode));
    head->next->val = 2;

    head->next->next = malloc(sizeof(struct ListNode));
    head->next->next->val = 6;

    head->next->next->next = malloc(sizeof(struct ListNode));
    head->next->next->next->val = 3;

    head->next->next->next->next = malloc(sizeof(struct ListNode));
    head->next->next->next->next->val = 4;

    head->next->next->next->next->next = malloc(sizeof(struct ListNode));
    head->next->next->next->next->next->val = 5;

    head->next->next->next->next->next->next = malloc(sizeof(struct ListNode));
    head->next->next->next->next->next->next->val = 6;
    head->next->next->next->next->next->next->next = NULL;

    printf("Original List:\n");
    printList(head);

    head = removeElements(head, 6);

    printf("After removing 6:\n");
    printList(head);

    freeList(head);

    return 0;
}


/*void Delete(struct ListNode*, int);

struct ListNode* removeElements(struct ListNode* head, int val) {
    //struct ListNode* list = (struct ListNode*)malloc(sizeof(struct ListNode*));

    if(head==NULL)
    {
        return NULL;
    }

    struct ListNode* current = head;
    int n=1;

    while(current->next!=NULL)
    {
        if (current->val==val)
        {
            Delete(head, n);
            n++;
            continue;
        }
        n++;
    }
    return head;
}

void Delete(struct ListNode* head, int n)
{
    struct ListNode* temp1 = (struct ListNode*)malloc(sizeof(struct ListNode*));temp1->next = head;

    if(n==1)
    {
        head = temp1;
        free(temp1);
        return;
    }

    for(int i=0 ; i<n-2 ; i++)
    {
        temp1 = temp1->next;
    }
    struct ListNode* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
    return;
}*/