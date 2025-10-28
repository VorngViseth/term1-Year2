#ifndef BOOKNODE_HPP // to prevent error when include multiple time
#define BOOKNODE_HPP

#include <string>

using namespace std;

class BookNode{
public:
    string title;
    string borrowDate;
    BookNode* next;

    // Constructor
    BookNode(string title, string borrowDate){
        // your code here
        this->title = title;
        this->borrowDate = borrowDate;
        this->next = nullptr;
    }
};

#endif