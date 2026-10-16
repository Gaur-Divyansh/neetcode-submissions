class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> delta(n,0);
        for(int i = 0;i< trust.size();i++){
            delta[trust[i][0]-1]--;
            delta[trust[i][1]-1]++;
        }
        for(int i = 0;i < n;i++){
            if(delta[i] == n-1) return i+1;
        }
        return -1;
    }
};