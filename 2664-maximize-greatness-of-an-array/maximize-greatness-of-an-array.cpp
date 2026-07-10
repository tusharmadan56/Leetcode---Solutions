class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int i=0,j=0;

        int ans =0;

        int n = nums.size();

        while(j<n){
          //  cout<<nums[i]<<" "<<nums[j]<<endl;
            if(nums[i]>=nums[j]){
                j++;
                continue;
            }
            ans++;
            i++;
            j++;
        }

        return ans;


    }
};