class Solution {
    vector<vector<int>> res;

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> comb;
        backtrack(comb, n, k, 1);
        return res;
    }
    void backtrack(vector<int>& comb, int n, int k, int start) {

        if (comb.size() == k) {
            res.push_back(comb);
            return;
        }
        for(int i = start;i <= n;i++){
            comb.push_back(i);
            backtrack(comb,n,k,i+1);
            comb.pop_back();
        }
    }
};