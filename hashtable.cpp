/*Creating Hash Table and Searching*/
#include <iostream>
using namespace std;

struct Node{
    int key;
    int value;
    Node* next;

    void createNode(int k, int v)
    {
        key = k;
        value = v;
        next = nullptr;
    }
};

class HashTable
{
public:
    HashTable();
    void insertNode(int key, int value);
    int search(int key);

private:
    int hashFunction(int key);
    static const int size = 10;
    Node* table[size];
};

static const int size = 10;
Node* table[size];
HashTable::HashTable()
{
    for (int i=0 ; i<size ; i++)
    {
        table[i] = nullptr;
    }
}

int HashTable::hashFunction(int key)
{
    int num = key%10;
    return num;
}

int HashTable::search(int key)
{
    int index = hashFunction(key);
    Node* current = table[index];
    while(current!=nullptr)
    {
        if (current->key == key)
        {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

void HashTable::insertNode(int key, int value)
{
    int index = hashFunction(key);
    
    Node* head = table[index];
    Node* current = head;
    while(current != nullptr)
    {
        if (current->key == key)
        {
            current->value = value;
            return;
        }
        current = current->next;
    }

    Node* newNode = new Node();
    newNode->createNode(key, value);

    newNode->next = head;
    table[index] = newNode;
}

int main()
{
    HashTable h;

    h.insertNode(1, 10);

    int found = h.search(1);
    if (found != -1)
    cout<<"Found at Index: "<<found<<endl;

    else
    cout<<"Index Not Found"<<endl;

    return 0;
}

// Run using:
// g++ hashtable.cpp -o hashtable
// ./hashtable