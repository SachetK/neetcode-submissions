class Solution {
public:
    bool dfs(int start, int n, std::unordered_map<int, vector<int>>& graph, std::unordered_set<int>& visited) {
        // 0 - haven't visited
        // 1 - currently visiting
        // 2 - visited
        std::vector<int> state(n, 0);

        // node, parent (so we don't go backwards), exiting
        std::stack<tuple<int, int, bool>> nodes;
        nodes.push({start, -1, false});

        while (!nodes.empty()) {
            auto tp = nodes.top();
            nodes.pop();
            const auto& [val, parent, exit] = tp;
            
            if (exit == true) {
                state[val] = 2;
                visited.insert(val);
                continue;
            }

            if (state[val] == 2) {
                continue;
            }

            if (state[val] == 1) {
                return false;    
            }

            state[val] = 1;
            nodes.push({ val, parent, true });

            for (auto neigh : graph[val]) {
                if (neigh != parent) { 
                    nodes.push({ neigh, val, false });
                }
            }
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        std::unordered_map<int, vector<int>> graph(n);
        
        if (edges.size() != n - 1) {
            return false;
        }

        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        std::unordered_set<int> visited;

        return dfs(0, n, graph, visited) && visited.size() == n;
    }
};
