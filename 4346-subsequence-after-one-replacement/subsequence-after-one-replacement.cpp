class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size();
        vector<int> pref(n+1,-1),suff(n+1,-1);

        int j =0 ;

        suff[n] = 1;

        int m =t.size();

        for(int i=0;i<n;i++){
            char ch = s[i];

            while(j<m && t[j]!=ch){
                j++;
            }

            if(j==m) break;

            pref[i] = j;
            j++;
        }

        j= m-1;

        for(int i=n-1;i>=0;i--){
            char ch = s[i];

            while(j>=0 && t[j]!=ch){
                j--;
            }

            if(j<0) break;
            suff[i] = j;
            j--;
        }

        

        for(int i=0;i<n;i++){
            if(i==0){
                int temp = suff[i+1];

               // cout<<temp<<endl;

                if(temp>0) return true;
            }
            else if(i==n-1){
                int temp = pref[i-1];
               //cout<<temp<<endl;
                if(temp>-1 && temp<m-1) return true;
            }

            else {
                int temp1 = pref[i-1],temp2 = suff[i+1];
               // cout<<temp1<<" "<<temp2<<endl;
                if(temp1==-1 || temp2==-1) continue;

                if(temp1<temp2 && temp2-temp1>1) return true;
            }
        }

        return false;

        return {};
    }
};