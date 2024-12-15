#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

std::map<std::pair<int, int>, char> map;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

std::vector<std::pair<int, int>> moveList;

bool move(int x, int y, int d) {
    // switch (map[{x, y}]) {
    //     case '#':
    //         return false;
    //     case '.':
    //         return true;
    //     default:
    //         int nx = x + dx[d];
    //         int ny = y + dy[d];
    //         if (move(nx, ny, d)) {
    //             map[{nx, ny}] = map[{x, y}];
    //             map[{x, y}] = '.';
    //             return true;
    //         }
    //         return false;
    // }
    
    if (std::find(moveList.begin(), moveList.end(), std::make_pair(x, y)) != moveList.end()) {
        return true;
    }
    
    int nx = x + dx[d];
    int ny = y + dy[d];
    switch (map[{x, y}]) {
        case '#':
            return false;
        case '.':
            return true;
        case '@':
            moveList = {};
            if (move(nx, ny, d)) {
                moveList.push_back({x, y});
                return true;
            } else {
                return false;
            }
        case '[':
            if (move(nx, ny, d)) {
                moveList.push_back({x, y});
                if (d%2 == 1 || move(x, y+1, d)) {
                    return true;
                }
            }
            return false;
        case ']':
            if (move(nx, ny, d)) {
                moveList.push_back({x, y});
                if (d%2 == 1 || move(x, y-1, d)) {
                    return true;
                }
            }
            return false;
    }
    return false;
}

int main() {
    std::string line;
    long total = 0;
    
    
    
    int X = 0, Y = 0;
    while (getline(std::cin, line)) {
        if (line == "") {
            break;
        }
        Y = 0;
        for (char c : line) {
            // map[{X, Y}] = c;
            // Y++;
            switch (c) {
                case '#':
                    map[{X, Y}] = '#';
                    Y++;
                    map[{X, Y}] = '#';
                    Y++;
                    break;
                case 'O':
                    map[{X, Y}] = '[';
                    Y++;
                    map[{X, Y}] = ']';
                    Y++;
                    break;
                case '.':
                    map[{X, Y}] = '.';
                    Y++;
                    map[{X, Y}] = '.';
                    Y++;
                    break;
                case '@':
                    map[{X, Y}] = '@';
                    Y++;
                    map[{X, Y}] = '.';
                    Y++;
                    break;
            }
        }
        X++;
    }
    
    while (getline(std::cin, line)) {
        for (char c : line) {
            int sx = -1, sy = -1;
            for (auto p : map) {
                if (p.second == '@') {
                    sx = p.first.first;
                    sy = p.first.second;
                }
            }
            if (sx == -1) {
                return -1;
            }

            moveList = {};
            int d = 0;
            switch (c) {
                case 'v':
                    d = 0;
                    break;
                case '<':
                    d = 1;
                    break;
                case '^':
                    d = 2;
                    break;
                case '>':
                    d = 3;
                    break;
            }
            
            if (move(sx, sy, d)) {
                for (auto p : moveList) {
                    int x = p.first;
                    int y = p.second;
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    map[{nx, ny}] = map[{x, y}];
                    map[{x, y}] = '.';
                }
            }
        }
    }
    int ans = 0;
    for (auto p : map) {
        // if (p.second == 'O') {
        if (p.second == '[') {
            int v = 100 * p.first.first + p.first.second;
            ans += v;
        }
    }
    std::cout << ans;
}
