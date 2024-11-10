#include<iostream>
#include<stack>
#include<queue>
#include<limits.h>
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

class BinaryTree
{
    public:
    Node *root;
    BinaryTree()
    {
        root=new Node();
        root->data=0;
        root->left=NULL;
        root->right=NULL;
    }
    BinaryTree(int data)
    {
        root->data=data;
        root->left=NULL;
        root->right=NULL;
    }
    void preOrder()
    {
        preOrder(root);
        cout<<endl;
    }
    void preOrderIterative()
    {
        preOrderIterative(root);
        cout<<endl;
    }
    void inOrder()
    {
        inOrder(root);
        cout<<endl;
    }
    void inOrderIterative()
    {
        inOrderIterative(root);
        cout<<endl;
    }
    void postOrder()
    {
        postOrder(root);
        cout<<endl;
    }
    void postOrderIterative()
    {
        postOrderIterative(root);
        cout<<endl;
    }
    void levelOrderTraversal()
    {
        levelOrderTraversal(root);
        cout<<endl;
    }
    int max()
    {
        return max(root);
    }
    int maxIterative()
    {
        return maxIterative(root);
    }
    bool search(int val)
    {
        return search(root, val);
    }
    bool searchIterative(int val)
    {
        return searchIterative(root, val);
    }
    void insert(int val)
    {
        insert(root,val);
        cout<<val<<" inserted successfully in tree"<<endl;
    }
    int size()
    {
        return size(root);
    }
    int sizeIterative()
    {
        return sizeIterative(root);
    }
    int height()
    {
        return height(root);
    }
    int diameter()
    {
        return diameter(root);
    }
    int findMaxLevelSum()
    {
        return findMaxLevelSum(root);
    }
    void rootToLeafPaths()
    {
        int a[20];
        rootToLeafPaths(root,a,0);
    }
    bool hasPathSum(int target)
    {
        return hasPathSum(root,target);
    }
    int sum()
    {
        return sum(root);
    }
    Node* mirrorOfBinaryTree()
    {
        return mirrorOfBinaryTree(root);
    }
    

