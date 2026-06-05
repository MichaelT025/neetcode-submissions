class MedianFinder {
    priority_queue<int> leftHeap;
    priority_queue<int, vector<int>, greater<int>> rightHeap;
    vector<int>nums;
    int prevmid;
    void adjust(int num){
        nums.push_back(num);
        rightHeap.push(num);
        int mid = nums.size()/2;
        if(abs((int)(leftHeap.size()-rightHeap.size()))>1){
            if(leftHeap.size()>rightHeap.size()){
                rightHeap.push(leftHeap.top());
                leftHeap.pop();
            } else {
                leftHeap.push(rightHeap.top());
                rightHeap.pop();    
            }
        }
        if(!leftHeap.empty() && !rightHeap.empty() && rightHeap.top()<=leftHeap.top()){
            int l = leftHeap.top(); leftHeap.pop();
            int r = rightHeap.top(); rightHeap.pop();
            rightHeap.push(l);
            leftHeap.push(r);
        }

        prevmid=mid;
    }
public:
    MedianFinder() {
        prevmid = 0;
    }
    
    void addNum(int num) {
        adjust(num);
    }
    
    double findMedian() {
        if(nums.size()%2==0){
            int m1 = leftHeap.top();
            int m2 = rightHeap.top();
            return (m1 + m2)/2.0;
        }
        if(leftHeap.size()>rightHeap.size()) return leftHeap.top();
        return rightHeap.top();
    }
};
