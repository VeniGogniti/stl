#include "vowel.hpp"

std::vector<std::string> removeVowels(std::vector<std::string>& newVowels){
    std::string wyraz = "AEIUOYaeiouy";

    for (auto& it : newVowels) {
        it.erase(std::remove_if(it.begin(), it.end(), [](char c) {
                    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y';
                }),
                it.end());
    }
    return newVowels;

}
