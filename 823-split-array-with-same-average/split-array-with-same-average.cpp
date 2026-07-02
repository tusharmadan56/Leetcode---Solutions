class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
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

        for(int i=0;i<=n;i++){
            
            for(auto x:lsum[i]){
                for(int j=0;j<=n;j++){
                    int C = i+j;
                    if(C==N || C==0) continue;

                    int target = C*total;

                    if(target%N ==0 ){
                        target/=N;
                        target -= x;

                        if(binary_search(rsum[j].begin(),rsum[j].end(),target)){
                            cout<<x<<" "<<target<<endl;
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};