#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

int main() {
    std::map<char, std::vector<std::pair<int, int>>> locs;
    
    std::string line;
    int X = 0, Y;
    while (getline(std::cin, line)) {
        int i = X, j = 0;
        for (char c : line) {
            if (c != '.') {
                locs[c].push_back({i, j});
            }
            j += 1;
        }
        X += 1;
        Y = j;
    }
    
    std::set<std::pair<int, int>> nodes;
    for (auto &p : locs) {
        auto &v = p.second;
        for (auto f : v) {
            for (auto s : v) {
                if (f != s) {
                    for (int c = 1; c < 2; c++) { // Use this line for part I
                    // for (int c = 0; c <= X || c <= Y; c++) { // Use this line for part II
                        nodes.emplace((c+1) * f.first - c * s.first, (c+1) * f.second - c * s.second);
                    }
                }
            }
        }
    }
    
    int ans = 0;
    for (auto p : nodes) {
        if (p.first >= 0 && p.first < X && p.second >= 0 && p.second < Y) {
            ans += 1;
        }
    }
    
    std::cout << ans;

    
    return 0;
}
