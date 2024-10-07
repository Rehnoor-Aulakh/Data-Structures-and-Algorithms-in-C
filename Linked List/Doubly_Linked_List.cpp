#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data=data;
    }
};

class DoublyLinkedList
{
    Node *start;
    Node *tail;
    public:
    DoublyLinkedList()
    {
        start=NULL;
        tail=NULL;
    }
    void insertAtBeginning(int val)
    {
        Node *nnode=new Node(val);
        nnode->prev=NULL;
        nnode->next=NULL;
        if(start==NULL)
        {
            //Linked List is Empty
            start=nnode;
            tail=nnode;
        }
        else
        {
            nnode->next=start;
            start->prev=nnode;
            start=nnode;
        }
        cout<<"Inserted "<<val<<" At the Beginning"<<endl;
    }
    void insertAtEnd(int val)
    {
        Node *nnode=new Node(val);
        nnode->next=NULL;
        nnode->prev=NULL;
        if(start==NULL)
        {
            start=nnode;
            tail=nnode;
        }
        else
        {
            tail->next=nnode;
            nnode->prev=tail;
            tail=nnode;
        }
        cout<<"Inserted "<<val<<" At the End"<<endl;
    }
    void insertAtPosition(int val, int pos)
    {
        Node *nnode=new Node(val);
        nnode->next=NULL;
        nnode->prev=NULL;
        if(pos==1)
        {
            //Insert At Beginning
            insertAtBeginning(val);
        }
        else
        {
            Node *temp=start;
            int k=1;
            while(k!=pos-1 && temp->next!=NULL)
            {
                temp=temp->next;
                k++;
            }
            if(k!=pos-1)
            {
                cout<<"Desired Position does not exist!!!"<<endl;
                return;
            }
            nnode->next=temp->next;
            nnode->prev=temp;
            if(temp->next)
            {
                temp->next->prev=nnode;
            }
            else
            {
                tail=nnode;
            }
            temp->next=nnode;
        }
    }
    void deleteFromBeginning()
    {
        if(start==NULL)
        {
            cout<<"List Is Empty!!!"<<endl;
            return;
        }
        Node *temp=start;
        cout<<"Deleted "<<temp->data<<" From Beginning"<<endl;
        start=start->next;
        start->prev=NULL;
        delete(temp);
    }
    void deleteFromEnd()
    {
        if(start==NULL)
        {
            cout<<"List is Empty!!!"<<endl;
            return;
        }
        Node *temp=tail;
        cout<<"Deleted "<<temp->data<<" From the end"<<endl;
        tail->prev->next=NULL;
        tail=tail->prev;
        delete(temp);
    }
    void deleteFromPosition(int pos)
    {
        if(pos==1)
        {
            deleteFromBeginning();
            return;
        }
        if(start==NULL)
        {
            cout<<"List is Empty!!!"<<endl;
            return;
        }
        Node *temp=start;
        int k=1;
        while(k!=pos && temp->next!=NULL)
        {
            temp=temp->next;
            k++;
        }
        temp->prev->next=temp->next;
        if(temp->next)
        {
            temp->next->prev=temp->prev;
        }
        else
        {
            tail=temp->prev;
        }
        cout<<"Deleted "<<temp->data<<" from "<<pos<<endl;
        delete(temp);
    }
    void print()
    {
        Node *temp=start;
        while(temp!=NULL)
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
};

int main()
{
    DoublyLinkedList dll;
    dll.insertAtBeginning(10);
    dll.insertAtBeginning(20);
    dll.insertAtBeginning(30);
    dll.insertAtEnd(40);
    dll.insertAtEnd(50);
    dll.insertAtPosition(60,3);
    dll.deleteFromBeginning();
    dll.deleteFromEnd();
    dll.deleteFromEnd();
    dll.insertAtEnd(70);
    dll.deleteFromPosition(3);
    dll.print();
}