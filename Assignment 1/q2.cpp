#include<iostream>
using namespace std;

int main()
{
    int n=7;
    int a[]={10,20,10,30,40,20,10};
    int *b=new int[n];
    int pos=0;
    bool isDistinct;

    for(int i=0;i<n;i++)
    {
        isDistinct=true;    //Assuming the current element is distinct

        //check if the current element has appeared before
        for(int j=0;j<i;j++)
        {
            if(a[i]==a[j])
            {
                isDistinct=false;
                break;
            }
        }
        if(isDistinct)
        {
            b[pos]=a[i];
            pos++;
        }
    }
    for(int i=0;i<pos;i++)
    {
        cout<<b[i]<<" ";
    }
}