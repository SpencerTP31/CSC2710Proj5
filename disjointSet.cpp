/*
 * Spencer Peters
 * Proj5
 */
#include <iostream>
#include "disjointSet.h"
using namespace std;

disjointSets::disjointSets(int numSets):n(numSets)
{
    rep = new int[n];
    rank = new int[n];
    for (int i = 0; i < n; i++)
    {
        rep[i] = -1;
        rank[i] = 0;
    }
}
disjointSets::~disjointSets()
{
    delete []rep;
    delete []rank;
}

int disjointSets::findSet(int i)
{
    int r = i;
    while(rep[r] != -1)
    {
        r = rep[r];
    }
    return r;
}

void disjointSets::unionSet(int u, int v)
{
    if(u != v)
    {
        if(rank[u] > rank[v])
        {
            //Set V has a lower rank
            rep[v] = u;
        }
        else if(rank[u] == rank[v])
        {
            //Sets have the same rank therefore increase rank size
            rep[v] = u;
            rank[u]++;
        }
        else
        {
            //Set U has a lower rank
            rep[u] = v;
        }
    }
}

void disjointSets::makeSet(int x)
{
    rep = new int[1];
    rank = new int[1];
    rep[0] = x;
    rank[0] = x;
}

void disjointSets::print()
{
    cout << "number of sets: " << n << endl;
    cout << "set#   rep   rank" << endl;
    for (int i = 1; i <= n; i++)
    {
            cout << i << "  " << rep << "  " << rank << endl;
    }

}
