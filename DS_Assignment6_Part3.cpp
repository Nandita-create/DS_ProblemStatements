#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(int data)
{
    TreeNode* newNode = new TreeNode();
    newNode->val = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

TreeNode* insertNode(TreeNode* root, int data)
{
    if (root==nullptr)
    {
        return createNode(data);
    }

    if (data<root->val)
    root->left = insertNode(root->left, data);

    else if (data>root->val)
    root->right = insertNode(root->right, data);

    return root;
}

TreeNode* smallestRight(TreeNode* root)
{
    if (root->right==NULL)
    return root;

    return smallestRight(root->right);
}

TreeNode* helper(TreeNode* root)
{
    if (root->left==NULL)
    return root->right;

    if (root->right==NULL)
    return root->left;

    TreeNode* rightChild = root->right;
    TreeNode* minRight = smallestRight(root->left);
    minRight->right = rightChild;
    return root->left;
}

TreeNode* deleteNode(TreeNode* root, int key)
{
    if (root==NULL)
    return NULL;

    if (root->val==key)
    return helper(root);

    TreeNode* dummy = root;  //copy of the root, to be returned 

    while (root!=NULL)
    {
        if (root->val>key)
        {
            if (root->left!=NULL && root->left->val==key)
            {
                root->left = helper(root->left);
                break;  //terminates loop after value is deleted
            }
            
            else
            root = root->left;
        }

    else
    {
        if (root->right!=NULL && root->right->val==key)
        {
            root->right = helper(root->right);
            break;
        }

        else
        root = root->right;
    }
    }

    return dummy;
}

bool searchNode(TreeNode* root, int key)
{
    if (root==NULL)
    return false;

    while (root!=NULL)
    {
        if (root->val==key)
        return true;

        else if (root->val>key)
        root = root->left;

        else
        root = root->right;
    }
    return false;
}

void Print(TreeNode* root)
{
    if (root==nullptr)
    return;

    Print(root->left);
    cout<<root->val<<" ";  //Printing InOrder
    Print(root->right);
}

int main()
{
    TreeNode* root = nullptr;
    int choice, data, key, result;
    while (true)
    {
        cout<<"Enter: \n1. Insert a node into the BST. \n2. Delete a node from the BST. \n3. Search for a given element in the BST. \n0.Exit \n";
        cin>>choice;

        switch (choice)
        {
            case 1:
            cout<<"Enter value to be inserted: ";
            cin>>data;
            root = insertNode(root, data);
            cout<<data<<" inserted"<<endl;
            Print(root);
            cout<<endl;
            break;

            case 2:
            cout<<"Enter value to be deleted: ";
            cin>>key;
            root = deleteNode(root, key);
            cout<<key<<" deleted"<<endl;
            Print(root);
            cout<<endl;
            break;

            case 3:
            cout<<"Enter value to be searched: ";
            cin>>key;
            result = searchNode(root, key);
            if (result==1)
            cout<<key<<" Found"<<endl;

            else
            cout<<key<<" Not Found"<<endl;
            break;

            case 0:
            cout<<"Exiting..."<<endl;
            return 0;
            break;

            default:
            cout<<"Invalid Input"<<endl;
        }
    }
    return 0;
}

// Run using:
// g++ DS_Assignment6_Part3.cpp -o DS_Assignment6_Part3
// ./DS_Assignment6_Part3