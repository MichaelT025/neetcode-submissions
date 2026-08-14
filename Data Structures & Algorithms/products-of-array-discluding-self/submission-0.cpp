class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> prefix(size);
        vector<int> suffix(size);
        int pre = 1;
        int suff = 1;
        prefix[0] = suffix[size-1] = 1;
        for( int i = 1; i< size; i++){
            pre *=nums[i-1];
            prefix[i] = pre;
        }
        for(int i = size-2; i>=0; i--){
            suff *= nums[i+1];
            suffix[i] =suff;
        }
        vector<int> ans;
        for(int i = 0; i<size; i++ ){
            ans.push_back(prefix[i]*suffix[i]);
        }
        return ans;
    }
};
