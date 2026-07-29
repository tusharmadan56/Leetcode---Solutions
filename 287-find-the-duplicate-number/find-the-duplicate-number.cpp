class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = nums[0] , f = s ;
        int n = nums.size();


        do{
            s = nums[s];
            f = nums[nums[f]];
        }while(s!=f);

        s=nums[0];

        while(s!=f){
            s = nums[s];
            f=nums[f];
        }

        return s;
    }
};