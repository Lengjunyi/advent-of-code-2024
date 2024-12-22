#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

int main() {
    long ans1 = 0;
	long ans2 = 0;

	std::string s;
	
	std::map<std::pair<std::pair<std::pair<int, int>, int>, int>, int> total;
	
	while (std::getline(std::cin, s)) {
	    std::stringstream ss(s);
		long a;
		ss >> a;
// 		std::cout << a << std::endl;
		
		std::set<std::pair<std::pair<std::pair<int, int>, int>, int>> seen;
		
		int b,c,d,e;
		int last = a;
		for (int i = 0; i < 2000; i++) {
		    a = (a*64) ^ a;
		    a %= 16777216;
		    a = (a / 32) ^ a;
		    a %= 16777216;
		    a = (a * 2048) ^ a;
		    a %= 16777216;
		  //  std::cout << a << " ";
		    
		    b = c; c=d;d=e;e=a%10-last;
		    last = a%10;
		    if (i >= 4) {
		        std::pair<std::pair<std::pair<int, int>, int>, int> p = {{{b, c}, d}, e};
		        if (0==seen.count(p)) {
		            total[p] += a%10;
		            seen.emplace(p);
		        }
		    }
		}
// 		std::cout << a << std::endl;
		ans1 += a;
	}
	std::cout << ans1 << std::endl;
	for (auto p : total) {
	   // std::cout << "poss:" << p.second << std::endl;
	    if (p.second > ans2) {
	        ans2 = p.second;
	    }
	}
	std::cout << ans2;
}
