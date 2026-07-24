class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> st;
        int n = temp.size();
        st.push(n-1);
        vector<int> ans(n);
        ans[n-1] = 0;
        for(int i = n-2;i>=0;i--){
            while (!st.empty() && temp[st.top()]<=temp[i]){
                st.pop();
            }
            ans[i] = (st.empty())?0:(st.top()-i);
            st.push(i);
        }
        return ans;
    }
};
