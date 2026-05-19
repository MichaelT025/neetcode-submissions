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
        unordered_map<Node*, Node*> visited;
        queue<Node *> bfs;
        bfs.push(node);
        Node* newNode= new Node(node->val);
        visited[node]=newNode;
        while(!bfs.empty()){
            Node *curr= bfs.front(); bfs.pop();
                for(auto neighbor: curr->neighbors){
                    if(!visited.contains(neighbor)){
                        visited[neighbor]= new Node(neighbor->val);
                        bfs.push(neighbor);
                    }
                    visited[curr]->neighbors.push_back(visited[neighbor]);
                    
                }
            }
        return newNode;
    }
};
