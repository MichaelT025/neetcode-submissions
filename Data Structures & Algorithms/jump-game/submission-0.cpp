class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size()-1;
        int i = goal-1;
        while(i>=0){
            if(i+nums[i]>=goal){
                goal=i;
                i=goal-1;
            } else i--;
        }
        return goal==0 ? true : false;
    }
};
