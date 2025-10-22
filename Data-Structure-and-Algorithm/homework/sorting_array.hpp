#ifndef SORTING_ARRAY
#define SORTING_ARRAY

using namespace std;

void sorting_array(int arr[], int size){
    // your code here for sorting the array

    // BUBBLE SORT
    // sort even and odd number, sort the even number at the left side of the array
    int temp;
    int i;
    int lap;
    bool swap = false;

    for(lap = 0; lap < size - 1; lap++) {
        for(i = 0; i < size - 1 - lap; i++) {
            if(arr[i] > arr[i+1]) {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swap = true;
            }

            if(!swap) return;
            
        }
    }
    
}

#endif // SORTING_ARRAY