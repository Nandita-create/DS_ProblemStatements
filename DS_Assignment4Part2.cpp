#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = NULL;

Node* Push(int value, Node* head)
{
    Node* temp = new Node();
    temp->data = value;

    temp->next = head;
    head = temp;
    return head;
}

Node* Pop(Node* head)
{
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

void Peek(Node* head)
{
    cout<<"Peek: "<<head->data<<endl;
}

void Display(Node* head)
{
    Node* current = head;
    while (current!=NULL)
    {
        cout<<current->data<<endl;
        current = current->next;
    }
    
    return;
}

int main()
{
    int choice, value;

    while (true)
    {
        cout<<"\nEnter Stack Using Linked List: \n";
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Peek\n";
        cout<<"4. Display\n";
        cout<<"0. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                head = Push(value, head);
                Display(head);
                break;

            case 2:
                if (head == NULL)
                    cout<<"Stack Underflow\n";
                else
                    head = Pop(head);
                    Display(head);
                break;
            
            case 3:
                if (head == NULL)
                    cout<<"Stack Empty\n";
                else
                    Peek(head);
                break;


            case 4:
                if (head == NULL)
                    cout << "Stack is Empty\n";
                else
                    Display(head);
                break;

            case 0:
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
// Run using:
// g++ DS_Assignment4Part2.cpp -o DS_Assignment4Part2
// ./DS_Assignment4Part2