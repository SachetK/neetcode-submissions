class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int start, std::vector<int>& states) {
        std::stack<pair<int, int>> nodes;
        nodes.push({ start, 0 });

        while (!nodes.empty()) {
            auto [val, exit] = nodes.top();
            nodes.pop();
            
            if (exit) {
                states[val] = 2;
            }

            if (states[val] == 2) {
                continue;
            }

            if (states[val] == 1) {
                return false;
            }

            states[val] = 1;
            nodes.push({ val, 1 });
            for (const auto& nb : graph[val]) {
                nodes.push({ nb, 0 });
            }
        }

        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<vector<int>> graph(numCourses);
        for (const auto& pr : prerequisites) {
            graph[pr[1]].push_back(pr[0]);
        }

        std::vector<int> states(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (states[i] == 0 && !dfs(graph, i, states)) {
                return false;
            }
        }
        
        return true;
    }
};
