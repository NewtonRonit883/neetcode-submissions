using ll = long long;
class Solution {
public:
    ll calc(ll op1,ll op2,char c){
        if (c == '+') return op1+op2;
        else if (c=='-') return op2-op1;
        else if (c=='*') return op2*op1;
        else return op2/op1;
    }
    int evalRPN(vector<string>& tokens) {
        stack<ll> st;
        for(string s : tokens){
            if (isdigit(s[0]) || (s.size()>1 && isdigit(s[1]))){
                st.push((ll)stoi(s));
            }else{
                ll op1 = st.top();st.pop();
                ll op2 = st.top();st.pop();
                ll op3 = calc(op1,op2,s[0]);
                st.push(op3);
            }
        }
        return (int)st.top();
    }
};
