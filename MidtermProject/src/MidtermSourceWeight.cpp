// Reference : Algoritm.BellmanFord

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

struct node
{
    int n_visited;                       // No. of visited this node
    int n_neighbors;                     // No. of neighbors
    int id;                              // node identifier
    int sum_weight;                      // sum of to neighbor weight
    float pageRankVal;                   // Current node PageRankVal
    string name;                         // string name of this node
    vector<pair<node *, int>> neighbors; // neighbors node address container
};

class Graph
{
    int nodeNum;             // No. of nodes
    vector<node *> nodes;    // vector container for nodes
    vector<int> id2IdxTable; // to find index from file node id. first: id from file, second : idx from vector

public:
    Graph(string filename); // Constructor
    ~Graph();
    void LoadEdge(string filename, bool opt);                   // load edge file
    void AddEdge(int source, int target, int weight, bool opt); //adding edge
    int Id2Idx(int n);                                          // convert file node id to vector node id
    void RandomWalker(int i, int n, float q);                   // i : starting node, n : walking length, q : probability jumping to random node
    int PageRank(int i, int n, float q);                        // cal pagerank
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

        temp->n_visited = 0;
        temp->id = std::stoi(id); //first col
        temp->pageRankVal = 0;
        temp->name = name; //second col
        temp->n_neighbors = 0;
        temp->sum_weight = 0;

        nodes.push_back(temp);
        id2IdxTable.push_back(std::stoi(id));
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
void Graph::AddEdge(int source, int target, int weight, bool opt) //opt: whether interdirectional
{
    nodes[source]->neighbors.push_back({nodes[target], weight});
    nodes[source]->n_neighbors++;
    nodes[source]->sum_weight += weight;

    if (opt == true)
    {
        vector<pair<node *, int>>::iterator it;
        for (it = nodes[target]->neighbors.begin(); it != nodes[target]->neighbors.end(); it++)
        {
            if ((*it).first == nodes[source])
                break;
        }
        if (it == nodes[target]->neighbors.end())
        {
            nodes[target]->neighbors.push_back({nodes[source], weight});
            nodes[target]->n_neighbors++;
            nodes[target]->sum_weight += weight;
        }
    }
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
void Graph::LoadEdge(string filename, bool opt) //opt: whether interdirectional
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

        int idxS = Id2Idx(std::stoi(source)); // Vector index of node source
        int idxT = Id2Idx(std::stoi(target)); // Vector index of node target
        int valW = std::stoi(weight);

        AddEdge(idxS, idxT, valW, opt);
    }

    ifs.close();
/*
    for (vector<node *>::iterator it = nodes.begin(); it != nodes.end(); it++)
    {
        cout << "id : " << (*it)->id << endl             << "neighbors : ";
        for (vector<pair<node *, int>>::iterator tt = (*it)->neighbors.begin(); tt != (*it)->neighbors.end(); tt++)
            cout << (*tt).first->id << " ";
        cout << endl             << endl;
    }*/
}

////////////////////////////////////////
////////         Task 1         ////////
//////// implement RandomWalker ////////
////////////////////////////////////////

//todo
void Graph::RandomWalker(int i, int n, float q) // i : starting node, n : walking length, q : probability jumping to random node
{
    int random = 0;
    int random_node = 0;
    int q_percent = q * 100;
    node *ptr;
    ptr = nodes[i];

    int sum = 0;
    vector<pair<node*, int>>::iterator it;

    while (n > 0)
    {
        random = rand() % 100;
        if ((random <= q_percent) | (ptr->n_neighbors == 0)) //random node pick
        {
            random_node = rand() % nodeNum;
            ptr = nodes[random_node];
        }
        else // pick node from neighbors
        {
            sum = 0;
            random_node = rand() % ptr->sum_weight;
            //sum weight 아래로 돌면서 계속 합을 구해나감. 만약 합이 random_node값보다 커지는 경우 그 때가 그때다!
            for(it = ptr->neighbors.begin(); (it != ptr->neighbors.end()) && (sum < random_node);it++)
            {
                sum += (*it).second;
            }
            if(it == ptr->neighbors.end())
                it--;
            ptr = (*it).first;
            //for (int i = 0; i < ptr->sum_weight;)   
        }
        ptr->n_visited++;
        n--;
    }
}

/////////////////////////////////////////
////////          Task 2         ////////
//////// implement PageRank func ////////
/////////////////////////////////////////

