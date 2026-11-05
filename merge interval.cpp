#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }

        // 1. Sort the intervals based on their start times
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        });

        std::vector<std::vector<int>> merged;
        
        // 2. Iterate through each interval and check for overlaps
        for (const auto& interval : intervals) {
            // If the merged list is empty or the current interval does not overlap 
            // with the last merged interval, add it directly.
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } else {
                // There is an overlap, so merge the current interval into the last merged interval
                merged.back()[1] = std::max(merged.back()[1], interval[1]);
            }
        }

        return merged;
    }
};
