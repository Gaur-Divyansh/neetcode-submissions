class Solution {
    vector<vector<string>> res;
public:
    vector<vector<string>> partition(string s) {
        vector<string> part;
        dfs(part,s,0);
        return res;
    }
    void dfs(vector<string>& part,string& s,int j){
        if(j >= s.size()){
            res.push_back(part);
            return;
        }
        for(int i = j;i < s.size();i++){
            if(isPalindrome(s,j,i)){
                part.push_back(s.substr(j,i-j+1));
                dfs(part,s,i+1);
                part.pop_back();
            }
        }
    }
    bool isPalindrome(string& s,int start,int end){
        while(start < end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
};
