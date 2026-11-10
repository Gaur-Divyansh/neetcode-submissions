class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto& pre : prerequisites){
            indegree[pre[1]]++;
            adj[pre[0]].push_back(pre[1]);
        }
        queue<int> q;
        for(int i = 0; i < numCourses;i++){
            if(indegree[i] == 0) q.push(i);
        }
        int finish = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            finish++;
            for(int neighbor : adj[node]){
                indegree[neighbor]--;
                if(indegree[neighbor] == 0) q.push(neighbor);
            }
        }
        if(finish != numCourses) return {};
        reverse(res.begin(),res.end());
        return res;
        
    }
};