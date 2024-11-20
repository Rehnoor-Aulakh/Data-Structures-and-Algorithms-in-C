#include<iostream>
using namespace std;

int partition(int a[], int L, int U)
{
    int pivot=a[U];
    int i=L-1;
    int t;
    for(int j=L;j<U;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            //swap a[i] with a[j]
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    //swap pivot with the (i+1)th element
    t=a[i+1];
    a[i+1]=a[U];
    a[U]=t;
    return i+1;
}

void quickSort(int a[],int L, int U)
{
    if(L<U)
    {
        int pos=partition(a,L,U);

        quickSort(a,L,pos-1);
        quickSort(a,pos+1,U);
    }
}



void printArr(int a[], int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int a[]={9,6,4,3,10,8,7,2,1,5};
    cout<<"---------Initially----------"<<endl;
    int size=10;
    printArr(a,size);
    quickSort(a,0,size-1);
    cout<<"---------After Sorting----------"<<endl;
    printArr(a,size);
}