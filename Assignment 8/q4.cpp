#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;
};

int max(Node *root)
{
    //maximum value in bst is found on the right most side of the tree
    if(root==NULL)
    {
        return -1;
    }
    if(root->right)
    {
        max(root->right);
    }
    else
    {
        return root->data;
    }
}

int min(Node *root)
{
    //Minimum value in bst is found on the left most side of the tree
    if(root==NULL)
    {
        return -1;
    }
    if(root->left)
    {
        min(root->left);
    }
    else
    {
        return root->data;
    }
}

int isBST(Node *root)
{
    if(root==NULL)
    {
        return 1;
    }
    if(root->left!=NULL && max(root->left)>root->data)
    {
        return 0;
    }
    if(root->right!=NULL && min(root->right)<root->data)
    {
        return 0;
    }
    if(!isBST(root->left) || !isBST(root->right))
    {
        return 0;
    }
    return 1;
}