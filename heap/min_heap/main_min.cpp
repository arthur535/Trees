#include "/Users/arthur/Desktop/data structures/heap/max_heap/max_heap.hpp"
#include <iostream>
using namespace std;
int main(){
    MaxHeap<int> h;
    h.insert(50);
    h.insert(30);
    h.insert(40);
    h.insert(25);
    h.insert(29);
    h.insert(39);
    h.insert(35);
    h.insert(7);
    h.insert(16);
    h.insert(8);
    h.insert(18);
    h.insert(55);
    h.remove(25);
    cout << h.size() << endl;
    h.update(4,78);
    h.print_data();
}
