class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x,int y){
        int a = find(x);
        int b = find(y);

        if(x==y) return ;

        if(rank[a]<rank[b]){
            swap(a,b);
        }

        rank[a]+=rank[b];
        parent[b]=a;


    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent.resize(n);
        rank.resize(n,1);

        for(int i=0;i<n;i++) parent[i] = i;

        for(int i=0;i<n-1;i++){
            int val = nums[i+1]-nums[i];
            if(val<=maxDiff){
                unite(i,i+1);
            }
        }

        vector<bool> fans;


        for(auto &q:queries){
            int a = find(q[0]);
            int b = find(q[1]);

            if(a==b) fans.push_back(true);
            else fans.push_back(false);
        }

        return fans;
    }
};