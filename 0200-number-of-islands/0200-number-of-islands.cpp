struct coord {
    const int x;
    const int y;
    coord(const int x, const int y) : x(x), y(y) {} 
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        stack<coord> s;
        for(int x = 0; x < m; ++x){
            for(int y = 0; y < n; ++y){
                if(grid[x][y] == '0') continue;
                s.emplace(x,y);
                while(!s.empty()){
                    const coord c = s.top();
                    s.pop();
                    grid[c.x][c.y] = '0';
                    if(c.x - 1 >= 0 && grid[c.x-1][c.y] == '1'){
                        s.emplace(c.x-1,c.y);
                    }
                    if(c.x + 1 < m && grid[c.x+1][c.y] == '1'){
                        s.emplace(c.x+1,c.y);
                    }
                    if(c.y - 1 >= 0 && grid[c.x][c.y-1] == '1'){
                        s.emplace(c.x,c.y-1);
                    }
                    if(c.y + 1 < n && grid[c.x][c.y+1] == '1'){
                        s.emplace(c.x,c.y+1);
                    }
                }
                ans++;
            }
        }
        return ans;
    }
};