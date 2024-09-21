#include<iostream>
using namespace std;

int main()
{
    int a[]={10,8,2,7,9,6,1};
    int size=sizeof(a)/sizeof(int);
    int i,j,pos;
    for(i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int small;
    for(i=0;i<size;i++)
    {
        small=a[i];
        pos=i;
        //find the smallest element from i to size-1 and place it at the ith position
        for(j=i+1;j<size;j++)
        {
            if(a[j]<small)
            {
                small=a[j];
                pos=j;
            }
        }
        //After finding the smallest element, swap a[pos] with a[i]
        int t=a[i];
        a[i]=a[pos];
        a[pos]=t;
    }
    for(i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}