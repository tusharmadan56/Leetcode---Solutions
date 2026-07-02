class Solution {
public:
    #define tup tuple<int,int,int>
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();


        vector<vector<int>> dp(n,vector<int> (m,-1));

        int h=health ;

        if(grid[0][0] == 1) h--;

        dp[0][0] = h;

        queue<tup> q;
        q.push({0,0,h});

        while(!q.empty()){
            auto [i,j,h] = q.front();
            q.pop();

            //cout<<i<<" "<<j<<" "<<h<<endl;


            if(i==n-1 && j==m-1 && h>=0) {
                //cout<<h;
                return true;
            }



            int dx[] = {1,-1,0,0};
            int dy[] = {0,0,1,-1};

            for(int k=0;k<4;k++){
                int x = i+dx[k];
                int y = j+dy[k];

                if(x>=0 && y>=0 && x<n && y<m){
                    int ok = h;
                    if(grid[x][y]==1){
                        ok--;
                    }

                    if(ok<=0) continue;

                    if(dp[x][y]==-1 || dp[x][y]<ok){
                        dp[x][y] = ok;
                        q.push({x,y,ok});
                    }
                }
            }
        }

        return false;
    }
};