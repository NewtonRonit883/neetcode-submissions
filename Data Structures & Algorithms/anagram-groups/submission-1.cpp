class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;

        for(auto& s : strs){
            vector<int> count(26);
            for(char& c : s){
                count[c-'a']++;
            }
            string s1 = "";
            for(int i = 0;i<26;i++){
                s1+=to_string(count[i])+',';
            }
            mp[s1].push_back(s);
        }
        vector<vector<string>> result;
        for(auto& p : mp ){
            result.push_back(p.second);
        }
        return result;
    }
};
