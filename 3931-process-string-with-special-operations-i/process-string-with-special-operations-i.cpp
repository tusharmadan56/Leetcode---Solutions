class Solution {
public:
    string processStr(string s) {
        string str ="";

        for(auto x:s){
            if(x=='*'){
                if(str.size()>0) str.pop_back();
            }
            else if(x=='#') str+=str;
            else if(x=='%'){
                reverse(str.begin(),str.end());
            }
            else{
                str+=x;
            }
        }
        return str;
    }
};