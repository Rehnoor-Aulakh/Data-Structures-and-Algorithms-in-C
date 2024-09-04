#include<iostream>
using namespace std;

int main()
{
    int n=7;
    int i,j,t;
    int a[]={64,34,25,12,22,11,90};
    int a[n];
    for(i=0;i<=n-1;i++)
    {
        cout<<"Enter "<<i+1<<" Number";
        cin>>a[i];
    }
    for(i=0;i<=n-2;i++)
    {
        for(j=0;j<=(n-2)-i;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    
    for(i=0;i<=n-1;i++)
    {
        cout<<a[i]<<" ";
    }
}
