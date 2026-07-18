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
    Node* cpy(Node* root){
        if (!root) return nullptr;
        return new Node(root->val);
    }
    void bfs(deque<Node*> &q,deque<Node*> &q2,unordered_map <Node*,Node*> &m){
        if(!q.size()) return;
        while(q.size()){
            Node* t =q.front();
            vector<Node*> neighbors;
            for (const auto v : t->neighbors){
                if (m.find(v)==m.end()){
                    Node* c = cpy(v);
                    m[v]=c;
                    q.push_back(v);
                    q2.push_back(m[v]);
                }
                neighbors.push_back(m[v]);
            }
            q2.front()->neighbors = neighbors;
            q.pop_front();
            q2.pop_front();
        }
        return;
    }
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        Node * curr = new Node(node->val);
        unordered_map <Node*,Node*> m;
        deque<Node*> q,q2;
        q.push_back(node);
        q2.push_back(curr);
        m[node]=curr;
        bfs(q,q2,m);
        return curr;
    }
};
