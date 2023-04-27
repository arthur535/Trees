#include "/Users/arthur/Desktop/BinarySearchTree/includes.hpp"
#include <iostream>
using namespace std;
int main(){
    BSTree<int> binary_search_tree;
    int k = 9;
    binary_search_tree.insert(70);
    binary_search_tree.insert(60);
    binary_search_tree.insert(80);
    binary_search_tree.inorder_tarversal();
    cout << endl;
    binary_search_tree.insert(50);
    binary_search_tree.insert(65);
    binary_search_tree.preorder_tarversal();
    cout << endl;
    binary_search_tree.insert(85);
    binary_search_tree.remove(50);
    binary_search_tree.insert(75);
    binary_search_tree.postorder_tarversal();
    cout << endl;
    
    binary_search_tree.clear();
    cout << binary_search_tree.is_empty() << endl;
}
