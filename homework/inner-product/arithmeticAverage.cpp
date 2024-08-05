#include "arithmeticAverage.hpp"
#include <numeric>
#include <algorithm>
#include <iostream>
#include <cmath>


double ArithmeticAverage(std::vector<int> first, std::vector<int> second) {
    std::vector<double> result(first.size());
    std::transform(first.begin(), first.end(), second.begin(), result.begin(),
            [](auto it1, auto it2){return static_cast<double> (it1 + it2); });

    double total_result = std::accumulate(result.begin(), result.end(), 0.0);

    double average = total_result / (first.size() + second.size());

    return average;
}

double Distance(std::vector<int> first, std::vector<int> second) {
    std::vector<double> result(first.size());
    std::transform(first.begin(), first.end(), second.begin(), result.begin(),
            [](auto it1, auto it2){return std::pow(it1 - it2, 2);});

    double range = std::accumulate(result.begin(), result.end(), 0.0);
    return std::sqrt(range);
}
