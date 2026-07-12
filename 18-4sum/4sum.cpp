class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();


        sort(nums.begin(),nums.end());
        vector<vector<int>> fans;

        for(int i=0;i<n-3;i++){
            int a = nums[i];

            if(i>0 && nums[i]==nums[i-1]) continue;


            for(int j=i+1;j<n-2;j++){
                int b = nums[j];

                if(j>i+1 && nums[j]==nums[j-1]) continue;

                int l = j+1;
                int r = n-1;

                long long  val = 0LL+target - a - b;

                while(l<r){
                    long long  gg = 0LL+ nums[l]+nums[r];

                    if(gg==val){
                        fans.push_back({a,b,nums[l],nums[r]});
                        l++;
                        r--;

                        while(l<n && nums[l]==nums[l-1]) l++;
                        while(r>=0 && nums[r]==nums[r+1]) r--;
                    }
                    else if(gg>val){
                        r--;
                    }
                    else{
                        l++;
                    }
                    
                }
            }

            
        }
        return fans;
    }
};