#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> result;
    
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& current) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) break; // pruning
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, current); // i, not i+1 (reuse allowed)
            current.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> current;
        backtrack(candidates, target, 0, current);
        return result;
    }
};