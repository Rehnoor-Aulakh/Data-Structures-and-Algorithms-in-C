class MyStack {
public:
    queue<int> q1;
    MyStack() 
    {
        //Create two queues
        
    }
    
    void push(int x) 
    {
        if(q1.empty())
        {
            q1.push(x);
        }
        else
        {
            q1.push(x);
            int size=q1.size();
            int temp;
            for(int i=0;i<size-1;i++)
            {
                temp=q1.front();
                q1.pop();
                q1.push(temp);
            }
        }
        
    }
    
    int pop() 
    {
        int x=q1.front();
        q1.pop();
        return x;
    }
    
    int top() 
    {
        return q1.front();
    }
    
    bool empty() 
    {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */