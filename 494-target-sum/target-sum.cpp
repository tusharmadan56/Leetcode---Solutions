class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<vector<int>> dp(n+1,vector<int>(40005,0));

        

        const int offset = 20000;
        dp[0][offset] = 1;


        for(int i=1;i<=n;i++){
            for(int j=-20000;j<=20000;j++){
                int ans = 0;

                


                if(j-nums[i-1]>=-offset) dp[i][j+offset] += dp[i-1][j-nums[i-1]+offset];
                if(j+nums[i-1]<=20000) dp[i][j+offset] += dp[i-1][j+nums[i-1]+offset];
                
            }


        }

        return dp[n][target+offset];
    }
};