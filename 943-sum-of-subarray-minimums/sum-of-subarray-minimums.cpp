class Solution {
public:
    const int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n  = arr.size();


        stack<int> s;
        vector<int> nse(n,n);

        for(int i=n-1;i>=0;i--){
            int val = arr[i];

            while(!s.empty() && arr[s.top()]>=val){
                s.pop();
            }

            if(!s.empty()){
                nse[i] = s.top();
            }

            s.push(i);

        }

        stack<int> st;
        vector<int> pse(n,-1);

        for(int i=0;i<n;i++){
            int val = arr[i];

            while(!st.empty() && arr[st.top()]>val){
                st.pop();
            }

            if(!st.empty()){
                pse[i] = st.top();
            }

            st.push(i);
        }

        long long ans = 0 ;

        for(int i=0;i<n;i++){
            int left = i-pse[i];
            int right = nse[i] - i;

            long long freq = 1LL*left*right;

            long long tot = (1LL* freq*arr[i])%mod;

            ans = (ans + tot)%mod;
        }
        return ans;
    }
};