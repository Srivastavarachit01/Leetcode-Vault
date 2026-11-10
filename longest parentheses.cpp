#include <iostream>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), best = 0;

        // Left to right
        int open = 0, close = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') open++;
            else close++;

            if (open == close) best = max(best, 2 * close);
            else if (close > open) open = close = 0;
        }

        // Right to left
        open = close = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '(') open++;
            else close++;

            if (open == close) best = max(best, 2 * open);
            else if (open > close) open = close = 0;
        }

        return best;
    }
};