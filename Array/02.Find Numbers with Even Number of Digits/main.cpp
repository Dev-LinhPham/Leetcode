#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int num : nums) {
            if (to_string(num).length() % 2 == 0) { 
                count++;
            }
        }
        return count;
    }
};
/*
Other solution without converting to string:
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int size = nums.size();
        int count_loop = 0;
        int count_num = 0;
        
        for(int i = 0; i < size; ++i)
        {
            int num = nums[i];
            while(num > 0)
            {
                num = num / 10;
                ++count_loop;
            }
            if(count_loop % 2 == 0)
                ++count_num;
            count_loop = 0;
        }
        
        return count_num;
    }
};
*/