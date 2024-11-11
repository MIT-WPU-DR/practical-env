#include <iostream>
#include <vector>
using namespace std;

    template <typename T>
    void bubbleSort(vector<T> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

int main()
{
    vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90};
    cout << "Original array 1: ";
    for (auto i : arr1)
    {
        cout << i << " ";
    }
    cout << endl;

    bubbleSort(arr1);
    cout << "Sorted array 1: ";
    for (auto i : arr1)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<float> arr2 = {10.1, 9.9, 1.0, 2.2, 3.3, 4.4, 5.5};
    cout << "Original array 2: ";
    for (auto i : arr2)
    {
        cout << i << " ";
    }
    cout << endl;

    bubbleSort(arr2);
    cout << "Sorted array 2: ";
    for (auto i : arr2)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}