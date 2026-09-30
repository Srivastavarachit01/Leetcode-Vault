#include <vector>
#include <algorithm>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int jumps = 0;
        int current_end = 0;
        int farthest = 0;

        for (int i = 0; i < nums.size() - 1; ++i) {
            farthest = std::max(farthest, i + nums[i]);

            if (i == current_end) {
                jumps++;
                current_end = farthest;
                if (current_end >= nums.size() - 1) break;
            }
        }

        return jumps;
    }
};