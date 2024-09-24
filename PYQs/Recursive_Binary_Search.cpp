#include<iostream>
using namespace std;

void search(int *A,int num,int low, int high, int i)
{
    if(low>high)
    {
        return;
    }
    int mid=(low+high)/2;
    if(A[mid]==num)
    {
        cout<<num<<" found at index "<<mid<<endl;
        cout<<"Answer found after "<<i<<" calls"<<endl;
    }
    else
    {
        if(num>A[mid])
        {
            low=mid+1;
        }
        else if(num<A[mid])
        {
            high=mid-1;
        }
        search(A,num,low,high,i+1);
    }
}

//Recursive Calls:
//First Call: low=0 and high=11 and mid=0+11/2 i.e 5
//A[5]=9, now num<a[mid], so high will be updated to mid-1 i.e. 4
//Second Call: low=0,high=4,mid=0+4/2 i.e. 2
//A[2]=6, now num>mid, so low will be updated to mid+1 i.e. 3
//Third Call: low=3, high=4, mid=3+4/2 i.e. 3
//A[3]=7, now num>mid, so low will be updated to mid+1 i.e. 4
//Fourth Call: low=4,high=4, mid=4 A[4]=8, here number is found and loop breaks
//Answer comes in fourth call


int main()
{
    int A[] = {2, 5, 6, 7, 8, 9, 10, 15, 16, 18, 19, 20};
    int size=sizeof(A)/sizeof(int);
    //Last argument indicates number of call
    search(A,8,0,size-1,1);
}
