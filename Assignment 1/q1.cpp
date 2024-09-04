#include<iostream>
#include<limits.h>
using namespace std;

class Array
{
    int* a;
    int size;
    int i;
    public:
    Array()
    {
        a=nullptr;
        size=0;
        i=0;
    }
    Array(int s)
    {
        size=s;
        i=0;
        a=new int[size];
    }
    void display()
    {
        cout<<"\n----------------------Array----------------\n";
        for(int j=0;j<i;j++)
        {
            cout<<a[j]<<" ";
        }
        cout<<"\n-------------------------------------------\n";
    }
    void insertAtEnd(int data)
    {
        //Insert at i+1 position
        if(i>=size)
        {
            cout<<"Array Out of Bound!!!\n";
            return;
        }
        a[i]=data;
        i++;
        cout<<data<<" inserted successfully at end\n";
    }
    void insertAtBeginning(int data)
    {
        if(i+1>=size)
        {
            cout<<"Array Out of Bound!!!"<<endl;
            return;
        }
        for(int j=i;j>=0;j--)
        {
            a[j+1]=a[j];
        }
        a[0]=data;
        i++;
        cout<<data<<" inserted successfully at beginning\n";
    }
    void insertAtGivenPosition(int data, int pos)
    {
        if(i>=size)
        {
            cout<<"Array out of bound!!!\n";
        }
        else if(pos<0 || pos>i)
        {
            cout<<"Invalid Position!!!\n";
        }

        for(int j=i;j>pos;j--)
        {
            a[j]=a[j-1];
        }
        a[pos]=data;
        i++;
        cout<<data<<" inserted successfully at position "<<endl;
    }
    int deleteAtEnd()
    {
        if(i==0)
        {
            cout<<"Array is Empty!!!\n";
            return INT_MIN;
        }
        i--;
        return a[i+1];   
    }
    int deleteAtFront()
    {
        if(i==0)
        {
            cout<<"Array is Empty!!!"<<endl;
            return INT_MIN;
        }

        int val=a[0];
        for(int j=0;j<i-1;j++)
        {
            a[j]=a[j+1];
        }
        i--;
        return val;
    }
    int deleteAtGivenPosition(int pos)
    {
        if(pos<0 || pos>=i)
        {
            cout<<"Array out of bound!!!\n";
            return INT_MIN;
        }
        int val=a[pos];
        for(int j=pos;j<i-1;j++)
        {
            a[j]=a[j+1];
        }
        i--;
        return val;
    }
    int search(int val)
    {
        int j;
        for(j=0;j<i;j++)
        {
            if(val==a[j])
            {
                return j;
            }
        }
        return INT_MIN;
    }

};


int main()
{
    Array arr;
    while(1)
    {
        cout<<"Press 1 to Create an Array\n";
        cout<<"Press 2 to Display an Array\n";
        cout<<"Press 3 to Insert Element in Array\n";
        cout<<"Press 4 to Delete Element from Array\n";
        cout<<"Press 5 to Search for an Element in Array\n";
        cout<<"Press 6 to Exit\n";
        cout<<"Enter Your Choice: ";
        int choice;
        cin>>choice;
        if(choice==6)
        {
            break;
        }
        cout<<endl;
        int size;
        switch(choice)
        {
            case 1:
            {
                cout<<"Enter the size of Array: ";
                cin>>size;
                arr= Array(size);
                cout<<"Array Created Successfully"<<endl;
                break;
            }
            case 2:
            {
                arr.display();
                break;
            }
            case 3:
            {
                cout<<"Press 1 to Insert at End\n";
                cout<<"Press 2 to Insert at Beginning\n";
                cout<<"Press 3 to Insert at Defined Position\n";
                int ch;
                cout<<"Enter your choice: ";
                cin>>ch;
                int data;
                cout<<"Enter the value you want to insert: ";
                cin>>data;
                cout<<endl;
                switch(ch)
                {
                    case 1:
                    {
                        arr.insertAtEnd(data);
                        break;
                    }
                    case 2:
                    {
                        arr.insertAtBeginning(data);
                        break;
                    }
                    case 3:
                    {
                        int pos;
                        cout<<"Enter the position where you want to insert element: ";
                        cin>>pos;
                        cout<<endl;
                        arr.insertAtGivenPosition(data,pos);
                        break;
                    }
                }
                break;
            }
            case 4:
            {
                cout<<"Press 1 to Delete from End\n";
                cout<<"Press 2 to Delete from Beginning\n";
                cout<<"Press 3 to Delete from Defined Position\n";
                int ch;
                cout<<"Enter your choice: ";
                cin>>ch;
                switch(ch)
                {
                    case 1:
                    {
                        cout<<arr.deleteAtEnd()<<" deleted from end\n";
                        break;
                    }
                    case 2:
                    {
                        cout<<arr.deleteAtFront()<<" deleted from beginning\n";
                        break;
                    }
                    case 3:
                    {
                        int pos;
                        cout<<"Enter the Position to Delete\n";
                        cin>>pos;
                        cout<<arr.deleteAtGivenPosition(pos)<<" deleted from position "<<pos<<endl;
                    }
                }
                break;
            }
            case 5:
            {
                int val;
                cout<<"Enter the element you want to search: ";
                cin>>val;
                int pos=arr.search(val);
                if(pos!=INT_MIN)
                {
                    cout<<"Element found at position "<<pos<<endl;
                }
                break;
            }
        }
    }
}
