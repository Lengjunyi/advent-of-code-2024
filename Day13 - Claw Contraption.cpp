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
    while (getline(std::cin, line)) {
        long ax, ay, bx, by, tx, ty;
        std::stringstream strm(line);
        strm.ignore(100 ,'+');
        strm >> ax;
        strm.ignore(100 ,'+');
        strm >> ay;
        
        getline(std::cin, line);
        std::stringstream strm2(line);
        strm2.ignore(100 ,'+');
        strm2 >> bx;
        strm2.ignore(100 ,'+');
        strm2 >> by;
        
        getline(std::cin, line);
        std::stringstream strm3(line);
        strm3.ignore(100 ,'=');
        strm3 >> tx;
        strm3.ignore(100 ,'=');
        strm3 >> ty;
        
        getline(std::cin, line);
        
        // int tokens = 10000;
        // for (int i = 0; i <= 100; i++) {
        //     for (int j = 0; j <= 100; j++) {
        //         if (ax * i + bx * j == tx) {
        //             if (ay * i + by * j == ty) {
        //                 if (3 * i + j < tokens) {
        //                     tokens = 3 * i + j;
        //                 }
        //             }
        //         }
        //     }
        // }
        // if (tokens != 10000) {
        //     total += tokens;
        // }
        
        tx += 10000000000000;
        ty += 10000000000000;
        
        long tokens = 0;
        long coeff = by * ax - bx * ay;
        long n = ty * ax - tx * ay;
        if (n % coeff == 0) {
            long j = n / coeff;
            if (j >= 0) {
                long i = ty - by * j;
                if (i % ay == 0) {
                    i = i / ay;
                    if (i >= 0) {
                        tokens = 3 * i + j;
                    }
                }
            }
        }
        total += tokens;
    }
    std::cout << total;
    
    return 0;
}
