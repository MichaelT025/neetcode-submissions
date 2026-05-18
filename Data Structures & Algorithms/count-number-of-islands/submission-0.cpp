class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c){
        if(r<0 || r>= grid.size() || c<0 || c>=grid[0].size() || grid[r][c]=='0') return;
        grid[r][c] = '0';
        dfs(grid, r-1,c);
        dfs(grid, r+1,c);
        dfs(grid, r,c-1);
        dfs(grid, r,c+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ulim=0, leftlim=0;
        int lowerlim=grid.size(), rightlim=grid[0].size();
        int count=0;
        for(int i=0; i< lowerlim; i++){
            for(int j=0; j<rightlim; j++){
                if (grid[i][j]=='1'){
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};
