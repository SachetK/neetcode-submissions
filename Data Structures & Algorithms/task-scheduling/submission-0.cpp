class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::vector<int> freq(26, 0);

        for (auto task : tasks) {
            freq[task - 'A']++;
        }

        std::priority_queue<int> todo;
        
        for (int count : freq) {
            if (count > 0) {
                todo.push(count);
            }
        }

        std::queue<pair<int, int>> cooldown;
        int time = 0;

        while (!todo.empty() || !cooldown.empty()) {
            time++;

            // Release tasks whose cooldown has expired
            if (!cooldown.empty() &&
                cooldown.front().second == time) {
                todo.push(cooldown.front().first);
                cooldown.pop();
            }

            if (!todo.empty()) {
                int new_count = todo.top() - 1;
                todo.pop();

                if (new_count > 0) {
                    cooldown.push({new_count, time + n + 1});
                }
            }
        }

        return time;
    }
};
