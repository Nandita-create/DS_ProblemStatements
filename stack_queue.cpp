// Implementing Stack using Queue
#include <iostream>
using namespace std;

void Push(int queue[], int &front, int &rear, int value, int size)
{
    if (rear == size - 1)
    {
        cout << "Stack Overflow \n";
        return;
    }

    if (front == -1)
    {
        front = rear = 0;
        queue[front] = value;
    }
    else
    {
        // Shift all elements one position to the right
        for (int i = rear; i >= front; i--)
        {
            queue[i + 1] = queue[i];
        }

        queue[front] = value;
        rear++;
    }
}

int Pop(int queue[], int &front, int &rear)
{
    if (front == -1)
    {
        cout << "Stack Underflow \n";
        return -1;
    }

    int element = queue[front];

    front++;

    if (front > rear)
    {
        front = rear = -1;
    }

    return element;
}

void Peek(int queue[], int &front, int &rear)
{
    if (front == -1)
    {
        cout << "Stack is Empty \n";
        return;
    }

    cout << queue[front] << endl;
}

void Display(int queue[], int front, int rear)
{
    if (front == -1)
    {
        cout << "Stack is Empty \n";
        return;
    }

    for (int i = front; i <= rear; i++)
    {
        cout << queue[i] << endl;
    }
}

int main()
{
    int size;

    cout << "Enter size of stack: ";
    cin >> size;

    int queue[size];

    int front = -1, rear = -1;
    int x = 1, choice, value, del;

    while (x != 0)
    {
        cout << "\nEnter choice to implement Stack Operations: \n1. Push \n2. Pop \n3. Peek \n4. Display \n0. Exit \n";
        cin >> choice;

        switch (choice)
        {
            case 1:

                cout << "Enter value: ";
                cin >> value;

                Push(queue, front, rear, value, size);

                Display(queue, front, rear);

                break;

            case 2:

                del = Pop(queue, front, rear);

                if (del != -1)
                    cout << "Value Popped: " << del << endl;

                Display(queue, front, rear);

                break;

            case 3:

                cout << "Peek: ";
                Peek(queue, front, rear);

                break;

            case 4:

                cout << "Displaying Stack: \n";
                Display(queue, front, rear);

                break;

            case 0:

                cout << "Exiting...";
                x = 0;

                break;

            default:

                cout << "Invalid Input \n";
        }
    }

    return 0;
}
// Run using:
// g++ stack_queue.cpp -o stack_queue
// ./stack_queue