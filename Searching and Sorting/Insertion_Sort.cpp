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
    //Main loop will run from 1 to the end of the array
    for(i=1;i<size;i++)
    {
        int temp=i;
        for(j=i-1;j>=0;j--)
        {
            //Check from the previous element of i, if it is smaller than jth element, start swapping it
            if(a[temp]<a[j])
            {
                //swap a[i] with a[j]
                int t=a[temp];
                a[temp]=a[j];
                a[j]=t;
                //After swapping once, decrement temp
                temp--;
            }
            else
            {
                break;
            }
        }
    }
    //Print the resultant array
    for(i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
