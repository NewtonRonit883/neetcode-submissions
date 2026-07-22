class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        //if (n==m) return s1==s2;
        if (n>m) return false;
        vector<int> freq_s1(26),freq_s2(26);;
        for(char c : s1){
            freq_s1[c-'a']++;
        }
        
        for(int i = 0;i<n;i++){
                freq_s2[s2[i]-'a']++;
        }
        if (freq_s1 == freq_s2) return true;
        int i = 0, j = n;
        while (j<m){
            freq_s2[s2[j]-'a']++;
            freq_s2[s2[i]-'a']--;
            i++;j++;
            if (freq_s1 == freq_s2) return true;
        }
        return false;
    }
};
