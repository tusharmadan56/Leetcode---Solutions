class Solution {
public:
    vector<int> asteroidCollision(vector<int>& val) {
        vector<int> ans;

        int n  = val.size();


        stack<int> st;

        for(int i=n-1;i>=0;i--){
            if(val[i]<0){
                st.push(val[i]);
            }
            else{
                int gg = val[i];
                while(!st.empty() && gg>abs(st.top())){
                    st.pop();
                }
                if(!st.empty() && abs(st.top())==gg){
                    st.pop();
                    continue;
                }
                if(st.empty()){
                    ans.push_back(gg);
                }
                else{

                }
            }
        }

        int c =0;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
            c++;
        }

       


        reverse(ans.begin(),ans.end());
        reverse(ans.begin(),ans.begin()+c);
        return ans;
    }
};