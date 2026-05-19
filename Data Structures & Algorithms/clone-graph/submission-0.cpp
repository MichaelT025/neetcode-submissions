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
        while(!bfs.empty()){
            Node *curr= bfs.front(); bfs.pop();
            if(!visited.contains(curr)){
                Node* newcurr= new Node(curr->val);
                visited[curr]=newcurr;
                for(auto it: curr->neighbors) bfs.push(it);
            }
        }
        for(auto it=visited.begin(); it!=visited.end(); it++){
            Node* orig=it->first;
            Node* copy=it->second;
            for(auto temp: orig->neighbors) 
                copy->neighbors.push_back(visited[temp]);
        }
        return visited[node];
    }
};
