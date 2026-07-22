class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int i =0,j = 0;
        int n = s.size();
        int longest = 0;
        while (j<n){
            if (mp.count(s[j]) && mp[s[j]] > 0){
                mp[s[i]]--;
                i++;
            }else{
                mp[s[j]]++;
                longest = max(longest,j-i+1);
                j++;
            }
        }
        return longest;
    }
};
