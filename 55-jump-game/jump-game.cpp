class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curr = 0 , end = 0;

        int n = nums.size();

        for(int i=0;i<n-1;i++){
            end = max(end , nums[i]+i);
            if(i==curr){
                if(curr==end){
                    return false;
                }
                curr = end;
            }

        }
        return true;
    }
};