#include <iostream>
#include "sorting_array.hpp"

using namespace std;

int main(){
    // testing your implementation
    int size;
    cout << "Enter the size of your array : " << endl;
    cin >> size ;

    int arr[size] = {};

    cout << "enter your array : " << endl;

    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    sorting_array(arr, size);

    cout << "after sort : " ;
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    return 0;
}