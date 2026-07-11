class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> dp(40005,0),prev(40005,0);

        

        const int offset = 20000;
        //dp[0][offset] = 1;

        prev[offset] = 1;


        for(int i=1;i<=n;i++){
            //dp = prev;

            //dp.fill(dp.begin(),dp.end(),0);
            for(int j=-20000;j<=20000;j++){
                int ans = 0;

                


                if(j-nums[i-1]>=-offset) dp[j+offset] = prev[j-nums[i-1]+offset];
                if(j+nums[i-1]<=20000) dp[j+offset] += prev[j+nums[i-1]+offset];
                
            }

            prev = dp;


        }

        return dp[target+offset];
    }
};