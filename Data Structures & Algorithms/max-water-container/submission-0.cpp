class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0,j=n-1;
        int max_ = INT_MIN;
        while (i<j){
            max_ = max((j-i)*min(heights[i],heights[j]),max_);
            (heights[i]>heights[j])?j--:i++;
        }
        return max_;
    }
};
