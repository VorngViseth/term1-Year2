#include <iostream>

using namespace std;

struct Node {
    /* data */
    int data;
    Node *left, *right;
};

class BinaryTree {
private:
    /* data */
    int size;
    Node *root;

    // healper func for recursion
    Node *insertRec(Node *node, int data) {
        if(node == nullptr) {
            size++ ;
            return new Node{data, nullptr, nullptr};
        }

        if(data < node->data) node->left = insertRec(node->left, data);
        else if(data > node->data) node->right = insertRec(node->right, data);

        if(data == node->data) {
            cout<<"we already have this data (" << data << "), keep the tree unique"<< endl;
        }

        return node;
    }

    Node *findMin(Node *node) {
        while(node && node->left) node = node->left;
        return node;
    }

    Node *deleteRec(Node *node, int data) {                                                     
        if(node == nullptr) {
            cout<< "data not found" << endl;
            return node;
        }

        if(data < node->data) node->left = deleteRec(node->left, data);
        else if(data > node->data) node->right = deleteRec(node->right, data);
        else {
            if(node->left == nullptr) {
                Node *temp = node->right;
                size-- ;
                delete node;
                return temp;
            }else if (node->right == nullptr) {
                Node *temp = node->left;
                size-- ;
                delete node;
                return temp;
            }

            Node *successor = findMin(node->right);
            node->data = successor->data;
            node->right = deleteRec(node->right, successor->data);
        }

        return node;
    }

    void inOrderRec(Node *node) {
        if(node == nullptr) return;
        inOrderRec(node->left);
        cout<< node->data << " ";
        inOrderRec(node->right);
    }

    void preOrderRec(Node *node) {
        if(node == nullptr) return;
        cout<< node->data << " ";
        preOrderRec(node->left);
        preOrderRec(node->right);
    }

    void postOrderRec(Node *node) {
        if(node == nullptr) return;
        postOrderRec(node->left);
        postOrderRec(node->right);
        cout<< node->data << " ";
    }


public:
    BinaryTree() {
        root = nullptr;
        size = 0;
    }

    int getSize() {return size;}
    int getRoot() {return root->data;}

    void insert(int data) {
        root = insertRec(root, data);   
    }

    void deleteNode(int data) {
        root = deleteRec(root, data);
    }

    void inOrder() {
        inOrderRec(root);
        cout << endl;
    }

    void preOrder() {
        preOrderRec(root);
        cout << endl;
    }

    void postOrder() {
        postOrderRec(root);
        cout << endl;
    }

};