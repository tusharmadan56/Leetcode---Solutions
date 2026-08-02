class Solution {
public:

    string countAndSay(int n) {
        if(n==1) return "1";

        string ans = countAndSay(n-1);

        string ok ="";
        int c=1;
        int sz = ans.size();
        for(int i=1;i<sz;i++){
            if(ans[i]==ans[i-1]){
                c++;
            }
            else{
                ok+=to_string(c);
                ok+=ans[i-1];
                c=1;
            }
        }
        if(c!=0){
            ok+=to_string(c);
            ok+=ans.back();
        }
        return ok;
    }
};