#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

int main() {
	int dx[] = {0, 1, 0, -1};
	int dy[] = {1, 0, -1, 0};

	std::string line;

	long ans1 = 0;
	while (std::getline(std::cin, line)) {
		int code = 0;
		std::vector<std::map<std::string, long>> movess = {{}};
		int cur = -1;
		for (char c : line) {
		    std::vector<std::map<std::string, long>> new_movess;
			int next = c - '0' - 1;
			if (c == 'A') {
				next = -1;
			} else {
				code *= 10;
				if (c == '0') {
					next = -2;
				} else {
					code += c - '0';
				}
			}
			
			std::string move1;
			if (cur >= 0 || next % 3 != 0) {
				int now = cur;
				std::string curMove;
				while ((now + 3) % 3 > (next + 3) % 3) {
					curMove += "<";
					now -= 1;
				}
				while ((now + 3) % 3 < (next + 3) % 3) {
					curMove += ">";
					now += 1;
				}
				while (now > next) {
					curMove += "v";
					now -= 3;
				}
				while (now < next) {
					curMove += "^";
					now += 3;
				}
				for (auto moves : movess) {
    				moves[curMove] += 1;
    				new_movess.push_back(moves);
				}
				move1 = curMove;
			}
			if (cur % 3 != 0 || next >= 0) {
				int now = cur;
				std::string curMove;
				while ((now + 3) / 3 > (next + 3) / 3) {
					curMove += "v";
					now -= 3;
				}
				while ((now + 3) / 3 < (next + 3) / 3) {
					curMove += "^";
					now += 3;
				}
				while (now > next) {
					curMove += "<";
					now -= 1;
				}
				while (now < next) {
					curMove += ">";
					now += 1;
				}
				if (curMove != move1) {
    				for (auto moves : movess) {
        				moves[curMove] += 1;
    				    new_movess.push_back(moves);
				    }
				}
			}
			movess = new_movess;
			cur = next;
		}
		for (auto moves : movess) {
		    for (auto move : moves) {
// 			std::cout << code << " " << move.first << " " << move.second << std::endl;       
		    }
		}

		std::map<std::pair<char, char>, std::vector<std::string>> jump = {
			{{'^', '^'}, {""}},
			{{'^', 'A'}, {">"}},
			{{'^', '<'}, {"v<"}},
			{{'^', '>'}, {"v>"}},//, ">v"}},
			{{'^', 'v'}, {"v"}},

			{{'A', '^'}, {"<"}},
			{{'A', 'A'}, {""}},
			{{'A', '<'}, {"v<<"}},
			{{'A', '>'}, {"v"}},
			{{'A', 'v'}, {"<v"}},//, "v<"}},

			{{'<', '^'}, {">^"}},
			{{'<', 'A'}, {">>^"}},
			{{'<', '<'}, {""}},
			{{'<', '>'}, {">>"}},
			{{'<', 'v'}, {">"}},

			{{'v', '^'}, {"^"}},
			{{'v', 'A'}, {"^>"}},//, ">^"}},
			{{'v', '<'}, {"<"}},
			{{'v', '>'}, {">"}},
			{{'v', 'v'}, {""}},

			{{'>', '^'}, {"<^"}},//, "<^"}},
			{{'>', 'A'}, {"^"}},
			{{'>', '<'}, {"<<"}},
			{{'>', '>'}, {""}},
			{{'>', 'v'}, {"<"}},
		};
		
		long best_ans = 10000000000000000000000;
		for (auto moves : movess) {
    		for (int i = 0; i < 25; i++) {
    		    std::map<std::string, long> newMoves = {};
    		    
    		    for (auto p : moves) {
    		        auto s = p.first;
    		        long n = p.second;
    		        
    		        char now = 'A';
    		        for (char c : s) {
    		            newMoves[jump[{now, c}][0]] += n;
    		            now = c;
    		        }
    		        newMoves[jump[{now, 'A'}][0]] += n;
    		    }
    		    
    		    moves = newMoves;
        // 		for (auto move : moves) {
        // 			std::cout << code << " " << i << " " << move.first << " " << move.second << std::endl;
        // 		}
    		}
    		
    		long ans = 0;
    		
    		for (auto p : moves) {
    		    ans += (p.first.size() + 1) * p.second;
    		}
    		if (ans < best_ans) {
    		    best_ans = ans;
    		}
	    }
		
		std::cout << best_ans << " " << code<< std::endl;
        
		ans1 += code * best_ans;
	}
	std::cout << ans1 << std::endl;
}
