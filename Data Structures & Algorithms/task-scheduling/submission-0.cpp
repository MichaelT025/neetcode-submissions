class Solution {
    
public:
    int leastInterval(vector<char>& tasks, int n) {
        int move[26] = {0};
        for(char c: tasks){
            move[c-'A']++;
        }
        priority_queue<int> maxHeap;
        for(int i=0; i<26;i++){
            if (move[i]==0) continue;
            maxHeap.push(move[i]);
        }
        queue<pair<int, int>> cooldown;
        int cyc=0;;
        while(!maxHeap.empty() || !cooldown.empty()){
            cyc++;
            if(!maxHeap.empty()){
                int currTask=maxHeap.top(); maxHeap.pop();
                if((--currTask)>0){
                    cooldown.push({currTask, cyc+n});
                }
            }
            if(!cooldown.empty()){
                auto popd = cooldown.front();
                if (popd.second==cyc){
                    maxHeap.push(popd.first);
                    cooldown.pop();
                }
            }
        }
        return cyc;
    }
};
