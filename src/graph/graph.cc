#include <iostream>
#include <atomic>
#include <map>

#include "preconditions.hpp"
#include "graph.hpp"

using namespace std;
using namespace jbi_graph;
using namespace jbi_preconditions;

class jbi_graph::GraphPimpl
{
    friend Graph;

    Graph& owner;
    atomic_int node_count;

    NodeKey insert(Fact_ptr fact)
    {
        NodeKey id = node_count++;
        fact->put_in(owner);
        facts[id] = fact;
        return id;
    }

    void process()
    {
        for (auto dirty_truth : dirty_nodes)
        {
            dirty_truth->evaluate();
        }
    }

    void dirty(NodeKey nk)
    {
        dirty_nodes.push_back(get(facts, nk));
    }

    GraphPimpl(Graph& instance) : owner(instance), node_count(0)
    {
    }

    vector<Fact_ptr> dirty_nodes;
    map<NodeKey, Fact_ptr> facts;

    public:
    ~GraphPimpl() { }
};

Graph::Graph() : pimpl(new GraphPimpl(*this)) { }
Graph::~Graph() {} 

NodeKey Graph::insert(Fact_ptr fact)
{
    return pimpl->insert(fact);
}

void Graph::process()
{
    pimpl->process();
}

void Graph::dirty(NodeKey nk)
{
    pimpl->dirty(nk);
}
