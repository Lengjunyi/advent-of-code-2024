#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

std::map<std::string, std::set<std::string>> mapping;

int main() {
	std::string s;
	long ans = 0;
	
	while (std::getline(std::cin, s)) {
	    std::stringstream ss(s);
	    std::string a, b;
	    std::getline(ss, a, '-');
	    std::getline(ss, b);
	   // std::cout << a << " " << b << std::endl;

	   for (auto p : mapping[a]) {
	       if (mapping[b].count(p) != 0) {
	           	   if (a[0] == 't' || b[0] == 't' || p[0] == 't') {
	                    ans += 1;
	           	   }
	       }
	       //std::cout << p << " vs " << a << " " << b << std::endl;
	   }
	   mapping[a].emplace(b);
	   mapping[b].emplace(a);
	}
	std::cout << ans;
	
	int maximum = 0;
	
	for (auto p : mapping) {
	   // std::cout << p.second.size() << std::endl;
	    for (int i = 0; i < 1 << p.second.size(); i++) {
	        std::set<std::string> sub;
	        int ii = i;
	        for (auto next : p.second) {
	            if (ii % 2 == 0) {
	                sub.emplace(next);
	            }
	            ii /= 2;
	        }
	        if (sub.size() <= maximum) {
	            continue;
	        }
	        bool flag = true;
	        for (auto f : sub) {
	            for (auto s : sub) {
	                if (f != s && mapping[f].count(s) == 0) {
	                    flag = false;
	                }
	            }
	        }
	        if (flag) {
	            maximum = sub.size();
	            std::cout << p.first;
	            for (auto n : sub) {
	                std::cout << "," << n;
	            }
	            std::cout << std::endl;
	        }
	    }
	}

}
