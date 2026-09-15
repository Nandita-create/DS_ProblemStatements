// Circular Queue using Linked List

#include <iostream>
using namespace std;

struct QueueNode
{
    int val;
    QueueNode* next;
};

QueueNode* front;
QueueNode* rear;

void Insert(QueueNode* &front, QueueNode* &rear, int value)
{
    QueueNode* temp = new QueueNode();
    temp->val = value;

    if (front == NULL)
    {
        front = temp;
        rear = temp;
        rear->next = front;
    }
    else
    {
        temp->next = front;
        rear->next = temp;
        rear = temp;
    }
}

int Delete(QueueNode* &front, QueueNode* &rear)
{
    if (front == NULL)
    {
        cout << "Queue is Empty \n";
        return -1;
    }

    int element = front->val;
    QueueNode* current = front;

    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front;
    }

    delete current;

    return element;
}

void Peek(QueueNode* front)
{
    if (front == NULL)
    {
        cout << "Queue is Empty" << endl;
        return;
    }

    cout << front->val << endl;
}

void Display(QueueNode* front, QueueNode* rear)
{
    if (front == NULL)
    {
        cout << "Queue is Empty" << endl;
        return;
    }

    QueueNode* current = front;

    do
    {
        cout << current->val << " ";
        current = current->next;
    } while (current != front);

    cout << endl;
}

int main()
{
    front = NULL;
    rear = NULL;

    int x = 1, choice, value, del;

    while (x == 1)
    {
        cout<<"Enter: \n1. Insert \n2. Delete \n3. Peek \n4. Display \n0. Exit \n";

        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value to be inserted: ";
                cin >> value;

                Insert(front, rear, value);

                Display(front, rear);
                break;

            case 2:
                del = Delete(front, rear);

                if (del == -1)
                    break;

                cout << "Deleted Element: " << del << endl;

                Display(front, rear);
                break;

            case 3:
                cout << "Peek: ";
                Peek(front);
                cout << endl;
                break;

            case 4:
                cout << "Displaying Queue: \n";

                Display(front, rear);
                break;

            case 0:
                cout << "Exiting...\n";
                x = 0;
                break;

            default:
                cout << "Invalid Input \n";
        }
    }

    return 0;
}
// Run using:
// g++ circular_queue_linkedlist.cpp -o circular_queue_linkedlist
// ./circular_queue_linkedlist