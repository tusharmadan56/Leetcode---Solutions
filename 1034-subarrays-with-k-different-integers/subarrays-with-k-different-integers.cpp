class Solution {
public:
    
    int fun(vector<int>& nums, int k) {
        int n  = nums.size();
        int i =0 , j = 0;

        vector<int> temp(n+1 , 0 );
        int ans = 0 , c = 0;

        while(j<n){
            if(temp[nums[j]]==0){
                c++;
            }
            temp[nums[j]]++;

            while(c > k){
               
                if(temp[nums[i]]==1){
                    c--;
                }
                temp[nums[i]]--;
                i++;
            }
            

            ans += (j-i+1);

            j++;
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fun(nums , k ) - fun(nums , k - 1);
    }
};