#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
      
        
        int totalCodes = 1 << n;  
      
        for (int i = 0; i < totalCodes; ++i) {
           
            int grayValue = i ^ (i >> 1);
            result.push_back(grayValue);
        }
      
        return result;
    }
};