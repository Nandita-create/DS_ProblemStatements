#include <iostream>
using namespace std;

void Insert(int, int, int&, int&, int);
void Delete(int, int&, int&, int);
void Peek(int, int&);
void Display(int, int, int, int);

void Insert(int queue[], int value, int &front, int &rear, int size)
{
    if ((rear+1)%size==front)
    {
        cout<<"Queue is Full "<<endl;
        return;
    }
    if (front==-1)
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear+1)%size;
    }
    queue[rear] = value;
}

int Delete(int queue[], int &front, int &rear, int size)
{
    if (front==-1)
    {
        cout<<"Queue is Empty \n";
        return -1;
    }
    int element = queue[front];
    if (front==rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front+1)%size;
    }
    return element;
}

void Peek(int queue[], int &front)
{
    if (front==-1)
    {
        cout<<"Queue is Empty"<<endl;
        return;
    }

    cout<<queue[front]<<endl;
}

void Display(int queue[], int front, int rear, int size)
{
    if (front==-1)
    {
        cout<<"Queue is Empty \n";
        return;
    }

    int current = front;
    while(true)
    {
        cout<<queue[current]<<" ";
        if (current==rear)
        break;
        
        current = (current+1)%size;  //as we are moving current
    }
    cout<<endl;
}

int main()
{
    int size;
    cout<<"Enter size of queue: ";
    cin>>size;

    int queue[size];  //just to get a standard queue using array
    int front=-1, rear=-1, value, del, choice;
    int x=1;
    while(x==1)
    {
        cout<<"Enter: \n1. Insert \n2. Delete \n3. Peek \n4. Display \n0. Exit \n";
        cin>>choice;

        switch (choice)
        {
            case 1:
            cout<<"Enter value to be inserted: ";
            cin>>value;
            Insert(queue, value, front, rear, size);
            Display(queue, front, rear, size);
            break;

            case 2:
            del = Delete(queue, front, rear, size);
            cout<<"Deleting "<<del<<endl;
            Display(queue, front, rear, size);
            break;

            case 3:
            cout<<"Peek: ";
            Peek(queue, front);
            break;

            case 4:
            cout<<"Displaying Queue: \n";
            Display(queue, front, rear, size);
            break;

            case 0:
            cout<<"Exiting...";
            x=0;
            break;

            default:
            cout<<"Invalid Input \n";
        }
    }
    return 0;
}
//run using: 
//g++ queue_circular.cpp -o queue_circular
//./queue_circular