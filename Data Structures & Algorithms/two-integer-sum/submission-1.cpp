class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> lookup;
        for(int i=0;i<nums.size();i++){
            int t = target-nums[i];
            if(lookup.contains(t)){
                return { min(i, lookup[t]), max(i, lookup[t])};
            }
            else lookup[nums[i]] = i;
        }
        return {-1, -1};
    }
};
