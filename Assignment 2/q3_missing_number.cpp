#include<iostream>
using namespace std;

int findMissing(int *arr, int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=i+1)
        {
            return i+1;
        }

    }
    return -1;
    //If no missing element found
}
int main()
{
    int arr[]={1,2,3,4,6,7,8};
    int n=8;
    cout<<"Missing Number is "<<findMissing(arr,n)<<endl;
}