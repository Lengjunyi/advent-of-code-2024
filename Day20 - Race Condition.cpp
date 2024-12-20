#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

int main() {
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

	std::string line;
	std::map<std::pair<int, int>, char> map;

    int X = 0;
    int Y = 0;
	while (std::getline(std::cin, line)) {
	    Y = 0;
	    for (char c : line) {
	        map[{X, Y}] = c;
	        Y++;
	    }
	    X++;
	}
	
	std::pair<int, int> end;
	
	for (int i = 0; i < X; i++) {
	    for (int j = 0; j < Y; j++) {
	        if (map[{i, j}] == 'E') {
	            end = {i, j};
	            std::cout << end.first << " " <<end.second <<std::endl;
	        }
	    }
	}
	
	// flood-fill
	std::vector<std::pair<int, int>> queue;
	std::map<std::pair<int, int>, int> dis;
	queue.push_back(end);
	dis[end] = 1;
	
	for (int i = 0; i < queue.size(); i++) {
	    auto loc = queue[i];
	    for (int d = 0; d < 4; d++) {
	        int nx = loc.first + dx[d];
	        int ny = loc.second + dy[d];
	        if (map[{nx, ny}] == '#') {
	            continue;
	        }
	        if (dis[{nx, ny}] == 0) {
	            dis[{nx, ny}] = dis[loc] + 1;
	            queue.push_back({nx, ny});
	        }
	    }
	}
	
	std::map<int, int> counter;
	
	for (int x = 0; x < X; x++) {
	    for (int y = 0; y < Y; y++) {
	        std::pair<int, int> preloc = {x, y};
	        if (map[preloc] == '#') {
	            continue;
	        }
	       // int total = 2;
	        int total = 20;
	        for (int nx = x - total; nx <= x + total; nx++) {
	            for (int ny = y - total; ny <= y + total; ny++) {
	                if (nx < 0 || nx >= X || ny < 0 || ny >= Y) {
	                    continue;
	                }
	                if (std::abs(nx - x) + std::abs(ny - y) > total) {
	                    continue;
	                }
	                
	                if (map[{nx, ny}] == '#') {
	                    continue;
	                }
	                int predis = dis[{x, y}];
	                int postdis = std::abs(nx - x) + std::abs(ny - y) + dis[{nx, ny}];
	                counter[predis - postdis] += 1;
	            }
	        }
	    }
	}

	int ans = 0;
	for (auto p : counter) {
	   // std::cout << p.first << " " << p.second << std::endl;
	    if (p.first >= 100) {
	        ans += p.second;
	    }
	}
	std::cout << ans;
}
