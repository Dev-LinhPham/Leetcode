#include <iostream>
#include <stack>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size(), 0);
        stack<int> st;
        for(int i = 0; i < T.size(); ++i)
        {
            while(!st.empty() && T[i] > T[st.top()])
            {
               res[st.top()] = i - st.top();
               st.pop();     
            }
            st.push(i);

        }

    }
};