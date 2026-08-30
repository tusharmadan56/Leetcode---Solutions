class Solution {
public:
    #define ll long long 
    long long modpow(long long x,long long y){
        long long MOD = 1e9+7;
        long long res = 1;
        while(y>0){
            if(y & 1){
                res = res*x % MOD;
            }
            x = x*x %MOD;
            y >>= 1;
        }
        return res;
    }
    const int mod = 1e9+7;
    int sumDecoded(vector<long long>& nums) {
        long long ans = 0;

        for(auto x:nums){
            ll w = x%10;
            ll d = floor(x/10);

            string str = to_string(d);

            cout<<str<<endl;

            string lol = str.substr(0,w);
            string lol2 = str.substr(w);

            //cout<<lol<<" "<<lol2<<endl;

            ll nx = stoi(lol);
            ll y = stoi(lol2);


            ans = (ans + modpow(nx,y))%mod;


            

           // cout<<nx<<" "<<y<<endl;

        }
        return ans;
    }
};