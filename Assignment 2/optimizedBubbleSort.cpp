//Optimized Bubble Sort
//Best Case Time Complexity: O(N)
//Worst Case Time Complexity: O(N^2)

#include<iostream>
using namespace std;

void bubbleSort(int *arr,int size)
{
    int i,j;
    int count=0;
    for(i=1;i<=size-1;i++)
    {
        bool flag=true;
        //this loop is for the passes
        for(j=0;j<=size-i-1;j++)
        {
            //compare arr[j] with arr[j+1], swap if arr[j+1] is smaller
            if(arr[j]>arr[j+1])
            {
                flag=false;
                //Whenever there is any swapping, turn flag false
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
                
            }
            count++;
        }
        if(flag==true)
        {
            //If the j loop has ended without any swapping, it means that the array is now sorted
            //No need to run the left over i iterations, break the loop and return the answer.
            break;
        }
    }
    cout<<"Number of times inner loops ran= "<<count<<endl;
}

int main()
{
    int arr[]={5,1,4,3,2};
    //It will be sorted after first pass, so inner loop runs 10 times and outer loop runs 2 times
    int size=sizeof(arr)/sizeof(int);
    bubbleSort(arr,size);
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}