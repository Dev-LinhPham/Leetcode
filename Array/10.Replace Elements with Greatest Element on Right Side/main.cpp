#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();

        for(int i = 0; i < n - 1; ++i)
        {
            int maxElement = arr[i +1];

            for(int j = i + 2; j < n; ++j)
            {
                maxElement = max(maxElement, arr[j]);
            }
            arr[i] = maxElement;
        }
        arr[n - 1] = -1;
        return arr;
    }
};
