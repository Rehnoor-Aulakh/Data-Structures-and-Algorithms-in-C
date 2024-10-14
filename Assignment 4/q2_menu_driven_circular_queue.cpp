#include<iostream>
using namespace std;

class queue
{
    public:
    int *arr;
    int front,rear;
    int size;
    int capacity;
    queue(int capacity)
    {
        arr=new int[capacity];
        front=-1;
        rear=-1;
        this->capacity=capacity;
        size=0;
        cout<<"Queue Created Successfully!!!"<<endl;
    }
    bool isEmpty()
    {
        return(front==-1 && rear==-1);
        
    }
    bool isFull()
    {
        return (size==capacity-1);
    }
    void enQueue(int data)
    {
        if(isFull())
        {
            cout<<"Cannot insert "<<data<<endl<<"Queue is Full!!!"<<endl;
            return;
        }
        else
        {
            rear=(rear+1)%capacity;
            arr[rear]=data;
            //If initially queue was empty, then increment front
            if(front==-1)
            {
                front=rear;
            }
            size++;
            cout<<data<<" inserted Successfully!!!"<<endl;
        }
    }
    int deQueue()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty!!!"<<endl;
            return 0;
        }
        int data=arr[front];
        if(front==rear)
        {
            //If element to be deleted is the only element
            //Then after deleting size should be 0 and front=rear=-1
            front=-1;
            rear=-1;
            size=0;
        }
        else
        {
            //Increment Front
            front=(front+1)%capacity;
            size--;
            
        }
        return data;
        
    }
    int peek()
    {
        return arr[front];
    }

    void display()
    {
        cout<<"--------------Printing Queue------------"<<endl;
        for(int i=front,count=0;count<size;count++)
        {
            cout<<arr[i]<<" ";
            i=(i+1)%capacity;
        }
        cout<<endl<<"-----------------------------------------"<<endl;
    }
};

int main()
{
    int size;
    cout<<"Enter the size of queue: ";
    cin>>size;
    cout<<endl;
    queue q(size);
    while(1)
    {
        cout<<"Press 1 to Enqueue"<<endl;
        cout<<"Press 2 to Dequeue"<<endl;
        cout<<"Press 3 to Check Empty"<<endl;
        cout<<"Press 4 to Check Full"<<endl;
        cout<<"Press 5 to Display Queue"<<endl;
        cout<<"Press 6 to Peek"<<endl;
        cout<<"Press 7 to Exit"<<endl;
        int choice;
        cout<<"Enter your choice: "<<endl;
        cin>>choice;
        cout<<endl;
        if(choice==7)
        {
            break;
        }
        switch(choice)
        {
            case 1:
            {
                int data;
                cout<<"Enter Element you want to Enqueue: ";
                cin>>data;
                cout<<endl;
                q.enQueue(data);
                break;
            }
            case 2:
            {
                cout<<q.deQueue()<<" removed from the Queue"<<endl;
                break;
            }
            case 3:
            {
                if(q.isEmpty())
                {
                    cout<<"Queue is Empty"<<endl;
                }
                break;
            }
            case 4:
            {
                if(q.isFull())
                {
                    cout<<"Queue is Full"<<endl;
                }
                break;
            }
            case 5:
            {
                q.display();
                break;
            }
            case 6:
            {
                cout<<q.peek()<<endl;
                break;
            }

        }
    }
}
