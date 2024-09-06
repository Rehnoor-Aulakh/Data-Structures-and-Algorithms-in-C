#include<iostream>
#include<limits.h>
using namespace std;

int main()
{
    int a[5][4]={
        {55,92,74,91},
        {201,104,511,911},
        {1444,1883,1193,1200},
        {591,1003,54,512},
        {244,311,999,1024}
    };
    int i=0,j=0;
    for(i=0;i<5;i++)
    {
        int min=INT_MAX;
        //find the smallest element in a[i] array
        for(j=0;j<4;j++)
        {
            if(a[i][j]<min)
            {
                min=a[i][j];
            }
        }
        //now min is the smallest element of ith row, check in its column if it is the largest
        for(j=0;j<5;j++)
        {
            if(a[j][i]>min)
            {
                break;
            }
        }
        if(j==5)
        {
            cout<<min;
        }
    }

}
