#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int s1 = mid - left;
    int s2 = right - mid + 1;

    int larr[s1];
    int rarr[s2];
    for (int i = 0; i < s1; i++)
    {
        larr[i] = arr[left + i];
    }
    for (int i = 0; i < s2; i++)
    {
        rarr[i] = arr[mid + i];
    }
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < s1 && j < s2)
    {
        if (larr[i] < rarr[j])
        {
            arr[k] = larr[i];
            i++;
        }
        else
        {
            arr[k] = rarr[j];
            j++;
        }
        k++;
    }
    while (i < s1)
    {
        arr[k] = larr[i];
        i++;
        k++;
    }
    while (j < s2)
    {
        arr[k] = rarr[j];
        j++;
        k++;
    }
}
void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid - 1);
        merge_sort(arr, mid, right);
        merge(arr, left, mid, right);
    }
}
void printArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "Enter size of array";
    int size;
    cin >> size;

    int array[size];
    for (int ind = 0; ind < size; ind++)
    {
        cout << "Enter array element at index " << ind;
        cin >> array[ind];
    }
    cout << "Before" << endl;
    printArray(array, size);
    merge_sort(array, 0, size - 1);
    cout << "After" << endl;
    printArray(array, size);
    return 0;
}