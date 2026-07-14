class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (nums[l] + nums[r] + nums[i] < 0)
                    l++;
                else if (nums[l] + nums[r] + nums[i] > 0)
                    r--;
                else {
                    res.push_back({nums[l], nums[i], nums[r]});
                    while (l < r && nums[l+ 1] == nums[l]) l++;
                    while (l < r && nums[r - 1] == nums[r]) r--;
                    l++;
                    r--;
                }
            }
        }
        return res;
    }
};
