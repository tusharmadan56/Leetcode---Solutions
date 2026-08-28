class Solution {
public:
    int trap(vector<int>& height) {
        int n  = height.size();


        int l = 0 , r = n-1;
        int lmax = 0 , rmax = 0;
        int ans = 0;
        while(l<r){
            if(height[l]<=height[r]){
                lmax = max(lmax , height[l]);
                rmax = max(rmax , height[r]);

                ans+= (lmax - height[l]);
                l++;
            }
            else{
                lmax = max(lmax , height[l]);
                rmax = max(rmax , height[r]);

                ans+= (rmax - height[r]);
                r--;
            }
        }

        return ans;
    }
};