class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int x = 0; x<n;++x){
            for(int y = 0; y<m;++y){
                int island_size{0};
                dfs(x,y,grid,island_size);
                ans = max(ans,island_size);
            }
        }
        return ans;
    }
    void dfs(const int x, const int y, vector<vector<int>>& grid, int & island_size){
        // Out of bounds
        if(x<0 || y < 0 || x >= grid.size() || y >= grid[0].size()) return;
        // Water
        if(grid[x][y]==0) return;
        // Land
        ++island_size;
        grid[x][y] = 0; // Prevent duplicate sightings
        dfs(x-1,y,grid,island_size);
        dfs(x+1,y,grid,island_size);
        dfs(x,y-1,grid,island_size);
        dfs(x,y+1,grid,island_size);
    }
};