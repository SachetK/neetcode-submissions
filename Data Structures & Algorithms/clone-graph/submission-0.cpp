/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        std::unordered_map<int, Node*> graph;
        graph[1] = new Node(1);

        std::queue<Node*> nodes;
        nodes.push(node);

        while (!nodes.empty()) {
            auto tp = nodes.front();
            nodes.pop();
            
            for (const auto& nb : tp->neighbors) {
                if (!graph.contains(nb->val)) {
                    graph[nb->val] = new Node(nb->val);
                    nodes.push(nb);
                }

                graph[tp->val]->neighbors.push_back(graph[nb->val]);
            }
        }
        
        return graph[1];
    }
};
