class Solution {
    int area=0;
public:
    void dfs(vector<vector<int>>& grid, int r, int c, int &curr){
        if(r<0 || r>= grid.size() || c<0 || c>=grid[0].size() || grid[r][c]==0) return;
        grid[r][c] = 0;
        curr++;
        area=max(area, curr);
        dfs(grid, r-1,c, curr);
        dfs(grid, r+1,c, curr);
        dfs(grid, r,c-1, curr);
        dfs(grid, r,c+1, curr);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS=grid.size(), COLS=grid[0].size();
        for(int i=0; i<ROWS; i++){
            for(int j=0; j<COLS; j++){
                if(grid[i][j]==1){
                    int curr=0;
                    dfs(grid, i, j, curr);
                }
            }
        }
        return area;
    }
};
