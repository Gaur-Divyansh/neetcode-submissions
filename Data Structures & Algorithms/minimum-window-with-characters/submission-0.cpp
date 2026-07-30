class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> freq;
        int cnt = 0, minlen = INT_MAX,sIndex = -1;
        for(int i = 0;i < t.size();i++){
            freq[t[i]]++;
        }
        int l = 0;
        for(int r = 0;r < s.size();r++){
            if(freq[s[r]] > 0) cnt++;
            freq[s[r]]--;
            while(cnt == t.size()){
                if(r-l+1 <  minlen){
                    minlen = r-l+1;
                    sIndex = l;
                }
                freq[s[l]]++;
                if(freq[s[l]] > 0) cnt--;
                l++;
            }
        }
        return sIndex == -1 ? "" : s.substr(sIndex,minlen);
    }
};
