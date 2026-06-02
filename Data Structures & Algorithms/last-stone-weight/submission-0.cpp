class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxHeap;
        for(int num: stones) maxHeap.push(num);
        while(maxHeap.size()>1){
            int one= maxHeap.top(); maxHeap.pop();
            int two = maxHeap.top(); maxHeap.pop();
            if(one==two) continue;
            maxHeap.push(abs(one-two));
        }
        return maxHeap.size()==1 ? maxHeap.top() : 0;
    }
};