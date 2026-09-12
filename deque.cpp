//Deque
#include <iostream>
using namespace std;

void InsertFront(int[], int &, int &, int, int);
void InsertRear(int[], int &, int &, int, int);
int DeleteFront(int[], int &, int &, int);
int DeleteRear(int[], int &, int &, int);
void Display(int[], int, int, int);

void InsertFront(int deque[], int &front, int &rear, int value, int size)
{
    if ((rear+1)%size == front)
    {
        cout<<"Deque is Full \n";
        return;
    }

    else if (front==-1)
    {
        front = rear = 0;
    }

    else if (front==0)
    {
        front = size-1;
    }

    else
    {
        front--;
    }
    deque[front] = value;
}

void InsertRear(int deque[], int &front, int &rear, int value, int size)
{
    if ((rear+1)%size==front)
    {
        cout<<"Deque is Full \n";
        return;
    }

    else if(rear==-1)
    {
        front = rear = 0;
    }

    else
    {
        rear = (rear+1)%size;
    }
    deque[rear] = value;
}

int DeleteFront(int deque[], int &front, int &rear, int size)
{
    if (front==-1)
    {
        cout<<"Deque is Empty \n";
        return -1;
    }

    int element = deque[front];
    if (front==rear)
    front = rear = -1;

    else
    front = (front+1)%size;

    return element;
}

int DeleteRear(int deque[], int &front, int &rear, int size)
{
    if (rear==-1)
    {
        cout<<"Deque is Empty \n";
        return -1;
    }

    int element = deque[rear];

    if (front == rear)
{
    front = rear = -1;
}
else if (rear == 0)
{
    rear = size - 1;
}
else
{
    rear--;
}
    return element;
}

void Display(int deque[], int front, int rear, int size)
{
    if (front==-1)
    {
        cout<<"Deque is Empty \n";
        return;
    }

    int i=front;
    while(true)
    {
        cout<<deque[i]<<" ";

        if (i==rear)
        break;

        i = (i+1)%size;
    }
    cout<<endl;
}

int main()
{
    int size;
    cout<<"Enter size of Deque: ";
    cin>>size;
    int deque[size];
    int choice, front=-1, rear=-1, value, del;
    int x=1;
    while (x!=0)
    {
        cout<<"Enter: \n1. Insert at Front \n2. Insert at Rear \n3. Delete from Front \n4. Delete from Rear \n5. Display \n0. Exit \n";
        cin>>choice;
        switch (choice)
        {
            case 1:
            cout<<"Enter value: ";
            cin>>value;
            InsertFront(deque, front, rear, value, size);
            Display(deque, front, rear, size);
            break;

            case 2:
            cout<<"Enter value: ";
            cin>>value;
            InsertRear(deque, front, rear, value, size);
            Display(deque, front, rear, size);
            break;

            case 3:
            del = DeleteFront(deque, front, rear, size);
            if (del!=-1)
            cout<<"Deleting element from Front: "<<del<<endl;

            Display(deque, front, rear, size);
            break;

            case 4:
            del = DeleteRear(deque, front, rear, size);
            if (del!=-1)
            cout<<"Deleting element from Rear: "<<del<<endl;

            Display(deque, front, rear, size);
            break;

            case 5:
            cout<<"Displaying Deque: \n";
            Display(deque, front, rear, size);
            break;

            case 0:
            cout<<"Exiting...";
            x = 0;
            break;

            default:
            cout<<"Invalid Input \n";
            break;
        }
    }
    return 0;
}
//run using: 
//g++ deque.cpp -o deque
//./deque