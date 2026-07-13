class Solution {
public:
    bool ok(vector<vector<int>>& grid,int j1,int j2,int limit){
        for(int i=0;i<grid.size();i++){
            if(abs(grid[i][j2]-grid[i][j1])<=limit){

            }
            else return false;
        }
        return true;
    }
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> dp(m,1);

        dp[0] = 1;

        for(int i=1;i<m;i++){
            for(int j=i-1;j>=0;j--){
                if(ok(grid,i,j,limit)){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }   

        

        return *max_element(dp.begin(),dp.end());

        
    }
};