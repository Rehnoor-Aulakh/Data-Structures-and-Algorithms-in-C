class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
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
            int temp;
            //pop all the elements from q1 and push into q2
            while(!q1.empty())
            {
                temp=q1.front();
                q1.pop();
                q2.push(temp);
            }
            //Then insert the new element in q1
            q1.push(x);
            //Pop all the elements from q2 and insert into q1
            while(!q2.empty())
            {
                temp=q2.front();
                q2.pop();
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