#include "bst.h"
#include <iostream>
//#define COUT_S

using namespace std;
//traversals : private
template<typename T>
void BSTree<T>::inorder_tarversal(Node* root) const {
#ifdef COUT_S
    cout << "private: inorder tarversal" << endl;
#endif
    if(!root){
        return;
    }
    inorder_tarversal(root->left);
    cout << root->val << " ";
    inorder_tarversal(root->right);
}

template<typename T>
void BSTree<T>::preorder_tarversal(Node* root) const {
#ifdef COUT_S
    cout << "private: preorder tarversal" << endl;
#endif
    if(!root){
        return;
    }
    cout << root->val << " ";
    preorder_tarversal(root->left);
    preorder_tarversal(root->right);
}

template<typename T>
void BSTree<T>::postorder_tarversal(Node* root) const {
#ifdef COUT_S
    cout << "private: postorder tarversal" << endl;
#endif
    if(!root){
        return;
    }
    postorder_tarversal(root->left);
    postorder_tarversal(root->right);
    cout << root->val << " ";
}

//insert function : private
template<typename T>
void BSTree<T>::insert(const T& value, Node*& root){
#ifdef COUT_S
    cout << "private: insert function call" << endl;
#endif
    if(!root){
        root = GetNewNode(value);
        return;
    }
    if(root->val > value) {
        insert(value, root->left);
    }
    else if(root->val < value) {
        insert(value, root->right);
    }
}

//find_min function : private
template <typename T>
typename BSTree<T>::Node* BSTree<T>::find_min(Node* root) const {
#ifdef COUT_S
    cout << "private: find_min function call" << endl;
#endif
    if (!root) {
        return nullptr;
    }
    if (!root->left) {
        return root;
    }
    return find_min(root->left);
}

//find_max function : private
template <typename T>
typename BSTree<T>::Node* BSTree<T>::find_max(Node* root) const {
#ifdef COUT_S
    cout << "private: find_max function call" << endl;
#endif
    if (!root) {
        return nullptr;
    }
    if (!root->right) {
        return root;
    }
    return find_max(root->right);
}

//remove function : private
template<typename T>
void BSTree<T>::remove(const T& value, Node*& root){
#ifdef COUT_S
    cout << "private: insert function call" << endl;
#endif
    if(!root){
        return;
    }
    if(root->val > value) {
        remove(value, root->left);
    }
    else if(root->val < value) {
        remove(value, root->right);
    }
    else{
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            root = nullptr;
        }
        else if(root->left != nullptr or root->right != nullptr){
            root->val = find_min(root->right)->val;
            remove(root->val, root->right);
        }
    }
}

//if tree contains T value : private
template<typename T>
bool BSTree<T>::contains(const T& value, Node* root) const {
#ifdef COUT_S
    cout << "private: contains function call" << endl;
#endif
    if(!root){
        return false;
    }
    if(root->val > value) {
        return contains(value, root->left);
    }
    else if(root->val < value) {
        return contains(value, root->right);
    }
    
    return true;
}

//destruct function : private
template <typename T>
void BSTree<T>::destruct(Node* root){
#ifdef COUT_S
    cout << "private: destruct/clear function call" << endl;
#endif
    if (root != nullptr) {
        destruct(root->left);
        destruct(root->right);
        delete root;
    }
    root = nullptr;
}

//if the tree is empty : private
template <typename T>
bool BSTree<T>::is_empty(Node* root) const {
#ifdef COUT_S
    cout << "private: is_empty function call" << endl;
#endif
    return root == nullptr;
}

template <typename T>
typename BSTree<T>::Node* BSTree<T>::clone(Node* root) const {
    if (!root) {
        return nullptr;
    }
    return new Node(root->val, clone(root->left), clone(root->right));
}
