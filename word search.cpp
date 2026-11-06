#include <iostream>
#include <vector>
#include <string>
#include <functional>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
     
        int dirs[5] = {-1, 0, 1, 0, -1};
      
        
        function<bool(int, int, int)> dfs = [&](int row, int col, int index) -> bool {
            
            if (index == word.size() - 1) {
                return board[row][col] == word[index];
            }
          
          
            if (board[row][col] != word[index]) {
                return false;
            }
          
            char originalChar = board[row][col];
            board[row][col] = '0';  
            
            for (int dir = 0; dir < 4; ++dir) {
                int nextRow = row + dirs[dir];
                int nextCol = col + dirs[dir + 1];
              
               
                if (nextRow >= 0 && nextRow < rows && 
                    nextCol >= 0 && nextCol < cols && 
                    board[nextRow][nextCol] != '0') {
                  
                    
                    if (dfs(nextRow, nextCol, index + 1)) {
                        return true;
                    }
                }
            }
          
            
            board[row][col] = originalChar;
            return false;
        };
      
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (dfs(i, j, 0)) {
                    return true;  
                }
            }
        }
      
        return false;  
    }
};