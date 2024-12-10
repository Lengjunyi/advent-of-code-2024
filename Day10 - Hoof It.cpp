#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

int main() {
    std::vector<std::string> map;
    
    std::string line;
    while (getline(std::cin, line)) {
        map.emplace_back(line);
    }
    
    std::map<std::pair<int, int>, int> values;
    
    for (char cur = '9'; cur >= '0'; cur--) {
        std::map<std::pair<int, int>, int> new_values;
        for (int i = 0; i < map.size(); i++) {
            for (int j = 0; j < map[i].size(); j++) {
                if (map[i][j] == cur) {
                    std::cout << cur;
                    if (cur == '9') {
                        new_values[{i, j}] = 1;
                    }
                    int dx[] = {0, 1, 0, -1};
                    int dy[] = {1, 0, -1, 0};
                    for (int d = 0; d < 4; d++) {
                        new_values[{i, j}] += values[{i+dx[d], j+dy[d]}];
                    }
                    std::cout << " " << new_values[{i,j}]<<std::endl;
                }
            }
        }
        values = new_values;
    }
    
    int ans = 0;
    for (auto p : values) {
        ans += p.second;
    }
    
    std::cout <<" "<<ans;
}

// Below is part 1 and part 2 above was solved first by mistake
// int main() {
//     std::vector<std::string> map;
    
//     std::string line;
//     while (getline(std::cin, line)) {
//         map.emplace_back(line);
//     }
    
//     std::map<std::pair<int, int>, std::set<std::pair<int, int>>> values;
    
//     for (char cur = '9'; cur >= '0'; cur--) {
//         std::map<std::pair<int, int>, std::set<std::pair<int, int>>> new_values;
//         for (int i = 0; i < map.size(); i++) {
//             for (int j = 0; j < map[i].size(); j++) {
//                 if (map[i][j] == cur) {
//                     if (cur == '9') {
//                         new_values[{i, j}].emplace(i, j);
//                     }
//                     int dx[] = {0, 1, 0, -1};
//                     int dy[] = {1, 0, -1, 0};
//                     for (int d = 0; d < 4; d++) {
//                         auto &v = values[{i+dx[d], j+dy[d]}];
//                         new_values[{i, j}].insert(v.begin(), v.end());
//                     }
//                 }
//             }
//         }
//         values = new_values;
//     }
    
//     int ans = 0;
//     for (auto p : values) {
//         ans += p.second.size();
//     }
    
//     std::cout <<" "<<ans;
// }