    private:
    void preOrder(Node *root)
    {
        //First Process the root node, then the left subtree, then right subtree and this should be recursive
        if(root)
        {
            cout<<root->data<<" ";
            preOrder(root->left);
            preOrder(root->right);            
        }
    }
    void preOrderIterative(Node *root)
    {
        //In Recursion, Function Stack was helping us store the previous node while going to left and then right
        //for iterative approach, we will manually store the current node in the stack and then move left and right in the tree
        stack<Node *> st;
        //first process the current node, then store the node on the stack before going left, after completing the left subtree, pop the current node from the stack and go right
        while(1)
        {
            while(root)
            {
                cout<<root->data<<" ";
                st.push(root);
                root=root->left;    //If left subtree exists, push it to stack
            }
            //Now we are at the extreme left and the stack is now full, start poping
            if(st.empty())
            {
                break;
            }
            root=st.top();
            st.pop();
            //Now go to the right subtree
            root=root->right;
        }
        cout<<endl;
    }
    void inOrder(Node *root)
    {
        if(root)
        {
            inOrder(root->left);
            cout<<root->data<<" ";
            inOrder(root->right);
        }
    }
    void inOrderIterative(Node *root)
    {
        stack<Node *> st;
        while(1)
        {
            while(root)
            {
                st.push(root);
                root=root->left;
            }
            if(st.empty())
            {
                break;
            }
            root=st.top();
            st.pop();
            cout<<root->data<<" ";
            root=root->right;
        }
    }
    void postOrder(Node *root)
    {
        if(root)
        {
            postOrder(root->left);
            postOrder(root->right);
            cout<<root->data<<" ";
        }
    }
    void postOrderIterative(Node *root)
    {
        stack<Node *> st;
        while(1)
        {
            while(root)
            {
                st.push(root);
                root=root->left;
            }
            if(st.empty())
            {
                break;
            }
            root=st.top();
            root=root->right;
            
        }
    }
    void levelOrderTraversal(Node *root)
    {
        queue<Node *>q;
        q.push(root);
        while(!q.empty())
        {
            Node *temp=q.front();
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    int max(Node *root)
    {
        if(root)
        {
            int max_val;
            int root_val=root->data;
            int left=max(root->left);
            int right=max(root->right);
            if(left>right)
            {
                max_val=left;
            }
            else
            {
                max_val=right;
            }
            if(root_val>max_val)
            {
                max_val=root_val;
            }
            return max_val;
        }
        else
        {
            return INT_MIN;
        }
    }
    int maxIterative(Node *root)
    {
        //In level order traversal, simply check for the maximum value while deleting from the queue
        queue<Node *>q;
        int max=INT_MIN;
        q.push(root);
        while(!q.empty())
        {
            Node *temp=q.front();
            if(temp->data>max)
            {
                max=temp->data;
            }
            q.pop();
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
        return max;
    }
    bool search(Node *root, int val)
    {
        if(!root)
        {
            return false;
        }
        if(root->data==val)
        {
            return true;
        }
        else
        {
            return search(root->left,val)||search(root->right,val);
        }
    }
    bool searchIterative(Node *root, int val)
    {
        queue<Node *>q;
        q.push(root);
        Node *temp=root;
        while(!q.empty())
        {
            temp=q.front();
            q.pop();
            if(temp->data==val)
            {
                return true;
            }
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
        }
        return false;
    }
    void insert(Node *root, int val)
    {
        //Since it is binary tree, we can insert wherever we want
        //using level order traversal, where we find left or right node to be null, we will insert new node there
        Node *nnode=new Node(val);
        queue<Node *>q;
        Node *temp;
        q.push(root);
        while(!q.empty())
        {
            temp=q.front();
            q.pop();
            if(temp->left)
            {
                q.push(temp->left);
            }
            else
            {
                //Insert new node at temp->left
                temp->left=nnode;
                return;
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
            else
            {
                temp->right=nnode;
                return;
            }
        }
    }
    int size(Node *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        else
        {
            return size(root->left)+1+size(root->right);
        }
    }
    int sizeIterative(Node *root)
    {
        queue<Node *>q;
        Node *temp;
        q.push(root);
        int count=0;
        while(!q.empty())
        {
            temp=q.front();
            q.pop();
            count++;
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
        }
        return count;
    }
    int height(Node *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int lheight=height(root->left);
        int rheight=height(root->right);
        if(lheight>rheight)
        {
            return 1+lheight;
        }
        else
        {
            return 1+rheight;
        }
    }
    int max(int a,int b)
    {
        if(a>b)
        {
            return a;
        }
        else
        {
            return b;
        }
    }
    int diameter(Node *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        //Diameter is the distance between two leaves
        int ldiameter=diameter(root->left);
        int rdiameter=diameter(root->right);
        int lheight=height(root->left);
        int rheight=height(root->right);
        return max(max(ldiameter,rdiameter),lheight+1+rheight);

    }
    int findMaxLevelSum(Node *root)
    {
        if(!root)
        {
            return 0;
        }
        queue<Node *>q;
        int max_sum=0,curr_sum=0,level=0,maxLevel=0;
        q.push(root);
        q.push(NULL);
        //NULL marks the end of first level
        Node *temp;
        while(!q.empty())
        {
            temp=q.front();
            q.pop();
            //If the current level is completed, then compare sums
            if(temp==NULL)
            {
                if(curr_sum>max_sum)
                {
                    max_sum=curr_sum;
                    maxLevel=level;
                }
                curr_sum=0;
                //Place the indicator for end of next level at end of queue
                if(!q.empty())
                {
                    q.push(NULL);
                }
                level++;
            }
            else
            {
                curr_sum+=temp->data;
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
            }
        }
        return maxLevel;
    }
    void printArray(int arr[], int count)
    {
        for(int i=0;i<count;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void rootToLeafPaths(Node *root, int arr[], int count)
    {
        if(root==NULL)
        {
            return;
        }
        arr[count++]=root->data;
        if(root->left==NULL && root->right==NULL)
        {
            printArray(arr,count);
            return;
        }
        rootToLeafPaths(root->left,arr,count);
        rootToLeafPaths(root->right,arr,count);
    }
    bool hasPathSum(Node *root, int target)
    {
        if(root==NULL)
        {
            return (target==0);
        }
        target-=root->data;
        return hasPathSum(root->left,target) || hasPathSum(root->right,target);
    }
    int sum(Node *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        return root->data+sum(root->left)+sum(root->right);
    }
    Node* mirrorOfBinaryTree(Node *root)
    {
        if(root)
        {
            //Recursively Swap the left and right Nodes
            Node *temp=root->left;
            root->left=root->right;
            root->right=temp;
        }
        return root;
    }
    bool checkMirror(Node *root1, Node *root2)
    {
        if(root1==NULL && root2==NULL)
        {
            return true;
        }
        if(root1==NULL || root2==NULL)
        {
            return false;
        }
        return (root1->data==root2->data) && checkMirror(root1->left,root2->right) && checkMirror(root1->right,root2->left);
    }
    Node* lowestCommonAncestor(Node *root, Node *p, Node *q)
    {
        if(root==NULL)
        {
            return NULL;
        }
        Node *left=lowestCommonAncestor(root->left,p,q);
        Node *right=lowestCommonAncestor(root->right,p,q);
        if(left!=NULL && right!=NULL)
        {
            return root;
        }
        else if(left==NULL && right!=NULL)
        {
            return right;
        }
        else if(left!=NULL && right==NULL)
        {
            return left;
        }
    }

};

void createTree(Node* root) 
{
    if(!root)
    {
        return;
    }   
    cout << "Enter Node Data: ";
    cin >> root->data;

    while (true) {
        cout << "Press 1 to Create Left Node" << endl;
        cout << "Press 2 to Create Right Node" << endl;
        cout << "Press 3 to Return" << endl;
        int choice;
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (root->left == NULL) {  // Check if left node already exists
                    root->left = new Node(); // Create left node
                    cout << "Left Node Created" << endl;
                    createTree(root->left);
                } else {
                    cout << "Left Node already exists." << endl;
                }
                break;

            case 2:
                if (root->right == NULL) { // Check if right node already exists
                    root->right = new Node(); // Create right node
                    cout << "Right Node Created" << endl;
                    createTree(root->right);
                } else {
                    cout << "Right Node already exists." << endl;
                }
                break;

            case 3:
                return;  // Exit the function
            default:
                cout << "Invalid Choice. Try again." << endl;
        }
    }
}

int search(int inOrder[],int start,int end,int element)
    {
        for(int i=start;i<=end;i++)
        {
            if(inOrder[i]==element)
            {
                return i;
            }
        }
        return -1;
    }
Node* buildBinaryTreePreOrderInOrder(int inOrder[],int preOrder[],int inOrderStart,int inOrderEnd)
    {
        static int preOrderIndex=0;
        if(inOrderStart>inOrderEnd)
        {
            return NULL;
        }
        Node *nnode=new Node(preOrder[preOrderIndex++]);
        if(inOrderStart==inOrderEnd)
        {
            return nnode;
        }
        //search for the element index in inOrder Traversal
        int inOrderIndex=search(inOrder,inOrderStart,inOrderEnd,nnode->data);
        nnode->left=buildBinaryTreePreOrderInOrder(inOrder,preOrder,inOrderStart,inOrderIndex-1);
        nnode->right=buildBinaryTreePreOrderInOrder(inOrder,preOrder,inOrderIndex+1,inOrderEnd);
        return nnode;
    }
Node* buildBinaryTreePostOrderInOrder(int inOrder[],int postOrder[],int inOrderStart,int inOrderEnd)
{
    static int postOrderIndex=(sizeof(postOrderIndex)/sizeof(int))-1;
    if(inOrderStart>inOrderEnd)
    {
        return NULL;
    }
    Node *nnode=new Node(postOrder[postOrderIndex--]);
    if(inOrderStart==inOrderEnd)
    {
        return nnode;
    }
    //search for the inOrderIndex of nnode->data
    int inOrderIndex=search(inOrder,inOrderStart,inOrderEnd,nnode->data);
    nnode->right=buildBinaryTreePostOrderInOrder(inOrder,postOrder,inOrderIndex+1,inOrderEnd);
    nnode->left=buildBinaryTreePostOrderInOrder(inOrder,postOrder,inOrderStart,inOrderIndex-1);
    return nnode;
}
Node* buildBinaryTreeLevelOrderInOrder(int inOrder[],int levelOrder[],int inOrderStart,int inOrderEnd)
{
    static int levelOrderIndex=0;
    if(inOrderStart>inOrderEnd)
    {
        return NULL;
    }
    Node *nnode=new Node(levelOrder[levelOrderIndex++]);
    if(inOrderStart==inOrderEnd)
    {
        return nnode;
    }
    int inOrderIndex=search(inOrder,inOrderStart,inOrderEnd,nnode->data);
    nnode->left=buildBinaryTreeLevelOrderInOrder(inOrder,levelOrder,inOrderStart,inOrderIndex-1);
    nnode->right=buildBinaryTreeLevelOrderInOrder(inOrder,levelOrder,inOrderIndex+1,inOrderEnd);
    return nnode;
}
void InOrderTraversal(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    InOrderTraversal(root->left);
    cout<<root->data<<" ";
    InOrderTraversal(root->right);
}


int main()
{
    // BinaryTree bt;
    // createTree(bt.root);
    // bt.insert(12);
    // cout<<"PreOrder Traversal"<<endl;
    // bt.preOrder();
    // bt.preOrderIterative();
    // cout<<"InOrder Traversal"<<endl;
    // bt.inOrder();
    // bt.inOrderIterative();
    // cout<<"Level Order Traversal"<<endl;
    // bt.levelOrderTraversal();
    // cout<<"Maximum Value is "<<bt.maxIterative()<<endl;
    // if(bt.searchIterative(8))
    // {
    //     cout<<"8 Exists"<<endl;
    // }
    // cout<<"Size of tree is "<<bt.sizeIterative()<<endl;
    // cout<<"Height of tree is "<<bt.height()<<endl;
    // cout<<"Diameter of tree is "<<bt.diameter()<<endl;
    // bt.rootToLeafPaths();
    // cout<<"Sum of All Nodes in Tree is "<<bt.sum()<<endl;
    int inOrder[]={4,2,5,1,6,3,7};
    int levelOrder[]={1,2,3,4,5,6,7};
    Node *root=buildBinaryTreeLevelOrderInOrder(inOrder,levelOrder,0,6);
    InOrderTraversal(root);
}

