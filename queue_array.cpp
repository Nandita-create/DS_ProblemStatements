#include <iostream>
using namespace std;

void Insert(int, int, int&, int&, int);
int Delete(int, int&, int&);
void Print(int, int, int);

void Insert(int queue[], int value, int &front, int &rear, int size)
{
    if (rear==size-1)
    {
        cout<<"Queue is Full "<<endl;
        return;
    }
    if (front==-1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = value;
}

int Delete(int queue[], int &front, int &rear)
{
    if (front==-1)
    {
        cout<<"Queue is Empty \n";
        return -1;
    }
    int element = queue[front];

    if (front==rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
    return element;
}

void Print(int queue[], int front, int rear)
{
    int current = front;
    while (current<=rear)
    {
        cout<<queue[current]<<" ";
        current++;
    }
    cout<<endl;
}

int main()
{
    int size;
    cout<<"Enter size of queue: ";
    cin>>size;

    int queue[size];
    int x=1, choice, del, front=-1, rear=-1;
    while (x==1)
    {
        cout<<"For following operations, enter: \n1. Insert \n2. Delete \n3. Display \n0. Exit \n";
        cin>>choice;

        switch(choice)
        {
            case 1:
            int value;
            cout<<"Enter value to be inserted: ";
            cin>>value;
            Insert(queue, value, front, rear, size);
            Print(queue, front, rear);
            break;

            case 2:
            del = Delete(queue, front, rear);
            if (del==-1)
            break;

            cout<<"Deleted Element: "<<del<<endl;
            Print(queue, front, rear);
            break;

            case 3:
            cout<<"Printing Queue: \n";
            Print(queue, front, rear);
            break;

            case 0:
            cout<<"Exiting...";
            x=0;
            break;

            default:
            cout<<"Invalid Input \n";
            break;
        }
    }
    return 0;
}
//run using: 
//g++ queue_array.cpp -o queue_array
//./queue_array