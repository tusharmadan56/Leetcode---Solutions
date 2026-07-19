class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        vector<bool> fans;

        int c0=0,c1=0;
        for(auto x:s) {
            if(x=='0') c0++;
            else c1++;
        }


        for(auto &x:strs){
            int a=0,b=0;
            for(auto z:x){
                if(z=='0') a++;
                else if(z=='1') b++;
            }

            if(a<=c0 && b<=c1){
                int sz = x.size();
                vector<int> temp1(sz,0),temp2(sz,0);

                bool f= true;

                int diff = c1-b;

                for(int i=sz-1;i>=0;i--){
                    if(diff==0) break;

                    if(x[i]=='?'){
                        x[i]='1';
                        diff--;
                    }
                }


                for(int i=0;i<sz;i++){
                    if(x[i]=='1') temp1[i]++;
                    if(s[i]=='1') temp2[i]++;
                    if(i>0) temp1[i]+=temp1[i-1];
                    if(i>0) temp2[i]+=temp2[i-1];
                    //cout<<temp1[i]<<" "<<temp2[i]<<endl;

                    if(temp1[i]<=temp2[i]){
                        
                    }
                    else{
                        //cout<<x<<endl;
                        //cout<<temp1[i]<<" "<<temp2[i]<<endl;
                        f=false;
                        break;
                    }
                }

                if(f) fans.push_back(true);
                else fans.push_back(false);
            }
            else fans.push_back(false);
        }
        return fans;
    }
};