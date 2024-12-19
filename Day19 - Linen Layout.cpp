#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

int main() {
    int ans1 = 0;
	long ans2 = 0;

	std::string s;
	getline(std::cin, s);
	std::stringstream strm(s);

	std::string pattern;
	std::vector<std::string> patterns;

	while (std::getline(strm, pattern, ',')) {
		patterns.push_back(pattern);
		strm.ignore(100, ' ');
	}
	getline(std::cin, s);

	while(getline(std::cin, s)) {
		std::vector<long> dp(s.size() + 1);
		dp[0] = 1;

		for (int i = 1; i <= s.size(); i++) {
			for (auto pattern : patterns) {
				if (i < pattern.size()) {
					continue;
				}
				if (pattern == s.substr(i - pattern.size(), pattern.size())) {
					dp[i] += dp[i - pattern.size()];
				}
			}
		}

		if (dp[s.size()] != 0) {
			ans1 += 1;
			ans2 += dp[s.size()];
		}
	}

	std::cout << ans1 << " " << ans2;
}
