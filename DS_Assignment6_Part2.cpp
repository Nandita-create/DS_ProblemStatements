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

TreeNode* InsertNode(TreeNode* root, int data)
{
    if (root==nullptr)
    {
        return createNode(data);
    }

    if (data<root->val)
    {
        root->left = InsertNode(root->left, data);
    }

    else if (data>root->val)
    {
        root->right = InsertNode(root->right, data);
    }

    return root;
}

void count(TreeNode* root, int& c1, int& c2)
{
    if (root==nullptr)
    return;

    count(root->left, c1, c2);

    c1++;

    if (root->left==nullptr && root->right==nullptr)
    c2++;

    count(root->right, c1, c2);
}

void MirrorTree(TreeNode* root)
{
    if (root==nullptr)
    return;

    MirrorTree(root->left);
    MirrorTree(root->right);

    swap(root->left, root->right);
}

void Print(TreeNode* root)
{
    if (root==nullptr)
    return;

    Print(root->left);
    cout<<root->val<<" ";
    Print(root->right);
}

int main()
{
    int value = 1;
    TreeNode* root = nullptr;

    while (value!=0)
    {
        cout<<"Insert value entered in binary tree or press 0 to move to next options: "<<endl;
        cin>>value;
        if(value==0)
        break;

        root = InsertNode(root, value);
        cout<<value<<" inserted"<<endl;
    }

    int c1=0, c2=0;

    count(root, c1, c2);
    cout<<"Total No. of Nodes: "<<c1<<endl;
    
    cout<<"Number of Leaf Nodes: "<<c2<<endl;

    cout<<"Number of Internal Nodes: "<<(c1-c2)<<endl;

    cout<<"Original Tree (inorder): "<<endl;
    Print(root);

    cout<<"\nMirror Image Tree: "<<endl;
    MirrorTree(root);
    Print(root);
    return 0;
}

// Run using:
// g++ DS_Assignment6_Part2.cpp -o DS_Assignment6_Part2
// ./DS_Assignment6_Part2