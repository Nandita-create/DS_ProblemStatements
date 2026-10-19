#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* right;
    Node *left;
};

Node* createNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* InsertNode(Node* root, int data)
{
    if (root == nullptr)
    {
        return (createNode(data));
    }

    if (data<root->data)
    {
        root->left = InsertNode(root->left, data);
    }
    else if (data>root->data)
    {
        root->right = InsertNode(root->right, data);
    }
    return root;
}

Node* minValue(Node* node)
{
    Node* current = node;

    while(current && current->left!=nullptr)
    {
        current = current->left;
    }

    return current;
}

Node* DeleteNode(Node* root, int data)
{
    if (root == nullptr)
    {
        return root;
    }

    if (data<root->data)
    {
        root->left = DeleteNode(root->left, data);
    }

    else if (data>root->data)
    {
        root->right = DeleteNode(root->right, data);
    }

    else
    {
        if (root->left == nullptr)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        else if (root->right == nullptr)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = minValue(root->right);
        root->data = temp->data;
        root->right = DeleteNode(root->right, temp->data);
    }
    return root;
}

Node* searchNode(Node* root, int data)
{
    if (root==nullptr || root->data==data)
    {
        return root;
    }

    if (root->data < data)
    {
        return searchNode(root->right, data);
    }

    return searchNode(root->left, data);
}

void preorder(Node* root)
{
    if(root == nullptr)
    return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root)
{
    if (root == nullptr)
    return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root)
{
    if (root == nullptr)
    return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    int choice, value;
    Node* root = nullptr;

    while (true)
    {
        cout<<"Enter: \n1. Insert a node into the binary tree \n2. Delete a node from the binary tree \n3. Search for a given element in the binary tree \n4. Inorder \n5. Preorder \n6. Postorder traversals \n0. Exit \n";
        cin>>choice;

        switch (choice)
        {
            case 1:
            cout<<"Enter a value: ";
            cin>>value;
            root = InsertNode(root, value);
            cout<<value<<" inserted"<<endl;
            break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                if (searchNode(root, value) != nullptr) 
                {
                    root = DeleteNode(root, value);
                    cout << value << " deleted successfully." << endl;
                } 
                
                else 
                {
                    cout << "Value not found in the tree!" << endl;
                }
                break;
            
            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                if (searchNode(root, value) != nullptr) {
                    cout << "Element " << value << " found in the tree." << endl;
                } else {
                    cout << "Element " << value << " NOT found in the tree." << endl;
                }
                break;
            
            case 4:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;
            
            case 5:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
        
            case 6:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;
            
            case 0:
                cout << "Exiting program..." << endl;
                return 0;
            
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}

// Run using:
// g++ binary_tree.cpp -o binary_tree
// ./binary_tree