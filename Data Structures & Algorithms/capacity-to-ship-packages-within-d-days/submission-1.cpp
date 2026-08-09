class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int res = 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            int sum = 0;
            int cnt = 0;
            for(int i = 0;i < weights.size();i++){
                if(sum + weights[i] <= mid) sum+= weights[i];
                else{
                    sum = weights[i];
                    cnt++;
                }
            }
            cnt++;
            if(cnt <= days) {
                high = mid-1;
                res = mid;
            }
            else low = mid + 1;
        }
        return res;
    }
};