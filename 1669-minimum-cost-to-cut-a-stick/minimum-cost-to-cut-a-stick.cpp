class Solution {
public:
    int sz;
    vector<int> cuts;
    map<pair<int,int>,int> mp;
    int dfs(int i,int j){

        if(i==j) return 0;

        if(mp.find({i,j})!=mp.end()) return mp[{i,j}];

        int ans =1e9;

        for(int k=0;k<sz;k++){
            if(cuts[k]>i && cuts[k]<j){
                ans = min(ans , j-i + dfs(i,cuts[k])+dfs(cuts[k],j));
            }
        }

        if(ans == 1e9) return 0;

        return mp[{i,j}]=ans; 
    }
    int minCost(int n, vector<int>& cuts) {
        this->sz = cuts.size();
        this->cuts = cuts;

        return dfs(0,n);
    }
};