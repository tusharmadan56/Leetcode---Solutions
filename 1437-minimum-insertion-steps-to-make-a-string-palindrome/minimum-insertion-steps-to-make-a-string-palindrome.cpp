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
        dp.resize(n,vector<int>(n,-1));
        return dfs(0,n-1,s);
    }
};