class Solution {
public:
    int fun(vector<int>& temp){
        int ans = 0;

        stack<int> st;
        int n=temp.size();

        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || temp[st.top()]>=temp[i])){
                int val = temp[st.top()];
                st.pop();

                int gg = -1;
                if(!st.empty()){
                    gg = st.top();
                }

                ans = max(ans , val * (i-gg-1));
            }
            st.push(i);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;

        int n = matrix.size();
        int  m  = matrix[0].size();

        vector<vector<int>> temp(n,vector<int> (m,0));

        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                if(matrix[i][j]=='1'){
                    temp[i][j] =1;
                    if(i>0) temp[i][j] += temp[i-1][j];
                }
                
                
            }
        }



        for(auto x:temp){
            ans  = max(ans , fun(x));
        }
        return ans;
    }
};