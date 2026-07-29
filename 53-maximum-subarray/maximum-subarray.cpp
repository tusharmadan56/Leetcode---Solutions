class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        

        int fans = -1e9 ;
        int ans = -1e9;
        int n = nums.size();

        for(int i=0;i<n;i++){
            

            ans = max(ans + nums[i] , nums[i]);

            fans = max({fans , ans , nums[i]});
        }

        return fans;
    }
};