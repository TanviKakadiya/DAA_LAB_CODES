#include<iostream>
using namespace std;

int main(){
    cout << "Enter size of array: ";
    int size;
    cin >> size;

    int array[size];
    for(int ind = 0; ind < size; ind++) {
        cout << "Enter array element at index " << ind << ": ";
        cin >> array[ind];
    }

    for(int j=1;j<size;j++){
        int key=array[j];
        int i=j-1;

        while(i>-1 && array[i]>key){
            array[i+1]=array[i];
            i--;
        }
        array[i+1]=key;
    }

    
    cout << "Sorted array: ";
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
