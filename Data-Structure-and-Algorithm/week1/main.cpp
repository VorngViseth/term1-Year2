#include <iostream>
#include <chrono>
#include "func.hpp"

using namespace std;
using clk = chrono::high_resolution_clock;
volatile int sink_int = 0;

int main(){
    const int MAX_CAP = 100000;
    int n = 1;

    int *arr = new int[n] {1};
    int size = 1;

    int pos = 0;

    auto t0 = clk::now();

    insertElement(arr, size, n, pos, 12);

    auto t1 = clk::now();
    cout << size << endl;
    cout << chrono::duration_cast<chrono::nanoseconds>(t1 - t0).count() << "\n";

    for(int i = 0; i < size; i++){
        cout << "value " << i << " : " << arr[i] << endl ;
    }

    delete[] arr;

    return 0;
}