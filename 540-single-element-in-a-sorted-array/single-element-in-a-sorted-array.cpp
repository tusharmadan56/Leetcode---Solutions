class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0 , hi = nums.size();
        int n = nums.size();


        while(lo<=hi){
            int mid = (lo+hi)/2;
//
            //cout<<mid<<" ";

            if(mid>0){
                int pos ;
                if(mid+1<n && nums[mid]==nums[mid+1]){
                    pos = mid;
                }
                else if(nums[mid]==nums[mid-1]){
                    pos = mid-1;
                }
                else{
                    return nums[mid];
                }

                if(pos%2==0){
                    lo = pos+2;

                }
                else{
                    hi = pos - 1;
                }
            }
            else{
                if(mid+1<n && nums[mid]==nums[mid+1]){
                    lo = mid+1;
                }
                else{
                    return nums[mid];
                }
            }

           // cout<<lo<<" "<<hi<<endl;
        }
        return -1;
    }
};