#include <iostream>
using namespace std;

const int SIZE = 10;

 
struct Node {
    int data;
    Node* next;
};

class HashTable {
    Node* chain[SIZE];
    int linear[SIZE];
    int quadratic[SIZE];
    int doubleHash[SIZE];

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            chain[i] = NULL;
            linear[i] = -1;
            quadratic[i] = -1;
            doubleHash[i] = -1;
        }
    }

    
    void insertChain(int key) {
        int index = key % SIZE;
        Node* temp = chain[index];

        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Duplicate key!\n";
                return;
            }
            temp = temp->next;
        }

        Node* newNode = new Node;
        newNode->data = key;
        newNode->next = chain[index];
        chain[index] = newNode;

        cout << "Key inserted.\n";
    }

    bool searchChain(int key) {
        int index = key % SIZE;
        Node* temp = chain[index];

        while (temp != NULL) {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }

        return false;
    }

    void displayChain() {
        for (int i = 0; i < SIZE; i++) {
            cout << i << " -> ";
            Node* temp = chain[i];

            while (temp != NULL) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }

            cout << "NULL\n";
        }
    }

    
    void insertLinear(int key) {
        int h = key % SIZE;

        for (int i = 0; i < SIZE; i++) {
            int index = (h + i) % SIZE;

            if (linear[index] == key) {
                cout << "Duplicate key!\n";
                return;
            }

            if (linear[index] == -1) {
                linear[index] = key;
                cout << "Key inserted at index "
                     << index << "\n";
                return;
            }
        }

        cout << "Hash table is full!\n";
    }

    bool searchLinear(int key) {
        int h = key % SIZE;

        for (int i = 0; i < SIZE; i++) {
            int index = (h + i) % SIZE;

            if (linear[index] == -1)
                return false;

            if (linear[index] == key)
                return true;
        }

        return false;
    }

    void displayLinear() {
        for (int i = 0; i < SIZE; i++)
            cout << i << " : " << linear[i] << "\n";
    }

    
    void insertQuadratic(int key) {
        int h = key % SIZE;

        for (int i = 0; i < SIZE; i++) {
            int index = (h + i * i) % SIZE;

            if (quadratic[index] == key) {
                cout << "Duplicate key!\n";
                return;
            }

            if (quadratic[index] == -1) {
                quadratic[index] = key;
                cout << "Key inserted at index "
                     << index << "\n";
                return;
            }
        }

        cout << "No available slot in probe sequence!\n";
    }

    bool searchQuadratic(int key) {
        int h = key % SIZE;

        for (int i = 0; i < SIZE; i++) {
            int index = (h + i * i) % SIZE;

            if (quadratic[index] == -1)
                return false;

            if (quadratic[index] == key)
                return true;
        }

        return false;
    }

    void displayQuadratic() {
        for (int i = 0; i < SIZE; i++)
            cout << i << " : " << quadratic[i] << "\n";
    }

    
    void insertDouble(int key) {
        int h1 = key % SIZE;
        int h2 = 7 - (key % 7);

        for (int i = 0; i < SIZE; i++) {
            int index = (h1 + i * h2) % SIZE;

            if (doubleHash[index] == key) {
                cout << "Duplicate key!\n";
                return;
            }

            if (doubleHash[index] == -1) {
                doubleHash[index] = key;
                cout << "Key inserted at index "
                     << index << "\n";
                return;
            }
        }

        cout << "Hash table is full!\n";
    }

    bool searchDouble(int key) {
        int h1 = key % SIZE;
        int h2 = 7 - (key % 7);

        for (int i = 0; i < SIZE; i++) {
            int index = (h1 + i * h2) % SIZE;

            if (doubleHash[index] == -1)
                return false;

            if (doubleHash[index] == key)
                return true;
        }

        return false;
    }

    void displayDouble() {
        for (int i = 0; i < SIZE; i++)
            cout << i << " : " << doubleHash[i] << "\n";
    }
};

int main() {
    HashTable ht;
    int technique, choice, key;
    bool found;

    do {
        cout << "\nHASH TABLE\n";
        cout << "1. Separate Chaining\n";
        cout << "2. Linear Probing\n";
        cout << "3. Quadratic Probing\n";
        cout << "4. Double Hashing\n";
        cout << "0. Exit\n";
        cout << "Enter technique: ";
        cin >> technique;

        if (technique == 0)
            break;

        if (technique < 1 || technique > 4) {
            cout << "Invalid technique!\n";
            continue;
        }

        do {
            cout << "\n1. Insert\n";
            cout << "2. Search\n";
            cout << "3. Display\n";
            cout << "0. Back\n";
            cout << "Enter choice: ";
            cin >> choice;

            if (choice == 1) {
                cout << "Enter non-negative key: ";
                cin >> key;

                if (key < 0) {
                    cout << "Invalid key!\n";
                    continue;
                }

                if (technique == 1)
                    ht.insertChain(key);
                else if (technique == 2)
                    ht.insertLinear(key);
                else if (technique == 3)
                    ht.insertQuadratic(key);
                else
                    ht.insertDouble(key);
            }
            else if (choice == 2) {
                cout << "Enter key to search: ";
                cin >> key;

                if (key < 0) {
                    cout << "Invalid key!\n";
                    continue;
                }

                if (technique == 1)
                    found = ht.searchChain(key);
                else if (technique == 2)
                    found = ht.searchLinear(key);
                else if (technique == 3)
                    found = ht.searchQuadratic(key);
                else
                    found = ht.searchDouble(key);

                if (found)
                    cout << "Key found!\n";
                else
                    cout << "Key not found!\n";
            }
            else if (choice == 3) {
                if (technique == 1)
                    ht.displayChain();
                else if (technique == 2)
                    ht.displayLinear();
                else if (technique == 3)
                    ht.displayQuadratic();
                else
                    ht.displayDouble();
            }
            else if (choice != 0) {
                cout << "Invalid choice!\n";
            }

        } while (choice != 0);

    } while (true);

    return 0;
}

// Run using:
// g++ DS_Assignment5.cpp -o DS_Assignment5
// ./DS_Assignment5