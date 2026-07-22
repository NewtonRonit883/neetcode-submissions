class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n<=1) return n;
        sort(nums.begin(),nums.end());
        int cnt = 1;
        int max_cnt = 1;
        for(int i =1;i<n;i++){
            if (nums[i] == nums[i - 1]) {
                continue;                  // Ignore duplicates
            }
            else if (nums[i] == nums[i - 1] + 1) {
                cnt++;                     // Consecutive element
            }
            else {
                max_cnt = max(max_cnt, cnt);
                cnt = 1;                   // Start new sequence
            }
        }
        max_cnt = max(cnt,max_cnt);
        return max_cnt;
    }
};
