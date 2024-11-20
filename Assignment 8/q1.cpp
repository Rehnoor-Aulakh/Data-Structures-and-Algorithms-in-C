// 1. Write program using functions for binary tree traversals: Pre-order, In-order and Postorder using recursive approach.

#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;
};

void inOrder(Node *root)
{
    //Left Node Right
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void preOrder(Node *root)
{
    //Node Left Right
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    //Left Right Node
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}



