class Solution {
public:

    // E 2 3
    // 2 X 2 
    // 1 2 s
   
    #define tup tuple<int,int,int>

    #define ll long long 

    int fans = -1;
    int n,m;

    vector<string> board;

    vector<vector<vector<int>>> ndp;

    ll dfs(int i, int j , int score){

        if(i==0 && j==0) {
            //score += '0' - 'E';
            if(score == fans ) return 1;
            return 0;
        }

        ll cache = ndp[i][j][score];
        if(cache!=-1) return cache;

        ll ans  = 0 ;

        int dx[] = {-1,0,-1};
        int dy[] = {0,-1,-1};

        for(int k=0;k<3;k++){
            int x = dx[k] + i;
            int y = dy[k] + j;

            if(x>=0 && y>=0 && x<n && y<m && board[x][y]!='X'){
                int val  = board[x][y] - '0';
                if(board[x][y]=='E') val+='0'-'E';
                val+=score;

                //cout<<val<<" ";

                ans+=dfs(x,y,val);

                
            }
        }

        return cache = ans;

        
    }

    const int mod = 1e9+7;



    vector<int> pathsWithMaxScore(vector<string>& board) {
        this->n = board.size();
        this->m = board[0].size();

        ndp.resize(n,vector<vector<int>> (m,vector<int>(1800 , -1)));

        this->board = board;

        priority_queue<tup,vector<tup>,greater<tup>> pq;

        vector<vector<int>> dp(n,vector<int>(m,-1));
        

        //cout<<dp[0][0];

        dp[n-1][m-1] = 0;

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int ok = -1;

                if(i==n-1 && j==m-1) continue;

                if(board[i][j] == 'X' ) continue;

                if(i+1<n && j+1<m){
                    ok = max(ok , dp[i+1][j+1]);
                }

                if(j+1<m) ok = max(ok,dp[i][j+1]);

                if(i+1<n) ok = max(ok , dp[i+1][j]);

                if(ok==-1){
                    continue;
                }

                if(board[i][j]=='E' || board[i][j]=='S'){

                }
                else{
                    
                    ok+= board[i][j] - '0';
                }
                
                dp[i][j] = ok;
            }
        }

        // for(auto x:dp){
        //     for(auto y:x){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }

        
        fans = dp[0][0];
        

        

        //cout<<fans;

        if(fans==-1) return {0,0};


        vector<vector<ll>> ndp(n,vector<ll>(m,0));

        ndp[n-1][m-1] = 1;

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1) continue;

                if(board[i][j] == 'X' ) continue;

                ll ok = 0;

                if(i+1<n && j+1<m ){
                    int ans  = dp[i+1][j+1];

                    if(ans!=-1){
                        ans +=  board[i][j] - '0';

                        if(board[i][j] == 'E') ans+= '0' - 'E';

                        if(ans == dp[i][j]){
                            ok= (ok+ndp[i+1][j+1])%mod;
                        }
                    }
                }

                if(j+1<m) {
                    int ans  = dp[i][j+1];

                    if(ans!=-1){
                        ans +=  board[i][j] - '0';
                        if(board[i][j] == 'E') ans+= '0' - 'E';

                        if(ans == dp[i][j]){
                            ok=(ok+ndp[i][j+1])%mod;
                        }
                    }
                }

                if(i+1<n) {
                    int ans  = dp[i+1][j];

                    if(ans!=-1){
                        ans +=  board[i][j] - '0';
                        if(board[i][j] == 'E') ans+= '0' - 'E';

                        if(ans == dp[i][j]){
                            ok=(ok+ndp[i+1][j])%mod;
                        }
                    }
                }

                
                
                ndp[i][j] = ok;
            }
        }


        int fans2 = ndp[0][0]%mod;



        


        return {fans,fans2};
    }
};