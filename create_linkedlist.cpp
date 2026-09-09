//Program to create a linked list in C++
//Use a new Node for each element
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* link;  //no need to mention 'struct' in struct Node* link;
};

int main()
{
    struct Node* A;
    A = NULL;
    //need to mention'struct' Node* A in C, not just Node* A

    Node* first = new Node();

    first->data = 2;
    first->link = NULL;
    A = first;  //address of added node

    //Traverse List - Visit each item of the list one by one
    struct Node* temp1 = A;
    cout<<"Adding 1st element to the linked list: "<<endl;
    while (temp1!=NULL)
    {
        cout<<temp1->data<<" ";
        temp1 = temp1->link;
    }

    //Adding 2 more elements to the list. Use new pointer variable for this.
    //Do not reuse previous pointers
    Node* second = new Node();
    second->data = 4;
    second->link = NULL;
    first->link = second;  //linking to 1st element

    Node* third = new Node();
    third->data = 6;
    third->link = NULL;
    second->link = third;  //linking to 2nd element

    cout<<endl<<"Added 2 more elements to the linked list: "<<endl;
    struct Node* temp2 = A;
    while(temp2!=NULL)
    {
        cout<<temp2->data<<" ";
        temp2 = temp2->link;
    }
    cout<<endl;
    return 0;
}

//In linked list,
//Entire node is of type Node datatype
//'Value' part of node is int datatype
//'Address of next node' part of node is Node* datatype