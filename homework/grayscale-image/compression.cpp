#include <vector>
#include <array>
#include <cstdint>
#include "compression.hpp"
#include <iostream>
#include <utility>
#include <vector>
#include <cstddef>

//constexpr size_t width = 32;
//constexpr size_t height = 32;

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>& myFunction) {
    std::vector<std::pair<uint8_t, uint8_t>> result;
    uint8_t counter = 0;
    uint8_t character = myFunction[0][0];

    for (int i = 0; i < myFunction.size(); i++) {
        for (int j = 0; j < myFunction[i].size(); j++) {
            if (myFunction[i][j] == character) {
                counter++;
            } else {
                result.push_back(std::make_pair(character, counter)); 
                counter = 0;
                character = myFunction[i][j];
                counter++;
            }
        }
        if (counter != 0) {
            result.push_back(std::make_pair(character, counter));
            counter = 0;
            if (i + 1 != myFunction.size()) {
                character = myFunction[i + 1][0];
            }
        }
    }
return result;

}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& decMyFunction) {
    std::array<std::array<uint8_t, width>, height> result{}; 
    size_t row = 0, col = 0;
    for (const auto& [value, count] : decMyFunction) {
        for (uint8_t c = 0; c < count; ++c) {
            if (col == width) {
                col = 0;
                ++row;
            }
            if (row == height) {
                return result;
            }
            result[row][col] = value;
            ++col;
        }
    }
    return result;
}


