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

class CircularLinkedList
{
    public:
    Node *start;
    int size;
    CircularLinkedList()
    {
        start=NULL;
        size=0;
    }
    void insertAtBeginning(int data)
    {
        Node *nnode=new Node(data);
        if(start==NULL)
        {
            start=nnode;
            nnode->next=start;
        }
        else
        {
            nnode->next=start;
            Node *temp=start;
            while(temp->next!=start)
            {
                temp=temp->next;
            }
            temp->next=nnode;
            start=nnode;
            cout<<data<<" inserted Successfully at Beginning"<<endl;
        }
        size++;
        
    }
    void insertAtEnd(int data)
    {
        Node *nnode=new Node(data);
        if(start==NULL)
        {
            start=nnode;
            nnode->next=start;
        }
        else
        {
            Node *temp=start;
            while(temp->next!=start)
            {
                temp=temp->next;
            }
            temp->next=nnode;
            nnode->next=start;
            cout<<data<<" inserted Successfully at End"<<endl;
        }
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
    void deleteNode(int data)
    {
        //Delete the node with data, it may be in the beginning or end or in between
        //We will manage this using edge cases
        if(start==NULL)
        {
            cout<<"List is Empty!!!"<<endl;
            return;
        }
        //Delete from beginning
        if(start->val==data)
        {
            Node *temp=start;
            //temp will be used to assign the last pointer to start
            Node *t=start;
            //It will be used to delete t
            start=start->next;
            temp=temp->next;
            while(temp->next!=t)
            {
                temp=temp->next;
            }
            temp->next=start;
            cout<<data<<" deleted successfully from the list"<<endl;
            delete(t);
            return;
            
        }
        //Delete from Middle
        Node *prev=start;
        Node *temp=start->next;
        while(temp->next!=start)
        {
            if(temp->val==data)
            {
                prev->next=temp->next;
                delete(temp);
                cout<<data<<" deleted successfully from the list"<<endl;
                return;
            }
            prev=temp;
            temp=temp->next;
        }
        if(temp->val==data)
        {
            prev->next=start;
            delete(temp);
            cout<<data<<" deleted successfully from the list"<<endl;
            return;
        }
        cout<<data<<" Not Found!!!"<<endl;

    }
    void search(int data)
    {
        if(start==NULL)
        {
            cout<<"List is Empty!!!"<<endl;
            return;
        }
        Node *temp=start;
        do
        {
            if(temp->val==data)
            {
                cout<<data<<" found in the list"<<endl;
                return;
            }
            temp=temp->next;
        }while(temp!=start);
        cout<<data<<" Not Found!!!"<<endl;
    }
    void display()
    {
        if(start==NULL)
        {
            cout<<"List is Empty!!!"<<endl;
            return;
        }
        Node *temp=start;
        cout<<"-------------Printing Circular Linked List---------------"<<endl;
        cout<<"start-->";
        do
        {
            cout<<temp->val<<"-->";
            temp=temp->next;
        } while (temp!=start);
        cout<<"start"<<endl;
    }
};

int main()
{
    CircularLinkedList cll;   
    while(1)
    {
        cout<<"Press 1 to Insert At Beginning"<<endl;
        cout<<"Press 2 to Insert At End"<<endl;
        cout<<"Press 3 to Insert Before Given Positioin"<<endl;
        cout<<"Press 4 to Delete an Element"<<endl;
        cout<<"Press 5 to Search for an Element"<<endl;
        cout<<"Press 6 to Display"<<endl;
        cout<<"Press 7 to Exit"<<endl;
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;
        if(choice==7)
        {
            break;
        }
        switch(choice)
        {
            case 1:
            {
                int data;
                cout<<"Enter the element you want to insert: ";
                cin>>data;
                cout<<endl;
                cll.insertAtBeginning(data);
                break;
            }
            case 2:
            {
                int data;
                cout<<"Enter the element you want to insert: ";
                cin>>data;
                cout<<endl;
                cll.insertAtEnd(data);
                break;
            }
            case 3:
            {
                int data;
                cout<<"Enter the element you want to insert: ";
                cin>>data;
                cout<<endl;
                cout<<"Enter the position before which you want to insert: ";
                int pos;
                cin>>pos;
                cout<<endl; 
                cll.insertInBetween(data,pos);
                break;
            }
            case 4:
            {
                int data;
                cout<<"Enter the element you want to delete: ";
                cin>>data;
                cout<<endl;
                cll.deleteNode(data);
            }
            case 5:
            {
                int data;
                cout<<"Enter the element you want to delete: ";
                cin>>data;
                cout<<endl;
                cll.search(data);
            }
            case 6:
            {
                cll.display();
            }
        }

    }
}
