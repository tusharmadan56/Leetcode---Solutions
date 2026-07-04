class Solution {
public:
    int minOperations(string s1, string s2) {
        int n =s1.size();

        int ans =0;

        for(int i=n-1;i>=0;i--){
            if(s1[i]==s2[i]){
                continue;
            }

            if(s1[i]=='0' && s2[i]=='1'){
                ans++;
            }
            else{
                if(i>0){
                    if(s1[i-1]=='1'){
                        ans++;
                        s1[i-1]='0';
                    }
                    else{
                        ans+=2;
                        s1[i-1]='0';
                    }
                }
                else {
                    
                    if(n>1) ans+=2;
                    else return -1;
                }
            }

        }

        return ans;

    }
};