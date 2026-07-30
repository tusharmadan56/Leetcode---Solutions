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

        dp.resize(n,vector<int>(2,-1));

        return dfs(0,false);
    }
};