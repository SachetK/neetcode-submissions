class Solution {
public:
    bool dfs(int start, int n, std::vector<int>& states, std::unordered_map<int, vector<int>>& graph) {
        std::stack<pair<int, int>> nodes;
        nodes.push({ start, 0 });

        while (!nodes.empty()) {
            auto [val, exit] = nodes.top();
            nodes.pop();

            if (exit) {
                states[val] = 2;
                continue;
            }

            if (states[val] == 2) {
                continue;
            }

            if (states[val] == 1) {
                return false;
            }

            states[val] = 1;

            nodes.push({ val, 1 });

            for (const auto nb : graph[val]) {
                nodes.push({ nb, 0 });
            }
        }

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::unordered_map<int, vector<int>> graph(numCourses);

        for (const auto& edge : prerequisites) {
            graph[edge[0]].push_back(edge[1]);
        }

        std::vector<int> states(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (states[i] == 0) {
                if (!dfs(i, numCourses, states, graph)) {
                    return false;
                }
            }
        }

        return true;
    }
};
