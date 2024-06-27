#include<iostream>
#include<vector>
#include<utility>
#include<stack>
using namespace std;

vector<int> next(vector<int> arr, int n)
{
    stack<pair<int,int> > st;
    st.push({-1,-1});
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        //i will traverse in the arr
        if (st.top().first < arr[i])
        {
            ans[i] = (st.top().second);
            st.push({arr[i],i});
        }
        else
        {
           while(st.top().first>=arr[i])
           {
               st.pop();
           }
           //At the end top element must be smaller than arr[i]
           ans[i]=st.top().second;
           st.push({arr[i],i});
        }
    }
    return ans;
}
vector<int> prev(vector<int> arr, int n)
{
    stack<pair<int,int> > st;
    st.push({-1,-1});
    vector<int> ans(n);
    for (int i=0;i<n;i++)
    {
        //i will traverse in the arr
        if (st.top().first < arr[i])
        {
            ans[i] = (st.top().second);
            st.push({arr[i],i});
        }
        else
        {
           while(st.top().first>=arr[i])
           {
               st.pop();
           }
           //At the end top element must be smaller than arr[i]
           ans[i]=st.top().second;
           st.push({arr[i],i});
        }
    }
    return ans;
}
int largestRectangleArea(vector<int>& heights)
{
    int size=heights.size();
    vector<int> n= next(heights,size);
    vector<int> p= prev(heights,size);
    int max=-1,area=1;
    for(int i=0;i<size;i++)
    {
        if(n[i]==-1)
        {
            n[i]=size;
        }
        area=heights[i]*(n[i]-p[i]-1);
        if(area>max)
        {
            max=area;
        }
    }
    return max;
    
}


int main()
{
    vector<int> heights;
    heights.push_back(2);
    heights.push_back(1);
    heights.push_back(5);
    heights.push_back(6);
    heights.push_back(2);
    heights.push_back(3);
    int size=heights.size();
    heights=next(heights,size());
    heights=prev(heights,size);
    for(int i=0;i<heights.size();i++)
    {
        cout<<heights[i]<<" ";
    }

}