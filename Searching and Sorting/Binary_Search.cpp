#include<iostream>
using namespace std;

int main()
{
    int a[]={5,12,15,43,56,72,89,100};
    //Condition for Binary Search is that Array Must be Sorted.
    int n;
    cout<<"Enter the element you want to find in the array: ";
    cin>>n;
    cout<<endl;
    int size=sizeof(a)/sizeof(int);
    int low=0,high=size-1;
    int mid;
    bool flag=false;
    while(low<=high)
    {
        mid=(low+high)/2;
        //Compare number to be searched to the middle element of array
        //If n is equal to a[mid], then number is found
        //If n is smaller than a[mid], search from low to mid-1
        //If n is larger than a[mid], search from mid+1 to high
        if(n==a[mid])
        {
            cout<<"Number found at "<<mid<<endl;
            flag=true;
            break;
        }
        else if(n<a[mid])
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    if(!flag)
    {
        cout<<"Number Not Found!!!"<<endl;
    }
}