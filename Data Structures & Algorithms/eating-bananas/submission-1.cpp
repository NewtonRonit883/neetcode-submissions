class Solution {
public:
    bool check(vector<int>& piles,int k,int h){
        int cnt = 0;
        //int sum = 0;
        for(int i : piles){
            cnt += (i + k - 1) / k;
        }
        return cnt<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans = high;
        while (low<=high){
            int mid = low + (high-low)/2;
            if (check(piles,mid,h)){
                high = mid-1;
                ans = mid;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};
