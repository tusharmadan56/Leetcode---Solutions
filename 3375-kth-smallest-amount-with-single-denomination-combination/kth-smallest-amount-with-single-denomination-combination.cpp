class Solution {
public:
    #define ll long long 

    ll lcm(ll a , ll b){
        return a/__gcd(a,b) * b;
    }
    bool can(ll mid,vector<int>& coins,int k){
        ll fans = 0;
        int n = coins.size();


        for(int i=1;i< (1<<n);i++){
            ll gg = 1;
            int c = 0;

            for(int j=0;j<n;j++){
                if(i & (1<<j)){
                    c++;
                    gg = lcm(gg,1LL*coins[j]);
                    if(gg>mid) break;
                }

            }
            if(gg>mid) continue;

            if(c%2) fans += mid/gg;
            else fans-= mid/gg;
        }

        return fans>=k;
        
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        ll lo = 1,hi = 1e12;

        ll ans = -1;

       

        while(lo<=hi){
            ll mid = (lo+hi)/2;

            if(can(mid,coins,k)){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }

        return ans;
    }
};