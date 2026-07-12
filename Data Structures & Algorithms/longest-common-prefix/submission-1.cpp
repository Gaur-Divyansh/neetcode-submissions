class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string base = strs[0];
        for(int i = 0; i < base.size();i++){
            for(int j = 1;j < strs.size();j++){
                char currentChar = base[i];
                if(i >= strs[j].size() || currentChar != strs[j][i]) return base.substr(0,i);
            }
        }
        return base;
    }
};