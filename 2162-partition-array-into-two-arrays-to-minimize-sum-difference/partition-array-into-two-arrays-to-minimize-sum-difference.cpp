class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int N = nums.size();

        int total = accumulate(nums.begin(),nums.end(),0);

        int n = N/2;

        vector<vector<int>> lsum(n+1),rsum(n+1);


        for(int i=0;i< (1<<n);i++){
            int cnt =0 ;
            int left = 0;

            int r = 0;


            for(int j=0;j<n;j++){
                if(i & (1<<j)){
                    cnt++;
                    left += nums[j];
                    r += nums[j+n];
                }
            }

            lsum[cnt].push_back(left);
            rsum[cnt].push_back(r);
        }

        for(int i=0;i<=n;i++){
            sort(rsum[i].begin(),rsum[i].end());
        }


        int ans = 1e9;

        for(int i=1;i<=n;i++){
            
            for(auto x:lsum[i]){
                int target = total/2-x;

                int cnt = n-i;

                auto it = lower_bound(rsum[cnt].begin(),rsum[cnt].end(),target);

                if(it!=rsum[cnt].end()){
                    ans = min( ans  , abs(total - 2*(x + *it)));
                }

                if(it!=rsum[cnt].begin()){
                    it--;
                    ans = min( ans  , abs(total - 2*(x + *it)));
                }
            }
        }
        return ans;
    }

    
};