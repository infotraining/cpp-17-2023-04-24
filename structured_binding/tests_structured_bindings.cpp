#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

tuple<int, int, double> calc_stats(const vector<int>& data)
{
    vector<int>::const_iterator min, max;
    tie(min, max) = minmax_element(data.begin(), data.end());

    double avg = accumulate(data.begin(), data.end(), 0.0) / data.size();

    return make_tuple(*min, *max, avg);
}

TEST_CASE("Before C++17")
{
    vector<int> data = {4, 42, 665, 1, 123, 13};

    int min, max;
    double avg;

    tie(min, max, avg) = calc_stats(data);

    REQUIRE(min == 1);
    REQUIRE(max == Catch::Approx(665));
    REQUIRE(avg == Catch::Approx(141.333));
}