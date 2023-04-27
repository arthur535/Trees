#include "max_heap_class.h"
template <typename T>
void MaxHeap<T>::insert(const int value){
    if(0 == A.size()){
        A.push_back(value);
        return;
    }
    A.push_back(value);
    int i = A.size() - 1;
    while (i > 0 && A[i] > A[parent(i)]) {
        swap(A[i], A[parent(i)]);
        i = parent(i);
    }
}

template <typename T>
void MaxHeap<T>::update(unsigned int i, const int value){
    if(i > A.size()) {
        return;
    }
    A[i] = value;
    while (i != 0 && A[parent(i)] < A[i])
    {
        swap(A[i], A[parent(i)]);
        i = parent(i);
    }
}

template <typename T>
void MaxHeap<T>::remove(const int value){
    int index = NULL;
    for (int i = 0; i < A.size(); ++i) {
        if(A[i] == value){
            index = i;
        }
    }
    if(!index){
        return;
    }
    update(index, INT_MAX);
    swap(A[A.size()-1], A[0]);
    A.pop_back();
    min_heapify(0);
}

template <typename T>
void MaxHeap<T>::max_heapify(unsigned int i){
    unsigned int largest = i;
    int l = left(i);
    int r = right(i);
    
    if(l < A.size() && A[largest] < A[l]){
        largest = l;
    }
    if(r < A.size() && A[largest] < A[r]){
        largest = r;
    }
    
    if(largest != i){
        swap(A[i], A[largest]);
        max_heapify(largest);
    }
}

template <typename T>
void MaxHeap<T>::print_data(){
    for (int i = 0; i < A.size(); ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}

template <typename T>
T MaxHeap<T>::get_max(){
    return A[0];
}

template <typename T>
size_t MaxHeap<T>::size(){
    return A.size();
}


