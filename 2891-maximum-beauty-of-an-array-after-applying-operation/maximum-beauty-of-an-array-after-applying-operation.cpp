class Solution {
public:
    const int inf = 2e5+1;
    int maximumBeauty(vector<int>& nums, int k) {
        vector<int> v(inf,0);


        for(int i=0;i<nums.size();i++){
            v[nums[i]+k]++;

            if(nums[i]-k>0){
                v[nums[i]-k-1]--;
            }
        }

        int ans = v[inf-1];

        for(int i=inf-2;i>=0;i--){
            v[i]+=v[i+1];
            ans = max(ans,v[i]);
        }

        //for(auto x:v) cout<<x<<" ";

        return ans;

    }
};