//Checking if a linked list is palindrome
//Time Complexity = O(n^2)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode  {
    int val;
    struct ListNode  *next;
};

void Insert(int);
void reverse(struct ListNode*);

struct ListNode* head2 = NULL;

bool isPalindrome(struct ListNode * head) {
    struct ListNode* current_node = head;
    while(current_node!=NULL)
    {
        int value = (int)current_node->val;
        Insert(value);
        current_node = current_node->next;
    }

    reverse(head);
    current_node = head;
    struct ListNode* current_node2 = head2;
    while(current_node!=NULL)
    {
        if (current_node->val != current_node2->val)
        return false;

        current_node = current_node->next;
    }
    return true;
}

void Insert(int value)
{
    //head2 already initialised
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->val = value;
    struct ListNode* current = head2;

    if (head2==NULL)
    {
        head2 = temp;
        temp->next = NULL;
        return;
    }
    
    while(current->next!=NULL)
    {
        current = current->next;
    }
    current->next = temp;
    temp->next = NULL;
    }

void reverse(struct ListNode * head)
{
    struct ListNode * current = head;
    struct ListNode * prev = NULL;
    struct ListNode * link;
    while(current!=NULL)
    {
        link = current->next;
        current->next = prev;
        prev = current;
        current = link;
    }
}

int main()
{
    struct ListNode *head = NULL;
    struct ListNode *current = NULL;

    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);

        struct ListNode *newNode =
            (struct ListNode*)malloc(sizeof(struct ListNode));

        newNode->val = value;
        newNode->next = NULL;
        
        if(head == NULL)
        {
            head = newNode;
            current = newNode;
        }
        else
        {
            current->next = newNode;
            current = newNode;
        }
    }

    if(isPalindrome(head))
        printf("The linked list is a palindrome.\n");
    else
        printf("The linked list is not a palindrome.\n");

    return 0;
}

//For Time Complexity = O(n)
/*#include <stdbool.h>
#include <stddef.h>

struct ListNode* reverse(struct ListNode* head) {
    struct ListNode *current = head, *prev = NULL, *link;
    while (current != NULL) {
        link = current->next;
        current->next = prev;
        prev = current;
        current = link;
    }
    return prev;
}

bool isPalindrome(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    // 1. Find the midpoint using fast and slow pointers
    struct ListNode *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 2. Reverse the second half of the list
    struct ListNode *second_half = reverse(slow->next);

    // 3. Compare the first half with the reversed second half
    struct ListNode *p1 = head;
    struct ListNode *p2 = second_half;
    bool result = true;

    while (p2 != NULL) {
        if (p1->val != p2->val) {
            result = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    // 4. Restore the original list structure
    slow->next = reverse(second_half);

    return result;
}*/