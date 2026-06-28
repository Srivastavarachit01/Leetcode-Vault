#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        int top=0, bottom=n-1, left=0, right=n-1, num=1;
        while(num <= n*n) {
            for(int i=left; i<=right; i++) mat[top][i]=num++;
            top++;
            for(int i=top; i<=bottom; i++) mat[i][right]=num++;
            right--;
            for(int i=right; i>=left; i--) mat[bottom][i]=num++;
            bottom--;
            for(int i=bottom; i>=top; i--) mat[i][left]=num++;
            left++;
        }
        return mat;
    }
};