class Solution {
public:
    int n ;
    vector<int> arr;
    vector<vector<int>> dp;
    int dfs(int i,int d){

        if(i==n){
            if(!d){
                return 0;
            }
            return 1e9;
        }

        if(d==0) return 1e9;
        int &cache = dp[i][d];
        if(cache!=-1) return cache;
        
        int ans = 1e9;

        int ma = 0;
        for(int j=i;j<n;j++){
            ma = max(ma , arr[j]);
            ans = min(ans ,ma + dfs(j+1,d-1));
        }

        return cache = ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        this->arr = jobDifficulty;
        this-> n = arr.size();
        dp.resize(n , vector<int>(d+1 , -1));
         dfs(0,d);

        return dp[0][d] == 1e9 ? -1 : dp[0][d];
    }
};