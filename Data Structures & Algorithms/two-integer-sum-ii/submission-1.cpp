class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //unordered_map<int ,int> mp;
        int low = 0, high = nums.size()-1;
        while(low < high){
           if(nums[low] + nums[high] == target){
            //return {min(nums[low],nums[high]),max(nums[low],nums[high])};
            return {low +1 , high+1};
           }
           else if(nums[low] + nums[high] < target) low++;
           else high--;
        }
    }
};
