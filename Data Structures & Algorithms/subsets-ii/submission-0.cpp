class Solution {
    void helper(vector<int>& nums,int start,vector<vector<int>>& res,vector<int>& subset){
        res.push_back(subset);
        for(int i = start;i < nums.size();i++){
            if(i > start && nums[i] == nums[i-1]) continue;
            subset.push_back(nums[i]);
            helper(nums,i+1,res,subset);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> subset;
        helper(nums,0,res,subset);
        return res;
    }
};
