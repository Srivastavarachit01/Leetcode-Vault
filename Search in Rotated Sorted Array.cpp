#include <iostream>
using namespace std;

class Solution {
public:
    // Function to search for the target in the array
    int search(vector<int>& nums, int target) {
        int n = nums.size(); // Get the size of the array
        // Iterate through the array
        for (int i = 0; i < n; ++i) {
            // Check if the current element is the target
            if (nums[i] == target) {
                return i; // Return the index if target is found
            }
        }
        return -1; // Return -1 if target is not found
    }
};