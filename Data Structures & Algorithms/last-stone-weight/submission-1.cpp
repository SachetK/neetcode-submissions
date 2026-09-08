class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> simulation(stones.begin(), stones.end());

        while (simulation.size() > 1) {
            int x = simulation.top();
            simulation.pop();
            int y = simulation.top();
            simulation.pop();
            if (x != y) {
                simulation.push(x - y);
            }
        }

        simulation.push(0);
        return simulation.top();
    }
};
