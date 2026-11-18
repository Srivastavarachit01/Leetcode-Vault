#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
      
        
        int closestSum = 1 << 30;
        int n = nums.size();
      
        for (int i = 0; i < n; ++i) {
         
            int left = i + 1;
            int right = n - 1;
          
            while (left < right) {
                
                int currentSum = nums[i] + nums[left] + nums[right];
              
                
                if (currentSum == target) {
                    return currentSum;
                }
              
                if (abs(currentSum - target) < abs(closestSum - target)) {
                    closestSum = currentSum;
                }
              
               
                if (currentSum > target) {
                   
                    --right;
                } else {
                    
                    ++left;
                }
            }
        }
      
        return closestSum;
    }
};