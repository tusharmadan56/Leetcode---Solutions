class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        set<pair<int,int>> s;

        q.push({0,0});

        int ans =1;

        if(grid[0][0]==1) return -1;

        s.insert({0,0});

        int c =0;

        while(!q.empty()){
            int size= q.size();

            //cout<<"s="<<s<<endl;

            for(int i=0;i<size;i++){
                auto [x,y] = q.front();
                q.pop();

                s.insert({x,y});
                //cout<<x<<" "<<y<<endl;
                // c++;
                // if(c==10010) return -1;

                //cout<<x<<" "<<y<<endl;

                if(x==n-1 && y==m-1 ) return ans;

                int dx[]={-1,-1,-1,0,1,1,1,0};
                int dy[]={-1,0,1,1,1,0,-1,-1};

                for(int k=0;k<8;k++){
                    int nx = dx[k]+x;
                    int ny = dy[k]+y;

                    if(nx>=0 && nx<n && ny>=0 && ny<m && s.find({nx,ny})==s.end() && grid[nx][ny]==0){
                        q.push({nx,ny});
                        s.insert({nx,ny});
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};