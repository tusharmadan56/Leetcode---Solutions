class Solution {
public:
    string s;
    int n;
    vector<int> dp;
    int dfs(int i){
        if(i==n){
            return 1;
        }
        if(s[i]=='0') return 0;

        if(dp[i]!=-1) return dp[i];

        int ans = 0;

        ans += dfs(i+1);

        if(i+2<=n) {
            string ok = s.substr(i,2);
            int gg = stoi(ok);

            if(gg<=26){
               ans += dfs(i+2);
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