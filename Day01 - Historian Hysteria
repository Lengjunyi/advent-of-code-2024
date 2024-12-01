#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

int main() {
    std::vector<int> as;
    std::vector<int> bs;
    
    std::string inputPair;
    while (getline(std::cin, inputPair)) {
        int a, b;
        std::stringstream strm(inputPair);
        strm >> a >> b;
        as.push_back(a);
        bs.push_back(b);
    }
    
    // Part 1
    std::sort(as.begin(), as.end());
    std::sort(bs.begin(), bs.end());
    
    int ans = 0;
    for (int i = 0; i < as.size(); i++) {
        ans += std::abs(as[i] - bs[i]);
    }
    
    std::cout << ans << std::endl;
    
    // Part 2
    ans = 0;
    for (int a : as) {
        for (int b : bs) {
            if (a == b) {
                ans += a;
            }
        }
    }
    
    std::cout << ans << std::endl;
    
    return 0;
}
