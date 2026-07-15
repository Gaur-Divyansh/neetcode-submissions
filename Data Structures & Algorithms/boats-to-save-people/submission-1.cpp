class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int l = 0, h  = people.size()-1;
        int boat = 0;
        while(l <= h){
            if(people[l] + people[h] <= limit){
                 boat++;
                 l++;
                 h--;
            }
            else {
                boat++;
                h--;
            }
        }
        return boat;
    }
};