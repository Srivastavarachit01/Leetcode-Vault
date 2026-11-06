#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // Initialize the result vector to store Pascal's triangle
        vector<vector<int>> triangle;
      
        // Add the first row [1] to the triangle
        triangle.push_back(vector<int>(1, 1));
      
       
        for (int rowIndex = 0; rowIndex < numRows - 1; ++rowIndex) {
          
            vector<int> currentRow;;
          
           
            currentRow.push_back(1);
          
            
            for (int colIndex = 1; colIndex < triangle[rowIndex].size(); ++colIndex) {
                int sum = triangle[rowIndex][colIndex - 1] + triangle[rowIndex][colIndex];
                currentRow.push_back(sum);
            }
          
        
            currentRow.push_back(1);
          
           
            triangle.push_back(currentRow);
        }
      
        return triangle;
    }
};