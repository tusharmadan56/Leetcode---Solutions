class Solution {
public:
    #define tup tuple<int,int,int>
    vector<int> st;
    vector<tup> v;
    int n;
    vector<int> dp;
    int dfs(int i){

        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];

        int ans = 0;

        auto [s,e,p] = v[i];

        ans = dfs(i+1);

        auto ok = lower_bound(st.begin()+i+1,st.end(),e);

        int pos=-1;

        if(ok!=st.end()){
            pos = ok-st.begin();
            //cout<<i<<" "<<pos<<endl;
            ans = max(ans , p + dfs(pos));
        }
        else{
            ans = max(ans , p);
        }

        return dp[i]=ans;



        
    }
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& p) {
        

        
        this->n = st.size();

        dp.resize(n,-1);
        

        for(int i=0;i<n;i++){
            v.push_back({st[i],et[i],p[i]});
            
            
        } 

        sort(st.begin(),st.end());
        this->st = st;

        sort(v.begin(),v.end());

        return dfs(0);





    }
};