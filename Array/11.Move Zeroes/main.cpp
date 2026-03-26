#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int writeIndex = 0;
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] != 0)
            {
                nums[writeIndex++] = nums[i];
            }
        }
        while(writeIndex < n)
        {
            nums[writeIndex++] = 0;
        }
    }
};