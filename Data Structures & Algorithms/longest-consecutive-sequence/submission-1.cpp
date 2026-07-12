class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> st(nums.begin(),nums.end());
        int longest = 0;
        for(int i = 0; i < nums.size();i++){ 
            if(!st.count(nums[i]-1)){
                int len = 1; 
                while(st.count(nums[i] + len)){
                    len++;
                }
                longest = max(longest,len);
            }
        }
        return longest;
    }
};
