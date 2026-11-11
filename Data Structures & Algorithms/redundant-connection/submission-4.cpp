class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size()+1);
        vector<int> indegree(edges.size()+1);
        for(int i = 0; i < edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
        }
            queue<int> q;
          for(int i = 1;i <= edges.size();i++){
            if(indegree[i] == 1) q.push(i);
          }
          while(!q.empty()){
            int node = q.front();
            q.pop();
            indegree[node]--;
            for(int nei : adj[node]){
                indegree[nei]--;
                if(indegree[nei]==1) q.push(nei);
            }
          }
        
        for(int i = edges.size()-1;i>=0;i--){
            int u = edges[i][0],v = edges[i][1];
            if(indegree[u] == 2 && indegree[v]) return {u,v};
        }
        return {};
    }
};
