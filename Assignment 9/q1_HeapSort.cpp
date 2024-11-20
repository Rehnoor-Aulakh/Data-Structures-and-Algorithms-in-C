#include<iostream>
using namespace std;

class Heap
{
    private:
    int *arr;
    int capacity;
    int count;
    int parent(int i)
    {
        if(i<=0 || i>=count)
        {
            return -1;
        }
        return (i-1)/2;
    }
    int leftChild(int i)
    {
        int left=2*i+1;
        if(left<=0 || left>=count)
        {
            return -1;
        }
        return left;
    }
    int rightChild(int i)
    {
        int right=2*i+2;
        if(right<=0||right>=count)
        {
            return -1;
        }
        return right;
    }
    void resizeHeap()
    {
        capacity=capacity*2;
        int *newArray=new int[capacity];
        for(int i=0;i<count;i++)
        {
            newArray[i]=arr[i];
        }
        delete[] arr;
        arr=newArray;
    }
    public:
    Heap(int capacity=10)
    {
        this->capacity=capacity;
        count=0;
        arr=new int[capacity];
    }
    int size()
    {
        return count;
    }
    int isEmpty()
    {
        return (count==0);
    }
    int getMax()
    {
        if(count==0)
        {
            return -1;
        }
        return arr[0];
    }
    void percolateDown(int i)
    {
        //find the left child and the right child
        int left=leftChild(i);
        int right=rightChild(i);
        int max;
        //now swap the ith element with whichever's greater
        if(left!=-1 && arr[left]>arr[i])
        {
            max=left;
        }
        else
        {
            max=i;
        }
        if(right!=-1 && arr[right]>arr[max])
        {
            max=right;
        }
        if(max!=i)
        {
            int t=arr[max];
            arr[max]=arr[i];
            arr[i]=t;
            percolateDown(max);
        }
        
    }

    int deleteMax()
    {
        int data=arr[0];
        arr[0]=arr[count-1];
        count--;
        percolateDown(0);
        return data;
    }

    void insert(int data)
    {
        int i;
        if(count==capacity)
        {
            resizeHeap();
        }
        arr[count]=data;
        i=count;
        count++;
        int par=parent(i);
        int t;
        //compare the ith element with its parent, if its greater, then swap
        while(i!=0 && arr[i]>arr[par])
        {
            t=arr[i];
            arr[i]=arr[par];
            arr[par]=t;
            i=par;
            par=parent(i);
        }
    }
    void printHeap()
    {
        if(count==-1)
        {
            cout<<"Heap is Empty!!!"<<endl;
        }
        else
        {
            cout<<endl;
            for(int i=0;i<count;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
};

int* heapSort(Heap h)
{
    //Given is a heap, now we will delete the maximum elements until heap is empty and store it in an array
    int size=h.size();
    int *sorted=new int[size];
    int i=0;
    while(!h.isEmpty())
    {
        sorted[i]=h.deleteMax();
        i++;
    }
    return sorted;
}

int main()
{
    Heap h(20);
    h.insert(10);
    h.insert(3);
    h.insert(8);
    h.insert(7);
    h.insert(19);
    h.insert(16);
    h.insert(1);
    h.insert(12);
    h.insert(31);
    h.printHeap();
    int size=h.size();
    int *arr=heapSort(h);
    cout<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
