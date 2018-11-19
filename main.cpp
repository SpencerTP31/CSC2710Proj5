/*
 * Author: Spencer Peters
 * Date: 11/3/18
 * Class: CSC-2710
 * File Location: ~/CSC2710/Proj5
 *
 * This program is used to find the minimumm cost of a spanning tree using
 * kruskals algorithm and minHeap to sort
 *
 * To compile g++ main.cpp disjointSet.cpp and then use IO redirection to run, a.out < (filename)
 */
#include <iostream>
#include <string>
#include "minMaxHeap.cpp"
#include "edges.h"
#include "disjointSet.h"
using namespace std;

//Function Prototypes
void load(edges newEdge[], string cities[], int &count);
int insert(string cities[], int &count, string checkCity);
bool kruskal(int edgeCount, int vertCount, edges sorted[]);
void print(edges sorted[], int edgeCount, string cities[]);

/*Main Function:
 *      Main is used to call the other functions needed to properly find the minimum cost
 */
int main()
{
    int edgeCount;
    int verticyCount;
    int cnt;
    cin >> cnt;
    bool connection;
    for (int i = 0; i < cnt; i++)
    {
        cout << "Customer " << i+1 << ":" << endl;
        cin >> edgeCount >> verticyCount;
        cin.get();
        edges E[edgeCount];
        string cities[verticyCount];
        load(E, cities, edgeCount);
        minHeap<edges> heap(edgeCount);
        for (int j = 0; j < edgeCount; j++)
        {
            heap.insert(E[j]);
        }
        edges sortedEdges[edgeCount];
        for (int k = 0; k < edgeCount; ++k)
        {
            sortedEdges[k] = heap.extractMin();
        }
        connection = kruskal(edgeCount, verticyCount, sortedEdges);
        if(connection == 1)
        {
            print(sortedEdges,edgeCount, cities);
        }
        else
        {
            cout << "No Solution" << endl;

        }
    }
    return 0;
}

/*load Function:
 *      File loads in data from the text file and loads it into an edge type
 *
 *precondition:
 *      This function takes
 *      newEdge an empty array of edges
 *      cities an empty array of strings to store the cities
 *      count a counter for the amount of edges sent from main
 *
 *post conditon:
 *      Once the function has completed the array of edges will hold the the to, from, and cost values in each edge
 *      cities array will be filled with only one instance of each city to insure no duplicates of a city name
 *      the cities from the data file will be sent to insert to properly convert them to numerical values to store
 *      correclty in each edge
 */
void load(edges newEdge[], string cities[], int &count)
{
    string firstCity;
    string secondCity;
    int costofCon;
    int cityTo;
    int cityFrom;
    int counter = 0;

    for (int i = 0; i < count; i++)
    {
        getline(cin,firstCity,',');
        cin.get();
        getline(cin,secondCity,',');
        cin >> costofCon;
        while(isspace(cin.peek()))
        {
            cin.get();
        }
        cityTo = insert(cities, counter, firstCity);
        cityFrom = insert(cities, counter, secondCity);
        newEdge[i] . cityFrom = cityFrom;
        newEdge[i] . cityTo = cityTo;
        newEdge[i] . cost = costofCon;
    }
}

/*insert Function:
 *      Converts the city name to a number and checks to see if a city is in the cities array
 *      yet and if not inserts it
 *
 *precondition:
 *      Takes the string of cities in order to determine whether the city has been used or not yet
 *      and takes the checkCity to convert to a number which is the position the city is in in the array
 *      of cities
 *
 *post conditon:
 *      Once the function has completed the checkCity will either be inserted into the cities array or the
 *      subscript of the city in the array will be returned
 */
int insert(string cities[], int &count, string checkCity)
{
    for (int i = 0; i < count; i++)
    {
        if(cities[i] == checkCity)
        {
            return i;
        }
    }
    cities[count++] = checkCity;
    return count-1;
}

/*kruskal Function:
 *      This created the minimum spanning tree and checks for cycles by using disjoint sets
 *
 *precondition:
 *
 *
 *post conditon:
 *      Once the function has completed
 */
bool kruskal(int edgeCount, int vertCount, edges sorted[])
{
    int count = 0;
    disjointSets dSet(vertCount);
    int i = 0;
    int left;
    int right;
    while(i < edgeCount && count != vertCount - 1)
    {
        left = dSet.findSet(sorted[i].cityFrom);
        right = dSet.findSet(sorted[i].cityTo);
        if(left != right)
        {
            dSet.unionSet(right, left);
            count++;
            sorted[i].used = 1;
        }
        i++;
    }
    if(count != vertCount-1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/*print Function:
 *      Prints the final array of edges
 *
 *precondition:
 *      takes the sorted edges and the cities and prints them
 *
 *
 *post conditon:
 *      Once the function is complete the output will be properly displayed
 */
void print(edges sorted[], int edgeCount, string cities[])
{
    int cityTo;
    int cityFrom;
    int cost = 0;
    for (int i = 0; i < edgeCount; ++i)
    {
        if(sorted[i].used == 1)
        {
            cityTo = sorted[i].cityTo;
            cityFrom = sorted[i].cityFrom;
            cout << "(" << cities[cityTo] << ", " << cities[cityFrom] << ") " << sorted[i].cost << endl;
            cost += sorted[i].cost;
        }
    }
    cout << "Minimal Cost: " << cost << endl;
}

