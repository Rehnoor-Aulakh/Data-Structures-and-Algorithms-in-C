#include<stdio.h>
#include<string.h>

int palindrome(char str[])
{
    int i=0,j=strlen(str)-1;
    while(1)
    {
        if(i==j)
        {
            break;
        }
        if(str[i]==str[j])
        {
            i++;
            j--;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    printf("%d",palindrome("abbabbaXabbabba"));
}

