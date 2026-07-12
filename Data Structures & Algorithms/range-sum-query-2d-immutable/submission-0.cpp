class NumMatrix {
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        prefix = vector<vector<int>> (rows,vector<int>(cols,0));
        for(int r = 0; r < rows; r++){
            prefix[r][0] = matrix[r][0];
            for(int c = 1; c < cols;c++){
                prefix[r][c] = prefix[r][c-1] + matrix[r][c];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        for(int r = row1; r <= row2 ; r++){
            if(col1 > 0){
                res += prefix[r][col2] - prefix[r][col1-1];
            }
            else{
                res += prefix[r][col2];
            }
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */