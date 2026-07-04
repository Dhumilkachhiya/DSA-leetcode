class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        int score = INT_MAX;
        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int w = road[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        queue<int> q;
        q.push(1);
        vector<int> vis(n + 1, 0);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (vis[node] == 1)
                continue;
            vis[node]=1;
            for (auto& it : adj[node]) {
                int nn = it.first;
                int cost = it.second;
                score = min(score, cost);
                if (vis[nn] != 1) {
                    q.push(nn);
                }
            }
        }
        return score;
    }
};