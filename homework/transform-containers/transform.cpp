#include "transform.hpp"

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> list, std::deque<int> deq) {
    list.sort();
    list.unique();

    std::sort(deq.begin(), deq.end());
    deq.erase(std::unique(deq.begin(), deq.end()), deq.end());

    std::map<int, std::string> result;
    auto iter = list.begin();
    std::transform(deq.begin(), deq.end(), std::inserter(result, result.end()), [&](auto i) { return std::make_pair(i, *iter++); });
 return result; 
}
