#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;
};

int Search(Node *root, int data)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->data==data)
    {
        return 1;
    }
    else if(data<root->data)
    {
        //go left
        Search(root->left,data);
    }
    else
    {
        //go right
        Search(root->right,data);
    }
}

int searchNonRecursive(Node *root, int data)
{
    while(1)
    {
        if(root==NULL)
        {
            return 0;
        }
        if(root->data==data)
        {
            return 1;
        }
        else if(data<root->data)
        {
            root=root->left;
        }
        else if(data>root->data)
        {
            root=root->right;
        }
    }
}

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

Node* inOrderSuccessor(Node *root, Node *n)
{
    //inorder successor is the smallest node larger than the given node
    //if there is a right child, then the minimum value of right subtree is the answer
    if(n->right)
    {
        return min(n->right);
    }
    Node *successor=NULL
    while(root!=NULL)
    {
        if(n->data<root->data)
        {
            successor=root;
            root=root->left;
        }
        else if(n->data>root->data)
        {
            root=root->right;
        }
        else
        {
            break;
        }
    }
    return successor;
}

Node* inOrderPredecessor(Node *root, Node *n)
{
    if(n->left)
    {
        return max(n->left);
    }
    Node *predecessor=NULL;
    while(root!=NULL)
    {
        if(root->data>n->data)
        {
            root=root->left;
        }
        else if(root->data<n->data)
        {
            predecessor
            root=root->right;
        }
        else
        {
            break;
        }
    }
    return predecessor;
}