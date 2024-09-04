class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() 
    {
        //Create 2 Stacks
        
    }
    
    void push(int x) 
    {
        if(s2.empty())
        {
            s2.push(x);
        }
        else
        {
            int temp;
            //Pop all the elements from s2 and push into s1
            while(!s2.empty())
            {
                temp=s2.top();
                s2.pop();
                s1.push(temp);

            }
            //Push the new element onto s2
            s2.push(x);
            //Pop all the elements from s1 and push into s2
            while(!s1.empty())
            {
                temp=s1.top();
                s1.pop();
                s2.push(temp);
            }
        }
    }
    
    int pop() 
    {
        int temp=s2.top();
        s2.pop();
        return temp;
    }
    
    int peek() 
    {
        return s2.top();
    }
    
    bool empty() 
    {
        return s2.empty();   
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */