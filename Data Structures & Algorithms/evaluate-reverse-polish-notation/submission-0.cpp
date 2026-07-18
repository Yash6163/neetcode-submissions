int operation(int a, int b, char c){
    if(c=='+') return a+b;
    else if(c=='-') return a-b;
    else if(c=='*') return a*b;
    else return a/b;
}

class Solution {
public:
    int evalRPN(vector<string>& arr) {
        stack<int> st;

        for(auto it : arr){
            if(it=="+" || it=="-" || it=="*" || it=="/"){
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(operation(a, b, it[0]));
            }
            else{
                st.push(stoi(it));
            }
        }

        return st.top();
    }
};