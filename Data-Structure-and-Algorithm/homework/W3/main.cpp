#include "utils/Exercise.hpp"
#include <string>

using namespace std;

int main(){
    Solution solution;
    // test your solution here ...
    string sentence = " i have 10 black dog and 5 cats";
    cout<<solution.areNumAscending(sentence)<<endl;

    return 0;
}