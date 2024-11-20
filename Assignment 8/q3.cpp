#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val): data(val),left(NULL),right(NULL){}
};

Node* insert(Node *root, int data)
{
    if(root==NULL)
    {
        return new Node(data);
    }
    if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else
    {
        root->right=insert(root->right,data);
    }
    return root;
}

Node* max(Node *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->right==NULL)
    {
        return root;
    }
    else
    {
        return root->right;
    }
}

Node* remove(Node *root, int data)
{
    //if there is no child, simply point it to NULL
    //if there is one child, point it to its child
    //if there are two children, swap the node with the left subtrees largest data and then remove the largest of the left subtree using the same function because it cannot have any child
    Node *temp;
    if(root==NULL)
    {
        cout<<"Element not found!!!"<<endl;
    }
    else if(data<root->data)
    {
        root->left=remove(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=remove(root->right,data);
    }
    else
    {
        //Element Found
        if(root->left && root->right)
        {
            //Both Children
            //Replace with the largest value in left subtree
            temp=max(root->left);
            root->data=temp->data;
            root->left=remove(root->left,root->data);
        }
        else
        {
            //One child
            temp=root;
            if(root->left==NULL)
            {
                root=root->right;
            }
            if(root->right==NULL)
            {
                root=root->left;
            }
            delete temp;
        }
    }
    return root;
}

int maxDepth(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        int leftDepth=maxDepth(root->left);
        int rightDepth=maxDepth(root->right);

        //add one to the larger depth
        if(leftDepth>rightDepth)
        {
            return leftDepth+1;
        }
        else
        {
            return rightDepth+1;
        }
    }
}

int minDepth(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    //If left subtree is NULL, consider the depth of right subtree only
    //because depth is the distance from the root node to the leaf node
    if(root->left==NULL)
    {
        return minDepth(root->right)+1;
    }
    if(root->right==NULL)
    {
        return minDepth(root->left)+1;
    }

    //if both subtrees are not NULL, consider the minimum depth of both subtrees
    int leftDepth=minDepth(root->left);
    int rightDepth=minDepth(root->right);

    if(leftDepth<rightDepth)
    {
        return leftDepth+1;
    }
    else
    {
        return rightDepth+1;
    }
}