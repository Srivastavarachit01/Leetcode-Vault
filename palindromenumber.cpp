#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        string s = to_string(x);
        return s == string(s.rbegin(), s.rend());
    }
};