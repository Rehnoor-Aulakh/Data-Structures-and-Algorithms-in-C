class Node
{
    public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val=val;
    }
};

class Stack
{
    Node *top;
    int size;
    public:
    Stack()
    {
        top=NULL;
        size=0;
    }
    bool isEmpty()
    {
        if(top==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(int data)
    {
        Node *nnode=new Node(data);
        nnode->next=top;
        top=nnode;
        size++;
    }
    int pop()
    {
        if(isEmpty())
        {
            cout<<"Stack Underflow!!!"<<endl;
            return -9999;
        }
        else
        {
            Node *temp=top;
            int data=top->val;
            top=top->next;
            delete(temp);
            return data;
        }
    }
    int peek()
    {
        if(isEmpty())
        {
            cout<<"Stack Underflow!!!"<<endl;
            return -9999;
        }
        else
        {
            return top->val;
        }
    }
    int getSize()
    {
        int count=0;
        Node *temp=top;
        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        return count;
    }
    void print()
    {
        Node *temp=top;
        while(temp!=NULL)
        {
            cout<<temp->val<<endl;
            temp=temp->next;
        }
    }
};

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.print();
}
