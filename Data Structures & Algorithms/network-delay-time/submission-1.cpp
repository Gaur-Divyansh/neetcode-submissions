class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>> adj(n+1);
        for(int i = 0;i < times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int> time(n+1,INT_MAX);
        time[k] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        minHeap.push({0,k});
        while(!minHeap.empty()){
            pair<int,int> p = minHeap.top();
            minHeap.pop();
            int t = p.first;
            int node = p.second;
            if(t > time[node]) continue;
            for(auto j : adj[node]){
                int nei = j[0];
                int wt = j[1];
                if(t + wt < time[nei]){
                    time[nei] = t+wt;
                    minHeap.push({t+wt,nei});
                }
            }
        }
        int res = 0;
        for(int i = 1;i <= n;i++){
            if(time[i] == INT_MAX) return -1;
            if(time[i] > res) res = time[i]; 
        }
        return res;
    }
};
