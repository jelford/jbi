#include <iostream>
#include <boost/test/unit_test.hpp>

#include "graph.hpp"

using namespace std;
using namespace jbi_graph;

BOOST_AUTO_TEST_SUITE(test_suite_one)

BOOST_AUTO_TEST_CASE(test1)
{
    Graph g;
    BOOST_REQUIRE(1 == 2);
}

BOOST_AUTO_TEST_SUITE_END()
