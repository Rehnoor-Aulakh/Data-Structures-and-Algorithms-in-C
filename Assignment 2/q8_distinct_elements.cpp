#include<iostream>
using namespace std;

int main()
{
    int a[] = {10, 20, 10, 20, 40, 30, 30};
    int size = sizeof(a) / sizeof(int);
    int count = 0;
    bool isDistinct;

    for(int i = 0; i < size; i++)
    {
        isDistinct = true;  // Assume current element is distinct

        // Check if the current element has appeared before
        for(int j = 0; j < i; j++)
        {
            if(a[i] == a[j])
            {
                isDistinct = false;
                break;
            }
        }

        // If it's still distinct, increase the count
        if(isDistinct)
        {
            count++;
        }
    }

    cout << "Number of distinct elements are " << count << endl;

    return 0;
}
