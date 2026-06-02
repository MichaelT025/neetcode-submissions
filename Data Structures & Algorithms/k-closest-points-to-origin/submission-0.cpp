class Solution {
public:
    struct dist{
        bool operator()(vector<int>one, vector<int>two){
            return (one[0]*one[0]+one[1]*one[1])>(two[0]*two[0]+two[1]*two[1]);
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, dist> minHeap;
        for(auto curr: points) minHeap.push(curr);
        vector<vector<int>>result;
        for(int i=0;i<k;i++){
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        return result;
    }
};
