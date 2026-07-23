class MinStack {
public:
    stack<int> st;
    map<int,int> mp;
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        mp[val]++;
    }
    
    void pop() {
        int val = st.top();
        st.pop();
        mp[val]--;
        if (mp[val]==0){
            mp.erase(val);
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        auto it = mp.begin();
        return it->first;
    }
};
