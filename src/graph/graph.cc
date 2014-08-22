#include <iostream>
#include <atomic>

#include "graph.hpp"

using namespace std;
using namespace jbi_graph;

class jbi_graph::GraphPimpl
{
    friend Graph;

    Graph& owner;
    atomic_int node_count;

    NodeKey insert(Fact_ptr fact)
    {
        fact->put_in(owner);
        return node_count++;
    }
    

    GraphPimpl(Graph& instance) : owner(instance), node_count(0)
    {
    }

    public:
    ~GraphPimpl() { }
};

Graph::Graph() : pimpl(new GraphPimpl(*this)) { }
Graph::~Graph() {} 

NodeKey Graph::insert(Fact_ptr fact)
{
    cout << "Graph::insert" << endl;
    return pimpl->insert(fact);
}
