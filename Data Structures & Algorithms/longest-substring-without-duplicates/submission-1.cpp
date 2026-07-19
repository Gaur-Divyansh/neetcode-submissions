class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> mp;
        int l = 0;
        int res = 0;
        for(int r = 0; r < s.size();r++){
            if(mp.count(s[r])){
                l = max(l,mp[s[r]] + 1);
            }
            mp[s[r]] = r;
            res = max(res,r-l+1);
        }
        return res;
    }
};
