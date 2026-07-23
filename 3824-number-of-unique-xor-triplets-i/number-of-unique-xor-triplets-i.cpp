class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int ele = *max_element(nums.begin(),nums.end());
        int sz = 0;
        if(ele<=2) return ele;
        for(int i=0;i<32;i++){
            if(ele&(1<<i)){
                sz=i;
            }
        }
        sz++;
        return (1<<sz);
    }
};