class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if(n>m) return findMedianSortedArrays(nums2,nums1);


        int middle = (n+m+1)/2;

        int lo = 0 , hi = n;

        while(lo<=hi){
            int mid = (lo+hi)/2;

            int rem = middle - mid;

            int l1,l2,r1,r2;
            l1=l2=-1e9 ;
             r1=r2=1e9;

            if(mid!=0){
                l1 = nums1[mid-1];
            }
            if(mid<n){
                r1 = nums1[mid];
            }

            if(rem!=0){
                l2 = nums2[rem-1];
            }
            if(rem<m){
                r2 = nums2[rem];
            }

            if(l1<=r2 && l2<=r1){
                if((n+m)%2){
                    return max(l1*1.0,l2*1.0);
                }
                else{
                    return (min(r1*1.0,r2*1.0) + max(l1*1.0,l2*1.0)) /2;
                }
            }
            else if(l1>r2){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }

        }
        return -1;

    }
};