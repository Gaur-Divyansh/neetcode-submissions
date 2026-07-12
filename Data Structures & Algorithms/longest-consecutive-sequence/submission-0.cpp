class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         if(nums.empty()) return 0;
        unordered_set<int> st(nums.begin(),nums.end());
        int length = 1;
        int cnt = 1;
        for(int i = 0; i < nums.size();i++){ 
            if(st.count(nums[i]-1)){
                cnt = 2;
                int curr = nums[i]-1;
                while(st.count(curr-1)){
                    cnt++;
                    curr--;
                }
                length = max(length,cnt);
            }
        }
        return length;
    }
};
