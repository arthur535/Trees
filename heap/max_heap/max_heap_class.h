#ifndef MAX_H
#define MAX_H
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class MaxHeap {
public:
    void print_data();
    T get_max();
    size_t size();
    void insert(int);
    void remove(int);
    void update(unsigned int, int);
private:
    vector<T> A;
private:
    unsigned int parent(unsigned int i) {return (i - 1) / 2;}
    unsigned int left(unsigned int i)   {return (2 * i + 1);}
    unsigned int right(unsigned int i)  {return (2 * i + 2);}
    
    void max_heapify(unsigned int);
};

#endif // MAX_H

