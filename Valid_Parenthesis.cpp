#include <stack>
class Solution {
public:
    bool matchSymbol(char a, char b)
    {
        if(a=='(' && b==')')
        {
            return true;
        }
        else if(a=='[' && b==']')
        {
            return true;
        }
        else if(a=='{' && b=='}')
        {
            return true;
        }
        return false;
    }
    bool isValid(string s) 
    {
        stack<char> st;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                st.push(s[i]);
            }
            else if(s[i]==')' || s[i]==']' || s[i]=='}')
            {
                if(st.empty())
                {
                    //then only closing brackets are there, so parentheses is invalid
                    return false;
                }
                if(matchSymbol(st.top(),s[i]))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            
        }
        if(st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};