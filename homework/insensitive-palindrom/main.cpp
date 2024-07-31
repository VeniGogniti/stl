#include <algorithm>
#include <string>
#include "main.hpp"

bool is_palindrome(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    
    s.erase(std::remove_if(s.begin(), s.end(), [](char c) {
                return !std::isalnum(c);
                }), s.end());
    
    std::string reversed = s;
    std::reverse(reversed.begin(), reversed.end());

    return s == reversed;
}
