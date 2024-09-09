vector<int> Solution::prevSmaller(vector<int> &A) 
{
    int size=A.size();
    vector<int> ans;
    stack<int> st;
    for (int i = 0; i < size; i++) 
    {
        //if the element in the stack is larger than the current element, pop it from stack until smaller element is encountered
        while(!st.empty() && st.top()>=A[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            //if stack is empty, push -1 into the array
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(st.top());
        }
        st.push(A[i]);
    }

    return ans;

}