#include <iostream>
#include <string>
using namespace std;    
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if (n + m != s3.size()) return false;

        vector<bool> dp(m + 1, false);
        dp[0] = true;

        // Initialize first row (only s2 contributes)
        for (int j = 1; j <= m; j++)
            dp[j] = dp[j-1] && s2[j-1] == s3[j-1];

        for (int i = 1; i <= n; i++) {
            // update dp[0] for this row (only s1 contributes)
            dp[0] = dp[0] && s1[i-1] == s3[i-1];

            for (int j = 1; j <= m; j++) {
                bool fromS1 = dp[j] && s1[i-1] == s3[i+j-1];
                bool fromS2 = dp[j-1] && s2[j-1] == s3[i+j-1];
                dp[j] = fromS1 || fromS2;
            }
        }
        return dp[m];
    }
};