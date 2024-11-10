#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    Node()
    {
        data=0;
        left=NULL;
        right=NULL;
    }
    Node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

bool search(Node *root, int data)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==data)
    {
        return true;
    }
    else
    {
        return search(root->left,data) || search(root->right,data);
    }
}

Node* insert(Node *root, int data)
    {
        if(root==NULL)
        {
            Node *nnode=new Node(data);
            root=nnode;
        }
        else
        {
            if(data<root->data)
            {
                //go left
                root->left=insert(root->left,data);
            }
            else if(data>root->data)
            {
                //go right
                root->right=insert(root->right,data);
            }
        }
        return root;
    }
Node* findMin(Node *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->left==NULL)
    {
        return root;
    }
    else
    {
        return findMin(root->left);
    }
}

Node *findMinNonRecursive(Node *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    Node *temp=root;
    while(temp->left)
    {
        temp=temp->left;
    }
    return temp;
}

Node *findMax(Node *root)
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
        return findMax(root->right);
    }
}

Node *findMaxNonRecursive(Node *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    Node *temp=root;
    while(temp->right)
    {
        temp=temp->right;
    }
    return temp;
}

Node *remove(Node *root, int data)
{
    Node *temp;
    if(root==NULL)
    {
        cout<<"Element Not in the tree!!!"<<endl;
    }
    else if(data<root->data)
    {
        //go left
        root->left=remove(root->left,data);
    }
    else if(data>root->data)
    {
        //go right
        root->right=remove(root->right,data);
    }
    else
    {
        //Element found
        if(root->left && root->right)
        {
            //Both children are present, so replace root with largest element in the left subtree
            temp=findMax(root->left);
            root->data=temp->data;
            //Now remove temp from the left subtree
            //since it is rightmost, so it will have max one child
            root->left=remove(root->left,root->data);
        }
        else
        {
            //One Child is Present
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

void inOrderTraversal(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

int main()
{
    Node *root=NULL;
    while(1)
    {
        cout<<"Press 1 to Insert Element into BST"<<endl;
        cout<<"Press 2 to Delete Element from BST"<<endl;
        cout<<"Press 3 to Search Element from BST"<<endl;
        cout<<"Press 4 to Print BST"<<endl;
        cout<<"Press 5 to find Minimum in BST"<<endl;
        cout<<"Press 6 to find Maximum in BST"<<endl;
        cout<<"Press 7 to Exit"<<endl;
        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;cout<<endl;
        if(choice==7)
        {
            break;
        }
        switch(choice)
        {
            case 1:
            {
                int data;
                cout<<"Enter Element you want to insert: ";
                cin>>data;
                cout<<endl;
                root=insert(root,data);
                cout<<"Data inserted Successfully!!!"<<endl;
                break;
            }
            case 2:
            {
                int data;
                cout<<"Enter Element you want to delete: ";
                cin>>data;
                cout<<endl;
                root=remove(root,data);
                
                
            }
            case 3:
            {
                int data;
                cout<<"Enter the element you want to search: ";
                cin>>data;cout<<endl;
                if(search(root,data))
                {
                    cout<<data<<" found :)"<<endl;
                }
                else
                {
                    cout<<data<<" not found :("<<endl;
                }
                break;
            }
            case 4:
            {
                cout<<"------------------Printing Binary Search Tree----------------"<<endl;
                inOrderTraversal(root);
                cout<<endl<<"-------------------------------------------------------------"<<endl;
                break;
            }
            case 5:
            {
                Node *ans=findMinNonRecursive(root);
                if(!ans)
                {
                    cout<<"BST is Empty!!!"<<endl;
                }
                else
                {
                    cout<<"Minimum value is "<<ans->data<<endl;
                }
                break;
            }
            case 6:
            {
                Node *ans=findMax(root);
                if(!ans)
                {
                    cout<<"BST is Empty!!!"<<endl;
                }
                else
                {
                    cout<<"Maximum value is "<<ans->data<<endl;
                }
                break;
            }
        }
    }
}
