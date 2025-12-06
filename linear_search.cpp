#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int> &arr, int ele)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == ele)
        {
            return true;
        }
    }
    return false;
}

void inputArr(vector<int> &arr)
{
    cout << "enter array elements: " << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

int main()
{
    int n, ele;
    cout << "enter size of arr: ";
    cin >> n;
    vector<int> arr(n);
    inputArr(arr);
    cout << "element to be found: ";
    cin >> ele;
    bool ans = linearSearch(arr, ele);
    cout << ans;
    return 0;
}