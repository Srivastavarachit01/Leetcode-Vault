#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> cur;
        backtrack(nums, 0, cur, res);
        return res;
    }
    
    void backtrack(vector<int>& nums, int start, vector<int>& cur, vector<vector<int>>& res){
        res.push_back(cur);
        for(int i = start; i < nums.size(); i++){
            // skip duplicate at same level
            if(i > start && nums[i] == nums[i-1]) continue;
            cur.push_back(nums[i]);
            backtrack(nums, i + 1, cur, res);
            cur.pop_back();
        }
    }
};
