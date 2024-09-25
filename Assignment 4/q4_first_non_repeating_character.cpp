#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

void findNonRepeating(char *a)
{
    queue<char> q;
    int arr[26] = {0};
    // Initialize an integer array of size 26 which is English alphabets size which will count the frequency
    int size = strlen(a);
    for (int i = 0; i < size; i++)
    {
        q.push(a[i]);
        // Enqueue every character into the queue
        arr[a[i] - 'a']++;
        // a[i] will be the current character of a string in its ASCII code and a[i]-'a' will give its value from 0 to 25 and we will increment its place in arr
        while (!q.empty())
        {
            if (arr[q.front() - 'a'] > 1)
            {
                q.pop();
            }
            else
            {
                cout << q.front() << " ";
                break;
            }
        }
        if (q.empty())
        {
            cout << -1<<" ";
        }
    }
    cout<<endl;
}

int main()
{
    char *a = "aabc";
    findNonRepeating(a);
}