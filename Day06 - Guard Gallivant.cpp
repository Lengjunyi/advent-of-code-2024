#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>

int getVisited(int x, int y, int M, int N, std::set<std::pair<int, int>> &grids, std::set<std::pair<int, int>> &visited) {
    int dir = 0;
    int vxs[] = {-1, 0, 1, 0};
    int vys[] = {0, 1, 0, -1};
    
    std::map<std::pair<int, int>, int> visited_with_dir;
    
    while (x >=0 && x < M && y >= 0 && y < N) {
        visited.emplace(x, y);
        if ((1 << dir) & visited_with_dir[std::make_pair(x, y)]) {
            return -1;
        }
        visited_with_dir[std::make_pair(x, y)] |= (1 << dir);
        
        int nx = x + vxs[dir];
        int ny = y + vys[dir];
        
        if (grids.count(std::make_pair(nx, ny))) {
            dir = (dir + 1) % 4;
        } else {
            x = nx;
            y = ny;
        }
    }
    
    return visited.size();
}

int main() {
    std::set<std::pair<int, int>> grids;
    
    int M = 0;
    int N = 0;
    
    int x, y;
    
    std::string line;
    while (getline(std::cin, line)) {
        N = line.size();
        
        for (int j = 0; j < N; j++) {
            if (line[j] == '#') {
                grids.emplace(M, j);
            }
            if (line[j] == '^') {
                x = M;
                y = j;
            }
        }
        
        M += 1;
    }
    std::set<std::pair<int, int>> visited;
    int ans1 = getVisited(x, y, M, N, grids, visited);
    int ans2 = 0;
    
    for (auto p : visited) {
        int i = p.first;
        int j = p.second;
        if (grids.count(std::make_pair(i, j))) {
            continue;
        }
        if (i == x && j == y) {
            continue;
        }
        std::set<std::pair<int, int>> visited;
        grids.emplace(i, j);
        if (getVisited(x, y, M, N, grids, visited) < 0) {
            ans2 += 1;
        }
        grids.erase({i, j});
    }
    
    std::cout << ans1 << " " << ans2;
    
    return 0;
}
