class Solution {
public:
    long long res = -1e9;
    int k ;
    vector<int> nums ;
    #define ll long long 
    int c =0;
    vector<vector<ll>> dp;
    ll dfs(int i, int gg){
        if(i<0) return -1e12;

        ll &cache = dp[i][gg];
        if(cache!=-1e12) return cache;
       // c++;
        ll ans = -1e12;
        if(gg==0){
            ans = max({ans,1LL*nums[i],dfs(i-1,0)+nums[i]});

            res = max(res , ans);
            ans = max({ans,1LL*nums[i]*k,dfs(i-1,1)+1LL*nums[i]*k});

            res = max(res , ans);

            
            ans = max({ans,1LL*nums[i]/k,dfs(i-1,2)+nums[i]/k});
            res = max(res , ans);

        }
        else if (gg == 1){
            ans = max({ans,1LL*nums[i]*k , dfs(i-1,1)+1LL*nums[i]*k});
            res = max(res , ans);

            ans = max({ans,1LL*nums[i] , dfs(i-1,3) + nums[i]});
            res = max(res , ans);

        }
        else if(gg==2){
            ans = max({ans,1LL*nums[i]/k,dfs(i-1,2)+nums[i]/k});
            res = max(res , ans);
            ans = max({ans,1LL*nums[i] , dfs(i-1,3) + nums[i]});
            res = max(res , ans);
        }
        else {
            ans = max({ans,1LL*nums[i] , dfs(i-1,3)+nums[i]});
            res = max(res , ans);
        }

        return cache = ans;
    }
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        this->k = k;
        this->nums = nums;

        dp.resize(n+1,vector<long long > (4,-1e18));
        

        dp[0][0] = nums[0];
        dp[0][1] = 1LL*nums[0]*k;
        dp[0][2] = 1LL*nums[0]/k;
        dp[0][3] = -1e18;


        res = max(1LL*nums[0]*k,1LL*nums[0]/k);

        for(int i=1;i<n;i++){
            // 0 
            ll ans = -1e18;
            ans = max({ans,1LL*nums[i],dp[i-1][0]+nums[i]});

            res = max(res , ans);
          
            dp[i][0] = ans;

            //1
            ans = -1e18;
            ans = max({ans,1LL*nums[i]*k , dp[i-1][1]+1LL*nums[i]*k , dp[i-1][0]+1LL*nums[i]*k});
            res = max(res , ans);

           
            dp[i][1] = ans;

            //2
            ans = -1e18;
            
            ans = max({ans,1LL*nums[i]/k,dp[i-1][2]+nums[i]/k , dp[i-1][0]+nums[i]/k});
            res = max(res , ans);
           
            dp[i][2] = ans;

            //3
            ans = -1e18;
            ans = max({ans,1LL*nums[i] , dp[i-1][3]+nums[i] , dp[i-1][2]+nums[i],dp[i-1][1]+nums[i]});
            res = max(res , ans);
            dp[i][3] = ans;
        }
        //cout<<c;
        return res;


    }
};