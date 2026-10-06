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
        } else {
            parent[rootB] = rootA;
            if (rank[rootA] == rank[rootB]) {
                rank[rootA]++;
            }
        }

        return true;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        std::vector<int> parent(n);
        std::vector<int> rank(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        auto components = n;
        for (const auto& edge : edges) {
            if (unite(edge[0], edge[1], parent, rank)) {
                components--;
            }
        }
        return components;
    }
};
