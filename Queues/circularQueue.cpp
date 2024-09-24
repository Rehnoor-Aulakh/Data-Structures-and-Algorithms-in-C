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
        arr=new int[capacity+1];
        front=-1;
        rear=-1;
        this->capacity=capacity+1;
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
    queue Q(6);
    Q.enQueue(4);
    Q.enQueue(5);
    Q.enQueue(7);
    cout<<Q.deQueue()<<endl;
    cout<<Q.deQueue()<<endl;
    Q.enQueue(8);
    Q.enQueue(9);
    Q.enQueue(1);
    Q.enQueue(1);
    Q.display();
}