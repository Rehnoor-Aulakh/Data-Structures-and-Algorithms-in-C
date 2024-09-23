#include<iostream>
using namespace std;

//Definition of Linked List from q1, solution is inside main function
class Node
{
    public:
    int val;
    Node *next;
    Node()
    {
        val=0;
        next=NULL;
    }
    Node(int val)
    {
        this->val=val;
        next=NULL;
    }
};

class LinkedList
{
    public:
    Node *start;
    int size;
    LinkedList()
    {
        start=NULL;
    }
    void insertAtBeginning(int data)
    {
        Node *nnode=new Node(data);
        nnode->next=start;
        start=nnode;
        cout<<data<<" inserted Successfully at Beginning"<<endl;
        size++;
    }
    void insertAtEnd(int data)
    {
        Node *nnode=new Node(data);
        if(start==NULL)
        {
            start=nnode;
            return;
        }
        Node *temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=nnode;
        nnode->next=NULL;
        cout<<data<<" inserted Successfully at End"<<endl;
        size++;
    }
    void insertInBetween(int data, int pos)
    {
        //Insert the data before the pos value
        Node *temp=start;
        while(temp->next->val!=pos)
        {
            temp=temp->next;
        }
        Node *nnode=new Node(data);
        Node *t=temp->next;
        temp->next=nnode;
        nnode->next=t;
        cout<<data<<" inserted before "<<pos<<endl;
        size++;
    }
    void deleteFromBeginning()
    {
        Node *temp=start;
        int val=temp->val;
        start=start->next;
        delete(temp);
        cout<<"Deleted First Node "<<val<<" Successfully!!!"<<endl;
        size--;
    }
    void deleteFromEnd()
    {
        Node *temp=start,*t=start;
        while(t->next->next!=NULL)
        {
            t=t->next;
        }
        temp=t->next;
        t->next=NULL;
        cout<<temp->val<<" Deleted from End Successfully!!!"<<endl;
        delete(temp);
        size--;
    }
    void deleteNode(int data)
    {
        Node *temp=start;
        while(temp->next!=NULL && temp->next->val!=data)
        {
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            cout<<"Element Not Found!!!"<<endl;
            return;
        }
        Node *t=temp->next->next;
        delete(temp->next);
        temp->next=t;
        size--;
    }
    void search(int data)
    {
        Node *temp=start;
        int i=0;
        while(temp->val!=data && temp!=NULL)
        {
            temp=temp->next;
            i++;
        }
        if(temp==NULL)
        {
            cout<<"Element Not Found!!!"<<endl;
        }
        else
        {
            cout<<data<<" found at position "<<i<<" from head"<<endl;
        }
    }
    void display()
    {
        Node *temp=start;
        while(temp!=NULL)
        {
            cout<<temp->val<<"-->";
            temp=temp->next;
        }
        cout<<"X"<<endl;
    }
};

int main()
{
    LinkedList ll;
    ll.insertAtEnd(1);
    ll.insertAtEnd(2);
    ll.insertAtEnd(3);
    ll.insertAtEnd(4);
    ll.insertAtEnd(5);
    //Easy method, first find size of the linked list and then iterate till size/2 and print the middle node
    Node *t=ll.start;
    int size=0;
    ll.display();
    while(t!=NULL)
    {
        t=t->next;
        size++;
    }
    cout<<size<<endl;
    t=ll.start;
    for(int i=1;i<=size/2;i++)
    {
        t=t->next;
    }
    cout<<"Middle of Linked list is: "<<t->val<<endl;
    
    //Better Method is to use slow and fast pointers where slow pointer moves 1 step and fast pointer moves 2 steps
    //When fast pointer is null, print slow pointer's value which would be the middle of linked list because at every iteration, difference of slow and fast pointer increases by 1
    Node *slow=ll.start;
    Node *fast=ll.start;
    while(fast!=NULL && fast->next!=NULL)
    {
        if(fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
    }
    cout<<"Middle of Linked list is: "<<slow->val<<endl;
}