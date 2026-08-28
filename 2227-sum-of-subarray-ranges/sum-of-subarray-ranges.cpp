class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
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

        stack<int> s1 ,s2;

        vector<int> nge(n,n);

        for(int i=n-1;i>=0;i--){
            int val = arr[i];

            while(!s1.empty() && arr[s1.top()]<=val){
                s1.pop();
            }

            if(!s1.empty()){
                nge[i] = s1.top();
            }

            s1.push(i);
        }

        vector<int> pge(n,-1);

        for(int i=0;i<n;i++){
            int val = arr[i];

            while(!s2.empty() && arr[s2.top()]<val){
                s2.pop();
            }

            if(!s2.empty()){
                pge[i] = s2.top();
            }

            s2.push(i);
        }



        long long ans = 0 ;

        for(int i=0;i<n;i++){
            int left = i-pse[i];
            int right = nse[i] - i;

            long long freq = 1LL*left*right;

            long long tot = (1LL* freq*arr[i]);

            ans = (ans - tot);

            long long freq2 = 1LL*(nge[i]-i)*(i-pge[i]);

            ans += freq2*arr[i];
        }

        return ans;
    }
};