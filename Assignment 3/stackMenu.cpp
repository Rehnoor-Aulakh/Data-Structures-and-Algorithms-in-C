#include<iostream>
#include<limits.h>
using namespace std;

class Stack
{
    int *arr;
    int top;
    int capacity;
    public:
    Stack()
    {

    }
    Stack(int capacity)
    {
        this->capacity=capacity;
        arr=new int[capacity];
        top=-1;
    }
    
    bool push(int);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
    void display()
    {
        if(isEmpty())
        {
            return;
        }
        else
        {
            int val=pop();
            cout<<val<<endl;
            display();
            push(val);
        }
    }

};

bool Stack::push(int val)
{
    if(top==capacity)
    {
        return false;
    }
    top++;
    arr[top]=val;
    return true;
}

int Stack::pop()
{
    if(top==-1)
    {
        return INT_MIN;
    }
    int val=arr[top];
    top--;
    return val;
}

int Stack::peek()
{
    if(top==-1)
    {
        return INT_MIN;
    }
    return arr[top];
}

bool Stack::isEmpty()
{
    return (top==-1);
}

bool Stack::isFull()
{
    return (top==capacity);
}


int main()
{
    Stack st;
    while(1)
    {
        cout<<"Press 1 to Create Stack"<<endl;
        cout<<"Press 2 to Push into Stack"<<endl;
        cout<<"Press 3 to Peek from Stack"<<endl;
        cout<<"Press 4 to Pop from Stack"<<endl;
        cout<<"Press 5 to Display Stack"<<endl;
        cout<<"Press 6 to Quit"<<endl;
        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;
        cout<<endl;
        if(choice==6)
        {
            break;
        }
        switch(choice)
        {
            case 1:
            {
                int size;
                cout<<"Enter size of Stack: ";
                cin>>size;
                cout<<endl;
                st=Stack(size);
                cout<<"Stack Created Successfully"<<endl;
                break;
            }
            case 2:
            {
                int val;
                cout<<"Enter value to push: ";
                cin>>val;
                cout<<endl;
                st.push(val);
                break;
            }
            case 3:
            {
                cout<<"Top value is "<<st.peek()<<endl;
                break;
            }
            case 4:
            {
                cout<<"Popped value is "<<st.peek()<<endl;
                break;
            }
            case 5:
            {
                st.display();
                break;
            }
        }
    }
    
}