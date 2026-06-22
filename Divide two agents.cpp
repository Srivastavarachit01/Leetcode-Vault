#include<iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Overflow edge case
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        int sign = (dividend > 0) == (divisor > 0) ? 1 : -1;
        
        long long result = 0;
        while (a >= b) {
            long long temp = b, multiple = 1;
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            a -= temp;
            result += multiple;
        }
        
        return sign == 1 ? result : -result;
    }
};