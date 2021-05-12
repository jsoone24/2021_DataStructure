// Reference : DFS

#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <vector>

using namespace std;

struct node
{
    int n;                    // No. of visited this node
    int id;                   // node identifier
    int pageRankVal;          // Current node PageRankVal
    string name;              // string name of this node
    vector<node *> neighbors; // neighbors node address container
};

class Graph
{
    int nodeNum;                   // No. of nodes
    vector<node *> nodes;          // vector container for nodes
    vector<pair<int, int>> id2IdxTable; // to find index from file node id

public:
    Graph(string filename);                         // Constructor
    void AddEdge(int u, int v);            //adding edge
    int Id2Idx(int n);                     // convert file node id to vector node id
    void LoadEdge(string filename);            // load edge file
    int RandomWalker(int i, int n, int q); // i : starting node, n : walking length, q : probability jumping to random node
    int PageRank();                        // cal pagerank
};

//todo
Graph::Graph(string filename)
{
    this->nodeNum = 0;

    std::ifstream ifs(filename);
    std::string line;
    std::getline(ifs, line);
    std::cout << line << std::endl;
    std::stringstream ls(line);
    int n;
    ls >> n;
    for (int i = 0; i < n; i++)
    {
        std::getline(ifs, line);
        std::string str;
        int val;
        std::stringstream ls(line);
        ls >> str;
        insertVertex(str);
        for (int j = 0; j < n; j++)
        {
            ls >> val;
            if (val != 0)
            {
                insertEdge(i, j);
            }
        }
    }
    ifs.close();

    while (EOF)
    {
        //read file by line
        node *temp = new node;

        temp->n = 0;
        temp->id; //first col
        temp->pageRankVal = 0;
        temp->name; //second col

        nodes.push_back(temp);
        this->nodeNum++;
    }
}

//todo
Graph::~Graph()
{
    // dealloc nodes
}

//todo
void Graph::AddEdge(int u, int v)
{
    int uV = Id2Idx(u); // Vector index of node u
    int vV = Id2Idx(v); // Vector index of node v

    nodes[uV]->neighbors.push_back(nodes[vV]);
    nodes[vV]->neighbors.push_back(nodes[uV]);
}

//todo
int Graph::Id2Idx(int n)
{
}

//todo
void Graph::LoadEdge(string filename)
{
    std::ifstream ifs(filename);
    std::string line;
    std::getline(ifs, line);
    std::cout << line << std::endl;
    std::stringstream ls(line);
    int n;
    ls >> n;
    for (int i = 0; i < n; i++)
    {
        std::getline(ifs, line);
        std::string str;
        int val;
        std::stringstream ls(line);
        ls >> str;
        insertVertex(str);
        for (int j = 0; j < n; j++)
        {
            ls >> val;
            if (val != 0)
            {
                insertEdge(i, j);
            }
        }
    }
    ifs.close();
}

////////////////////////////////////////
////////         Task 1         ////////
//////// implement RandomWalker ////////
////////////////////////////////////////

//todo
int Graph::RandomWalker(int i, int n, int q)
{
    vector<node *>::iterator i;
    for (i = w->neighbors.begin(); i != w->neighbors.end(); i++)
    {
        if ((*i)->visited == false)
        {
            currentTime = DFS(*i, currentTime);
            ++currentTime;
        }
    }
}

/////////////////////////////////////////
////////          Task 2         ////////
//////// implement PageRank func ////////
/////////////////////////////////////////

//todo
int Graph::PageRank()
{
}

/////////////////////////////////////
////////       Task 3        ////////
//////// test from real data ////////
/////////////////////////////////////

//todo
int main()
{
    // First. open node file
    Graph StarW_Ep1 = Graph("starwars-episode-1-interactions-allCharacters-nodes.tsv");
    Graph StarW_Ep2 = Graph("starwars-episode-2-interactions-allCharacters-nodes.tsv");
    Graph StarW_Ep3 = Graph("starwars-episode-3-interactions-allCharacters-nodes.tsv");
    Graph StarW_Ep4 = Graph("starwars-episode-4-interactions-allCharacters-nodes.tsv");
    Graph StarW_Ep5 = Graph("starwars-episode-5-interactions-allCharacters-nodes.tsv");
    Graph StarW_Ep6 = Graph("starwars-episode-6-interactions-allCharacters-nodes.tsv");
    Graph StarW_Ep7 = Graph("starwars-episode-7-interactions-allCharacters-nodes.tsv");
    Graph StarW_All = Graph("starwars-full-interactions-allCharacters-nodes.tsv");

    Graph BicycleT_50 = Graph("station_names.tsv");
    Graph BicycleT_100 = Graph("station_names.tsv");
    Graph BicycleT_All = Graph("station_names.tsv");

    // Second. open datafile
    BicycleT_50.LoadEdge("bicycle_trips_over_50.tsv");
    BicycleT_100.LoadEdge("bicycle_trips_all.tsv");
    BicycleT_All.LoadEdge("bicycle_trips_all.tsv");

    //Third. let RandomWalker run

    //Last. get PageRank

    return 0;
}