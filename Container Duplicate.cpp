#include <iostream>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Sort the array in ascending order
        sort(nums.begin(), nums.end());
      
        // Iterate through the sorted array and check adjacent elements
        for (int i = 0; i < nums.size() - 1; ++i) {
            // If two adjacent elements are equal, we found a duplicate
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
      
        // No duplicates found
        return false;
    }
};
