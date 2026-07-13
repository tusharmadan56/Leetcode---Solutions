class Solution {
public:
    #define ll long long
    int minimumCost(vector<int>& nums, int k) {
        long long ans = 0;

        long long val = k;

        const int mod = 1e9+7;

        for(int i=0;i<nums.size();i++){
            if(nums[i]<=val){
                val-=nums[i];
            }
            else{
                long long diff = nums[i]-val;
                ll okay = diff/k;
                if(diff%k!=0) okay++;

                ans= (ans + okay)%mod;

                val+= okay*k - nums[i];


            }
            //cout<<val<<" "<<ans<<endl;
        }

        //cout<<ans;

        

        ll fans = 1LL*ans*(ans+1)/2;

        return fans%mod;


    }
};