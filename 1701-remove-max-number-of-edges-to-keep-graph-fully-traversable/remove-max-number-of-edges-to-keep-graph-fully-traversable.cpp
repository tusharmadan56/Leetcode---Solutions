class Solution {
public:
    

    int find(int x,vector<int>& parent){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x],parent);
    }

    bool unite(int x,int y,vector<int>& parent,vector<int>& size){
        int a = find(x,parent);
        int b = find(y,parent);

        if(a==b) return false;

        if(size[a]<size[b]) swap(a,b);

        parent[b]=a;
        size[a]+=size[b];

        return true;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> parent1(n),parent2(n),size1(n,1),size2(n,1);
        for(int i=0;i<n;i++) {
            parent1[i] = i;
            parent2[i] = i;
        }

        int ans =0;

        for(auto &v:edges){
            if(v[0]==3){

                bool f1 = unite(v[1]-1,v[2]-1,parent1,size1);
                bool f2 = unite(v[1]-1,v[2]-1,parent2,size2);
                if(!(f1) && !(f2)){
                    ans++;
                }
            }
        }



        for(auto &v:edges){
            if(v[0]==1){
                if(!(unite(v[1]-1,v[2]-1,parent1,size1))){
                    ans++;
                }
            }
            else if(v[0]==2){
                if(!(unite(v[1]-1,v[2]-1,parent2,size2)) ){
                    ans++;
                }   
            }
            
        }

        int c1=0,c2=0;

        for(int i=0;i<n;i++){
            if(find(i,parent1)==i) c1++;
            if(find(i,parent2)==i) c2++;
        }

        if(c1>1 || c2>1) return -1;

        return ans;



        


    }
};