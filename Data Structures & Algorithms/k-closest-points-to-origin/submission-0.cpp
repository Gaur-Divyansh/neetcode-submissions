class Solution {
    typedef pair<int,vector<int>> entry;
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<entry> maxHeap;
        for(vector<int> point : points){
            maxHeap.push({(point[0]*point[0] + point[1]*point[1]),point});
            if(maxHeap.size() > k) maxHeap.pop();
        }
        while(!maxHeap.empty()){
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return res;
    }
};