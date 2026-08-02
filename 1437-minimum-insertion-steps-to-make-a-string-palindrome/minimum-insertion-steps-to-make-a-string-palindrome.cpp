class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int i,int j,string& s){
        if(i>=j){
            return 0;
        }
        int ans = 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==s[j]){
            ans = dfs(i+1,j-1,s);
        }
        else{
            ans = min(dfs(i+1,j,s)+1,dfs(i,j-1,s)+1);
        }
        return dp[i][j]=ans;
    }
    int minInsertions(string s) {
        int n = s.size();
        dp.resize(n+1,vector<int>(n+1,0));


        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]){
                    if(j-1>0) dp[i][j] = dp[i+1][j-1];
                }
                else{
                    dp[i][j] = 1+dp[i+1][j];
                    if(j-1>0) dp[i][j] = min(dp[i][j],1+dp[i][j-1]);
                }
            }
        }
        
        return dp[0][n-1];
    }
};