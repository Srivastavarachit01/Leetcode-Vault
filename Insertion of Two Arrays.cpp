#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
   
        bool seen[1001];

       
        memset(seen, false, sizeof(seen));

        for (int num : nums1) {
            seen[num] = true;
        }

        
        vector<int> result;


        for (int num : nums2) {
           
            if (seen[num]) {
                result.push_back(num);
                
                seen[num] = false;
            }
        }

        return result;
    }
};