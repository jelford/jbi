#include <iostream>
#include <boost/test/unit_test.hpp>
#include <memory>

#include "gmock/gmock.h"

#include "graph.hpp"
#include "fact.hpp"

using namespace std;
using namespace jbi_graph;
using namespace testing;

namespace {
    class MockFact : public Fact
    {
        public:
        MOCK_METHOD1(put_in, void(Graph& graph));
    };
}

BOOST_AUTO_TEST_SUITE(test_suite_one)

BOOST_AUTO_TEST_CASE(test1)
{
    Graph g;
    MockFact* f = new MockFact();
    auto f_ptr = shared_ptr<Fact>(f);
    
    EXPECT_CALL(*f, put_in(A<Graph&>())).Times(AtLeast(1));
    g.insert(f_ptr);

    f_ptr.reset();
}

BOOST_AUTO_TEST_SUITE_END()
