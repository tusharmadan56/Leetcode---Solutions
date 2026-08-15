class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int off = n + 2;
        int sz = 2*n + 5;

        vector<vector<int>> mp1(sz, vector<int>(2,-1)), mp2(sz, vector<int>(2,-1));
        vector<int> mp(sz,-1);

        int c =0 ;
        bool f1 = false,f2=false ;
        mp1[off][0] = 0;
        mp2[off][0] = 0;
        mp[off] = 0;
        int ans = 0;

        vector<bool> suff0(n+1,false), suff1(n+1,false);

        for(int i=n-1;i>=0;i--){
            suff1[i] = suff1[i+1] || (s[i]=='1');
            suff0[i] = suff0[i+1] || (s[i] == '0');
        }
        for(int i=0;i<n;i++){
            if(s[i]=='0') c--;
            else c++;

            if(mp2[c+2+off][1]!=-1){
                // if 1 avail
                ans = max(ans , i+1 - mp2[c+2+off][1]);
            }

            if(mp1[c-2+off][1]!=-1){
                // if 0 avail
                ans = max(ans , i+1 - mp1[c-2+off][1]);
            }

            if(mp[c+off]!=-1){
                ans = max(ans , i+1 - mp[c+off]);
            }

            if(mp2[c+2+off][0]!=-1 && suff1[i+1]){
                // if 1 avail
                ans = max(ans , i+1 - mp2[c+2+off][0]);
            }

            if(mp1[c-2+off][0]!=-1 && suff0[i+1]){
                // if 0 avail
                ans = max(ans , i+1 - mp1[c-2+off][0]);
            }

            if(s[i]=='0') f1=true;
            else f2 = true;

            if(mp2[c+off][f2]==-1){
                mp2[c+off][f2] = i+1;
            }

            if(mp1[c+off][f1]==-1){
                mp1[c+off][f1] = i+1;
            }

            if(mp[c+off]==-1){
                mp[c+off] = i+1;
            }
        }
        return ans;
    }
};