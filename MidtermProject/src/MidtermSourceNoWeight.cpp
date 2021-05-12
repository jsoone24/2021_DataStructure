// Reference : DFS

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
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
    int nodeNum;             // No. of nodes
    vector<node *> nodes;    // vector container for nodes
    vector<int> id2IdxTable; // to find index from file node id. first: id from file, second : idx from vector

public:
    Graph(string filename); // Constructor
    ~Graph();
    void LoadEdge(string filename);       // load edge file
    void AddEdge(int source, int target); //adding edge
    int Id2Idx(int n);                    // convert file node id to vector node id
    //int RandomWalker(int i, int n, float q); // i : starting node, n : walking length, q : probability jumping to random node
    //int PageRank();                        // cal pagerank
};

//todo
Graph::Graph(string filename)
{
    this->nodeNum = 0;

    std::ifstream ifs(filename);
    std::string line;

    //read file by line
    std::getline(ifs, line);
    while (std::getline(ifs, line))
    {
        std::stringstream ls(line);
        std::string id;
        std::string name;
        std::getline(ls, id, '\t');
        std::getline(ls, name);

        node *temp = new node;

        temp->n = 0;
        temp->id = std::atoi(id.c_str()); //first col
        temp->pageRankVal = 0;
        temp->name = name; //second col

        nodes.push_back(temp);
        id2IdxTable.push_back(std::atoi(id.c_str()));
        this->nodeNum++;
    }

    ifs.close();
}

//todo
Graph::~Graph()
{
    // dealloc nodes
}

//todo
void Graph::AddEdge(int source, int target)
{
    nodes[source]->neighbors.push_back(nodes[target]);
}

//todo
int Graph::Id2Idx(int n)
{
    auto it = find(id2IdxTable.begin(), id2IdxTable.end(), n);
    if (it == id2IdxTable.end())
    {
        cout << "찾을 수 없습니다.\n";
        return -1;
    }
    else
    {
        return std::distance(id2IdxTable.begin(), it);
    }
}

//todo
void Graph::LoadEdge(string filename)
{
    std::ifstream ifs(filename);
    std::string line;

    //read file by line
    std::getline(ifs, line);
    while (std::getline(ifs, line))
    {
        std::stringstream ls(line);
        std::string source;
        std::string target;
        std::string weight;
        std::getline(ls, source, '\t');
        std::getline(ls, target, '\t');
        std::getline(ls, weight);

        int idxS = Id2Idx(std::atoi(source.c_str())); // Vector index of node source
        int idxT = Id2Idx(std::atoi(target.c_str())); // Vector index of node target
        int valW = std::atoi(weight.c_str());

        AddEdge(idxS, idxT);
    }

    ifs.close();

    for (vector<node *>::iterator it = nodes.begin(); it != nodes.end(); it++)
    {
        cout <<"id : "<< (*it)->id << endl<<"neighbors : ";
        for (vector<node *>::iterator tt = (*it)->neighbors.begin(); tt != (*it)->neighbors.end(); tt++)
            cout << (*tt)->id << " ";
        cout << endl<<endl;
    }
}

//////////////////////////////////////////
//////////         Task 1         ////////
////////// implement RandomWalker ////////
//////////////////////////////////////////
//
////todo
//int Graph::RandomWalker(int i, int n, float q)
//{
//    vector<node *>::iterator i;
//    for (i = w->neighbors.begin(); i != w->neighbors.end(); i++)
//    {
//        if ((*i)->visited == false)
//        {
//            currentTime = DFS(*i, currentTime);
//            ++currentTime;
//        }
//    }
//}
//
///////////////////////////////////////////
//////////          Task 2         ////////
////////// implement PageRank func ////////
///////////////////////////////////////////
//
////todo
//int Graph::PageRank()
//{
//}
//
///////////////////////////////////////
//////////       Task 3        ////////
////////// test from real data ////////
///////////////////////////////////////

//todo
int main()
{
    // First. open node file
    Graph StarW_Ep1 = Graph("./dataset/starwars/starwars-episode-1-interactions-allCharacters-nodes.tsv");
    //Graph StarW_Ep2 = Graph("starwars-episode-2-interactions-allCharacters-nodes.tsv");
    //Graph StarW_Ep3 = Graph("starwars-episode-3-interactions-allCharacters-nodes.tsv");
    //Graph StarW_Ep4 = Graph("starwars-episode-4-interactions-allCharacters-nodes.tsv");
    //Graph StarW_Ep5 = Graph("starwars-episode-5-interactions-allCharacters-nodes.tsv");
    //Graph StarW_Ep6 = Graph("starwars-episode-6-interactions-allCharacters-nodes.tsv");
    //Graph StarW_Ep7 = Graph("starwars-episode-7-interactions-allCharacters-nodes.tsv");
    //Graph StarW_All = Graph("starwars-full-interactions-allCharacters-nodes.tsv");
    //
    //Graph BicycleT_50 = Graph("station_names.tsv");
    //Graph BicycleT_100 = Graph("station_names.tsv");
    //Graph BicycleT_All = Graph("station_names.tsv");

    // Second. open datafile
    StarW_Ep1.LoadEdge("./dataset/starwars/starwars-episode-1-interactions-allCharacters-links.tsv");
    //StarW_Ep2.LoadEdge("starwars-episode-2-interactions-allCharacters-links.tsv");
    //StarW_Ep3.LoadEdge("starwars-episode-3-interactions-allCharacters-links.tsv");
    //StarW_Ep4.LoadEdge("starwars-episode-4-interactions-allCharacters-links.tsv");
    //StarW_Ep5.LoadEdge("starwars-episode-5-interactions-allCharacters-links.tsv");
    //StarW_Ep6.LoadEdge("starwars-episode-6-interactions-allCharacters-links.tsv");
    //StarW_Ep7.LoadEdge("starwars-episode-7-interactions-allCharacters-links.tsv");
    //StarW_All.LoadEdge("starwars-full-interactions-allCharacters-links.tsv");
    //
    //BicycleT_50.LoadEdge("bicycle_trips_over_50.tsv");
    //BicycleT_100.LoadEdge("bicycle_trips_all.tsv");
    //BicycleT_All.LoadEdge("bicycle_trips_all.tsv");

    // Third. let RandomWalker run
    //StarW_Ep1.RandomWalker(50, 200, 0.3);
    //StarW_Ep2.RandomWalker(50, 200, 0.3);
    //StarW_Ep3.RandomWalker(50, 200, 0.3);
    //StarW_Ep4.RandomWalker(50, 200, 0.3);
    //StarW_Ep5.RandomWalker(50, 200, 0.3);
    //StarW_Ep6.RandomWalker(50, 200, 0.3);
    //StarW_Ep7.RandomWalker(50, 200, 0.3);
    //StarW_All.RandomWalker(50, 200, 0.3);
    //
    //BicycleT_50.RandomWalker(50, 200, 0.3);
    //BicycleT_100.RandomWalker(50, 200, 0.3);
    //BicycleT_All.RandomWalker(50, 200, 0.3);

    //Last. get PageRank
    //StarW_Ep1.PageRank();
    //StarW_Ep2.PageRank();
    //StarW_Ep3.PageRank();
    //StarW_Ep4.PageRank();
    //StarW_Ep5.PageRank();
    //StarW_Ep6.PageRank();
    //StarW_Ep7.PageRank();
    //StarW_All.PageRank();

    //BicycleT_50.PageRank();
    //BicycleT_100.PageRank();
    //BicycleT_All.PageRank();

    return 0;
}