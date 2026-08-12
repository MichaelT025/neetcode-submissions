class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> letters;
        for(string word: strs){
            vector<int> freq(26,0);
            for(char i : word) freq[i-'a']++;
            letters[freq].push_back(word);
        }
        vector<vector<string>> groups;
        for(auto it : letters){
            groups.push_back(it.second);
        }
        return groups;
    }
};
