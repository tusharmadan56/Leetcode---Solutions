class Solution {
public:

    int n;
    vector<vector<int>> dp;
    const int mod = 1e9+7;
    int dfs(int i , bool f){

        if(i==n) {
            return !f;
        }
        if(i>n) return 0;

        int &cac = dp[i][f];
        if(cac!=-1) return cac;
        
        long long  ans = 0;

        if(f){
            ans = (ans +  dfs(i+1 , true) ) %mod;
            ans= (ans + dfs(i+2 , false)) % mod;
        }
        else{
            ans = (ans + dfs(i+1 , false))%mod;
            ans=(ans +  dfs(i+2 , false))%mod;
            ans =(ans +  2LL * dfs(i+1 , true))%mod;
        }

        return cac = (int)ans;
    }
    int numTilings(int n) {
        this->n = n;

        dp.resize(n+3,vector<int>(2,0));


        dp[n][0] = 1;

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                long long ans = 0;
                if(j){
                    ans = (ans + dp[i+1][1])%mod;
                    ans = (ans+dp[i+2][0])%mod;

                }
                else{
                    ans = (ans + dp[i+1][0])%mod;
                    ans=(ans +  dp[i+2][0])%mod;
                    ans =(ans +  2LL * dp[i+1][1])%mod;
                }
                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }
};