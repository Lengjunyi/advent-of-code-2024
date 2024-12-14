#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

int main() {
    std::string line;
    long total = 0;
    std::vector<std::vector<long>> ns;
    
    long X = 101;
    long Y = 103;
    
    while (getline(std::cin, line)) {
        std::stringstream strm(line);
        
        int x, y, vx, vy;
        strm.ignore(100 ,'=');
        strm >> x;
        strm.ignore(100 ,',');
        strm >> y;
        strm.ignore(100 ,'=');
        strm >> vx;
        strm.ignore(100 ,',');
        strm >> vy;
        ns.push_back({x,y,vx,vy});
    }
    
    for (long t = 0; t < 10000; t++) {
        int tree[X][Y] = {};
        int count[4] = {};
        for (auto &n : ns) {
            long x = (n[0] + t * (X + n[2])) % X;
            long y = (n[1] + t * (Y + n[3])) % Y;
            
            if (x > X/2) {
                if (y > Y / 2) {
                    count[0] += 1;
                } else if (y < Y / 2) {
                    count[1] += 1;
                }
            } else if (x < X / 2) {
                if (y > Y / 2) {
                    count[2] += 1;
                } else if (y < Y / 2) {
                    count[3] += 1;
                }
            }
            tree[x][y] = 1;
        }
        
        int sim = 0;
        for (int i = 1; i < Y-1; i++) {
            for (int j = 1; j < X-1; j++) {
                if (tree[j][i])
                for (int ii = i-1;ii<=i+1;ii++) {
                    for (int jj = j-1;jj<=j+1;jj++) {
                        if (tree[jj][ii]) {
                            sim += 1;
                        }
                    }
                    
                }
            }
        }
        // Part 1
        if (t == 100) {
            std::cout << t << " " << count[0] * count[1] * count[2] * count[3] << std::endl;
        }
        
        if (sim > 1000) {
            std::cout << "similarity score: " << sim << std::endl;

            for (int i = 0; i < Y; i++) {
                for (int j = 0; j < X; j++) {
                    std::cout << (tree[j][i] ? '#' : '.');
                }
                std::cout << std::endl;
            }
            break;
        }

    }
}
