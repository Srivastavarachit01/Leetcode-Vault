#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       
        sort(nums.begin(), nums.end());
      
        int n = nums.size();
        vector<vector<int>> result;
        vector<int> currentPermutation(n);
        vector<bool> visited(n, false);
      
        function<void(int)> backtrack = [&](int position) {
        
            if (position == n) {
                result.push_back(currentPermutation);
                return;
            }
          
        
            for (int i = 0; i < n; ++i) {
               
                if (visited[i]) {
                    continue;
                }
              
                if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                    continue;
                }
              
                currentPermutation[position] = nums[i];
                visited[i] = true;
              
               
                backtrack(position + 1);
              
                visited[i] = false;
            }
        };
      
        
        backtrack(0);
      
        return result;
    }
};