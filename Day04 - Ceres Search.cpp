#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

int main() {
    std::vector<std::string> maze;
    
    std::string line;
    while (getline(std::cin, line)) {
        maze.push_back(line);
    }
    
    int M = maze.size();
    int N = maze[0].size();
    
    std::string target = "XMAS";
    
    int vxs[] = {1, 0, -1, 0, 1, 1, -1, -1};
    int vys[] = {0, 1, 0, -1, 1, -1, 1, -1};
    
    int ans = 0;
    
    for (int xs = 0; xs < M; xs++) {
        for (int ys = 0; ys < N; ys++) {
            if (false) {
                // Part 1
                for (int d = 0; d < 8; d++) {
                    int vx = vxs[d];
                    int vy = vys[d];
                    
                    if (xs + vx*3 < 0 || xs + vx*3 >= M) {
                        continue;
                    }
                    if (ys + vy*3 < 0 || ys + vy*3 >= N) {
                        continue;
                    }
    
                    int v = 1;
                    for (int i = 0; i < 4; i++) {
                        int x = xs + i*vx;
                        int y = ys + i*vy;
                        if (maze[x][y] != target[i]) {
                            v = 0;
                        }
                    }
                    ans += v;
                }
            } else {
                // Part 2
                int count = 0;
                for (int d = 4; d < 8; d++) {
                    int vx = vxs[d];
                    int vy = vys[d];
                    
                    int v = 1;
                
                    for (int i = -1; i <= 1; i++) {
                        int x = xs + i*vx;
                        int y = ys + i*vy;
                        
                        if (x < 0 || x >= M) {
                            v = 0;
                            break;
                        }
                        if (y < 0 || y >= N) {
                            v = 0;
                            break;
                        }
                        
                        if (maze[x][y] != target[i+2]) {
                            v = 0;
                        }
                    }
                    count += v;
                }
                // if (count == 2) {
                //     ans += 1;
                // }
                ans += count / 2;
            }
        }
    }
    
    std::cout << ans;
    
    return 0;
}
