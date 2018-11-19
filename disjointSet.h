/*
 * Spencer Peters
 * Proj5
 */
#ifndef CSC2710PROJ5_DISJOINTSET_H
#define CSC2710PROJ5_DISJOINTSET_H

#include <iostream>
using namespace std;

class disjointSets
{
private:
    int *rep;
    int n;
    int *rank;
public:
    //Constructor
    disjointSets(int numSets=1000);
    //Deconstruct
    ~disjointSets();
    int findSet(int i);
    void makeSet(int x);
    void unionSet(int u, int v);
    void print();
};
#endif