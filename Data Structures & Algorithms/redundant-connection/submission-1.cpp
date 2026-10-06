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
        int pa = find(a, parent);
        int pb = find(b, parent);

        if (pa == pb) {
            return false;
        }

        if (rank[pa] < rank[pb]) {
            parent[pa] = pb;
        } else {
            parent[pb] = pa;
            if (rank[pa] == rank[pb]) {
                rank[pa]++;
            }
        }

        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = 0;
        for (const auto& edge : edges) {
            n = std::max(n, edge[0]);
            n = std::max(n, edge[1]);
        }
                
        std::vector<int> parent(n);
        std::vector<int> rank(n, 0);
        
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (const auto& edge : edges) {
            auto a = edge[0] - 1;
            auto b = edge[1] - 1;

            if (!unite(a, b, parent, rank)) {
                return edge;
            }
        }
        
        return {}; // should never reach here;
    }
};
