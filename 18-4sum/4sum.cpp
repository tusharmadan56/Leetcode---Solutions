class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int tar) {
        int n  = nums.size();
        vector<vector<int>> fans ;

        sort(nums.begin(),nums.end());

        for(int j=0;j<n-3;j++){
            if(j>0 && nums[j]==nums[j-1]) continue;
        for(int i=j+1;i<n-2;i++){
            if(i>j+1 && nums[i]==nums[i-1]) continue;

            int l = i+1,r=n-1;

            long long  target  = 0LL+tar-nums[i]-nums[j];
            //cout<<target<<endl;

            while(l<r){
                long long  sum = 0LL+ nums[l]+nums[r];

                if(sum==target){
                    fans.push_back({nums[j],nums[i],nums[l],nums[r]});
                    l++;
                    r--;

                    while(l<n && nums[l]==nums[l-1]){
                        l++;
                    }
                    while(r>=0 && nums[r]==nums[r+1]){
                        r--;
                    }
                }
                else if(sum<target){
                    l++;
                }
                else{
                    r--;
                }

            }
        }
        }
        return fans;
    }
};