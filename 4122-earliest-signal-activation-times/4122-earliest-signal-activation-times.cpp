class Solution {
public:
       vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges, vector<int>& requiredSignals) {
        vector<vector<pair<int, int>>> g(n);
        for (auto& e : edges) {
            g[e[0]].emplace_back(e[2], e[1]);
        }
        vector<long long> res(n, -1);
        res[0] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;
        for (auto& [d, v] : g[0]) {
            q.emplace(d, v);
        }
        while (!q.empty()) {
            auto [t, u] = q.top();
            q.pop();
            if (res[u] >= 0) {
                continue;
            }
            if (--requiredSignals[u] == 0) {
                res[u] = t;
                for (auto& [d, v] : g[u]) {
                    if (res[v] < 0) {
                        q.emplace(t + d, v);
                    }
                }
            }
        }
        return res;
    }
};