#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

int main() {
    std::string line;
    getline(std::cin, line);


    // std::vector<int> contents;
    // std::vector<int> freeSpace;    
    // std::vector<int> vals;
    
    // for (int i = 0; i < line.size(); i+=1) {
    //     if (i % 2 == 0) {
    //         for (int n = 0; n < line[i] - '0'; n++) {
    //             vals.push_back(i/2);
    //         }
    //     } else {
    //         for (int n = 0; n < line[i] - '0'; n++) {
    //             vals.push_back(-1);
    //         }
    //     }
    // }

    // long ans = 0;
    // int end = vals.size();
    // for (int i = 0; i < end; i++) {
    //     if (vals[i] >= 0) {
    //         ans += i * vals[i];
    //         // std::cout << i << " " << vals[i] << std::endl;
    //     } else {
    //         end -= 1;
    //         while (vals[end] < 0) {
    //             end -= 1;
    //         }
    //         if (i < end) {
    //             ans += i * vals[end]; 
    //             // std::cout << i << " " << vals[end] << std::endl;
    //         }
    //     }
    // }
    
    // std::cout << ans << std::endl;
    
    std::vector<std::pair<int, int>> freeSpace;
    std::vector<std::pair<int, int>> usedSpace;
    
    int offset = 0;
    
    for (int i = 0; i < line.size(); i+=1) {
        int count = line[i] - '0';
        if (i % 2 == 0) {
            usedSpace.push_back({offset, count});
        } else {
            freeSpace.push_back({offset, count});
        }
        offset += count;
    }
    
    for (int i = usedSpace.size(); i--;) {
        for (int j = 0; j < i; j++) {
            auto &p = freeSpace[j];
            if (p.second >= usedSpace[i].second) {
                usedSpace[i].first = p.first;
                p.first += usedSpace[i].second;
                p.second -= usedSpace[i].second;
                break;
            }
        }
    }
    
    long ans = 0;
    for (int i = 0; i < usedSpace.size(); i++) {
        for (int n = 0; n < usedSpace[i].second; n++) {
            ans += i * (usedSpace[i].first + n);
        }
    }
    std::cout << ans;
    
    return 0;
}
