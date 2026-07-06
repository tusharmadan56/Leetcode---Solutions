class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> v;

        for(auto &e:intervals){
            v.push_back({e[1]-e[0]+1,e[0],e[1]});
        }

        sort(v.rbegin(),v.rend());

        set<int> s;
        int n = v.size();


        for(int i=0;i<n;i++){
            int a = v[i][1];
            int b = v[i][2];
           // cout<<a<<" "<<b<<endl;
            for(int j=i+1;j<n;j++){
                int c = v[j][1];
                int d = v[j][2];

               // cout<<c<<" "<<d<<endl;

                if(a<=c && d<=b){
                   // cout<<"j="<<j<<endl;
                    s.insert(j);
                }
            }
        }

        return v.size() - s.size();
    }
};