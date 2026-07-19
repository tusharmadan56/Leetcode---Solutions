class Solution {
public:
    int n,m;
    string s,t;
    vector<vector<int>> dp;

    int dfs(int i,int j){
        if(i==n && j==m) return 1;
        if(i==n) return 0;
        if(j==m) return 1;

        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(s[i]==t[j]){
            ans=dfs(i+1,j+1);
        }
        
            ans+=dfs(i+1,j);
        
        return dp[i][j]=ans;
    }
    int numDistinct(string s, string t) {
        n=s.size(),m=t.size();
        this->s = s;
        this->t = t;
        dp.resize(n,vector<int>(m,-1));
        return dfs(0,0);
    }
};