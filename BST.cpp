#include "BST.hpp"
#include <iostream>  

template <typename Type>
Node<Type>::Node(){
    left = nullptr;
    right = nullptr;
}

template <typename Type>
Node<Type>::~Node(){
    delete left;
    delete right;
}

template <typename Type>
int BST<Type>::maxHeight(Node<Type> *root){
    if(root == nullptr){
        return 0;
    }
    else{
        int m = 1+std::max(maxHeight(root->left), maxHeight(root->right));
        return m;
    }
}

template <typename Type>
int BST<Type>::sizeCount(Node<Type> *root){
    if(root == nullptr){
        return 0;
    }
    else{
        int s = 1+sizeCount(root->left) + sizeCount(root->right);
        return s;
    }
}

template <typename Type>
Node<Type>* newNode(const Type& t){
    Node<Type>* newNode = new Node<Type>;
    newNode->data = t;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 1;
    return newNode;
}

template <typename Type>
void BST<Type>::printHelp(Node<Type>* root){
    if(root == nullptr){
        return;
    }
    else{
        printHelp(root->left);
        std::cout <<root->data <<' ';
        printHelp(root->right);
    }
}

template <typename Type>
Node<Type>* findMin(Node<Type>* n){
    while(n->left != nullptr){
        n=n->left;
    }
    return n;
}

template <typename Type>
BST<Type>::BST(){
    root = nullptr;
}

template <typename Type>
BST<Type>::~BST(){
    delete root;
}

template <typename Type>
int BST<Type>::Height(){
    return maxHeight(root);
}

template <typename Type>
int BST<Type>::Size(){
    return sizeCount(root);
}

template <typename Type>
void BST<Type>::Print(){
    printHelp(root);
}

template <typename Type>
bool BST<Type>::Insert(const Type& d){
    Node<Type>* current;
    Node<Type>* parent;
    if(root == nullptr){
        root = newNode(d);
        current = root;
        return true;
    }
    else{
        current = root;
        while(current != nullptr){
            if(d < current->data){
                parent = current;
                current = current -> left;
            }
            else if (d > current->data){
                parent = current;
                current = current -> right;
            }
            else{
                return false;
            }
        }
        if(d < parent->data){
            parent -> left = newNode(d);
            return true;
        }
        else if(d > parent->data){
            parent -> right = newNode(d);
        }
        return true;
    }
}

template <typename Type>
bool BST<Type>::Remove(const Type& r){
    Node<Type>* prev;
    Node<Type>* current;
    if (root == nullptr){
        return false;
    }
    else{
        current = root;
        while(current != nullptr && current->data != r){
            prev = current;
            if(r < current->data){
                current = current->left;
            }
            else{
                current = current->right;
            }
        }
        if(current->data == r){
            if(current->right == nullptr && current->left == nullptr){
                if(prev->left==current){
                    prev->left = nullptr;
                    free(current);
                    current = nullptr;
                    return true;
                }
                else{
                    prev->right = nullptr;
                    free(current);
                    current = nullptr;
                    return true;
                }
            }
            else if(current->left == nullptr && current->right != nullptr){
                if(prev->left==current){
                    prev->left = current->right;
                    free(current);
                    current = nullptr;
                    return true;
                }
                else{
                    prev->right = current->right;
                    free(current);
                    current = nullptr;
                    return true;
                }
            }
            else if(current->left != nullptr && current->right == nullptr){
                if(prev->left==current){
                    prev->left = current->left;
                    free(current);
                    current = nullptr;
                    return true;
                }
                else{
                    prev->right = current->left;
                    free(current);
                    current = nullptr;
                    return true;
                }
            }
            else{
                Node<Type>*temp = findMin(current->right);
                current->data=temp->data;
                current->right=temp->right;
                free(temp);
                return true;
            }
        }
        return false;
    }
}



template <typename Type>
void BST<Type>::destroy(Node<Type>* d){
    if(d != nullptr){
        destroy(d->left);
        destroy(d->right);
        delete d;
    }
}

template <typename Type>
BST<Type>&BST<Type>::operator=(const Type& T){
    if(this != &T){
        destroy(root);
        root(T);
    }
    return *this;
}



