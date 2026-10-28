class Solution {
public:
    int find(int x, std::vector<int>& parents) {
        while (x != parents[x]) {
            parents[x] = parents[parents[x]];
            x = parents[x];
        }

        return x;
    }

    bool unite(int a, int b, std::vector<int>& parents, std::vector<int>& ranks) {
        int pa = find(a, parents);
        int pb = find(b, parents);

        if (pa == pb) {
            return false;
        }

        if (ranks[pa] < ranks[pb]) {
            parents[pa] = pb;
        } else {
            parents[pb] = pa;
            if (ranks[pa] == ranks[pb]) {
                ranks[pb]++;
            }
        }

        return true;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        auto parents = std::vector<int>(n);
        auto ranks = std::vector<int>(n, 0);
        int components = n;

        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }

        for (const auto& edge : edges) {
            if (unite(edge[0], edge[1], parents, ranks)) {
                components--;
            }
        }

        return components;
    }
};
