#pragma once

#include <string>
#include <vector>

namespace unrav {
class DFAMatcher {
    size_t pattern_length;
    static constexpr int ALPHABET_SIZE = 256;

    std::vector<std::array<int, ALPHABET_SIZE>> dfa;

    void build_dfa(const std::string &pattern) {
        dfa[0][(unsigned char)pattern[0]] = 1;
        int x = 0;

        for (size_t i = 1; i < pattern.size(); i++) {
            dfa[i] = dfa[x];
            dfa[i][(unsigned char)pattern[i]] = i + 1;
            x = dfa[x][(unsigned char)pattern[i]];
        }
    }

   public:
    explicit DFAMatcher(const std::string &needle)
        : pattern_length(needle.size()) {
        if (pattern_length == 0) {
            throw std::invalid_argument("Pattern cannot be empty");
        }

        dfa.resize(pattern_length, {0});
        build_dfa(needle);
    }

    [[nodiscard]] bool contains_in(const std::string &haystack) const {
        int state = 0;

        for (char c : haystack) {
            state = dfa[state][(unsigned char)c];

            if (state == pattern_length) {
                return true;
            }
        }

        return false;
    }
};
};  // namespace unrav
