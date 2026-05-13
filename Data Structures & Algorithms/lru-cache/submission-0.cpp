class Node{
public:
    int value;
    int priority;
    Node(int num1, int num2){
        value=num1;
        priority=num2;
    }
};
class LRUCache {
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    ~LRUCache(){
        for(auto it: map) delete it;
    }
    
    int get(int key) {
        max_prio++;
        if(!map[key]) return -1;
        map[key]->priority=max_prio;
        return map[key]->value;
        
    }
    
    void put(int key, int value) {
        max_prio++;
        if(!map[key]){
            if(size==cap) remove();
            Node* curr= new Node(value, max_prio);
            map[key]=curr;
            size++;
        }else{
            map[key]->value=value;
            map[key]->priority=max_prio;
        }
    }
private:
    vector<Node *> map = vector<Node *>(1000, nullptr);
    int max_prio=0;
    int cap;
    int size=0;
    void remove(){
        int key;
        int min=INT_MAX;
        for(int i=map.size()-1;i>=0; i--){
            if(!map[i]) continue;
            auto curr=map[i];
            if(curr->priority<min){
                min=curr->priority;
                key=i;
            }
        }
        delete map[key];
        map[key]=nullptr;
        size--;
    }
};


