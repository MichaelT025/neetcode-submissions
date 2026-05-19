class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> level;
        for(int i=0; i<grid.size(); i++){
            for(int j=0;j< grid[0].size(); j++){
                if(grid[i][j]==0) level.push({i,j});
            }
        }
        pair<int, int> dist[4]={{-1,0},{1,0}, {0,-1}, {0,1}};
        int COLS= grid[0].size();
        while(!level.empty()){
            auto [r,c]=level.front(); level.pop();
            for(auto [i,j]: dist){
                int nr=i+r;
                int nc=j+c;
                if(nr<0 || nc<0 || nr>=grid.size() || nc>=COLS) continue;
                if(grid[nr][nc]!=INT_MAX) continue;
                grid[nr][nc]=grid[r][c]+1;
                level.push({nr, nc});
            }
        }
    }
};
