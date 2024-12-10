#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>

int main() {
    int ans1 = 0;
    int ans2 = 0;

    std::string line;
    std::set<std::pair<int, int>> orders;
    
    while (getline(std::cin, line)) {
        if (line.empty()) {
            break;
        }
        int a, b;
        char _;
        std::stringstream strm(line);
        strm >> a >> _ >> b;

        orders.emplace(a, b);
    }
    while (getline(std::cin, line)) {
        std::stringstream strm(line);

        std::vector<int> nums;
        std::vector<int> numsCopy;
        for (int i; strm >> i;) {
            nums.push_back(i);
            numsCopy.push_back(i);
            strm.ignore();
        }

        std::sort(nums.begin(), nums.end(), [&](int a, int b){
            return orders.count(std::make_pair(a, b));
        });
        // bool allowed = true;
        // for (int l = 0; l < nums.size(); l++) {
        //     for (int r = l+1; r < nums.size(); r++) {
        //         int lv = nums[l];
        //         int rv = nums[r];
        //         if (orders.count(std::make_pair(rv, lv)) != 0) {
        //             allowed = false;
        //         }
        //     }
        // }
        // if (allowed) {
        //      ans1 += nums[nums.size() / 2];
        if (nums == numsCopy) {
            ans1 += nums[nums.size() / 2];
        } else {
            // std::sort(nums.begin(), nums.end(), [&](int a, int b){
            //     return orders.count(std::make_pair(a, b));
            // });
            ans2 += nums[nums.size() / 2];
        }
    }

    std::cout << ans1 << " " << ans2;

    return 0;
}
