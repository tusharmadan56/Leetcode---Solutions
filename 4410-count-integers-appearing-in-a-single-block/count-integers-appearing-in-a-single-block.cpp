class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int c = 0;
        unordered_set<int> mp;

        unordered_set<int> ans;

        int n = nums.size();

        for(int i=1;i<n;i++){
            if(nums[i-1]==nums[i]) {
                continue;
            }

            if(mp.find(nums[i-1])==mp.end()){
                ans.insert(nums[i-1]);
                mp.insert(nums[i-1]);
            }
            else{
                ans.erase(nums[i-1]);
            }
        }

        if(mp.find(nums[n-1])==mp.end()){
                ans.insert(nums[n-1]);
               // mp.insert(nums[i-1]);
            }
        else{
            ans.erase(nums[n-1]);
        }

        return ans.size();

        
    }
};