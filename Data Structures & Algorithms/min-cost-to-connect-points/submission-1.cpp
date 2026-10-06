class Solution {
public:
    int find(int x, vector<int>& parent) {
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }

        return x;
    }

    bool unite(int a, int b, vector<int>& parent, vector<int>& rank) {
        int rootA = find(a, parent);
        int rootB = find(b, parent);

        if (rootA == rootB) {
            return false;
        }

        if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        } else if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        } else {
            parent[rootB] = rootA;
            rank[rootA]++;
        }

        return true;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        std::priority_queue<
            pair<int, pair<int, int>>, 
            std::vector<pair<int, pair<int, int>>>,
            std::greater<pair<int, pair<int, int>>>
        > edges;

        std::vector<int> parent(points.size());
        std::vector<int> rank(points.size(), 0);

        for (int i = 0; i < points.size(); i++) {
            parent[i] = i;

            for (int j = i + 1; j < points.size(); j++) {
                if (i == j) {
                    continue;
                }

                auto p1 = points[i];
                auto p2 = points[j];

                auto distance = 
                    std::abs(p1[0] - p2[0]) + std::abs(p1[1] - p2[1]);

                edges.push({distance, {i, j}});
            }
        }
        
        auto added = 0;
        auto totalCost = 0;

        while (!edges.empty() && added < points.size() - 1) {
            auto [cost, endPoints] = edges.top();
            auto [i, j] = endPoints;
            edges.pop();

            if (find(i, parent) == find(j, parent)) {
                continue;
            }

            unite(i, j, parent, rank);
            totalCost += cost;
            added++;
        }

        return totalCost;
    }
};
