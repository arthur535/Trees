#include "/Users/arthur/Desktop/data structures/AVLTree/includes.h"
#include "/Users/arthur/Desktop/data structures/binary_search-tree/includes.hpp"
int main(){
    AVLTree<int> k;
    k.insert(23);
    k.insert(21);
    k.insert(20);
    k.insert(8);
    AVLTree<int> p;
    p.insert(232);
    p.insert(26);
    p.insert(10);
    p.insert(4);
    cout << k << endl;
    cout << k.count() << endl;
    k.merge(p);
    k.inorder_traversal();
}
