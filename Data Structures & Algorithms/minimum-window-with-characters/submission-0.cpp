class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        vector<int> s1(128);
        vector<int> s2(128);

        for(char c : t){
            s2[c]++;
        }
        int i = 0,j=0;
        int matches= 0;
        string ans = "";
        int len = INT_MAX;
    
        while (j<n1){
            if (s2[s[j]]){
                s1[s[j]]++;
                if (s1[s[j]]<=s2[s[j]]){
                    matches++;
                }
            }
            
            while (matches == n2){
                if (j-i+1 <len){
                    len = j-i+1;
                    ans = s.substr(i,j-i+1);
                }
                if (s1[s[i]]){
                    if (s1[s[i]]<=s2[s[i]]){
                        matches--;
                    }
                    s1[s[i]]--;
                }
                i++;
            }
            j++;
        }
        return (len == INT_MAX)?"":ans;
    }
};
