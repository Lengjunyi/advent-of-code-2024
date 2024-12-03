#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <regex>

int main() {
    int ans1 = 0;
    int ans2 = 0;

    bool enabled = true;    
    std::string line;
    while (getline(std::cin, line)) {
        std::regex word_regex("mul\\(([0-9]+),([0-9]+)\\)|do\\(\\)|don't\\(\\)");
        std::smatch res;
        while (std::regex_search(line, res, word_regex)) {
            if (res[0] == "do()") {
                enabled = true;
            } else if (res[0] == "don't()"){
                enabled = false;
            } else {
                int a = std::stoi(res[1]);
                int b = std::stoi(res[2]);
                ans1 += a * b;
                if (enabled) {
                    ans2 += a*b;
                }
            }
            line = res.suffix();
        }
    }
    std::cout << ans1 << " " << ans2 << std::endl;

    return 0;
}
