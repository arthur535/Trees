#ifndef MAX_H
#define MAX_H
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class MinHeap {
public:
    void print_data();
    T get_min();
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
    
    void min_heapify(unsigned int);
};

#endif // MAX_H

