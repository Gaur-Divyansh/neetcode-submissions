class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string base = strs[0];
        for(int i = 0; i < base.size();i++){
            int curr = base[i];
            for(int j = 1; j < strs.size();j++){
                if(i >= strs[j].size() || curr != strs[j][i]) return base.substr(0,i);
            }
        }
        return base;
    }
};