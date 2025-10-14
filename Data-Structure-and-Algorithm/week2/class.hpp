#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int value;
    Node* next;
};

class LinkedList{
    private:
        Node *head, *tail, *current;
        int size;
    
    public:

        void _travers() {
            current = head;
            while(current->next) current = current->next;
        }

        int getSize() {return size;}

        LinkedList() {
            head = nullptr;
            size = 0;
        }

        void insertFront(int value){
            Node* newNode = new Node{value, nullptr};
            newNode->next = head;
            head = newNode;
            size++ ;
        }

        void insertBack(int value) {
            if(size == 0) {
                insertFront(value);
                return;
            }

            _travers();
            Node* newNode = new Node{value, nullptr};
            current->next = newNode;
            size++;
            tail = newNode;
            
        }

        void insertAt(int pos, int value){
            if(pos == 0) {
                insertFront(value);
                return;
            }

            if(pos >= size) {
                insertBack(value);
                return;
            }

            
        }

        void print(){
            current = head;
            while(current->next) {
                cout << current->value << "->";
                current = current->next;
            }

            cout << current->value << endl;
        }

};