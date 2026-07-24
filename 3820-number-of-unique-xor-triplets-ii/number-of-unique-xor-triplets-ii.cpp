class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> s;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                s.insert(nums[i]^nums[j]);
            }
        }


        unordered_set<int> fans;

        for(int i=0;i<n;i++){
            for(auto x:s){
                fans.insert(x^nums[i]);
            }
        }

        return fans.size();

    }
};