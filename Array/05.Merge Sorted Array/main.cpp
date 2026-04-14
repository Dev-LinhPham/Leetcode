#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int midx = m - 1; 
        int nidx = n - 1; 
        int r_pos = m + n - 1; 

        while (nidx >= 0) { // We only need to check nidx because if midx < 0, we can directly copy the remaining elements of nums2
            if(midx >= 0 && nums1[midx] > nums2[nidx]){
                nums1[r_pos--] = nums1[midx--];
            }else{
                nums1[r_pos--] = nums2[nidx--];
            }
        }
    }
};