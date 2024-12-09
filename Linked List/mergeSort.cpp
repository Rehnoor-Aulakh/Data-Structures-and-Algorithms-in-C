#include <iostream>
using namespace std;

void merge(int orig[], int left, int right)
{
    int mid=(left+right)/2;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *leftArr = new int[n1];
    int *rightArr = new int[n2];

    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = orig[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        rightArr[j] = orig[mid + 1 + j];
    }

    //sorting while merging
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            orig[k] = leftArr[i];
            i++;
        }
        else
        {
            orig[k] = rightArr[j];
            j++;
        }
        k++;
    }
    //for the remaining elements of i(if any)
    while (i < n1)
    {
        orig[k] = leftArr[i];
        i++;
        k++;
    }
    //for the remaining elements of j(if any)
    while (j < n2)
    {
        orig[k] = rightArr[j];
        j++;
        k++;
    }

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(int orig[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right)/ 2;

        mergeSort(orig, left, mid);
        mergeSort(orig, mid + 1, right);

        merge(orig, left, right);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {40, 20, 50, 30, 80, 10, 70, 90};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}