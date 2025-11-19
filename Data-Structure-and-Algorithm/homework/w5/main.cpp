#include "Solution.hpp"

using namespace std;
namespace fs = std::filesystem;

int main(){
    // test your solution here...
    fs::path path1 = "noting";
    fs::path path2 = "seth";
    fs::path path3 = "omra";
    fs::path path4 = "david";

    cout << path1 << isFolderValid(path1) << endl;
    cout << path2 << isFolderValid(path2) << endl;
    cout << path3 << isFolderValid(path3) << endl;
    cout << path4 << isFolderValid(path4) << endl;
    return 0;
}