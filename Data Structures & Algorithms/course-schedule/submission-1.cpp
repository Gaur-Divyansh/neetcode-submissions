class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }
        vector<int> state(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, adj, state)) return false;
        }
        return true;
    }

    bool dfs(int i, vector<vector<int>>& adj, vector<int>& state) {
        if (state[i] == 1) return false;
        if (state[i] == 2) return true;
        state[i] = 1;
        for (int next : adj[i]) {
            if (!dfs(next, adj, state)) return false;
        }
        state[i] = 2;
        return true;
    }
};