/*
 * Spencer Peters
 * Proj5
 */
#include "minMaxHeap.h"
#include <iostream>
#include <climits>
using namespace std;

template <class T>
minHeap<T>::minHeap(int size)
{
    size++;
    curSize = 0;
    maxSize = size;
    holderArr = new T[maxSize];
}

template <class T>
minHeap<T>::~minHeap()
{
    delete []holderArr;
}

template <class T>
int minHeap<T>::parent(int i)
{
    return i/2;
}

template <class T>
int minHeap<T>::left(int i)
{
    return (2 * i);
}

template <class T>
int minHeap<T>::right(int i)
{
    return (2 * i + 1);
}

template <class T>
T& minHeap<T>::peek()
{
    if(curSize < 1)
    {
        cout << "Heap is empty" << endl;
    }
    else
    {
        return holderArr[1];
    }
}

template <class T>
T minHeap<T>::extractMin()
{
    T min;
    min = holderArr[1];
    holderArr[1] = holderArr[curSize];
    curSize--;
    heapify(1);
    return min;
}

template <class T>
void minHeap<T>::exchange(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
void minHeap<T>::heapify(int curIndex)
{
    int l = left(curIndex);
    int r = right(curIndex);
    int small = curIndex;
    if(l <= curSize && holderArr[l] < holderArr[curIndex])
    {
        small = l;
    }
    else
    {
        small = curIndex;
    }
    if(r <= curSize && holderArr[r] < holderArr[small])
    {
        small = r;
    }
    if(small != curIndex)
    {
        exchange(holderArr[curIndex], holderArr[small]);
        heapify(small);
    }
}

template <class T>
void minHeap<T>::increaseKey(int curIndex, T &key)
{
    if(key == holderArr[curIndex])
    {
        cout << "Error New Key is Smaller than Current Key" << endl;
    }
    holderArr[curIndex] = key;
    while(curIndex > 1 && holderArr[parent(curIndex)] > holderArr[curIndex])
    {
        exchange(holderArr[curIndex], holderArr[parent(curIndex)]);
        curIndex = parent(curIndex);
    }
}

template <class T>
void minHeap<T>::insert(T &key)
{
    curSize++;
    holderArr[curSize] = key.max();
    increaseKey(curSize, key);
}
