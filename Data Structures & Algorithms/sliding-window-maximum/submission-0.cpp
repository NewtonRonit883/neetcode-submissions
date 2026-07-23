class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (k==1 || n==1) return nums;
        priority_queue<pair<int,int>> pq;
        
        for(int i = 0;i<min(k,n);i++){
            pq.push({nums[i],i});
        }
        vector<int> windows;
        windows.push_back(pq.top().first);
        
        for(int i = k;i<n;i++){
            pq.push({nums[i],i});
            while (pq.top().second <= i-k){
                pq.pop();
            }
            windows.push_back(pq.top().first);
        }
        return windows;

    }
};
