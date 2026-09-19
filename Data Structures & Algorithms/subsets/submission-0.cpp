class Solution {
    void helper(vector<int>& nums,vector<vector<int>>& res, vector<int>& subset,int i){
        if(i == nums.size()){
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        helper(nums,res,subset,i+1);
        subset.pop_back();
        helper(nums,res,subset,i+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        int i = 0;
        helper(nums,res,subset,i);
        return res;
    }
};
