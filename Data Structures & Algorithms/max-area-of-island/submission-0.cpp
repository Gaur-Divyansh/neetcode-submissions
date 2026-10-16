class Solution {
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int currArea = 0;
        int maxArea = 0;
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[0].size();j++){
                if(grid[i][j] == 1){
                    dfs(grid,i,j,currArea);
                    maxArea = max(maxArea,currArea);
                    currArea = 0;
                }
            }
        }
        return maxArea;
    }
    void dfs(vector<vector<int>>& grid,int i, int j,int& currArea){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) return;
        grid[i][j] = 0;
        currArea ++;
        dfs(grid,i+1,j,currArea);
        dfs(grid,i-1,j,currArea);
        dfs(grid,i,j+1,currArea);
        dfs(grid,i,j-1,currArea);
    }
};
