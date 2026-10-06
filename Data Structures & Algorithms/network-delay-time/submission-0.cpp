class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        std::vector<vector<pair<int, int>>> graph(n + 1);  

        // Build directed weighted graph
        for (const auto& edge : times) {
            graph[edge[0]].push_back({edge[2], edge[1]});
        }

        std::priority_queue<
            pair<int, int>,
            std::vector<pair<int, int>>,
            std::greater<pair<int, int>>
        > nodes;

        std::vector<int> costs(n + 1, std::numeric_limits<int>::max());
        
        vector<bool> visited(n + 1, false);
        int visitedCount = 0;
        int maxPath = 0;

        costs[k] = 0;
        nodes.push({0, k});

        while (!nodes.empty()) {
            auto [cost, node] = nodes.top();
            nodes.pop();

            if (visited[node]) {
                continue;
            }

            visited[node] = true;
            visitedCount++;
            maxPath = cost;

            for (const auto& [weight, neighbor] : graph[node]) {
                if (!visited[neighbor] && 
                    cost + weight < costs[neighbor]) {
                        costs[neighbor] = cost + weight;
                        nodes.push({costs[neighbor], neighbor});
                }
            }
        }

        return visitedCount == n ? maxPath : -1;
    }
};
