#include <iostream>
#include <string>
#include "class.hpp"

using namespace std;

int main() {

    LinkedList list;

    list.insertFront(19);
    list.insertFront(19);
    list.insertFront(19);
    list.insertFront(19);
    list.insertBack(12);

    list.print();
    cout << "the size of list is : " << list.getSize() << endl;

    return 0;
}