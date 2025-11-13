#include "binaryTree.hpp"
#include <iostream>

using namespace std;

int main() {

    BinaryTree tree;
    tree.insert(3);
    tree.insert(2);
    tree.insert(2);

    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.preOrder();
    tree.inOrder();
    tree.postOrder();
    cout << tree.getRoot() << endl;
    return 0;
}