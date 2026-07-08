class Solution {
public:
    vector<int> parent,size;
    #define tup tuple<int,int,int>
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int x,int y){
        int a = find(x);
        int b= find(y);

        if(a==b){
            return false;
        }

        if(size[a]<size[b]){
            swap(a,b);
        }

        parent[b] = a;
        size[b]+=size[a];

        return true;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int cost = 0;

        int sz = edges.size();

        parent.resize(n);
        size.resize(n,1);

        for(int i=0;i<n;i++) parent[i]=i;

        priority_queue<tup , vector<tup> , greater<tup>> pq;

        int cnt =0;

        for(auto &e:edges){
            pq.push({e[2],e[1],e[0]});
        }

        while(!pq.empty()){
            auto [wt,x,y] = pq.top();
            pq.pop();

            if(!unite(x,y)){

            }
            else{
                cost+=wt;
                cnt++;
            }

        }

        if(cnt!=n-1) return {{},{}};

        vector<int> ans1 , ans2;

        for(int i=0;i<sz;i++){
            priority_queue<tup , vector<tup> , greater<tup>> pq,pq2;
            for(int j=0;j<sz;j++){
                if(i==j) continue;
                pq.push({edges[j][2],edges[j][1],edges[j][0]});

                
            }

            pq2 = pq;

            size.assign(n,1);

            for(int i=0;i<n;i++) parent[i]=i;

            int c =0;

            int cnt1 = 0;

            //cout<<pq.size()<<endl;

                while(!pq.empty()){
                    auto [wt,x,y] = pq.top();
                    pq.pop();

                    if(!unite(x,y)){

                    }
                    else{
                        c+=wt;
                        cnt1++;
                    }

                }

                if(cnt1!=n-1) {
                    ans1.push_back(i);
                    continue;
                }

                //cout<<c<<endl;

                int cnt2 = 1;

                

                size.assign(n,1);

            for(int i=0;i<n;i++) parent[i]=i;

            int c2 =0;
            c2+=edges[i][2];
            unite(edges[i][0],edges[i][1]);

            while(!pq2.empty()){
                    auto [wt,x,y] = pq2.top();
                    pq2.pop();

                    if(!unite(x,y)){

                    }
                    else{
                        c2+=wt;
                        cnt2++;
                    }

                }

                //cout<<c2<<endl;

                if(c2>cost) {

                }
                else if(c == c2 && cnt2==n-1){
                    ans2.push_back(i);
                }
                else{
                    ans1.push_back(i);
                }



            


        }

        

        return {ans1,ans2};


    }
};