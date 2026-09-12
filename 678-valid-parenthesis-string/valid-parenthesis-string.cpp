class Solution {
public:
    vector<vector<int>> dp;
    int n ;
    bool dfs(int i,int c,string& s){
        int n = s.size();
        if(i==n) return c==0;
        
        if(c<0) return false;
        if(dp[i][c]!=-1) return dp[i][c];
        bool f = false;
        if(s[i]=='(') {
            f = dfs(i+1 , c+1,s);
        }
        else if (s[i]==')'){
             f=dfs(i+1 , c-1 , s);
        }
        else{
            if(c>0){
                f= dfs(i+1 , c-1 , s);
            }
            f = f || dfs(i+1 , c+1 , s);
            f = f|| dfs(i+1 , c , s);
        }

        return dp[i][c] = f;
    }
    bool checkValidString(string s) {
        this->n = s.size();
        dp.resize(n , vector<int>(n+5 , -1));
        return dfs(0,0,s);
    }
};