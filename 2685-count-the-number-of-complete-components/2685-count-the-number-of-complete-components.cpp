class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, int& nodes,
             int& edge) {
        vis[node] = 1;
        nodes++;
        edge += adj[node].size();
        for (int i : adj[node]) {
            if (!vis[i]) {
                dfs(i, adj, vis, nodes, edge);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int nodes = 0;
                int edge = 0;
                dfs(i, adj, vis, nodes, edge);
                edge /= 2;
                if (edge == nodes * (nodes - 1) / 2)
                    count++;
            }
        }
        return count;
    }
};