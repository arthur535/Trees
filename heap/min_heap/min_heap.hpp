#include "min_heap_class.h"
template <typename T>
void MinHeap<T>::insert(const int value){
    if(0 == A.size()){
        A.push_back(value);
        return;
    }
    A.push_back(value);
    int i = A.size() - 1;
    while (i > 0 && A[i] < A[parent(i)]) {
        swap(A[i], A[parent(i)]);
        i = parent(i);
    }
}

template <typename T>
void MinHeap<T>::update(unsigned int i, const int value){
    if(i > A.size()) {
        return;
    }
    A[i] = value;
    while (i != 0 && A[parent(i)] > A[i])
    {
        swap(A[i], A[parent(i)]);
        i = parent(i);
    }
}

template <typename T>
void MinHeap<T>::remove(const int value){
    int index = NULL;
    for (int i = 0; i < A.size(); ++i) {
        if(A[i] == value){
            index = i;
        }
    }
    if(!index){
        return;
    }
    update(index, INT_MIN);
    swap(A[A.size()-1], A[0]);
    A.pop_back();
    min_heapify(0);
}

template <typename T>
void MinHeap<T>::min_heapify(unsigned int i){
    unsigned int smallest = i;
    int l = left(i);
    int r = right(i);
    
    if(l < A.size() && A[smallest] > A[l]){
        smallest = l;
    }
    if(r < A.size() && A[smallest] > A[r]){
        smallest = r;
    }
    
    if(smallest != i){
        swap(A[i], A[smallest]);
        min_heapify(smallest);
    }
}

template <typename T>
void MinHeap<T>::print_data(){
    for (int i = 0; i < A.size(); ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}

template <typename T>
T MinHeap<T>::get_min(){
    return A[0];
}

template <typename T>
size_t MinHeap<T>::size(){
    return A.size();
}


