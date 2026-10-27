class Solution {
   public:
    int find(std::vector<int>& parents, int x) {
        while (x != parents[x]) {
            parents[x] = parents[parents[x]];
            x = parents[x];
        }

        return x;
    }

    bool unite(std::vector<int>& parents, std::vector<int>& ranks, int a, int b) {
        int pa = find(parents, a);
        int pb = find(parents, b);

        if (pa == pb) {
            return false;
        }

        if (ranks[pa] < ranks[pb]) {
            parents[pa] = pb;
        } else if (ranks[pa] > ranks[pb]) {
            parents[pb] = pa;
        } else {
            parents[pb] = pa;
            ranks[pa]++;
        }

        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        std::vector<int> parents(n);
        std::vector<int> ranks(n, 1);

        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }

        for (const auto& edge : edges) {
            if (!unite(parents, ranks, edge[0] - 1, edge[1] - 1)) {
                return {edge[0], edge[1]};
            }
        }

        return {};
    }
};
