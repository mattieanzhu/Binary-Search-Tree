#ifndef BST_hpp
#define BST_hpp

#include <iostream>

template <typename Type>
struct Node {
    Type data;
    Node* left;
    Node* right;
    int height;
    Node();
    ~Node();
};

template <typename Type>
class BST {
private:
    Node<Type> *root;
public:
    BST();
    ~BST();
    int sizeCount(Node<Type>* root);
    void printHelp(Node<Type>* root);
    int maxHeight(Node<Type>* root);
    int Height();
    int Size();
    void Print();
    virtual bool Insert(const Type& d);
    virtual bool Remove(const Type& r);
    void destroy(Node<Type> *d);
    BST& operator=(const Type & T);
};







#include "BST.cpp"


#endif