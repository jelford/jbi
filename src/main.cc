#include <iostream>
#include <memory>
#include "graph.hpp"
#include "fact.hpp"

using namespace std;
using namespace jbi_graph;

int main(int const argc, char const * const * const argv)
{
    cout << "Hello, world" << endl;
    Graph g;
    g.insert(shared_ptr<Fact>(new Fact()));
}
