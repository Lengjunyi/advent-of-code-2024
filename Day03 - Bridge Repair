#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

int main() {
    long ans1 = 0;
    
    std::string line;
    while (getline(std::cin, line)) {
        std::stringstream strm(line);
        long target, start;
        strm >> target;
        strm.ignore();
        strm >> start;
        
        int n;
        std::vector<long> ns;
        while (strm >> n) {
            ns.push_back(n);
        }
        
        // Part 1 is commented out
        // for (int i = 0; i < 1 << ns.size(); i++) {
        for (int i = 0; i < 1 << (2 * ns.size()); i++) {
            int operation = i;
            long value = start;
            // for (int step = 0; step < ns.size(); step++) {
            //     if (operation % 2) {
            //         value *= ns[step];
            //     } else {
            //         value += ns[step];
            //     }
            //     operation /= 2;
            // }
            for (int step = 0; step < ns.size(); step++) {
                if (operation % 3 == 1) {
                    value *= ns[step];
                } else if (operation % 3 == 2) {
                    value += ns[step];
                } else {
                    int temp = ns[step];
                    while (temp != 0) {
                        value *= 10;
                        temp /= 10;
                    }
                    value += ns[step];
                }
                operation /= 3;
            }
            if (target == value) {
                ans1 += target;
                break;
            }
        }
    
    }
    
    std::cout << ans1 << std::endl;
    
    return 0;
}
