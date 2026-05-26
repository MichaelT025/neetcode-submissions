class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> rot;
        int count=0;
        int ROWS=grid.size();
        int COLS=grid[0].size();
        for(int i=0;i<ROWS;i++){
            for(int j=0; j<COLS;j++){
                if(grid[i][j]==1) count++;
                else if(grid[i][j]==2) rot.push({i,j});
            }
        }
        if(count==0) return 0;
        int minutes=-1;
        int rotten=0;
        vector<pair<int, int>> dir={{-1,0}, {1,0}, {0,-1}, {0,1}};
        while(!rot.empty()){
            int currsize=rot.size();
            while(currsize--){
                auto [r,c] = rot.front(); rot.pop();
                for(auto [i, j]: dir){
                    int nr=r+i;
                    int nc=c+j;
                    if(nr<0 || nc<0 || nr>=ROWS || nc>=COLS || grid[nr][nc]!=1) continue;
                    grid[nr][nc]=2;
                    rot.push({nr, nc});
                    rotten++;
                }
            }
            minutes++;
        }
        return rotten==count ? minutes : -1;
    }
};
