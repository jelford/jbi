#ifndef JBI_GRAPH_HPP
#define JBI_GRAPH_HPP

#include <vector>
#include <memory>

#include "fact.hpp"

namespace jbi_graph {

class GraphPimpl;

typedef int NodeKey;

class Graph
{
    private:
        std::vector<Fact_ptr> facts;
        std::unique_ptr<GraphPimpl> pimpl;

    public:
        NodeKey insert(Fact_ptr new_fact);
        Graph();

        ~Graph();
};


}

#endif
