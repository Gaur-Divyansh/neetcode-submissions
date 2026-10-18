class Solution {
    int rows,cols;
    vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size(); 
        for(int i = 0;i < rows;i++){
            if(board[i][0] == 'O'){
                dfs(board,i,0);
            }
            if(board[i][cols-1] == 'O'){
                dfs(board,i,cols-1);
            }
        }
        for(int j = 0;j < cols;j++){
            if(board[0][j] == 'O'){
                dfs(board,0,j);
            }
            if(board[rows-1][j] == 'O'){
                dfs(board,rows-1,j);
            }
        }
        for(int i = 0;i < rows;i++){
            for(int j = 0;j < cols;j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
    void dfs(vector<vector<char>>& board,int r,int c){
        board[r][c] = '#';
        for(auto [dr,dc] : directions){
            int nr = r + dr;
            int nc = c + dc;
            if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && board[nr][nc] == 'O') dfs(board,nr,nc);
        }
    }
};
