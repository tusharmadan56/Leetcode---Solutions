class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int curr = 0;
        int lol = 0;
        int n = nums.size();

        for(int i=0;i<n-1;i++){
            lol = max(lol , nums[i]+i);

            if(curr == i){
                ans++;
                curr = lol;
            }
        }

        return ans;
    }
};