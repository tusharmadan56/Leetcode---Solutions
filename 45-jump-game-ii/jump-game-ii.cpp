class Solution {
public:
    int jump(vector<int>& nums) {
        int steps = 0,max = 1;

        int n = nums.size();

        vector<int> v(n,1e9);
        v[0] = 0;

        

        for(int i=0;i<(int)nums.size();i++){
            int val = nums[i]+i;
            while(max<n && max<=val){
                v[max] = v[i]+1;
                max++;
            }

        }

        return v[n-1];
    }
};