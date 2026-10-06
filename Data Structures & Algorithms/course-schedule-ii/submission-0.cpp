class Solution {
public:
    bool dfs(int course, vector<int>& states, vector<int>& visited, vector<vector<int>>& courses) {
        std::stack<pair<int, int>> nodes;
        nodes.push({course, 0});

        while (!nodes.empty()) {
            auto [c, exit] = nodes.top();
            nodes.pop();

            if (exit) {
                states[c] = 2;
                visited.push_back(c);
            }

            if (states[c] == 2) {
                continue;
            }

            if (states[c] == 1) {
                return false;
            }

            states[c] = 1;
            nodes.push({c, 1});

            for (const auto& nb : courses[c]) {
                nodes.push({nb, 0});
            }
        }

        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<vector<int>> courses(numCourses);
        for (const auto& pr : prerequisites) {
            courses[pr[0]].push_back(pr[1]);
        }

        std::vector<int> visited;
        std::vector<int> states(numCourses, 0);

        for (auto i = 0; i < numCourses; i++) {
            if (states[i] == 0 && !dfs(i, states, visited, courses)) {
                return {};
            }
        }

        return visited;
    }
};
