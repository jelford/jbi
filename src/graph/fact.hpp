#ifndef JBI_GRAPH_FACT_HPP
#define JBI_GRAPH_FACT_HPP

#include <memory>

namespace jbi_graph {

class Graph;

class Fact
{
    public:
    virtual void put_in(Graph& graph) = 0;
    virtual void evaluate() = 0;
    virtual ~Fact() {} 
};

typedef std::shared_ptr<Fact> Fact_ptr;

}

#endif
