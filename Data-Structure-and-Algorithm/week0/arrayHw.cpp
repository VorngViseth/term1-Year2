#include <iostream>

using namespace std;

void insertElement(int * arr, int &size, int max, int index, int num) {

    if(index > max || size > max || index < 0) {
        cout << "error!" << endl;
        return;    
    }

    // move elements to the right
    for(int i = size; i > index; i--) {
        arr[i] = arr[i-1];
    }

    // make sure that the insert element in the last
    index = (index > size) ? size : index;
    arr[index] = num;
    size++ ;

}

void deleteElement(int * arr, int &size, int max, int index) {

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

int main() {

    int max = 10;
    int arr[max] = {1, 2, 3};
    int size = 3;

    insertElement(arr, size, max, 0, 12);
    // deleteElement(arr, size, max, 1);

    for(int i = 0; i < size; i++){
        cout << "value " << i << " : " << arr[i] << endl ;
    }

    return 0;
}