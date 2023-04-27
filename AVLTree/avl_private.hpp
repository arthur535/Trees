#include "avl_class.h"
//#define COUT_S

template<typename T>
int AVLTree<T>::get_height(const Node* root) const{
#ifdef COUT_S
    cout << "get height from root : private" << endl;
#endif
    if (!root)
        return 0;
    else {
        // Find the height of both subtrees
        // and use the larger one
        int left_height = get_height(root->left);
        int right_height = get_height(root->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}

template<typename T>
int AVLTree<T>::get_balance(const Node* root) const{
#ifdef COUT_S
    cout << "get balance factor : private" << endl;
#endif
    if(!root){
        return 0;
    }
    return get_height(root->left) - get_height(root->right);
}

template<typename T>
void AVLTree<T>::inorder_traversal(Node* root) const {
    if(!root){
        return;
    }
    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}
template<typename T>
void AVLTree<T>::preorder_traversal(Node* root) const {
    if(!root){
        return;
    }
    cout << root->data << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}
template<typename T>
void AVLTree<T>::postorder_traversal(Node* root) const {
    if(!root){
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout << root->data << " ";
}


template <typename T>
void AVLTree<T>::insert(const T& value, Node*& root){
#ifdef COUT_S
    cout << "insert function call : private" << endl;
#endif
    if(!root){
        root = new Node(value);
    }
    if(root->data > value) {
        insert(value,root->left);
    }
    if(root->data < value) {
        insert(value,root->right);
    }
    int bf = get_balance(root);
    if(abs(bf) > 1){
        root = do_rotation(root);
    }
}


template <typename T>
bool AVLTree<T>::contains(const T& value, Node* root) const{
#ifdef COUT_S
    cout << "contains function call : private" << endl;
#endif
    if(!root){
        return false;
    }
    if(root->data > value) {
        return contains(value, root->left);
    }
    else if(root->data < value) {
        return contains(value, root->right);
    }
    return true;
}


template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::find_max(Node* root) const {
#ifdef COUT_S
    cout << "find_max function call : private" << endl;
#endif
    if(!root){
        return nullptr;
    }
    if(!root->right){
        return root;
    }
    return find_max(root->right);
}


template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::find_min(Node* root) const {
#ifdef COUT_S
    cout << "find_min function call : private" << endl;
#endif
    if(!root){
        return nullptr;
    }
    if(!root->left){
        return root;
    }
    return find_min(root->left);
}


template <typename T>
void AVLTree<T>::remove(const T& value, Node*& root) {
#ifdef COUT_S
    cout << "remove function call : private" << endl;
#endif
    if(!root){
        return;
    }
    if(root->data > value) {
        remove(value, root->left);
    }
    else if(root->data < value) {
        remove(value, root->right);
    }

    else{
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }
        else if(root->left != nullptr || root->right != nullptr){
            root->data = find_min(root->right)->data;
            remove(root->data, root->right);
        }
    }
}


template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::clone(Node* node_ptr) const {
#ifdef COUT_S
    cout << "clone function call : private" << endl;
#endif
    Node* tmp = nullptr;
    if (node_ptr == nullptr){return tmp;}
    
    tmp = new Node(node_ptr->data);
    tmp->left = clone(node_ptr->left);
    tmp->right = clone(node_ptr->right);
    return tmp;
}


template <typename T>
void AVLTree<T>::clear(Node* root) {
#ifdef COUT_S
    cout << "clear function call : private" << endl;
#endif
    if (root == nullptr){return;}
    clear(root->right);
    clear(root->left);
    delete root;
    root = nullptr;
}


//rotations
template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::right_rotate(Node* root) {
#ifdef COUT_S
    cout << "right rotation : private" << endl;
#endif
    Node *T1 = root->left;
    Node *T2 = T1->right;
    
    T1->right = root;
    root->left = T2;
    
    return T1;
}
template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::right_left_rotate(Node* root) {
    root->right = right_rotate(root->right);
    root = left_rotate(root);
    return root;
}
template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::left_rotate(Node* root) {
#ifdef COUT_S
    cout << "left rotation : private" << endl;
#endif
    Node *T1 = root->right;
    Node *T2 = T1->left;

    T1->left = root;
    root->right = T2;

    return T1;
}
template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::left_right_rotate(Node* root) {
    root->left = left_rotate(root->left);
    root = right_rotate(root);
    return root;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::do_rotation(Node* root) {
    if (root == nullptr){
        return nullptr;
    }
    int bf = get_balance(root);
    if (bf > 1){
        if (get_balance(root->left) >= 0){
            root = right_rotate(root);
        }
        else {
            root = left_right_rotate(root);
        }
    }
    if (bf < -1){
        if (get_balance(root->right) <= 0){
            root = left_rotate(root);
        }
        else {
            root = right_left_rotate(root);
        }
    }
    return root;
}


template <typename T>
unsigned int AVLTree<T>::count(const Node* root) const {
#ifdef COUT_S
    cout << "count function call : private" << endl;
#endif
    if (root == nullptr){
        return 0;
    }
    return count(root->left) + count(root->right) + 1;
}

template <typename T>
void AVLTree<T>::merge(Node*& obj1, const Node* obj2){
#ifdef COUT_S
    cout << "merging two trees : private" << endl;
#endif
    if (obj2 == nullptr){
        return;
    }
    if (obj1 == nullptr){
        obj1 = new Node(obj2->data);
    }
    merge(obj1, obj2->left);
    insert(obj2->data, obj1);
    merge(obj1,obj2->right);
    insert(obj2->data, obj1);
}
