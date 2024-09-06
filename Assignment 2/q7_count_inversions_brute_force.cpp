#include<iostream>
using namespace std;

int main()
{
    int a[]={7, 2, 6, 3};
    int size=sizeof(a)/sizeof(int);
    //count the number of inversions
    int i=0,j=1,t=1;
    int count=0;
    while(i!=size)
    {
        while(j!=size)
        {
            if(i==j)
            {
                j++;
            }
            else if(a[i]>a[j] && i<j)
            {
                count++;
                j++;
            }
            else
            {
                i++;
            }
        }
        j=t+1;
        t++;
        i++;
    }
    cout<<"Number of Inversions are "<<count;
    
}