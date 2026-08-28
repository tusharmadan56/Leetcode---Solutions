class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n= arr.size();

        stack<int> st;
        int ans = *max_element(arr.begin(),arr.end());

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                int val = arr[st.top()];
                st.pop();

                int gg = -1;
                if(!st.empty()){
                    gg = st.top();
                }

                ans = max(ans , val*(i-gg-1));

               
            }
            st.push(i);
        }
        while(st.size()>0) {
            int val = arr[st.top()];
            st.pop();

            int gg = -1;
            if(!st.empty()){
                gg = st.top();
            }

            ans = max(ans , val*(n-gg-1));
            
        }
        return ans;
    }
};