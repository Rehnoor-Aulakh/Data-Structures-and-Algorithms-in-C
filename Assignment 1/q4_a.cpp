#include<iostream>
using namespace std;

int main()
{
    int a[]={10,20,30,40,50,60,70,80,90,100};

    int size=sizeof(a)/sizeof(int);
    int t;
    for(int i=0;i<size/2;i++)
    {
        //swap a[i] with a[size-1-i]
        t=a[i];
        a[i]=a[size-1-i];
        a[size-1-i]=t;
    }
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
}