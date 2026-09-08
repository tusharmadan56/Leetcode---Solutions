class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int f = -1 , s = -1 , f1=0,f2=0;


        int n  = nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]==f){
                f1++;

            }
            else if(nums[i]==s){
                f2++;
            }
            else if(f1==0){
                f1=1;
                f=nums[i];
            }
            else if(f2==0){
                s=nums[i];
                f2 = 1;
            }
            else{
                f1--;
                f2--;
            }
        }

        vector<int> ans;
        
        f1 = f2 = 0;

        for(auto x:nums){
            if(x==f) f1++;
            else if(x==s) f2++;
        }

        if(f1>(n/3)){
            ans.push_back(f);
        }
        if(f2 > (n/3)){
            ans.push_back(s);
        }

        

        return ans;
    }
};