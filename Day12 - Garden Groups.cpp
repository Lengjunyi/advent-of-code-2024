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

void dfs(int x, int y, int &area, int &perimeter, int &sides, char c) {
    if (visited.count({x, y}) != 0) {
        return;
    }
    area += 1;
    visited.emplace(x, y);
    
    for (int d = 0; d < 4; d++) {
        int nx = x + vx[d];
        int ny = y + vy[d];
        if (map[{nx, ny}] != c) {
            int nd = (d+1)%4;
            if (map[{x+vx[nd], y+vy[nd]}] != c) {
                sides += 1;
            } else if (map[{nx+vx[nd], ny+vy[nd]}] == c) {
                sides += 1;
            }
            perimeter += 1;
            continue;
        }
        dfs(nx, ny, area, perimeter, sides, c);
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

    int ans1 = 0, ans2 = 0;
    
    for (int x = 0; x < i; x++) {
        for (int y = 0; y < j; y++) {
            if (visited.count({x, y}) == 0) {
                int area = 0, perimeter = 0, sides = 0;
                dfs(x, y, area, perimeter, sides, map[{x, y}]);
                ans1 += area * perimeter;
                ans2 += area * sides;
            }
        }
    }
    
    std::cout << ans1 << " " << ans2;
    
    return 0;
}
