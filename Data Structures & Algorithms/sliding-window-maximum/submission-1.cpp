class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> leftmax(n);
        vector<int> rightmax(n);
        leftmax[0] = nums[0];
        rightmax[n-1] = nums[n-1];
        for(int i = 1;i<n;i++){
            leftmax[i] = (i%k==0)?nums[i]:max(leftmax[i-1],nums[i]);
            rightmax[n-i-1] = ((n-i-1)%k==0)?nums[n-i-1]:max(rightmax[n-i],nums[n-i-1]);
        }
        vector<int> ans(n-k+1);
        for(int i = 0;i<n-k+1;i++){
            ans[i] = (max(leftmax[i+k-1],rightmax[i]));
        }
        return ans;

    }
};
