#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string> &myString) {
    std::deque<std::string> deqSorted {};

    for (auto& it : myString) {
        deqSorted.emplace_back(it);
    }
    std::sort(deqSorted.begin(), deqSorted.end(), [](const std::string& compareA, const std::string& compareB) {
        if (compareA.length() == compareB.length()) {
            return compareA < compareB;
        }
        return compareA.length() < compareB.length();
    });

    return deqSorted;
}
