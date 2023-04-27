#include "bst.h"
#include <iostream>
//#define CTOR_S
using namespace std;

//default constructor
template<typename T>
BSTree<T>::BSTree() {
#ifdef CTOR_S
    cout << "default constructor" << endl;
#endif
    root = nullptr;
}

//copy constructor
template<typename T>
BSTree<T>::BSTree(const BSTree& oth) {
#ifdef CTOR_S
    cout << "copy constructor" << endl;
#endif
    if (this != &oth) {
        root = clone(oth.root);
    }
}

//move constructor
template<typename T>
BSTree<T>::BSTree(BSTree&& rhs) {
#ifdef CTOR_S
    cout << "move constructor" << endl;
#endif
    if (this != &rhs) {
        root = rhs.root;
        rhs.root = nullptr;
    }
}

//copy assignment operator
template<typename T>
BSTree<T>& BSTree<T>::operator=(const BSTree& oth) {
#ifdef CTOR_S
    cout << "copy assignment operator" << endl;
#endif
    if (this != &oth) {
        root = clone(oth.root);
    }
    return *this;
}

//move assignment operator
template<typename T>
BSTree<T>& BSTree<T>::operator=(BSTree&& rhs) {
#ifdef CTOR_S
    cout << "move assignment operator" << endl;
#endif
    if (this != &rhs) {
        root = rhs.root;
        rhs.root = nullptr;
    }
    return *this;
}

//destructor
template <typename T>
BSTree<T>::~BSTree<T>() {
#ifdef CTOR_S
    cout << "destructor" << endl;
#endif
    destruct(root);
}
