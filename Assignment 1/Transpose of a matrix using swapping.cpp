//Write a program to find the transpose of a square matrix by using swaping

#include<iostream>
using namespace std;
int main()
{
    int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int i,j,t;
    cout<<"----Original---"<<endl;
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=i;j++)
        {
            t=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=t;
        }
    }
    cout<<"----After Transpose---"<<endl;
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    
}