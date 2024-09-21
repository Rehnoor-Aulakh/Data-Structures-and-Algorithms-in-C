#include<stdio.h>
int main()
{
    int a[10]={10,22,55,66,77,88,89,41,50,40};
    int i,n;
    printf("Enter the number you wish to find in the array:");
    scanf("%d",&n);
    for(i=0;i<=9;i++)
    {
        if(a[i]==n)
        {
            break;
        }
    }
    if(i==10)
    {
        printf("Number Not Found");
    }
    else
    {
        printf("Number Found at index %d",i);
    }
    
}
