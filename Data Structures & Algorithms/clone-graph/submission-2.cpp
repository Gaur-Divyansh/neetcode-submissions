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
        unordered_map<Node*,Node*> mp;
        return dfs(node,mp);
    }
    Node* dfs(Node* node, unordered_map<Node*,Node*>& mp){
        if(!node) return node;
        if(mp.find(node) != mp.end()) return mp[node];

        Node* clone = new Node(node->val);
        mp[node] = clone;

        for(Node* neighbor : node->neighbors){
            Node* neighbor_clone = dfs(neighbor,mp);
            clone->neighbors.push_back(neighbor_clone);
        }
        return clone;
    }
};
