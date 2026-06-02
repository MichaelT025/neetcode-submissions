class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*
        maintain minHeap of k elements
        push if the new element is larger than top
        */
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int num: nums){
            if(minHeap.size()==k){
                if(num>minHeap.top()){
                    minHeap.pop();
                    minHeap.push(num);
                }
            } else minHeap.push(num);
        }
        return minHeap.top();
    }
};