class Solution {
public:
    long long minimumCost(string& source, string& target, vector<char>& original, vector<char>& changed, vector<int>& cost) 
    {
        const long long INF = numeric_limits<long long>::max() / 4;
        long long ans = 0;
        vector<vector<long long>> dist(26, vector<long long>(26, INF));

        for (size_t i = 0; i < cost.size(); ++i) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < 26; ++k)
            for (int i = 0; i < 26; ++i)
                if (dist[i][k] < INF)
                    for (int j = 0; j < 26; ++j)
                        if (dist[k][j] < INF)
                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        for (size_t i = 0; i < source.size(); ++i) {
            if (source[i] == target[i]) continue;
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if (dist[u][v] >= INF) return -1;
            ans += dist[u][v];
        }

        return ans;
    }
};