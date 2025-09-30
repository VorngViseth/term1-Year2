#include <iostream>
#include <vector>
using namespace std;

int main() {

    // int num = 5;
    // int num2 = 10;

    // int sum = num + num2;

    // cout << sum << endl;

    vector <int> vecNum = {1,2,3,4,5};
    cout << vecNum.at(4) << endl;

    vecNum.pop_back();
    vecNum.push_back(6);
    

    for(int i: vecNum) {
        cout<<i<<endl;
    }

    return 0;
}   