class Solution {
public:

    int n;
    vector<string> arr;

    int dfs(int i,vector<int>& pre,vector<vector<bool>>& v,vector<bool>& gg){

        if(i==n) return 0;
        
        int ans =0;

        ans = max(ans , dfs(i+1 , pre,v,gg));

        if(!gg[i]) return ans;


        bool f=true;

        for(auto x:pre){
            if(!v[x][i]){
                f=false;
                break;
            }
        }

        if(f){
            pre.push_back(i);
            ans = max(ans , (int)arr[i].size() + dfs(i+1 , pre,v,gg));
            pre.pop_back();
        }

        return ans;
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        this->arr = arr;
        this->n = arr.size();

        vector<vector<bool>> v(n,vector<bool>(n,false));
        vector<bool> gg(n,true);


        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int temp[26]={0};
                bool f =true;

                for(int k=0;k<arr[i].size();k++){
                    temp[arr[i][k]-'a']++;
                    if(temp[arr[i][k]-'a']>1) {
                        f=false;
                        break;
                    }
                }

                if(!f) gg[i] = false;

                for(int k=0;k<arr[j].size();k++){
                    if(temp[arr[j][k]-'a']>0){
                        f=false;
                        break;
                    }
                }
                if(f) v[i][j] = f;
            }
        }

        vector<int> pre;
       

        return dfs(0,pre,v,gg);
    }
};