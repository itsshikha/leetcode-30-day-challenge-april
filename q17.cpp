/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int rows = grid.size();
        if(rows == 0)
            return 0;
        int cols = grid[0].size();
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        stack<pair<int,int>>st; 
        for(int i=0; i<rows;i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    res++;
                    st.push(make_pair(i,j));
                    while(!st.empty()){
                        auto p = st.top();
                        int row = p.first, col = p.second;   
                        st.pop();
                        if(row>0 && grid[row-1][col]=='1'&&!visited[row-1][col])
                            st.push(make_pair(row-1,col));
                        if(row<rows-1 && grid[row+1][col]=='1'&&!visited[row+1][col])
                            st.push(make_pair(row+1,col));
                        if(col>0 && grid[row][col-1]=='1'&&!visited[row][col-1])
                            st.push(make_pair(row,col-1));
                        if(col<cols-1 && grid[row][col+1]=='1'&&!visited[row][col+1])
                            st.push(make_pair(row,col+1));
                        visited[row][col] = true;
                    }
                }
            }
        }
        return res;
    }
};
