// Reversing Stack using Queue

#include <iostream>
using namespace std;

void Push(int stack[], int &top, int value, int size)
{
    if (top == size - 1)
    {
        cout << "Stack Overflow\n";
        return;
    }

    top++;
    stack[top] = value;
}

int Pop(int stack[], int &top)
{
    if (top == -1)
    {
        cout << "Stack Underflow\n";
        return -1;
    }

    int element = stack[top];
    top--;

    return element;
}

void Display(int stack[], int top)
{
    if (top == -1)
    {
        cout << "Stack is Empty\n";
        return;
    }

    for (int i = top; i >= 0; i--)
    {
        cout << stack[i] << endl;
    }
}

void ReverseStack(int stack[], int &top, int queue[], int size)
{
    int front = -1;
    int rear = -1;

    while (top != -1)
    {
        int element = Pop(stack, top);

        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = element;
    }

    while (front <= rear)
    {
        Push(stack, top, queue[front], size);
        front++;
    }
}

int main()
{
    int size;

    cout << "Enter size of stack: ";
    cin >> size;

    int stack[size];
    int queue[size];

    int top = -1;
    int choice, value, x = 1;

    while (x == 1)
    {
        cout << "\nEnter choice: \n1. Push \n2. Pop \n3. Display \n4. Reverse Stack \n0. Exit\n";

        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                Push(stack, top, value, size);
                Display(stack, top);
                break;

            case 2:
                value = Pop(stack, top);

                if (value != -1)
                    cout << "Value Popped: " << value << endl;
                Display(stack, top);
                break;

            case 3:
                cout << "Stack:\n";
                Display(stack, top);
                break;

            case 4:
                ReverseStack(stack, top, queue, size);

                cout << "Stack after reversing:\n";
                Display(stack, top);
                break;

            case 0:
                cout << "Exiting...";
                x = 0;
                break;

            default:
                cout << "Invalid Input\n";
        }
    }

    return 0;
}
// Run using:
// g++ reverse_stack.cpp -o reverse_stack
// ./reverse_stack