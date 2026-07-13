class Solution {
public:
    #define ll long long 
    int divisibleGame(vector<int>& nums) {
        int n = nums.size();


        set<int> s;
        s.insert(2);

        for(int i=0;i<n;i++){
            int a = nums[i];

            if(nums[i]!=1) s.insert(nums[i]);

            for(int j=2;j*j<=a;j++){
                if(a%j==0){
                    s.insert(j);
                    if(j!=a/j ){
                        s.insert(a/j);
                    }
                }
            }
        }

        ll fans = -1e9 ;

        int nk = -1;


        for(auto k:s){
            ll sum = 0;
            ll gg = -1e9;

            ll ans = -1e9;

            for(int i=0;i<n;i++){
                ll ok;
                if(nums[i]%k==0){
                    ok = nums[i];
                }
                else{
                    ok = -nums[i];
                }

                sum  = max(sum + ok , ok);


                ans = max(sum , ans);
            }

            //fans = max(fans , ans);

            if(ans>fans){
                fans = ans;
                nk = k;
            }


        }

        cout<<fans<<" "<<nk<<endl;

        const int mod = 1e9+7;

        fans = (fans%mod+mod)%mod;

        fans = (fans*nk)%mod;

        return fans;



    }
};