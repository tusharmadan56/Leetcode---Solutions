class Solution {
public:
    vector<int> cuts;
    map<pair<int,int>,int> mp;
    int dfs(int i,int j){
        if(mp.find({i,j})!=mp.end()) return mp[{i,j}];
        if(j-i<=0) return 0;

        if(j==(i+1)) return 0;
        int ans=1e9;
        bool f=true;
        for(int k=i+1;k<j;k++){
            ans = min(ans , dfs(i,k)+dfs(k,j)+(cuts[j]-cuts[i]));
            f=false;
        }
        //if(f) return mp[{i,j}]=0;
        return mp[{i,j}]=ans;

    }
    int minCost(int n, vector<int>& cuts) {
        
        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(),cuts.end());
        this->cuts=cuts;

        int sz = cuts.size();

        vector<vector<int>> dp(sz+1,vector<int>(sz+1,1e9));

        for(int len = 1;len<sz;len++){

            for(int i=0;i<sz;i++){
                int j= i+len;

                if(j>=sz) continue;

                if(len == 1) dp[i][j] = 0;

                for(int k=i+1;k<j;k++){

                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]+cuts[j]-cuts[i]);
                }
            }
        }
        return dp[0][sz-1];
    }
};