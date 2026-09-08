class TimeMap {
public:
    std::unordered_map<string, std::map<int, string>> store;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto history = store.find(key);
        if (history == store.end()) {
            return "";
        }

        auto&& more = history->second.upper_bound(timestamp); // first element greater than timestamp
        if (more == history->second.begin()) {
            return "";
        }

        return std::prev(more)->second;
    }
};
