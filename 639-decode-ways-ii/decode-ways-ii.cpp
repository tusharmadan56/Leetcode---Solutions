class Solution {
public:
    string s;
    int n;
    vector<int> dp;
    const int mod = 1e9+7;
    int dfs(int i){
        if(i==n){
            return 1;
        }
        if(s[i]=='0') return 0;

        if(dp[i]!=-1) return dp[i];

        long long ans = 0;

        if(s[i]=='*') ans = (ans + (9LL*dfs(i+1))%mod)%mod;
        else ans = (ans + dfs(i+1))%mod;

        if(i+2<=n) {
            string ok = s.substr(i,2);

            if(ok[0]!='*' && ok[1]!='*'){
                int gg = stoi(ok);

                if(gg<=26){
                    ans = (ans + dfs(i+2))%mod;
                }
            }
            else if(ok[0]=='*' && ok[1]!='*'){
                int gg = ok[1]-'0';
                if(gg<=6){
                    ans= ( ans + (2LL* dfs(i+2))%mod)%mod;
                }
                else{
                    ans= (ans + dfs(i+2))%mod;
                }
            }
            else if(ok[0]!='*' && ok[1]=='*'){
                int gg = ok[0]-'0';
                if(gg!=0){
                    if(gg==2){
                        ans = (ans + (6LL*dfs(i+2))%mod)%mod;
                    }
                    else if(gg==1){
                        ans= (ans + (9LL*dfs(i+2))%mod)%mod;
                    }
                }
            }
            else{
                ans= (ans + (15LL*dfs(i+2))%mod ) %mod;
            }


           
        }

        return dp[i] = ans;
    }
    int numDecodings(string s) {
        this->s = s;
        n = s.size();
        dp.resize(n,-1);
        return dfs(0);
    }
};