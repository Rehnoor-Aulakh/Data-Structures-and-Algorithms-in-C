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
    //Create a linked list as given in the question
    LinkedList ll;
    ll.insertAtEnd(1);
    ll.insertAtEnd(2);
    ll.insertAtEnd(3);
    ll.insertAtEnd(4);
    ll.display();
    //If the linked list is empty or there is only one element, no need to reverse it.
    if(ll.start==NULL || ll.start->next==NULL)
    {
        //Return as it is
        return 0;
    }
    
    Node *preNode=NULL;
    Node *currNode=ll.start;
    while(currNode!=NULL)
    {
        Node *nextNode=currNode->next;
        currNode->next=preNode;
        preNode=currNode;
        currNode=nextNode;
    }
    ll.start=preNode;
    ll.display();

}
