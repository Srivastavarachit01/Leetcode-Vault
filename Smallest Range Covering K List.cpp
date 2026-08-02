#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Vector to store all numbers with their list index
        vector<pair<int, int>> ordered;

        // Populate the ordered vector with all numbers and their corresponding list index
        for (size_t k = 0; k < nums.size(); ++k)
            for (auto n: nums[k]) ordered.push_back({n, k});

        // Sort the ordered vector based on the numbers
        sort(ordered.begin(), ordered.end());

        int i = 0, k = 0;  // i: start of current range, k: count of unique lists covered
        vector<int> ans;   // Vector to store the final answer (smallest range)
        unordered_map<int, int> count;  // Map to keep track of number of elements from each list

        // Iterate through the sorted ordered vector
        for (size_t j = 0; j < ordered.size(); ++j) {
            // If this is a new list or increment the count for this list
            if (! count[ordered[j].second]++) ++k;

            // If we have covered all lists
            if (k == nums.size()) { 
                // Shrink the range from the start while maintaining coverage of all lists
                while (count[ordered[i].second] > 1) --count[ordered[i++].second]; 

                // Update the answer if this is the first valid range or if it's smaller than the previous range
                if (ans.empty() || ans[1] - ans[0] > ordered[j].first - ordered[i].first) {
                    ans = vector<int>{ordered[i].first, ordered[j].first};
                }
            }
        }

        return ans;  // Return the smallest range that includes at least one number from each list
    }
};