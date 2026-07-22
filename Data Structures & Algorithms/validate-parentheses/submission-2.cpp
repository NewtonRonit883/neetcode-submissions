class Solution {
public:
    char opp(char c){
        if (c == '(') return ')';
        else if (c == '{') return '}';
        else if (c == '[') return ']';
        else return '/';
    }
    bool isValid(string s) {
        stack<char> st;
        for(char c : s){
            if (c == '(' || c=='{' || c=='['){
                st.push(c);
            }else{
                
                if (st.empty() || opp(st.top())!=c) return false;
                st.pop();
            }
        }
        return (st.empty())?true:false;
    }
};
