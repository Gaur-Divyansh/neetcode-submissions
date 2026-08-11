class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low <= high){
            int mid = low + (high-low)/2;
            int sum = 0, cnt = 1;
            for(int i = 0; i < nums.size();i++){
                if(nums[i] + sum <= mid) sum+= nums[i];
                else{
                    sum = nums[i];
                    cnt++;
                }
            }
            if(cnt <= k) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};