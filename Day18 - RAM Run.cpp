#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>


std::vector<std::pair<int, int>> partial;

int N = 70;

int go(int count) {
    std::set<std::pair<int, int>> map;
    for (int i = 0; i <= count; i++){
        map.emplace(partial[i]);
    }
    std::map<std::pair<int, int>, int> dis;
    dis[{0, 0}] = 1;
    std::vector<std::pair<int, int>> q = {{0, 0}};

    for (int i = 0; i < q.size(); i++) {
        auto p = q[i];
        int x = p.first;
        int y = p.second;
        int vx[] = {1, 0, -1, 0};
        int vy[] = {0, 1, 0, -1};

        for (int d = 0; d<4;d++) {
            int nx = p.first + vx[d];
            int ny = p.second + vy[d];
            if (dis[{nx, ny}] != 0) {
                continue;
            }
            if (map.count({nx, ny}) != 0) {
                continue;
            }
            int N = 70;
            if (nx >N || ny > N || nx < 0 || ny < 0) {
                continue;
            }
            dis[{nx, ny}] = dis[{x, y}] + 1;
            q.push_back({nx,ny});
        }
    }
    return dis[{N,N}] - 1;
}



int main() {
    std::string s;
    while(getline(std::cin, s)) {
        std::stringstream strm(s);
        
        int a, b;
        strm >> a;
        strm.ignore(100, ',');
        strm >> b;
        partial.emplace_back(a, b);
    }
    
    std::cout << go(1024) << std::endl;
    
    int left = 0;
    int right = partial.size();
    
    while (left < right) {
        int mid = (left + right) / 2;
        std::set<std::pair<int, int>> map;

        if (go(mid) != -1) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    std::cout << partial[left].first << "," << partial[left].second;
}
