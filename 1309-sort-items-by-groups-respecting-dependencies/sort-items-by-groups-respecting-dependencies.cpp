class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& bef) {
        vector<vector<int>> g(n);
        vector<int> in(n,0);

        int it = m;

        for(int i=0;i<n;i++){
            if(group[i]==-1) {
                group[i] = it;
                it++;
            }
        }

        vector<unordered_set<int>> ng(it);
        vector<int> in2(it,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<bef[i].size();j++){
                //cout<<bef[i][j]<<endl;
                g[bef[i][j]].push_back(i);
                in[i]++;
                int a = group[bef[i][j]];
                int b = group[i];
                if(a==b) continue;
                if(ng[a].find(group[i])==ng[a].end()){
                    ng[a].insert(group[i]);
                    in2[group[i]]++;
                }
                
            }
           // gr[group[i]]++;
        }

        

        queue<int> q;
        for(int i=0;i<n;i++){
            if(in[i]==0){
                q.push(i);
            }
        }

        

        vector<int> ans;


        while(!q.empty()){
            int f = q.front();

            q.pop();

            //cout<<f<<endl;

            ans.push_back(f);

            for(auto x:g[f]){
                in[x]--;
                if(in[x]==0){
                    q.push(x);
                }
            }
        }

        if(ans.size()!=n) return {};


        

        for(int i=0;i<it;i++){
            if(in2[i]==0){
                q.push(i);
            }
        }

        // for(auto x:ans) cout<<x<<" ";
        // cout<<endl;

        

        vector<int> fans;


        while(!q.empty()){
            int f = q.front();

            q.pop();

           // cout<<f<<endl;

            fans.push_back(f);

            for(auto x:ng[f]){
                in2[x]--;
                if(in2[x]==0){
                    q.push(x);
                }
            }
        }

         if(fans.size()!=it) return {};
        // for(auto x:fans) cout<<x<<" ";
        // cout<<endl;


        vector<int> gg;

        map<int,vector<int>> mp;

        for(int i=0;i<n;i++){
            mp[group[ans[i]]].push_back(ans[i]);
        }

        for(int i=0;i<it;i++){
            for(auto x:mp[fans[i]]){
                gg.push_back(x);
            }
        }

        return gg;
    }
};