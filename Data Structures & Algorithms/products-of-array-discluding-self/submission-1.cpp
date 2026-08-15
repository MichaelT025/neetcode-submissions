class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size);
        res[0] = 1;
        for (int i=1; i<size; i++){
            res[i] = res[i-1] * nums[i-1];
        }
        int suff = 1;
        for (int i=size-2; i>=0; i--){
            suff *= nums[i+1];
            res[i] *= suff;
        }
        return res;
    }
};
