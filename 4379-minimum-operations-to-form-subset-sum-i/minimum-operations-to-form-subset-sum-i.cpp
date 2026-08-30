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

        {
            int temp = nums[i];
            int k = 0;
            while(temp<=sum){
                ans = min(ans , k + dfs(i+1 , sum-temp));
                temp*=2;
                k++;
            }
        }

        int k = 0;
        int temp = nums[i];
        while(temp>sum){
            temp/=2;
            k++;
        }

        while(temp>0) {
            ans = min ( ans , k+ dfs(i+1,sum-temp));
            k++;
            temp/=2;
        }

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