#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        vector<int> sortedArr(size);

        int right = size - 1;

        for(int left = 0; left <= right;)
        {
            if(abs(nums[left]) > abs(nums[right]))
            {
                sortedArr[right - left] = nums[left] * nums[left];
                ++left; 
            }else
            {
                sortedArr[right - left] = nums[right] * nums[right];
                --right;
            }
        }
        return sortedArr;
    }
};