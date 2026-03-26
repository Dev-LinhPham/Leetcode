#include <iostream>
#include <vector>

class Solution {
public:
    void duplicateZeros(std::vector<int>& arr) {
        int size = arr.size();
        for(int i = 0; i < size; ++i)
        {
            if(arr[i] == 0)
            {
                for(int j = size - 1; j > i ; --j)
                {
                    arr[j] = arr[j - 1];
                }
                ++i;
            }
        }
    }
};