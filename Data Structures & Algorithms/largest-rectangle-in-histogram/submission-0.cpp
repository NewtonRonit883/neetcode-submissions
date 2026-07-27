class Solution {
public:
    vector<int> Right(vector<int>& heights){
        int n = heights.size();
        stack<int> st;
        st.push(n-1);
        vector<int> ans(n);ans[n-1] = n;
        for(int i=n-2;i>=0;i--){
            while (!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            ans[i] = (st.empty())?n:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> Left(vector<int>& heights){
        int n = heights.size();
        stack<int> st;
        st.push(0);
        vector<int> ans(n);ans[0] = -1;
        for(int i=0;i<n;i++){
            while (!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            ans[i] = (st.empty())?-1:st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> right = Right(heights);
        vector<int> left = Left(heights);
        int max_ = INT_MIN;
        for(int i = 0;i<n;i++){
            int l = left[i]+1;
            int r = right[i]-1;
            max_ = max(max_ , (r-l+1)*heights[i]);
        }
        return max_;
    }
};
