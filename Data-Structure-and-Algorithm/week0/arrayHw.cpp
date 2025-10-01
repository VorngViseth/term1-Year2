#include <iostream>

using namespace std;

void insertElement(int * arr, int &size, int index, int num, int max) {

    if(index > max) {
        cout << "error!" << endl;
        return;    
    }

    size++ ;

    if(arr[index] != 0) {


        cout << "slow" << endl;
        int secArr[max];

        for(int i = 0; i < index; i++) {
            secArr[i] = arr[i];
        }

        secArr[index] = num;

        for(int i = index; i < size; i++) {
            secArr[i + 1] = arr[i];
        }

        for(int i = 0; i < size; i++) {
            arr[i] = secArr[i];
        }

    } else {

        cout << "fast" << endl;
        arr[size-1] = num;

    }

}

void deleteElement(int * arr, int &size, int index, int max) {
    
    if(index > max || index > size) {
        cout << "error!" << endl;
        return;    
    }

    int secArr[max];

    int j = 0;

    for(int i = 0; i < size; i++) {
        if(i != index) {
            secArr[j] = arr[i];
            j++ ;
        }
    }

    size-- ;

    for(int i = 0; i < size; i++){
        arr[i] = secArr[i];
    }

}

int main() {

    int max = 10;
    int arr[max] = {1, 2, 3};
    int size = 3;
    int index, num;

    cout << "Enter the insert number : " ;
    cin >> num ;

    cout << "Enter the index (1-10) : " ;
    cin >> index ;

    // insertElement(arr, size, index, num, max);
    deleteElement(arr, size, index, max);

    for(int i = 0; i < size; i++){
        cout << "value " << i << " : " << arr[i] << endl ;
    }

    return 0;
}