#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode{
    int val;
    int height;
    TreeNode* right;
    TreeNode* left;

    TreeNode(int data)
    {
        val = data;
        height = 1;
        left = nullptr;
        right =  nullptr;
    }
};

int height(TreeNode* n)
{
    if (n==nullptr)
    return 0;

    return n->height;
}

int getBalance(TreeNode* root)
{
    if (root==nullptr)
    return 0;

    return height(root->left) - height(root->right);
}

TreeNode* leftRotate(TreeNode* root)
{
    TreeNode* y = root->right;
    TreeNode* z = y->left;

    y->left = root;
    root->right = z;

    root->height = 1 + max(height(root->left), height(root->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

TreeNode* rightRotate(TreeNode* root)
{
    TreeNode* y = root->left;
    TreeNode* z = y->right;

    y->right = root;
    root->left = z;

    root->height = 1 + max(height(root->left), height(root->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

TreeNode* insertNode(TreeNode* root, int data)
{
    if (root==nullptr)
    return (new TreeNode(data));

    if (data<root->val)
    root->left = insertNode(root->left, data);

    else if (data>root->val)
    root->right = insertNode(root->right, data);

    else
    return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance>1 && data<root->left->val)
    return rightRotate(root);  //this is the Left-Left case

    if (balance<-1 && data>root->right->val)
    return leftRotate(root);  //this is the Right-Right case

    if (balance>1 && data>root->left->val)
    {
    root->left = leftRotate(root->left);  //this is for Left-Right case
    return rightRotate(root);
    }

    if (balance<-1 && data<root->right->val)
    {
    root->right = rightRotate(root->right);  //this is for Right-Left case
    return leftRotate(root);
    }
    return root;
}

TreeNode* smallestRight(TreeNode* root)
{
    if (root->left==nullptr)
    return root;

    return smallestRight(root->left);
}

TreeNode* helper(TreeNode* root)
{
    if (root->right==nullptr)
    return root->left;

    if (root->left==nullptr)
    return root->right;

    TreeNode* rightChild = root->right;
    TreeNode* minRight = smallestRight(root->left);
    minRight->right = rightChild;
    return root->left;
}

TreeNode* deleteNode(TreeNode* root, int key)
{
    if (root == nullptr)
        return nullptr;

    if (key < root->val)
        root->left = deleteNode(root->left, key);

    else if (key > root->val)
        root->right = deleteNode(root->right, key);

    else
    {
        if (root->left == nullptr || root->right == nullptr)
        {
            TreeNode* temp;

            if (root->left != nullptr)
                temp = root->left;
            else
                temp = root->right;

            if (temp == nullptr)
            {
                delete root;
                return nullptr;
            }

            TreeNode* oldRoot = root;
            root = temp;
            delete oldRoot;
        }
        else
        {
            TreeNode* temp = smallestRight(root->right);

            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);  //for Left-Left case

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);  //for Left-Right case
        return rightRotate(root);  
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);  //for Right-Right case

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);  //for Right-Left case
        return leftRotate(root);
    }

    return root;
}

bool searchNode(TreeNode* root, int key)
{
    if (root==NULL)
    return false;

    if (root->val==key)
    return true;

    while(root!=NULL)
    {
        if (key<root->val)
        {
            if (root->left!=NULL && (root->left->val==key))
            return true;

            else
            root = root->left;
        }

        else
        {
            if (root->right!=NULL && (root->right->val==key))
            return true;

            root = root->right;
        }
    }
    return false;
}

void InOrder(TreeNode* root)
{
    if (root==NULL)
    return;

    InOrder(root->left);
    cout<<root->val<<" ";
    InOrder(root->right);
}

void PreOrder(TreeNode* root)
{
    if (root==NULL)
    return;

    cout<<root->val<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void PostOrder(TreeNode* root)
{
    if (root==NULL)
    return;

    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->val<<" ";
}

int main()
{
    TreeNode* root = nullptr;
    int choice, data;

    while (true)
    {
        cout << "\nEnter: \n1. Insert a node \n2. Delete a node \n3. Search for an element \n4. Inorder Traversal \n5. Preorder Traversal \n6. Postorder Traversal \n0. Exit\n";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value to insert: ";
                cin >> data;
                root = insertNode(root, data);
                cout << "Node inserted successfully.";
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> data;

                if (searchNode(root, data))
                {
                    root = deleteNode(root, data);
                    cout << "Node deleted successfully.";
                }
                else
                    cout << "Element not found.";

                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> data;

                if (searchNode(root, data))
                    cout << "Element found.";
                else
                    cout << "Element not found.";

                break;

            case 4:
                cout << "Inorder Traversal: ";
                InOrder(root);
                break;

            case 5:
                cout << "Preorder Traversal: ";
                PreOrder(root);
                break;

            case 6:
                cout << "Postorder Traversal: ";
                PostOrder(root);
                break;

            case 0:
                return 0;

            default:
                cout << "Invalid choice. Try again.";
        }
    }
    return 0;
}

// Run using:
// g++ DS_Assignment6_Part5.cpp -o DS_Assignment6_Part5
// ./DS_Assignment6_Part5