class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> mono;
        vector<int> result(temperatures.size(),0);
        for(int i=0;i<temperatures.size();i++){
            int t=temperatures[i];
            while(!mono.empty() && t>mono.top().second){
                auto curr=mono.top(); mono.pop();
                result[curr.first]=i-curr.first;
            }
            mono.push({i,t});
        }
        return result;
    }
    
};
