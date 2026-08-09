class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(),piles.end());
        int k = 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            long long sum = 0;
            for(int i = 0;i < piles.size();i++){
                sum += ceil((double)(piles[i])/mid);
            }
            if(sum <= h){
                high = mid-1;
                k = mid;
            }
            else{
                low = mid+1;
            }
        }
        return k;
    }
};
