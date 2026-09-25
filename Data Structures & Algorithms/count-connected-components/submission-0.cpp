class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        std::unordered_map<int, vector<int>> graph;
        
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        std::unordered_set<int> visited;
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (!visited.contains(i)) {
                std::queue<int> nodes;
                nodes.push(i);

                while (!nodes.empty()) {
                    auto tp = nodes.front();
                    nodes.pop();

                    visited.insert(tp);

                    for (auto n : graph[tp]) {
                        if (!visited.contains(n)) {
                            nodes.push(n);
                        }
                    }
                }

                components++;
            }
        }

        return components;
    }
};
