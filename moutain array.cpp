#include <iostream>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2; // Prevents potential integer overflow
            
            if (arr[mid] < arr[mid + 1]) {
                // We are ascending, peak is to the right
                low = mid + 1;
            } else {
                // We are descending (or at peak), peak is at 'mid' or to the left
                high = mid;
            }
        }
        
        // At the end of the loop, low == high, pointing directly to the peak index
        return low;
    }
};
