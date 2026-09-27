#include <iostream>
using namespace std;

void Push(int stack[], int& top, int value, int size)
{
    if (top==size-1)
    {
        cout<<"Stack is Full"<<endl;
        return;
    }

    top++;
    stack[top] = value;
    return;
}

int Pop(int stack[], int& top, int size)
{
    if (top==-1)
    {
        cout<<"Stack is Empty"<<endl;
        return -1;
    }

    int element = stack[top];
    top--;
    return element;
}

void Peek(int stack[], int& top)
{
    if (top==-1)
    {
        cout<<"Stack is Empty"<<endl;
        return;
    }

    cout<<"Peek: "<<stack[top]<<endl;
}

void Display(int stack[], int& top)
{
    for (int i=top ; i>=0 ; i--)
    {
        cout<<stack[i]<<endl;
    }
    return;
}

int main()
{
    int size;
    cout<<"Enter size of stack: ";
    cin>>size;
    int* stack = new int[size];
    int value, del, choice, top=-1, x=1;
    while (x!=0)
    {
        cout<<"Enter: \n1. Push \n2. Pop \n3. Peek/Top \n4. Display \n0. Exit \n";
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter value to be pushed: ";
            cin>>value;
            Push(stack, top, value, size);
            Display(stack, top);
            break;

            case 2:
            del = Pop(stack, top, size);
            if (del!=-1)
            {
                cout<<"Element popped: "<<del<<endl;
                Display(stack, top);
            }
            break;

            case 3:
            Peek(stack, top);
            break;

            case 4:
            cout<<"Displaying Stack"<<endl;
            Display(stack, top);
            break;

            case 0:
            cout<<"Exiting...";
            x=0;
            break;

            default:
            cout<<"Invalid Input"<<endl;
        }
    }
    return 0;
}
// Run using:
// g++ DS_Assignment4Part1.cpp -o DS_Assignment4Part1
// ./DS_Assignment4Part1