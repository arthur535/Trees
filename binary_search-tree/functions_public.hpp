#include "bst.h"
#include <iostream>
//#define COUT_S

using namespace std;

//traversals
template <typename T>
void BSTree<T>::inorder_tarversal() const {
#ifdef COUT_S
    cout << "inorder tarversal" << endl;
#endif
    inorder_tarversal(root);
}

template <typename T>
void BSTree<T>::preorder_tarversal() const {
#ifdef COUT_S
    cout << "preorder tarversal" << endl;
#endif
    preorder_tarversal(root);
}

template <typename T>
void BSTree<T>::postorder_tarversal() const {
#ifdef COUT_S
    cout << "postorder tarversal" << endl;
#endif
    postorder_tarversal(root);
}

//find_min function
template <typename T>
const T& BSTree<T>::find_min() const {
#ifdef COUT_S
    cout << "find_min function call" << endl;
#endif
    return find_min(root)->val;
}

//find_min function
template <typename T>
const T& BSTree<T>::find_max() const {
#ifdef COUT_S
    cout << "find_max function call" << endl;
#endif
    return find_max(root)->val;
}

//insert function move
template<typename T>
void BSTree<T>::insert(const T& value){
#ifdef COUT_S
    cout << "insert function call" << endl;
#endif
    insert(value, root);
}

//insert function
template<typename T>
void BSTree<T>::insert(T&& value){
#ifdef COUT_S
    cout << "insert move function call" << endl;
#endif
    insert(value, root);
}

//remove function
template<typename T>
void BSTree<T>::remove(const T& value){
#ifdef COUT_S
    cout << "remove function call" << endl;
#endif
    remove(value, root);
}

//if tree contains T value
template<typename T>
bool BSTree<T>::contains(const T& value) const {
#ifdef COUT_S
    cout << "contains function call" << endl;
#endif
    return contains(value, root);
}

//if tree contains T value
template<typename T>
bool BSTree<T>::contains(T&& value) const {
#ifdef COUT_S
    cout << "contains move function call" << endl;
#endif
    return contains(value, root);
}

//clear the tree
template <typename T>
void BSTree<T>::clear(){
#ifdef COUT_S
    cout << "clear function call" << endl;
#endif
    destruct(root);
}

//if the tree is empty
template <typename T>
bool BSTree<T>::is_empty() const {
#ifdef COUT_S
    cout << "is_empty function call" << endl;
#endif
    return is_empty(root);
}
