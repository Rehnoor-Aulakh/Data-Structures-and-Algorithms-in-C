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
    //Creating the Linked List given in the question
    ll.insertAtEnd(1);
    ll.insertAtEnd(2);
    ll.insertAtEnd(1);
    ll.insertAtEnd(2);
    ll.insertAtEnd(1);
    ll.insertAtEnd(3);
    ll.insertAtEnd(1);
    ll.display();
    //You can create your custom linked list and check the algorithm
    cout<<"Enter the Key: ";
    int key;
    cin>>key;
    int count=0;
    if(ll.start==NULL)
    {
        cout<<"List is Empty!!!"<<endl;
        return 0;
    }
    //Delete all the nodes from the beginning that match with key
    while(ll.start!=NULL && ll.start->val==key)
    {
        Node *temp=ll.start;
        count++;
        ll.start=ll.start->next;
        delete(temp);
    }
    //Now start is not equal to key, maintain two pointers t and temp, temp is the one that will check if key is found
    //t is the previous node of temp and is used for deleting temp
    Node *current=ll.start;
    Node *previous=NULL;
    //It is a guarantee now that the current node is not key, so we can assign previous inside the loop
    while(current!=NULL)
    {
        if(current->val==key)
        {
            count++;
            previous->next=current->next;
            delete(current);
            current=previous->next;
        }
        else
        {
            previous=current;
            current=current->next;
        }
    }
    cout<<"Number of keys in the linked list are "<<count<<endl;
    ll.display();
}