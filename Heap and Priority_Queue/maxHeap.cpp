#include<iostream>
#include<queue>
using namespace std;

class Heap
{
    private:
    int *array;
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
        if(left>=count)
        {
            return -1;
        }
        return left;
    }
    int rightChild(int i)
    {
        int right=2*i+2;
        if(right>=count)
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
            newArray[i]=array[i];
        }
        delete[] array;
        array=newArray;
    }
    public:
    Heap(int capacity=10)
    {
        this->capacity=capacity;
        count=0;
        array=new int[capacity];
    }
    
    int getMax()
    {
        if(count==0)
        {
            return -1;
        }
        return array[0];
    }
    void percolateDown(int i)
    {
        int l,r,max,temp;
        l=leftChild(i);
        r=rightChild(i);
        if(l!=-1 && array[l]>array[i])
        {
            max=l;
        }
        else
        {
            max=i;
        }
        if(r!=-1 && array[r]>array[max])
        {
            max=r;
        }
        if(max!=i)
        {
            //swap array[i] with array[max]
            temp=array[i];
            array[i]=array[max];
            array[max]=temp;
            percolateDown(max);
        }
    }
    
    int deleteMax()
    {
        //copy the last element of array to the first element
        //decrement the size and then percolateDown
        if(count==0)
        {
            return -1;
        }
        int data=array[0];
        array[0]=array[count-1];
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
        count++;
        i=count-1;
        while(i>0 && data>array[(i-1)/2])
        {
            array[i]=array[(i-1)/2];
            i=(i-1)/2;
        }
        array[i]=data;
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
                cout<<array[i]<<" ";
            }
            cout<<endl;
        }
    }

};

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
    cout<<"Max element is "<<h.deleteMax()<<endl;
}



