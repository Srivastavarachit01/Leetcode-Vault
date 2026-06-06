#include <iostream>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0, leftSum = 0;
        
        for (int x : nums) total += x;
        
        for (int i = 0; i < nums.size(); i++) {
            // rightSum = total - leftSum - nums[i]
            if (leftSum == total - leftSum - nums[i])
                return i;
            leftSum += nums[i];
        }
        
        return -1;
    }
};