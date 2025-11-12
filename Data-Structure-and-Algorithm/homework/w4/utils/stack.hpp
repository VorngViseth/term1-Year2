#include <iostream>
#include <stdexcept>

#ifndef STACK
#define STACK

using namespace std;

struct Node {
    float number;
    Node *next;
};

class Stack{
    // complete the Stack ADT here
private: 
    Node *top;
    float size;
public:
    Stack() {
        top = nullptr;
        size = 0;
    }

    float peek() {
        if(size == 0) {
            cout << "stack is empty" << endl;
            return 0;
        }

        return top->number;
    }

    void push(float number) {
        Node *newNode = new Node{number, top};
        top = newNode;
        size++ ;
    }

    float pop() {
        if(size == 0) {
            cout << "the stack is empty" << endl;
            return 0;
        }

        Node *temp = top;
        float val = top->number;
        top = top->next;
        size-- ;
        delete temp;
        return val;
    }

    void print() {
        Node *current = top;
        while(current !=  nullptr) {
            cout << current->number;
            if(current->next != nullptr) cout << " -> " ;
            current = current->next;
        }

        cout<<endl;
    }

    bool isEmpty() {return size==0;}

};

#endif