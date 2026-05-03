#include <iostream>
#include <unrav/dfa_matcher.hpp>

int main() {
    unrav::DFAMatcher matcher("hello");

    std::string text = "well hello there, world!";

    if (matcher.contains_in(text)) {
        std::cout << "Match found!\n";
    } else {
        std::cout << "No match.\n";
    }

    return 0;
}
