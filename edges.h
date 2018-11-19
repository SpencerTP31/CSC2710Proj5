/*
 * Spencer Peters
 * Proj5
 */
#ifndef CSC2710PROJ5_EDGES_H
#define CSC2710PROJ5_EDGES_H
#include <iostream>
using namespace std;

class edges
{
public:
    int cost;
    int cityTo;
    int cityFrom;
    bool used;
    edges(const int u = 0, const int v = 0, const int c = 0, const bool t = 0):cityFrom(u),cityTo(v),cost(c),used(t){}
    bool operator<(const edges &other)
    {
        return this -> cost < other.cost;
    }
    bool operator>(const edges &other)
    {
        return this -> cost > other.cost;
    }
    bool operator==(const edges &other)
    {
        return this -> cost == other.cost;
    }
    edges max()
    {
        return edges(0,0,INT_MAX);
    }
    friend ostream & operator << (ostream &out, edges & edge)
    {
        out << edge.cityFrom << " " << edge.cityTo << " " << edge.cost;
        return out;
    }
    friend istream & operator >> (istream &in, edges & edge)
    {
        in >> edge.cityFrom >> edge.cityTo >> edge.cost;
        return in;
    }
};

#endif
