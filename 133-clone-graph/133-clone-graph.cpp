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
    unordered_map<Node*, Node*> visited;
    
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        
        // If not present
        if (visited.find(node) == visited.end()) {
            // Create new node and add as value to 'node' key in visited
            visited[node] = new Node(node->val, {});
            
            // Do same for neighbors
            for (Node* n : node->neighbors) {
                visited[node]->neighbors.push_back(cloneGraph(n));
            }
        }
        
        return visited[node];
    }
};