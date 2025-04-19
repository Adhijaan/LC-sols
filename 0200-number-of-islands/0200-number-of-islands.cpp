class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int x = 0; x < m; ++x){
            for (int y = 0; y < n; ++y){
                // Check each box if it is an island
                ans += bfs(grid,x,y)? 1 : 0;
            }
        }
        return ans;
    }

    bool bfs(vector<vector<char>>& grid, int x, int y){
        if (grid[x][y] == '0'){
            return false;
        }
        
        // Invalidate piece (mark as checked)
        grid[x][y] = '0';

        // Invalidate neighboring land if reachable
        if (x > 0){
            bfs(grid,x-1,y);
        }
        if (x + 1 < grid.size()){
            bfs(grid,x+1,y);
        }
        if (y > 0){
            bfs(grid,x,y-1);
        }
        if (y + 1 < grid[0].size()){
            bfs(grid,x,y+1);
        }
        return true;
    }
};