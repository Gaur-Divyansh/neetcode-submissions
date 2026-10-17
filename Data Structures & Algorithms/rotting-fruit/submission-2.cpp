class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int minutes = 0;
        queue<pair<int,int>> q;
        for(int i = 0;i < grid.size();i++){
            for(int j = 0; j < grid[0].size();j++){
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2) q.push({i,j});
            }
        }
        vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
        while(fresh > 0 && !q.empty()){
            int length = q.size();
            for(int i = 0;i < length;i++){
                pair<int,int> curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;
                for(int i = 0;i < directions.size();i++){
                    int row = r + directions[i].first;
                    int col = c + directions[i].second;
                    if(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] == 1){
                        grid[row][col] = 2;
                        q.push({row,col});
                        fresh--;
                    }
                }
            }
            minutes++;
        }
        return fresh == 0 ? minutes : -1;
    }
};
