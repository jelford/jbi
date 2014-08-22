#include <iostream>
#include <boost/test/unit_test.hpp>
#include <memory>

#include "graph.hpp"

using namespace std;
using namespace jbi_graph;

BOOST_AUTO_TEST_SUITE(test_suite_one)

BOOST_AUTO_TEST_CASE(test1)
{
    Graph g;
    g.insert(NULL);
}

BOOST_AUTO_TEST_SUITE_END()
