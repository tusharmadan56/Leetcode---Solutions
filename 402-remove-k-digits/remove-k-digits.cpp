class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        int n = num.size();

        if(n<=k) return "0";

        for(int i=0;i<(int)num.size();i++){
            while(!st.empty() && k>0 && num[i]<st.top()){
                st.pop();
                k--;

            }

            st.push(num[i]);
        }

        string ans ="";

        while(!st.empty()){
            if(k>0){
                k--;
                st.pop();
                continue;
            }
            ans += st.top();
            st.pop();

        }

        while(ans.size()>1 && ans.back()=='0'){
            ans.pop_back();
        }

        reverse(ans.begin(),ans.end());
        
        return ans;

    

    }
};