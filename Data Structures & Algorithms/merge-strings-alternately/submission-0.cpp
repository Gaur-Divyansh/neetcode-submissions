class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int p1 = 0, p2 =0;
        int n1 = word1.size(),n2 = word2.size();
        string res = "";
        while(p1 < n1 && p2 < n2){
            if(p1 < n1) res += word1[p1++];
            if(p2 < n2) res += word2[p2++];
        }
        while(p1 < n1) res+= word1[p1++];
        while(p2 < n2) res+= word2[p2++];
        return res;
    }
};