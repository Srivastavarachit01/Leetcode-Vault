#include <iostream>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
      
        int childCount = g.size();
        int cookieCount = s.size();
      
        int childIndex = 0;  
        int cookieIndex = 0; 
        int satisfiedChildren = 0; 
      
       
        while (childIndex < childCount && cookieIndex < cookieCount) {
            
            if (s[cookieIndex] >= g[childIndex]) {
                satisfiedChildren++;
                childIndex++;  
                cookieIndex++; 
            } else {
                
                cookieIndex++;
            }
        }
      
        return satisfiedChildren;
    }
};