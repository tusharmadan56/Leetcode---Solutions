class Solution {
public:
    const int mod = 1e9+7;
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int ok = *max_element(nums.begin(),nums.end());
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(ok+1,vector<int>(ok+1,0)));

        dp[0][0][0] = 1;

        for(int i=0;i<n;i++){
            for(int j=0;j<=ok;j++){
                for(int k=0;k<=ok;k++){
                    dp[i+1][j][k] = (dp[i+1][j][k] + dp[i][j][k])%mod;

                    int a = __gcd(nums[i],j);
                    int b = __gcd(nums[i],k);

                    if(dp[i][j][k]){
                        dp[i+1][a][k] = ( dp[i+1][a][k] + dp[i][j][k])%mod;
                    }
                    if(dp[i][j][k]) dp[i+1][j][b]=(dp[i+1][j][b] + dp[i][j][k])%mod;
                }
            }

           
        }

        int ans =0;

        for(int j=1;j<=ok;j++){
            ans=(ans + dp[n][j][j]) %mod;
        }
        return ans;
    }
};