#ifndef BST_H
#define BST_H
template<typename T>
class BSTree {
public:
    BSTree();
    BSTree(const BSTree&);
    BSTree(BSTree&&);
    ~BSTree();
    
    void inorder_tarversal() const;
    void preorder_tarversal() const;
    void postorder_tarversal() const;
    
    const T& find_min() const;
    const T& find_max() const;
    
    BSTree& operator=(const BSTree&);
    BSTree& operator=(BSTree&&);
    
    bool contains(const T&) const;
    bool contains(T&&) const;
    bool is_empty() const;
    
    void clear();
    
    void insert(const T&);
    void insert(T&&);
    void remove(const T&);
    
private:
    struct Node {
        Node(T v,Node* l,Node* r){
            val = v;
            left = l;
            right = r;
        }
        Node(T v = T()){
            val = v;
            left = nullptr;
            right = nullptr;
        }
        T val;
        Node* left;
        Node* right;
    }* root;
    
private:
    void inorder_tarversal(Node*) const;
    void preorder_tarversal(Node*) const;
    void postorder_tarversal(Node*) const;
    
    Node* clone(Node*) const;
    
    bool contains(const T&, Node*) const;
    void insert(const T&, Node*&);
    void remove(const T&, Node*&);
    
    Node* find_min(Node*) const;
    Node* find_max(Node*) const;
    
    void destruct(Node*);
    bool is_empty(Node*) const;
    
    BSTree::Node* GetNewNode(T data) {
        BSTree::Node* newNode = new Node();
        newNode->val = data;
        newNode->left = nullptr;
        newNode->right = nullptr ;
        return newNode;
    }
};

#endif // BST_H
