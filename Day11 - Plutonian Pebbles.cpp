#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>

long get_ans(long number, int depth, std::map<std::pair<long, int>, long> &memory) {
    if (depth == 0) {
        return 1;
    }
    if (memory.count({number, depth}) == 0) {
        long n;
        std::string s = std::to_string(number);
        if (number == 0) {
            n = get_ans(1, depth-1, memory);
        } else if (s.size() % 2 == 0) {
            int p = 1;
            for (int i = 0; i < s.size() / 2; i++) {
                p *= 10;
            }
            n = get_ans(number / p, depth-1, memory) + get_ans(number % p, depth-1, memory);
        } else {
            n = get_ans(number * 2024, depth-1, memory);
        }
        memory[{number, depth}] = n;
    }
    return memory[{number, depth}];
}

int main() {
    long ans1 = 0;
    long ans2 = 0;
    
    std::map<std::pair<long, int>, long> memory;
    
    std::string line;
    getline(std::cin, line);
    std::stringstream strm(line);

    long a;
    while (strm >> a) {
        ans1 += get_ans(a, 25, memory);
        ans2 += get_ans(a, 75, memory);
    }
    
    std::cout << ans1 << " " << ans2 << std::endl;
    
    return 0;
}
