class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int pdt = 1;
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if (nums[i]!=0){
                pdt *= nums[i];
            }else{
                cnt++;
            }
        }
        for(int i = 0;i<n;i++){
            if (nums[i]==0){
                ans[i] = (cnt>1)?0:pdt;
            }else{
                ans[i] = (cnt>0)?0:pdt/nums[i];
            }
        }
        return ans;
    }
};
