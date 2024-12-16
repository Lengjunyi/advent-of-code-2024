#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>

std::map<std::pair<int, int>, char> map;

auto cmp = [](std::pair<int, std::pair<int, std::pair<int, int>>> left, std::pair<int, std::pair<int, std::pair<int, int>>> right) { return left.first > right.first; };

std::priority_queue<std::pair<int, std::pair<int, std::pair<int, int>>>, std::vector<std::pair<int, std::pair<int, std::pair<int, int>>>>, decltype(cmp)> pq(cmp);
std::map<std::pair<int, std::pair<int, int>>, int> dis;

std::set<std::pair<int,int>> shortest;

int vx[] = {0, 1, 0, -1};
int vy[] = {1, 0 ,-1, 0};

void backwalk(int x, int y, int d) {
    shortest.emplace(x, y);
    int nd;
    nd = (d+3) % 4;
    if (dis[{nd, {x, y}}] + 1000 == dis[{d, {x, y}}]) {
        backwalk(x, y, nd);
    }
    nd = (d+1) % 4;
    if (dis[{nd, {x, y}}] + 1000 == dis[{d, {x, y}}]) {
        backwalk(x, y, nd);
    }
    int nx = x - vx[d];
    int ny = y - vy[d];
    if (map[{nx, ny}] != '#') {
        if (dis[{d, {nx, ny}}] + 1 == dis[{d, {x, y}}]) {
            backwalk(nx, ny, d);
        }
    }
}

int main() {
    std::string line;
    std::pair<int, int> sloc, eloc;
    int X = 0, Y = 0;
    while (getline(std::cin, line)) {
        Y = 0;
        for (char c : line) {
            if (c == 'S') {
                sloc = {X, Y};
                c = '.';
            } else if (c == 'E') {
                eloc = {X, Y};
                c = '.';
            }
            map[{X,Y}] = c;
            Y++;
        }
        X++;
    }
    
    for (int x = 0; x < X; x++) {
        for (int y = 0; y < Y; y++) {
            for (int d = 0; d < 4; d++) {
                dis[{d, {x, y}}] = 10000000;
            }
        }
    }
    pq.push({0, {0, sloc}});
    dis[{0, sloc}] = 0;
    
    int ed = -1;
    int eprice = -1;
    while (!pq.empty()) {
        auto elem = pq.top();
        int price = elem.first;
        auto pos = elem.second;
        int direction = pos.first;
        auto loc = pos.second;
        pq.pop();
        
        // std::cout <<" " << loc.first << " " << loc.second << " " << direction << " " << price << " :loc"<<pq.size()<< std::endl;
        if (loc == eloc) {
            std::cout << "part 1:" << price <<std::endl;
            ed = direction;
            eprice = price;
            break;
        }
        
        
        int nd;
        nd = (direction+3) % 4;
        if (price + 1000 < dis[{nd, loc}]) {
            int nprice = price + 1000;
            pq.push({nprice, {nd, loc}});
            dis[{nd, loc}] = nprice;
        }
        nd = (direction+1) % 4;
        if (price + 1000 < dis[{nd, loc}]) {
            int nprice = price + 1000;
            pq.push({nprice, {nd, loc}});
            dis[{nd, loc}] = nprice;
        }
        int nx = loc.first + vx[direction];
        int ny = loc.second + vy[direction];
        if (map[{nx, ny}] != '#') {
            if (price + 1 < dis[{direction, {nx, ny}}]) {
                int nprice = price + 1;
                pq.push({nprice, {direction, {nx, ny}}});
                dis[{direction, {nx, ny}}] = nprice;
            }
        }
    }
    
    backwalk(eloc.first, eloc.second, ed);
    std::cout << "part 2:" << shortest.size();
}
