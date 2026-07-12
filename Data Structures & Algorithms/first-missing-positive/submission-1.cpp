class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
         int n = nums.size();
        if(n < 1) return 1;
        int i = 0;
        while(i < n){
            if(nums[i] <= 0 || nums[i] > n || nums[i] == i+1){
                i++;
                continue;
            }
            if(nums[i] != nums[nums[i]-1]) swap(nums[i],nums[nums[i]-1]);
            else i++;
        }
        for(int i = 0;i < nums.size();i++){
            if(nums[i] != i+1) return i+1;
        }
        return n+1;
    }
};