#include <iostream>
#include <atomic>
#include <map>

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
        NodeKey id = node_count++;
        fact->put_in(owner);
        facts[id] = fact;
        return id;
    }

    void process()
    {
        cout << "Processing " << dirty_keys.size() << "!" << endl;
        for (auto dirty_truth : dirty_keys)
        {
            cout << dirty_truth << endl;
            auto f = facts[dirty_truth];
            cout << f << endl;
            f->evaluate();
        }
    }

    void dirty(NodeKey nk)
    {
        cout << "Dirtying: " << nk << endl;
        if (facts.count(nk) == 0)
        {
            throw "can't dirty a key we don't know";
        }
        dirty_keys.push_back(nk);
    }

    GraphPimpl(Graph& instance) : owner(instance), node_count(0)
    {
    }

    vector<NodeKey> dirty_keys;
    map<NodeKey, Fact_ptr> facts;

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

void Graph::process()
{
    pimpl->process();
}

void Graph::dirty(NodeKey nk)
{
    pimpl->dirty(nk);
}
