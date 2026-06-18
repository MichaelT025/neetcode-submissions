class Solution {
public:
    unordered_set<int> checked;
    unordered_set<int> preqs;
    unordered_map<int, vector<int>>classes;
    bool check(vector<int> &nums, int find){
        for (int num: nums){
            if(num == find) return true;
        }
        return false;
    }
    // bool initdfs(int num){
    //     unordered_set<int> preqs;
    //     return dfs(num, preqs);
    // }
    bool dfs(int curr){
        if(preqs.contains(curr)) return false;
        if(!classes.contains(curr) || checked.contains(curr)) return true;
        preqs.insert(curr);
        vector<int> next = classes[curr];
        bool valid = true;
        for (int i: next){
            valid = dfs(i);
            if(!valid) return false;
            checked.insert(i);
        }
        preqs.erase(curr);
        return true;

    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto nums: prerequisites){
            classes[nums[0]].push_back(nums[1]);
        }
        for ( auto it: classes){
            bool valid = dfs(it.first);
            if(!valid) return false;
        }
        return true;
    }
};
