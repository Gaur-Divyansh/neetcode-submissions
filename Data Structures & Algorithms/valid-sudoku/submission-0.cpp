class Solution {
public:
    bool traversal(vector<vector<char>>& board,int sr, int er,int sc ,int ec){
        unordered_set<char> seen;
        for(int i = sr;i <= er;i++){
            for(int j = sc;j <= ec;j++){
                if(board[i][j] == '.') continue;
                if(seen.count(board[i][j])) return false;
                seen.insert(board[i][j]);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row = 0; row < 9;row++){
            unordered_set<char> seen;
            for(int col = 0; col < 9;col++){
                if(board[row][col] == '.') continue;
                if(seen.count(board[row][col])) return false;
                seen.insert(board[row][col]);
            }
        }
        for(int col = 0; col < 9; col++){
            unordered_set<char> seen;
            for(int row = 0; row < 9; row++){
                if(board[row][col] == '.') continue;
                if(seen.count(board[row][col])) return false;
                seen.insert(board[row][col]);
            }
        }
        for(int sr = 0; sr < 9; sr += 3){
            int er = sr + 2;
            for(int sc = 0; sc < 9; sc += 3){
                int ec = sc + 2;
                if(!traversal(board,sr,er,sc,ec)) return false;
            }
        }
        return true;
    }
};
