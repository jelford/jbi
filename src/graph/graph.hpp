#ifndef JBI_GRAPH_HPP
#define JBI_GRAPH_HPP

#include <vector>


#include "fact.hpp"

namespace jbi_graph {

class Graph
{
    private:
        std::vector<Fact_ptr> facts;

    public:
        void insert(Fact_ptr new_fact);
};


}

#endif
