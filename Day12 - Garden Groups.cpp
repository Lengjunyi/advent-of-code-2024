#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

std::map<std::pair<int, int>, char> map;
std::set<std::pair<int, int>> visited;
int vx[] = {1, 0, -1, 0};
int vy[] = {0, 1, 0, -1};

std::set<std::pair<std::pair<int, int>, int>> edges;

void dfs(int x, int y, int &area, int &perimeter, char c) {
    if (visited.count({x, y}) != 0) {
        return;
    }
    area += 1;
    visited.emplace(x, y);
    
    for (int d = 0; d < 4; d++) {
        int nx = x + vx[d];
        int ny = y + vy[d];
        if (map[{nx, ny}] != c) {
            perimeter += 1;
            edges.emplace(std::make_pair(x, y), d);
            continue;
        }
        dfs(nx, ny, area, perimeter, c);
    }
}


int main() {
    int i = 0, j;
    std::string line;
    while (getline(std::cin, line)) {
        j = 0;
        for (char c : line) {
            map[{i, j}] = c;
            j++;
        }
        i++;
    }
    
    int ans1 = 0;
    int ans2 = 0;
    
    for (int x = 0; x < i; x++) {
        for (int y = 0; y < j; y++) {
            if (visited.count({x, y}) == 0) {
                int area = 0, perimeter = 0;
                edges = {};
                dfs(x, y, area, perimeter, map[{x, y}]);
                ans1 += area * perimeter;
                int sides = 0;
                while (!edges.empty()) {

                    auto edge = edges.begin();
                    auto loc = edge->first;
                    int d = edge->second;

                    for (int t = 0;; t++) {
                        int nd = (d+1)%4;
                        std::pair<int, int> nloc = {loc.first + t*vx[nd], loc.second + t*vy[nd]};
                        if (edges.count({nloc, d}) != 0) {
                            edges.erase({nloc, d});
                        } else {
                            break;
                        }
                    }
                    for (int t = 1;; t++) {
                        int nd = (d-1)%4;
                        std::pair<int, int> nloc = {loc.first + t*vx[nd], loc.second + t*vy[nd]};
                        if (edges.count({nloc, d}) != 0) {
                            edges.erase({nloc, d});
                        } else {
                            break;
                        }
                    }
                    sides += 1;
                }

                ans2 += sides * area;
            }
        }
    }
    
    std::cout << ans1 << " " << ans2;
    
    return 0;
}
