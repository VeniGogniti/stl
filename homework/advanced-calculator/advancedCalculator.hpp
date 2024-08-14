//
// Created by stefx on 8/8/24.
//

#ifndef ADVANCEDCALCULATOR_ADVANCEDCALCULATOR_HPP
#define ADVANCEDCALCULATOR_ADVANCEDCALCULATOR_HPP

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <regex>
#include <variant>

enum class ErrorCode { OK,
                       BadCharacter,
                       BadFormat,
                       DivideBy0,
                       SqrtOfNegativeNumber,
                       ModuleOfNonIntegerValue };

ErrorCode process(std::string input, double* out);

#endif  // ADVANCEDCALCULATOR_ADVANCEDCALCULATOR_HPP
