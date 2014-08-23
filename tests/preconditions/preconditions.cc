#include <iostream>
#include <memory>
#include <map>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "preconditions.hpp"

using namespace std;
using namespace jbi_preconditions;
using namespace testing;

namespace {
}

TEST(Preconditions, Get_From_Map_Returns_Map_Entry)
{
    map<int, int> m;
    m[1] = 1;

    ASSERT_EQ(1, get(m, 1));
}

TEST(Preconditions, Get_From_Map_Throws_When_Value_Not_Present)
{
    map<int, int> m;
    m[1] = 1;
    ASSERT_ANY_THROW(get(m, 5));
}
