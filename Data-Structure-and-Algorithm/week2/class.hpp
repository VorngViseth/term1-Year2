#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int value;
    Node *next;
};

class LinkedList
{
private:
    Node *head, *tail, *current;
    int size;

public:
    LinkedList()
    {
        head = nullptr;
        size = 0;
    }

    int getSize() { return size; }

    int getTail() { return tail->value; }

    int getHead() { return head->value; }

    void _travers()
    {
        current = head;
        while (current->next)
            current = current->next;
    }

    void _traverseTill(int pos)
    {
        current = head;
        for (int i = 0; i < pos - 1; i++)
        {
            current = current->next;
        }
    }

    void insertFront(int value)
    {
        Node *newNode = new Node{value, nullptr};
        newNode->next = head;
        head = newNode;
        if (size == 0)
            tail = newNode;
        size++;
    }

    void insertBack(int value)
    {
        if (size == 0)
        {
            insertFront(value);
            return;
        }

        Node *newNode = new Node{value, nullptr};
        tail->next = newNode;
        size++;
        tail = newNode;
    }

    void insertAt(int pos, int value)
    {
        if (pos == 0)
        {
            insertFront(value);
            return;
        }

        if (pos >= size)
        {
            insertBack(value);
            return;
        }

        Node *newNode = new Node{value, nullptr};
        Node *temp;
        _traverseTill(pos);
        temp = current->next;
        current->next = newNode;
        newNode->next = temp;
        size++;
    }

    void insertMiddle(int value)
    {
        _traverseTill(size / 2);
        Node *newNode = new Node{value, nullptr};
        Node *temp;
        temp = current->next;
        current->next = newNode;
        newNode->next = temp;
        size++;
    }

    void deleteFront()
    {
        if (head == nullptr)
        {
            cout << "the list is empty!" << endl;
            return;
        }

        Node *temp;
        temp = head;
        head = head->next;
        delete temp;
        size--;
        if (head == nullptr)
            tail = nullptr;
    }

    void deleteEnd()
    {
        if (head == 0)
        {
            cout << "The list is empty" << endl;
            return;
        }

        Node *temp;
        temp = tail;
        _traverseTill(size);
        tail = current;
        delete temp;
    }

    void deleteMiddle()
    {
        if (head == nullptr)
        {
            cout << "the list is empty" << endl;
            return;
        }

        if (size == 1)
        {
            deleteFront();
            return;
        }

        Node *temp;
        _traverseTill(size / 2);
        temp = current->next;
        current->next = temp->next;
        if (temp == tail)
            tail = current;
        delete temp;
        size--;
    }

    void print()
    {
        current = head;
        while (current->next)
        {
            cout << current->value << "->";
            current = current->next;
        }

        cout << current->value << endl;
    }

    void swapTwoNodes(int posFisrtNode, int posSecNode)
    {
        if (head == nullptr || size == 1)
        {
            cout << "The list is empty/not enough" << endl;
            return;
        }

        if (posFisrtNode < 0 || posSecNode >= size)
        {
            cout << "Error" << endl;
            return;
        }

        Node *prevFrist;
        Node *firstNode;
        _traverseTill(posFisrtNode);
        prevFrist = current;
        firstNode = current->next;

        Node *prevSec;
        Node *secNode;
        _traverseTill(posSecNode);
        prevSec = current;
        secNode = current->next;

        // if(prevFrist    )

    }
};