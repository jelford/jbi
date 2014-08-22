#include <iostream>
#include <memory>

#include "gtest/gtest.h"
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

TEST(Graph, Yields_Ascending_ids)
{
    Graph g;
    auto f = new MockFact();
    auto f_ptr = shared_ptr<Fact>(f);
    EXPECT_CALL(*f, put_in(A<Graph&>())).Times(AtLeast(1));

    auto i = g.insert(f_ptr);
    ASSERT_LT(i, g.insert(f_ptr));
}

TEST(Graph, Notifies_Fact_Of_Insertion_Into_Knowledge_Graph)
{
    Graph g;
    MockFact* f = new MockFact();
    auto f_ptr = shared_ptr<Fact>(f);
    
    EXPECT_CALL(*f, put_in(A<Graph&>())).Times(AtLeast(1));
    g.insert(f_ptr);

}

