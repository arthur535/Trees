#include "avl_class.h"
#include <iostream>
using namespace std;
#define CTOR_S

template <typename T>
AVLTree<T>::AVLTree(){
#ifdef CTOR_S
    cout << "default constructor" << endl;
#endif
    root = nullptr;
}

template <typename T>
AVLTree<T>::AVLTree(const AVLTree& oth){
#ifdef CTOR_S
    cout << "copy constructor" << endl;
#endif
    if(this != &oth){
        root = clone(oth.root);
    }
}

template <typename T>
AVLTree<T>::AVLTree(AVLTree&& rhs){
#ifdef CTOR_S
    cout << "move constructor" << endl;
#endif
    if(this != &rhs){
        root = rhs.root;
        rhs.root = nullptr;
    }
}

template <typename T>
AVLTree<T>::AVLTree(T elem){
#ifdef CTOR_S
    cout << "parameterized constructor" << endl;
#endif
    root = new Node(elem);
}

template <typename T>
AVLTree<T>::AVLTree(initializer_list<T> list){
#ifdef CTOR_S
    cout << "initializer list constructor" << endl;
#endif
    root = nullptr;
    for (auto& ref : list) {
        insert(ref);
    }
}

template <typename T>
AVLTree<T>& AVLTree<T>::operator=(const AVLTree& oth){
#ifdef CTOR_S
    cout << "copy assignment constructor" << endl;
#endif
    if (this == &oth){
        return *this;
    }
    if (root != nullptr){
        clear(root);
        root = nullptr;
    }
    root = clone(oth.root);
    return *this;
}

template <typename T>
AVLTree<T>& AVLTree<T>::operator=(AVLTree&& rhs){
#ifdef CTOR_S
    cout << "move assignment constructor" << endl;
#endif
    if (root != nullptr){
        clear(root);
        root = nullptr;
    }
    root = rhs.root;
    rhs.root = nullptr;
    return *this;
}

template <typename T>
AVLTree<T>::~AVLTree() {
#ifdef CTOR_S
    cout << "destructor" << endl;
#endif
    clear();
}
