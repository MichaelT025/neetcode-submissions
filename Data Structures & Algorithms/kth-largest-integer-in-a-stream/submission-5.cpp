class KthLargest {
    
    vector<int> heap;
    int size=0;
    
    void swap(int &one, int &two){
        int temp = one;
        one = two;
        two = temp;
    }
    void heapifyUp(int i){
        if(i==0) return;
        int p = (i-1)/2;
        if(heap[i]<heap[p]){
            swap(heap[i], heap[p]);
            heapifyUp(p);
        }
    }

    void heapifyDown(int index){
        int l = 2 * index + 1;
        int r = 2 * index + 2;
        int small = index;
        if(l<heap.size() && heap[l]< heap[small]) small = l;
        if(r<heap.size() && heap[r]< heap[small]) small = r;
        if(small != index){
            swap(heap[index], heap[small]);
            heapifyDown(small);
        }
    }
    int extract_min(){
        int min = heap[0];
        swap(heap[0], heap[size-1]);
        heap.pop_back();
        heapifyDown(0);
        return min;
    }
    void push(int val){
        if(heap.size()<size){
            heap.push_back(val);
        } else if (val>heap[0]) {
            extract_min();
            heap.push_back(val);
        }
        
        heapifyUp(heap.size()-1);
    }

public:
    
    KthLargest(int k, vector<int>& nums) {
        this->size = k;
        for(int num: nums){
            push(num);
        }
    }
    int add(int val) {
    push(val);
    return heap[0];
}
};
