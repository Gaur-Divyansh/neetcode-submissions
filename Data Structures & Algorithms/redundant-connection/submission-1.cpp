class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size()+1);
        for(int i = 0; i < edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            vector<bool> visit(edges.size()+1,false);
            if(dfs(edges[i][0],-1,adj,visit)) return {edges[i][0],edges[i][1]};
        }
        return {};
    }
    bool dfs(int node,int parent,vector<vector<int>>& adj,vector<bool>& visit){
        if(visit[node]) return true;
        visit[node]= true;
        for(int nei : adj[node]){
            if(nei == parent) continue;
            if(dfs(nei,node,adj,visit)) return true;
        }
        return false;
    }
};
