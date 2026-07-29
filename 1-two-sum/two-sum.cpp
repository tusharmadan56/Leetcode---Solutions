class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp ;

        int n = nums.size();

        for(int i=0;i<n;i++){
            int gg = target - nums[i];

            if(mp.find(gg)!=mp.end()){
                return {mp[gg],i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};