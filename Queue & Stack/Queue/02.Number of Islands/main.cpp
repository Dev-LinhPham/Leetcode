#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution{
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        unordered_set<string> visited;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == '1' && visited.find(to_string(r)+ "," + to_string(c)) == visited.end())
                {
                    count++;
                    bfs(grid, r, c, visited);
                }
            }
        }
        return count;
    }
private:
    void bfs(vector<vector<char>>& grid, int r, int c, unordered_set<string>& visited){
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        q.push({r, c});
        visited.insert(to_string(r) + to_string(c));

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!q.empty()){
            auto [currR, currC] = q.front();
            q.pop();

            for(auto [dr, dc] : directions){
                int newR = currR + dr;
                int newC = currC + dc;

                if(newR >= 0 && newR < rows && newC >= 0 && newC < cols && visited.find(to_string(newR) + "," + to_string(newC)) == visited.end() && grid[newR][newC] == '1')
                {
                    q.push({newR, newC});
                    visited.insert(to_string(newR) + "," + to_string(newC));
                }
            }

        }
    }
};