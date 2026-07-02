class Solution {
public:

    int dp[20001]={0};

    
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return false;

        //cout<<sum;
        int n=nums.size();

        int target=sum/2;

        

       
        dp[0]=1;

        for(int i=1;i<=n;i++){
            for(int j=target;j>=nums[i-1];j--){
                if(j-nums[i-1]>=0) dp[j]|=dp[j-nums[i-1]];
                dp[j]|=dp[j];
            }
        }

        return dp[target];
        
        

        
    }
};