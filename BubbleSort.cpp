#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr)
{
    bool swapped = false;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swapped = true;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}

void input_arr(vector<int> &arr)
{
    cout << "enter array elements: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

void print_arr(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << " ";
}

int main()
{
    int n;
    cout << "enter size of array: ";

    cin >> n;
    vector<int> arr(n);

    input_arr(arr);
    bubbleSort(arr);
    print_arr(arr);
    return 0;
}