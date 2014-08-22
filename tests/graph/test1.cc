#include <iostream>
#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_SUITE(test_suite_one)

BOOST_AUTO_TEST_CASE(test1)
{
    cout << "hello from tests1" << endl;
}

BOOST_AUTO_TEST_SUITE_END()
