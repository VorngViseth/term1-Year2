// #include <iostream>
// #include <vector>
// using namespace std;

// // int sum(int *a, int *b){
// //     int c = *a + *b;
// //     return c;
// // }

// void input(int * p_arr, int pos, int val, int &n, int size = 10){
//     p_arr[pos] = val;
//     n = (pos < n)? n : n+1;
// }

// int main() {

//     int a[10] = {1,2};
//     int n  =2;

//     input(a, 2, 10, n);


//     // int num = 5;
//     // int num2 = 10;

//     // int sum = num + num2;

//     // cout << sum << endl;

//     // vector <int> vecNum = {1,2,3,4,5};
//     // cout << vecNum.at(4) << endl;

//     // vecNum.pop_back();
//     // vecNum.push_back(6);
    

//     // for(int i: vecNum) {
//     //     cout<<i<<endl;
//     // }

//     // cout << "Size of bool is : " << sizeof(bool) << endl;
//     // cout << "Size of Char is : " << sizeof(char) << endl;
//     // cout << "Size of Float is : " << sizeof(float) << endl;
//     // cout << "Size of Int is : " << sizeof(int) << endl;

//     // int a = 5, b = 10;

//     // int c = sum(&a, &b);

//     // cout << "Value is : " << c << endl;

//     return 0;
// }   


// #include <iostream>

// using namespace std;

// void input(int * p_arr, int pos, int val, int &n, int size = 10){
    
//     if(pos >= size || pos > n){
//         cout<<"Error!"<<endl;
//         return;
//     }

//     p_arr[pos] = val;  
//     n = (pos < n)? n: n+1;
// }

// int main(){

//     int a[10] = {1,2};
//     int n = 2; // amount of number in the array

//     // input(a, 2, 10, n);
//     input(a, 3, 15, n);
//     input(a, 1, 25, n);
//     input(a, 4, 6, n);
    
    
//     for(int i = 0; i < n; i++){
//         cout<<"Value "<<i<<": "<<a[i]<<endl;
//     }
    

//     return 0;
// }

#include <iostream>

using namespace std;

void insert(int * arr, int &size, int index, int num, int max) {

    if(index > max) {
        cout << "error!" << endl;
        return;    
    }

    arr[index] = num;
    size = (index < size) ? size :  index + 1;

}

int main() {

    int max = 10;
    int arr[max] = {1, 2};
    int size = 2;
    int index, num;

    cout << "Enter the insert number : " ;
    cin >> num ;

    cout << "Enter the index (1-10) : " ;
    cin >> index ;

    insert(arr, size, index, num, max);

    for(int i = 0; i < size; i++){
        cout << "value " << i << " : " << arr[i] << endl ;
    }

    return 0;
}