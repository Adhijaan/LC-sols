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
        if(!node) return nullptr;
        unordered_map<int,Node*> visited_nodes;
        return dfs(node,visited_nodes);
    }
    Node* dfs(Node* node, unordered_map<int,Node*> & visited_nodes) {
        Node *n = new Node(node->val);
        n->neighbors.reserve(node->neighbors.size());
        visited_nodes.emplace(n->val,n);
        for(const auto c: node->neighbors){
            auto iter = visited_nodes.find(c->val);
            if(iter == visited_nodes.end()){
                n->neighbors.emplace_back(dfs(c,visited_nodes));
            } else {
                n->neighbors.emplace_back(iter->second);
            }
        }        
        return n;
    }
};