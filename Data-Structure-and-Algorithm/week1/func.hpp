#include <iostream>

using namespace std;

void expand(int *&arr, int &size, int &max) {
    int * tempArr = new int[max*2];
    max *= 2;

    for(int i = 0; i < size; i++){
        tempArr[i] = arr[i];
    }

    delete[] arr;
    arr = tempArr;
}

void insertElement(int *&arr, int &size, int &capacity, int index, int num) {

    if (index < 0 || index > size) {
        cout << "Error: Invalid index " << index << endl;
        return;
    }
    
    if (size == capacity) {
        expand(arr, size, capacity);
    }
    
    // Shift elements to the right
    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[index] = num;
    size++;
}

void deleteElement(int * arr, int &size, int max, int index) {
    
    // cout << "Enter the index (1-10) : " ;
    // cin >> index ;

    if(index >= size || index > max || index < 0) {
        cout << "error!" << endl;
        return;    
    }

    // move elements to the left
    for(int i = index; i < size; i++) {
        arr[i] = arr[i + 1];
    }

    size-- ;

}

void fongAndMo(string eyKorBan) {
    cout << eyKorBan << " " << "UNC" << endl;
}

