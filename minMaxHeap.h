/*
 * Spencer Peters
 * Proj5
 */
#ifndef MINMAXHEAP_MINMAXHEAP_H
#define MINMAXHEAP_MINMAXHEAP_H

template <class T>
class minHeap
{
private:
    int maxSize;
    T *holderArr;
    int curSize;
public:
    minHeap(int size = 1000);
    ~minHeap();
    int parent(int i);
    int left(int i);
    int right(int i);
    T& peek(void);
    T extractMin(void);
    void exchange(T &a, T &b);
    void heapify(int curIndex);
    void increaseKey(int curIndex, T & key);
    void insert(T & key);
};

#endif //MINMAXHEAP_MINMAXHEAP_H
