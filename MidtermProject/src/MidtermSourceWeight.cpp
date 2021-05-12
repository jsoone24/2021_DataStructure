// Reference : Algoritm.BellmanFord

#include <iostream>
#include <set>
#include <list>
#include <vector>

using namespace std;

struct node
{
    int n;                         // No. of visited this node
    vector<list<pair<int, int>>> adj; // neighbors node address, weight container
};

class Graph
{
    int nodeNum; // No. of nodes

public:
int **dist;
   vector<list<pair<int, int>>> nodes;
    Graph(int V); // Constructor
    void addEdge(int u, int v);
};

Graph::Graph(int nodeNum)
{
    this->nodeNum = nodeNum;
    for (int i = 0; i < nodeNum; i++)
    {
        list<pair<int, int>> t;
        adj.push_back(t);
    }
}

void Graph::addEdge(int u, int v, int w)
{
    pair<int, int> t;
    t.first = v;
    t.second = w;
    adj[u].push_back(t);
}

////////////////////////////////////////
////////         Task 4         ////////
//////// implement RandomWalker ////////
////////////////////////////////////////

int RandomWalker(int i, int n, int q) // i : starting node, n : walking length, q : probability jumping to random node
{
    for (int u = 0; u < V-2; u++)
    {
        list<pair<int, int>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;

            if (dist[u] != INF && dist[v] > dist[u] + weight)
                dist[v] = dist[u] + weight;
        }
        for (int k = 0; k < V; k++)
            printf("%d\t", dist[k]);
        printf("\n");
    }

    for (int u = 0; u < V; u++)
    {
        list<pair<int, int>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;

            if (dist[u] != INF && dist[v] > dist[u] + weight)
            {
                printf("NEGATIVE CYCLE\n");
                return;
            }
        }
    }
}

/////////////////////////////////////////
////////          Task 5         ////////
//////// implement PageRank func ////////
/////////////////////////////////////////

int PageRank()
{
}

/////////////////////////////////////
////////       Task 6        ////////
//////// test from real data ////////
/////////////////////////////////////

int main()
{
    Graph G = Graph(5);
    G.addEdge(0, 1, 1);
    G.addEdge(0, 2, -4);
    G.addEdge(1, 0, 1);
    G.addEdge(1, 2, 2);
    G.addEdge(1, 3, 3);
    G.addEdge(2, 0, -4);
    G.addEdge(2, 1, 2);
    G.addEdge(2, 3, 8);
    G.addEdge(3, 1, 3);
    G.addEdge(3, 2, 8);
    G.addEdge(3, 4, 9);
    G.addEdge(4, 3, 9);

    G.shortestPath(0);

    return 0;
}