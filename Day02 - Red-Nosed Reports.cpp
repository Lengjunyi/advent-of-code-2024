#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

int main() {
    int ans1 = 0;
    int ans2 = 0;
    
    std::string line;
    while (getline(std::cin, line)) {
        std::stringstream strm(line);

        std::vector<int> vector;

        int a, b, c;
        strm >> a >> b;
        bool safe = std::abs(a-b) <= 3;
        vector.push_back(a);
        vector.push_back(b);

        while (strm >> c) {
            vector.push_back(c);
            if ((c - b) * (b - a) <= 0) {
                safe = false;
            }
            if (std::abs(b-c) > 3) {
                safe = false;
            }
            a = b;
            b = c;
        }
        if (safe) {
            ans1 += 1;
        }

        safe = false;

        for (int i = 0; i < vector.size() + 1; i++) {
            bool safesafe = true;
            int a,b,c;
            for (int j = 0; j < vector.size()-3; j++) {
                a = j < i? vector[j] : vector[j+1];
                b = j+1 < i? vector[j+1] : vector[j+2];
                c = j+2 < i? vector[j+2] : vector[j+3];
                
                if (std::abs(a-b) > 3) {
                    safesafe = false;
                }
                if (std::abs(b-c) > 3) {
                    safesafe = false;
                }
                if ((c - b) * (b - a) <= 0) {
                    safesafe = false;
                }
            }
            if (safesafe) {
                safe = true;
            }
        }

        if (safe) {
            ans2 += 1;
        }
    }
    std::cout << ans1 << " " << ans2;

    return 0;
}