//todo
int Graph::PageRank(int i, int n, float q)
{
    vector<pair<float, int>> rank;
    RandomWalker(i, n, q);

    for (vector<node *>::iterator it = nodes.begin(); it != nodes.end(); it++)
    {
        (*it)->pageRankVal = (float)((*it)->n_visited) / (float)n;
        rank.push_back({(*it)->pageRankVal, (*it)->id});
    }
    sort(rank.begin(), rank.end());

    for (vector<pair<float, int>>::iterator it = rank.begin(); it != rank.end(); it++)
    {
        cout << "id : " << (*it).second << "\tpageRankValue : " << (*it).first << endl;
    }
}

/////////////////////////////////////
////////       Task 3        ////////
//////// test from real data ////////
/////////////////////////////////////

//todo
int main()
{
    srand(time(0));
    // First. open node file
    //Graph StarW_Ep1 = Graph("./dataset/starwars/starwars-episode-1-interactions-allCharacters-nodes.tsv");
    //Graph StarW_Ep2 = Graph("./dataset/starwars/starwars-episode-2-interactions-allCharacters-nodes.tsv");
    //Graph StarW_Ep3 = Graph("./dataset/starwars/starwars-episode-3-interactions-allCharacters-nodes.tsv");
    //Graph StarW_Ep4 = Graph("./dataset/starwars/starwars-episode-4-interactions-allCharacters-nodes.tsv");
    //Graph StarW_Ep5 = Graph("./dataset/starwars/starwars-episode-5-interactions-allCharacters-nodes.tsv");
    //Graph StarW_Ep6 = Graph("./dataset/starwars/starwars-episode-6-interactions-allCharacters-nodes.tsv");
    //Graph StarW_Ep7 = Graph("./dataset/starwars/starwars-episode-7-interactions-allCharacters-nodes.tsv");
    //Graph StarW_All = Graph("./dataset/starwars/starwars-full-interactions-allCharacters-nodes.tsv");
    //
    Graph BicycleT_50 = Graph("./dataset/bicycle/station_names.tsv");
    //Graph BicycleT_100 = Graph("./dataset/bicycle/station_names.tsv");
    //Graph BicycleT_All = Graph("./dataset/bicycle/station_names.tsv");

    // Second. open datafile. second parameter : if true : interdirectional, false : bidirectional
    //StarW_Ep1.LoadEdge("./dataset/starwars/starwars-episode-1-interactions-allCharacters-links.tsv", true);
    //StarW_Ep2.LoadEdge("./dataset/starwars/starwars-episode-2-interactions-allCharacters-links.tsv", true);
    //StarW_Ep3.LoadEdge("./dataset/starwars/starwars-episode-3-interactions-allCharacters-links.tsv", true);
    //StarW_Ep4.LoadEdge("./dataset/starwars/starwars-episode-4-interactions-allCharacters-links.tsv", true);
    //StarW_Ep5.LoadEdge("./dataset/starwars/starwars-episode-5-interactions-allCharacters-links.tsv", true);
    //StarW_Ep6.LoadEdge("./dataset/starwars/starwars-episode-6-interactions-allCharacters-links.tsv", true);
    //StarW_Ep7.LoadEdge("./dataset/starwars/starwars-episode-7-interactions-allCharacters-links.tsv", true);
    //StarW_All.LoadEdge("./dataset/starwars/starwars-full-interactions-allCharacters-links.tsv", true);
    //
    BicycleT_50.LoadEdge("./dataset/bicycle/bicycle_trips_over_50.tsv", false);
    //BicycleT_100.LoadEdge("./dataset/bicycle/bicycle_trips_all.tsv", false);
    //BicycleT_All.LoadEdge("./dataset/bicycle/bicycle_trips_all.tsv", false);

    //Last. let RandomWalker run and get PageRank
    //StarW_Ep1.PageRank(10, 300000, 0.9);
    //StarW_Ep2.PageRank(50, 200, 0.3);
    //StarW_Ep3.PageRank(50, 200, 0.3);
    //StarW_Ep4.PageRank(50, 200, 0.3);
    //StarW_Ep5.PageRank(50, 200, 0.3);
    //StarW_Ep6.PageRank(50, 200, 0.3);
    //StarW_Ep7.PageRank(50, 200, 0.3);
    //StarW_All.PageRank(50, 200, 0.3);
    //
    BicycleT_50.PageRank(50, 30000000, 0.7);
    //BicycleT_100.PageRank(50, 200, 0.3);
    //BicycleT_All.PageRank(50, 200, 0.3);

    return 0;
}