class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count1(26,0);
        vector<int> count2(26,0);
        for(char c : s1) count1[c-'a']++;
        int l = 0;
        for(int r = 0; r < s2.size();r++){
            count2[s2[r]-'a']++;
            if(r-l+1 > s1.size()) {
                count2[s2[l]-'a']--;
                l++;
            }
            if(count1 == count2) return true;
        }
        return false;
    }
};
