#include<iostream>
using namespace std;

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
    Node *start;
    int size;
    public:
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
    //Menu Driven Program
    LinkedList ll;
    while(1)
    {
        cout<<"Press 1 to Insert At Beginning"<<endl;
        cout<<"Press 2 to Insert At End"<<endl;
        cout<<"Press 3 to Insert Before Position"<<endl;
        cout<<"Press 4 to Delete From Beginning"<<endl;
        cout<<"Press 5 to Delete From End"<<endl;
        cout<<"Press 6 to Delete A Specific Node"<<endl;
        cout<<"Press 7 to Search For A Node"<<endl;
        cout<<"Press 8 to Display the Linked List"<<endl;
        cout<<"Press 9 to Exit"<<endl;
        int choice;
        cout<<"Enter Your Choice: ";
        cin>>choice;
        if(choice==9)
        {
            break;
        }
        cout<<endl;
        switch(choice)
        {
            case 1:
            {
                int val;
                cout<<"Enter the value you want to insert at Beginning: ";
                cin>>val;
                cout<<endl;
                ll.insertAtBeginning(val);
                break;
            }
            case 2:
            {
                int val;
                cout<<"Enter the value you want to insert at End: ";
                cin>>val;
                cout<<endl;
                ll.insertAtEnd(val);
                break;
            }
            case 3:
            {
                cout<<"Enter the position before which you wish to insert: ";
                int pos;
                cin>>pos;
                cout<<endl;
                int val;
                cout<<"Enter the value you want to insert before position: ";
                cin>>val;
                cout<<endl;
                ll.insertInBetween(val,pos);
                break;
            }
            case 4:
            {
                ll.deleteFromBeginning();
                break;
            }
            case 5:
            {
                ll.deleteFromEnd();
                break;
            }
            case 6:
            {
                int val;
                cout<<"Enter the node you want to delete: ";
                cin>>val;
                cout<<endl;
                ll.deleteNode(val);
                break;
            }
            case 7:
            {
                int val;
                cout<<"Enter the node you want to search: ";
                cin>>val;
                cout<<endl;
                ll.search(val);
                break;
            }
            case 8:
            {
                cout<<"-----------Linked List-------------"<<endl;
                ll.display();
                cout<<"-----------------------------------"<<endl;
                break;
            }
        }
    
    }
    


}
