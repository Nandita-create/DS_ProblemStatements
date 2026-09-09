/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
 };

void printList(struct ListNode*);
void freeList(struct ListNode*);
struct ListNode* createListFromInput(const char*);
struct ListNode*  createNode(int);
void Insert_end(int);

struct ListNode* sum_head;

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    //struct ListNode *temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    //struct ListNode *sum = (struct ListNode*)malloc(sizeof(struct ListNode));
    sum_head = NULL;
    struct ListNode *head = NULL;
    struct ListNode *current;
    int valuel1=0;
    int valuel2=0;
    int carry = 0;
    int value;

    while(l1!=NULL || l2!=NULL || carry!=0)
    {
        if (l1!=NULL)
        {
            valuel1 = l1->val;
            l1 = l1->next;
        }
        else
        {
            valuel1 = 0;
        }

        if (l2!=NULL)
        {
            valuel2 = l2->val;
            l2 = l2->next;
        }
        else
        {
            valuel2=0;
        }

        value = valuel2 + valuel1 + carry;
        carry=0;
        
        //int value = sum->val;
        if (value >=10)
        {
            carry = (value)/10;
            value = (value)%10;
        }

        Insert_end(value);
        
    }
    return sum_head;
}

void Insert_end(int x)
{
    struct ListNode* current = sum_head;
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->val = x;

    if (current==NULL)
    {
        sum_head = temp;
        temp->next=NULL;
        return;
    }

    while (current->next!=NULL)
    {
        current = current->next;
    }
    current->next = temp;
    temp->next = NULL;
}

int main() {
    // Dynamic list creation from user input
    struct ListNode* l1 = createListFromInput("List 1");
    struct ListNode* l2 = createListFromInput("List 2");

    if (l1 == NULL || l2 == NULL) {
        printf("Invalid input or empty list provided.\n");
        freeList(l1);
        freeList(l2);
        return 1;
    }

    printf("\nInput List 1: ");
    printList(l1);

    printf("Input List 2: ");
    printList(l2);

    // Compute sum
    struct ListNode* result = addTwoNumbers(l1, l2);

    printf("Result List : ");
    printList(result);

    // Free all allocated memory
    freeList(l1);
    freeList(l2);
    freeList(result);

    return 0;
}

void printList(struct ListNode* head) {
    struct ListNode* curr = head;
    while (curr != NULL) {
        printf("%d", curr->val);
        if (curr->next != NULL) printf(" -> ");
        curr = curr->next;
    }
    printf("\n");
}

void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* createListFromInput(const char* listName) {
    int count, val;
    struct ListNode *head = NULL, *tail = NULL;

    printf("Enter number of digits for %s: ", listName);
    if (scanf("%d", &count) != 1 || count <= 0) {
        return NULL;
    }

    printf("Enter %d digit(s) in reverse order (space-separated): ", count);
    for (int i = 0; i < count; i++) {
        scanf("%d", &val);
        struct ListNode* newNode = createNode(val);

        if (head == NULL) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return head;
}