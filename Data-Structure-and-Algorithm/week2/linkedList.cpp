#include <iostream>
#include <chrono>

using namespace std;
using clk = chrono::high_resolution_clock;
volatile int sink_int = 0;

struct Node
{
    int value;
    Node* next;
};


int main() {

    Node* head;
    Node* tail;
    Node* current;

    Node Viseth;
    Viseth.value = 10;

    Node Omra;
    Omra.value = 12;
    Omra.next = nullptr;

    Viseth.next = &Omra;

    head = &Viseth;
    tail = &Omra;

    auto t0 = clk::now();
    // insert at the end (reach is the tail now not omra)
    Node Reach;
    Reach.value = 13;
    Reach.next = nullptr;

    tail = &Reach;
    Omra.next = &Reach;

    auto t1 = clk::now();
    cout << chrono::duration_cast<chrono::nanoseconds>(t1 - t0).count() << "\n";

    current = head;
    while(current != nullptr) {
        cout<< current->value << endl;
        current = current->next;
    }

    return 0;
}