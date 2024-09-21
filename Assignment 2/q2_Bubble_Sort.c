#include<iostream>
using namespace std;

int main()
{
    int a[]={10,8,2,7,9,6,1};
    int size=sizeof(a)/sizeof(int);
    int i,j;
    //Printing Initial Array
    for(i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    //First Loop will be of passes and runs size-1 times
    for(i=0;i<size-1;i++)
    {
        //Nested Loop for comparing j with j+1 element and if j+1 is smaller, swap it with j
        for(j=0;j<size-1-i;j++)
        {
            if(a[j+1]<a[j])
            {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    for(i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
