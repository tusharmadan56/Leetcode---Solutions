class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(auto x:tokens){
            if(isdigit(x[0]) || (x[0]=='-' && x.size()>1 && isdigit(x[1]))){
                int val = stoi(x);
                st.push(val);
               // cout<<st.size()<<" ";
            }
            else{
                if(st.size()<2) return -1;
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                if(x[0]=='*'){
                    st.push(a*b);
                }
                else if(x[0]=='/'){
                    st.push(a/b);
                }
                else if(x[0]=='+'){
                    st.push(a+b);
                }
                else{
                   
                    st.push(a-b);
                
                }
               // cout<<st.size()<<" ";
            }
        }
        return st.top();
    }
};