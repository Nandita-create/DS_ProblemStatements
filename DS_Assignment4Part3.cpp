#include <iostream>
using namespace std;

void Push1(int stack[], int& top1, int& top2, int value, int size)
{
    if (top1+1 == top2)
    {
        cout<<"Stack is Full"<<endl;
        return;
    }

    top1++;
    stack[top1] = value;
    return;
}

void Push2(int stack[], int& top1, int& top2, int value, int size)
{
    if (top1+1==top2)
    {
        cout<<"Stack is Full";
        return;
    }
    top2--;
    stack[top2] = value;
    return;
}

int Pop1(int stack[], int& top1)
{
    if (top1==-1)
    {
        cout<<"Stack 1 is Empty"<<endl;
        return -1;
    }

    int element = stack[top1];
    top1--;
    return element;
}

int Pop2(int stack[], int& top2, int size)
{
    if (top2==size)
    {
        cout<<"Stack 2 is Empty"<<endl;
        return -1;
    }

    int element = stack[top2];
    top2++;
    return element;
}

void Display(int stack[], int& top1, int& top2, int size)
{
    if (top1==-1)
    {
        cout<<"Stack 1 is Empty\n";
    }
    else
    {
    cout<<"Stack 1"<<endl;
    for (int i=top1 ; i>=0 ; i--)
    {
        cout<<stack[i]<<endl;
    }
}

if (top2==size)
    {
        cout<<"Stack 2 is Empty\n";
    }
    else
    {
    cout<<"Stack 2"<<endl;
    for (int i=top2 ; i<size ; i++)
    {
        cout<<stack[i]<<endl;
    }
}
}

int main()
{
    int size;
    cout<<"Enter size of array: ";
    cin>>size;
    int* stack = new int[size];
    int choice, top1 = -1, top2 = size, value, del;
    while(true)
    {
        cout<<"Enter: \n1. Push in Stack 1 \n2. Push in Stack 2 \n3. Pop from Stack 1 \n4. Pop from Stack 2 \n5. Display Stacks \n0. Exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter value: ";
            cin>>value;
            Push1(stack, top1, top2, value, size);
            Display(stack, top1, top2, size);
            break;

            case 2:
            cout<<"Enter value: ";
            cin>>value;
            Push2(stack, top1, top2, value, size);
            Display(stack, top1, top2, size);
            break;

            case 3:
            del = Pop1(stack, top1);
            if(del!=-1)
            {
                cout<<"Value popped: "<<del<<endl;
            }
            Display(stack, top1, top2, size);
            break;

            case 4:
            del = Pop2(stack, top2, size);
            if(del!=-1)
            {
                cout<<"Value popped: "<<del<<endl;
            }
            Display(stack, top1, top2, size);
            break;

            case 5:
            cout<<"Displaying Stacks: "<<endl;
            Display(stack, top1, top2, size);
            break;

            case 0:
            cout<<"Exiting...";
            return 0;
            break;

            default:
            cout<<"Invalid Input \n";
        }
    }
    return 0;
}
// Run using:
// g++ DS_Assignment4Part3.cpp -o DS_Assignment4Part3
// ./DS_Assignment4Part3