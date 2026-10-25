#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* right;
    TreeNode* left;
};

TreeNode* createNode(int data)
{
    TreeNode* newNode = new TreeNode();
    newNode->val = data;
    newNode->right = nullptr;
    newNode->left = nullptr;

    return newNode;
}

TreeNode* insertNode(TreeNode* root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data<root->val)
    root->left = insertNode(root->left, data);

    else if (data>root->val)
    root->right = insertNode(root->right, data);

    return root;
}

//using inbuilt stack data structure of inorder, preorder and postorder as we are making it iterative
vector<int> Inorder(TreeNode* root)
{
    vector<int> result;
    stack<TreeNode*> s;
    TreeNode* current = root;

    while (current!=nullptr || s.empty()!=true)
    {
        while (current!=nullptr)
        {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();

        result.push_back(current->val);  //this is the root

        current = current->right;
    }
    return result;
}

vector<int> Preorder(TreeNode* root)
{
    vector<int> result;
    if (root==nullptr)
    return result;

    stack<TreeNode*> s;
    TreeNode* current = NULL;
    s.push(root);

    while (!s.empty())
    {
        current = s.top();
        s.pop();

        result.push_back(current->val);

        if (current->right!=NULL)
        s.push(current->right);

        if (current->left!=NULL)
        s.push(current->left);
    }
    return result;
}

vector<int> Postorder(TreeNode* root)
{
    vector<int> result;
    TreeNode* current = root;
    TreeNode* prev = NULL;
    stack<TreeNode*> s;

    while (current!=NULL || s.empty()!=true)
    {
        if (current!=NULL)
        {
            s.push(current);
            current = current->left;
        }

        else
        {
            current = s.top();
            if (current->right==NULL || current->right==prev)
            {
                result.push_back(current->val);
                s.pop();

                prev = current;
                current = NULL;
            }

            else
            {
                current = current->right;
            }
        }
    }
    return result;
}

int main()
{
    TreeNode* root = nullptr;
    int value;
    vector<int> results;
    while (true)
    {
        cout<<"Enter value in Binary Tree or press 0 to move to next step: ";
        cin>>value;
        if (value!=0)
        root = insertNode(root, value);

        else
        break;
    }

    cout<<"InOrder Traversal: "<<endl;
    results = Inorder(root);
    for (int i=0 ; i<results.size() ; i++)
    {
        cout<<results[i]<<" ";
    }

    cout<<"\nPreOrder Traversal: "<<endl;
    results = Preorder(root);
    for (int i=0 ; i<results.size() ; i++)
    {
        cout<<results[i]<<" ";
    }

    cout<<"\nPostOrder Traversal: "<<endl;
    results = Postorder(root);
    for (int i=0 ; i<results.size() ; i++)
    {
        cout<<results[i]<<" ";
    }
    return 0;
}

// Run using:
// g++ DS_Assignment6_Part4.cpp -o DS_Assignment6_Part4
// ./DS_Assignment6_Part4