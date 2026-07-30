class Solution {
public:
    int n ;

    vector<vector<int>> dp;
    int dfs(int i,int pre,vector<int>& nums){

        int ans = 0;

        int &cache  = dp[pre][i];
        if(cache!=-1) return cache;

        
        long long d = 0LL+nums[i]-nums[pre];



        for(int j=i+1;j<n;j++){
            long long ok = 0LL+nums[j]-nums[i];
            if(ok==d){
                ans+=1+ dfs(j,i,nums);

            }
        }

        

        return cache = ans;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        this->n = nums.size();
        dp.resize(n,vector<int>(n,-1));
        int fans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                fans += dfs(j,i,nums) > 0 ? dfs(j,i,nums)  : 0;
            }
        }
        return fans;
    }   
};