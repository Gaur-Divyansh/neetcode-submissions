/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len = mountainArr.length();
        int low = 1, high = len-2,peak = -1;
        while(low <= high){
            int mid = low + (high-low)/2;

            int left = mountainArr.get(mid-1);
            int btw = mountainArr.get(mid);
            int right = mountainArr.get(mid+1);

            if (btw > left && btw > right){
                peak = mid;
                break;
            }
            else if (left < btw && btw < right) low = mid + 1;
            else high = mid - 1;
        }
        if (mountainArr.get(peak) == target) return peak;
        //left half
        low = 0, high = peak-1;
        while(low <= high){
            int btw = low + (high-low)/2;
            int val = mountainArr.get(btw);
            if(val == target) return btw;
            else if(val < target) low = btw+1;
            else high = btw-1;
        }
        //right half
        low = peak+1,high = len-1;
        while(low <= high){
            int btw = low + (high-low)/2;
            int val = mountainArr.get(btw);
            if(val == target) return btw;
            else if(val < target) high = btw-1;
            else low = btw+1;
        }
        return -1;
  
    }
};