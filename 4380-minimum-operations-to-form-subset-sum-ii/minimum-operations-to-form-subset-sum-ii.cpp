class Solution {
public:
    vector<int> nums;
    int n ;
    vector<vector<int>> dp;
    int dfs(int i, int sum){
        if(sum<0) return 1e9;
        if(sum == 0 ) return 0;
        if(i==n) return 1e9;
        int ans = 1e9;

        if(dp[i][sum]!=-1) return dp[i][sum];

        ans = min(ans , dfs(i+1,sum));

        ans = min(ans , dfs(i+1 , sum-nums[i]));

        
        int og  = nums[i];
        int ok = 0;

        while(og>0)
        {
            int k = ok;
            int val = og;

            while(val<=sum){
                ans = min(ans , k+ dfs(i+1,sum-val));
                val*=2;
                k++;
            }

            og/=2;
            ok++;
        }

        
        //cout<<endl;

        //cout<<ans<<endl;

        return dp[i][sum]=ans;

    }
    int minOperations(vector<int>& nums, int sum) {
        this->nums = nums;
        this->n = nums.size();
        dp.resize(n,vector<int>(sum+1,-1));
        dfs(0,sum);

        return dp[0][sum]==1e9 ? -1 : dp[0][sum];
    }
};