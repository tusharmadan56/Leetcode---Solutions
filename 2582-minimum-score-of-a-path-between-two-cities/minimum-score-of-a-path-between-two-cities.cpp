class Solution {
public:
    vector<int> parent;
    vector<int> size;
    vector<int> val;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x,int y,int ok ){
        int a = find(x);
        int b = find(y);

        if(a==b) {
            val[a] = min(ok,val[a]);
            return ;
        }

        if(size[a]<size[b]){
            swap(a,b);
        }

        parent[b] = a;
        size[a]+=size[b];
        val[a] = min({val[a],val[b],ok});
    }
    int minScore(int n, vector<vector<int>>& roads) {
        parent.resize(n+1);
        size.resize(n+1,1);

        val.resize(n+1,1e9+7);

        for(int i=1;i<=n;i++){
            parent[i] = i;
        }


        for(auto &e:roads){
            unite(e[0],e[1],e[2]);
        }

        int a = find(1);
        int b = find(n);

        return val[a];


    }
};