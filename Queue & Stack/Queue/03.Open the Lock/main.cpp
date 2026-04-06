#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<string> deads(deadends.begin(), deadends.end());
        queue<string> q;
        unordered_set<string> visited;
        int step = 0;
        string root = "0000";
        q.push(root);
        visited.insert(root);

        if(deads.count(root))
            return -1;
        
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                string cur = q.front();
                q.pop();

                if(cur == target)
                    return step;

                for(int j = 0; j < 4; j++)
                {
                    for(int k = -1; k <= 1; k += 2)
                    {
                        string next = cur;
                        next[j] = (cur[j] - '0' + k + 10) % 10 + '0';

                        if(!deads.count(next) && !visited.count(next))
                        {
                            q.push(next);
                            visited.insert(next);
                        }
                    }
                }
            }
        }

        return -1;
    }
};