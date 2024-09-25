// https://www.geeksforgeeks.org/interesting-method-generate-binary-numbers-1-n/
#include<iostream>
#include<queue>
#include<string>
using namespace std;

void generateBinaryNumber(int n)
{
    queue<string> q;
    q.push("1");
    while(n--)
    {
        string s1=q.front();
        q.pop();
        cout<<s1<<endl;
        string s2=s1;
        s1.append("0");
        q.push(s1);
        s2.append("1");
        q.push(s2);
    }
}
int main()
{
    int n=100;
    generateBinaryNumber(n);
}