#include "avl_class.h"
//#define COUT_S

template <typename T>
int AVLTree<T>::get_height() const{
#ifdef COUT_S
    cout << "get tree height" << endl;
#endif
    return get_height(root);
}

template <typename T>
void AVLTree<T>::inorder_traversal() const{
    inorder_traversal(root);
}
template <typename T>
void AVLTree<T>::preorder_traversal() const{
    preorder_traversal(root);
}
template <typename T>
void AVLTree<T>::postorder_traversal() const{
    postorder_traversal(root);
}

template <typename T>
void AVLTree<T>::insert(const T& value) {
#ifdef COUT_S
    cout << "insert function call" << endl;
#endif
    insert(value,root);
}

template <typename T>
void AVLTree<T>::remove(const T& value) {
#ifdef COUT_S
    cout << "remove function call" << endl;
#endif
    remove(value,root);
}

template <typename T>
const T& AVLTree<T>::find_min() const {
#ifdef COUT_S
    cout << "find_min function call" << endl;
#endif
    return find_min(root)->data;
}

template <typename T>
const T& AVLTree<T>::find_max() const {
#ifdef COUT_S
    cout << "find_max function call" << endl;
#endif
    return find_max(root)->data;
}

template <typename T>
bool AVLTree<T>::contains(const T& value) const {
#ifdef COUT_S
    cout << "contains function call" << endl;
#endif
    return contains(value,root);
}

template <typename T>
void AVLTree<T>::clear() {
#ifdef COUT_S
    cout << "clear function call" << endl;
#endif
    clear(root);
}

template <typename T>
unsigned int AVLTree<T>::count() const {
#ifdef COUT_S
    cout << "count function call" << endl;
#endif
    return count(root);
}

template <typename T>
void AVLTree<T>::merge(const AVLTree& obj){
#ifdef COUT_S
    cout << "merging two trees : private" << endl;
#endif
    if (root == obj.root){return;}
    merge(root,obj.root);
}
