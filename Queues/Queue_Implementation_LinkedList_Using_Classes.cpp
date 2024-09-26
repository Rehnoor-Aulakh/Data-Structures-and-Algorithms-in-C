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

class Queue
{
    Node *front;
    Node *rear;
    public:
    Queue()
    {
        front=NULL;
        rear=NULL;
    }
    bool isEmpty()
    {
        return (front==NULL);
    }
    void enqueue(int data)
    {
        if(front==NULL)
        {
            front=new Node(data);
            rear=front;
        }
        else
        {
            Node *nnode=new Node(data);
            rear->next=nnode;
            rear=nnode;
        }
    }
    int dequeue()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty!!!"<<endl;
            return -9999;
        }
        //remove the front node
        int val=front->val;
        Node *temp=front;
        front=front->next;
        delete(temp);
        return val;
    }
    int peek()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty!!!"<<endl;
            return -9999;
        }
        return front->val;
    }
    void print()
    {
        Node *temp=front;
        while(temp!=NULL)
        {
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    int size()
    {
        if(front==NULL)
        {
            return 0;
        }
        int count=0;
        Node *temp=front;
        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        return count;
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.print();
    cout<<q.size()<<endl;
    cout<<q.dequeue();
    cout<<q.dequeue();
    cout<<q.dequeue();
    cout<<q.dequeue();
    cout<<q.dequeue();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout<<q.dequeue();
    cout<<q.dequeue();
    cout<<q.dequeue();
    cout<<q.dequeue();
    cout<<q.dequeue();

}
