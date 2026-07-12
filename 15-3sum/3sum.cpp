class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> fans;

        int n =nums.size();


        sort(nums.begin(),nums.end());


        for(int i=0;i<n;i++){
            int target = -nums[i];

            if(i>0 && nums[i]==nums[i-1]) {
                continue;
            }


            unordered_set<int> mp ;

            for(int j=i+1;j<n;j++){
                
                int val = target - nums[j];

                //cout<<val<<endl;

                if(mp.find(val)!=mp.end()){
                    fans.push_back({nums[i],val,nums[j]});
                    
                    while(j<n-1 && nums[j]==nums[j+1]) j++;
                }
                mp.insert(nums[j]);
            }
        }

        
        return fans;
    }
};