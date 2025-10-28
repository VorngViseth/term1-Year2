#ifndef MEMBER_HPP
#define MEMBER_HPP

#include <iostream>
#include "BookNode.hpp"
#include <string>

using namespace std;

class Member{
private:
    string name;
    BookNode* firstBook;

public:
    Member(string name){
        this->name = name;
        firstBook = nullptr;
    }
    ~Member(){
        BookNode* current = firstBook;
        while(current){
            BookNode* next = current->next;
            delete current;
            current = next;
        }
    }
    
    BookNode* getFirstBook(){
        return firstBook;
    }

    void borrowBook(string title, string borrowDate){
        // your code here
        BookNode* newBook = new BookNode(title, borrowDate);

        if(firstBook == nullptr) {
            firstBook = newBook;
            return;
        }
        
        BookNode* temp = firstBook;
        while(temp->next != nullptr){
            temp = temp->next;
        }

        temp->next = newBook;
    }

    void returnBook(string title){
        // your code here
        if(firstBook == nullptr) {
            cout<<"the borrowed list is empty" << endl;
            return;
        }

        if(firstBook->title == title) {
            BookNode* toDelete = firstBook;
            firstBook = firstBook->next;
            delete toDelete;
            cout<< "Returned : " << title << endl;
            return; 
        }

        BookNode* temp = firstBook;
        while(temp->next != nullptr && temp->next->title != title) {
            temp = temp->next;
        }

        if(temp->next == nullptr) {
            cout<<"Book not found" << endl;
            return;
        }

        BookNode* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        cout<< "Returned : " << title << endl;   

    }

    void displayBorrowInfo(){
        BookNode* temp = firstBook;
        while (temp){
            cout<<"- ";
            cout<< temp->title <<" Borrow on: "<< temp->borrowDate << endl;
            temp = temp->next;
        }
    }

    string getName(){
        return this->name;
    }
};

#endif