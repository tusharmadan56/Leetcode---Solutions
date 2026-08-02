class Solution {
public:
    void lps(string s,vector<int>& lis){
        int n = lis.size();

        int len = 0;
        int i=1;

        while(i<n){
            if(s[i]==s[len]){
                len++;
                lis[i] = len;
                i++;
            }
            else{
                if(len==0){
                    lis[i]=0;
                    i++;
                }
                else{
                    len = lis[len-1];
                }
            }
        }
    }
    int strStr(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<int> lis(m,0);

        lps(t,lis);

        int i=0,j=0;

        while(i<n){
            if(s[i]==t[j]){
                i++;
                j++;

                if(j==m){
                    return i-j;
                }
            }
            else{
                if(j!=0){
                    j = lis[j-1];
                }
                else{
                    i++;
                }
            }
        }

        return -1;


    }
};