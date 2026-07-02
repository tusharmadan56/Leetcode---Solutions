class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();

        int s= n/2;
        if(n%2!=0) s++;


        vector<int> lsum, rsum;


        for(int i=0;i<(1<<s);i++){
            int l=0,r=0;

            for(int j=0;j<s;j++){
                if(i & (1<<j)){
                    l+= nums[j];

                    if(j+s<n) r+=nums[j+s];
                }
            }
            lsum.push_back(l);
            rsum.push_back(r);
        } 

        int ans = 1e9;

        sort(rsum.begin(),rsum.end());

        for(auto x:lsum){
            int val = goal - x;

            auto it = lower_bound(rsum.begin(),rsum.end(),val);

            if(it!=rsum.end()){
                ans = min(ans , abs(goal - (x+*it)));
            }

            if(it!=rsum.begin()){
                it--;
                ans = min(ans , abs(goal - (x+*it)));
            }
        }

        return ans;
    }
};