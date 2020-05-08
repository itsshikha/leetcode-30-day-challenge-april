/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<unsigned int>> vec( n , vector<unsigned int> (m, 0));
        vec[0][0] = grid[0][0];
        for(int i=1; i<n; i++){
            vec[i][0] = vec[i-1][0] + grid[i][0];
        }
        for(int i=1; i<m; i++){
            vec[0][i] = vec[0][i-1] + grid[0][i];
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                vec[i][j] = min(vec[i-1][j], vec[i][j-1]) + grid[i][j];
            }
        }
        return vec[n-1][m-1];
    }
};
