#include "advancedCalculator.hpp"

ErrorCode process(std::string input, double* out) {
    input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
    std::regex regex1(R"([#@&?q\\[\]=;])");
    std::smatch match;
    auto token_begin = std::sregex_iterator(input.begin(), input.end(), regex1);
    auto token_end = std::sregex_iterator();

    if (token_begin != token_end) {
        return ErrorCode::BadCharacter;
    }

    std::map<char, std::function<double(double, double)>> myFunction;
    myFunction['+'] = [](auto a, auto b) { return a + b; };
    myFunction['-'] = [](auto a, auto b) { return a - b; };
    myFunction['/'] = [](auto a, auto b) { return a / b; };
    myFunction['*'] = [](auto a, auto b) { return a * b; };
    myFunction['^'] = [](auto a, auto b) { return std::pow(a, b); };
    myFunction['%'] = [](auto a, auto b) { return static_cast<int>(a) % static_cast<int>(b); };
    myFunction['$'] = [](double a, double b) { return std::pow(a, 1 / double(b)); };

    std::map<char, std::function<double(double)>> unaryFunction;
    unaryFunction['!'] = [](auto a) { return (a < 0) ? -std::tgamma(-a + 1) : std::tgamma(a + 1); };

    bool operatorFounded = false;
    char operators;
    std::string firstString{};
    std::string secondString{};

    for (auto& it: input) {
        if (!operatorFounded) {
            if (firstString.size() < 1 && it == '-' || it == '.' || std::isdigit(it) && !operatorFounded) {
                firstString += it;
            } else if (firstString.size() != 0 && !operatorFounded && it == '+' || it == '-' || it == '*' || it == '/' || it == '^' || it == '!' || it == '%' || it == '$') {
                operators = it;
                operatorFounded = true;
            } else {
                return ErrorCode::BadFormat;
            }
        } else if (std::isdigit(it) || it == '-' || it == '.') {
            secondString += it;
        } else {
            return ErrorCode::BadFormat;
        }
    }

    int copy = 0;
    for (auto& iter : firstString) {
        if (iter == '.') {
            ++copy;
        }
        if (copy >= 2) {
            return ErrorCode::BadFormat;
        }
    }

    for (auto& iter : secondString) {
        if (operators == '!' && secondString.size() > 2) {
            return ErrorCode::BadFormat;
        } else if (operators == '/' && std::stod(secondString) == 0) {
            return ErrorCode::DivideBy0;
        } else if (operators == '%' && std::stod(secondString) < 1 && std::stod(secondString) >= 0) {
            return ErrorCode::ModuleOfNonIntegerValue;
        }
    }

    if (operators != '!') {
        *out = myFunction[operators](std::stod(firstString), std::stod(secondString));
        if (operators == '$' && *out < 0) {
            std::cout << *out;
            return ErrorCode::SqrtOfNegativeNumber;
        }
    } else {
        *out = unaryFunction[operators](std::stod(firstString));
    }

    return ErrorCode::OK;
}